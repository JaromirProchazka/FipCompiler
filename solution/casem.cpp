#include "casem.hpp"
#include "ckgrptokens.hpp"
#include "ckcontext.hpp"
#include "cktables.hpp"
#include "ckbisonflex.hpp"
#include <iostream>
#include <string>
#include <climits>
#include <cstdio>

namespace casem
{
    int max_type_tag = 0;

    std::unordered_map<std::string, std::pair<int, int>> type_to_id;
    std::unordered_map<std::string, long> type_to_reuse_size;
    std::unordered_map<long, long> id_to_reuse_size;
    std::unordered_map<std::string, bool> parents_null_type;

    const std::string ttype_tag_label = "_tag";
    const std::string reuse_function_template = "_reuse_";
    const std::string constructor_name_template = "_const_";
    const std::string res_label = "_result";
    const std::string print_label = "log";
    const std::string pair_type = "Pair";
    const std::string tupple3_type = "Tuple3";
    const std::string tupple4_type = "Tuple4";
    const std::string tagged_parent_type = "object";
    const std::string tagged_child_type = "Tagged";
    const std::string boolean_non_heap_type = "Boolean";
    bool support_functions_defined = false;
    FipState fip_state;
    const int POINTER_BYTES_COUNT = 8;

#if GENERATE_STATIC_DEBUG_LOG
    void log(const char *msg, ...)
    {
        va_list args;
        va_start(args, msg);

        vprintf(msg, args);
        va_end(args);
    }
    void log(const std::string &msgs)
    {
        std::cout << msgs;
    }
    void log_name(const char *msg, const std::string &name)
    {
        std::cout << msg << " | '" << name << "'" << std::endl;
    }
#else
    void log(const char *msg, ...) {}
    void log(const std::string &msgs) {}
    void log_name(const char *msg, const std::string &name) {}
#endif

    void insert_null_ttype(const std::string &tlabel, bool is_null = true)
    {
        parents_null_type.emplace(tlabel, is_null);
    }
    bool is_null_ttype(const std::string &tlabel)
    {
        return parents_null_type.find(tlabel)->second;
    }
    void insert_ttypes(const std::string &tlabel, int first_tag, int end_tag, long reuse_size)
    {
        type_to_id.emplace(tlabel, std::make_pair(first_tag, end_tag));
        type_to_reuse_size.emplace(tlabel, reuse_size);
        insert_null_ttype(tlabel, false);
    }
    void insert_ttype(const std::string &tlabel, int tag, long reuse_size, bool is_empty_label_type)
    {
        type_to_id.emplace(tlabel, std::make_pair(tag, tag));
        type_to_reuse_size.emplace(tlabel, (long)reuse_size);
        id_to_reuse_size.emplace(tag, (long)reuse_size);
        insert_null_ttype(tlabel, is_empty_label_type);
    }
    const std::pair<int, int> &find_ttype(const std::string &tlabel)
    {
        auto it = type_to_id.find(tlabel);
        if (it != type_to_id.end())
            return it->second;
        static const std::pair<int, int> empty_pair(-1, -1);
        return empty_pair;
    }
    long find_ttype_size(const std::string &tlabel)
    {
        auto it = type_to_reuse_size.find(tlabel);
        if (it != type_to_reuse_size.end())
            return it->second;
        return -1;
    }
    long find_ttype_size(long tag)
    {
        auto it = id_to_reuse_size.find(tag);
        if (it != id_to_reuse_size.end())
            return it->second;
        return -1;
    }
    long check_subtypes_has_same_size(long first_tag, long end_tag)
    {
        if (first_tag == end_tag)
            return -1;

        bool same = true;
        long found_size = find_ttype_size(first_tag);
        for (long i = first_tag; i < end_tag; i++)
        {
            auto cur_found = find_ttype_size(i);
            if (cur_found != found_size)
            {
                found_size = -1;
                same = false;
            }
        }

        return (same) ? found_size : -1;
    }

    bool ttype_is_parent_of_subtype(const std::string &expected_parent_label, const std::string &expected_child_label)
    {
        auto p = find_ttype(expected_parent_label);
        auto c = find_ttype(expected_child_label);

        return (p.first <= c.first && c.first < p.second) || (p.first == c.first && p.second == c.second);
    }

    long fetch_ttype_size(cecko::context *ctx, cecko::CIName &label)
    {
        auto found_size = find_ttype_size(label);
        if (found_size < 0)
        {
#if ENFORCE_FIP
            ctx->message(cecko::errors::SYNTAX, ctx->line(), std::string("Type '") + label + "' has no found size!");
#endif
            found_size = -1;
        }
        return found_size;
    }

    InstructionWrapper init_instruction_from_name(cecko::context *ctx, const cecko::CIName &name)
    {
        // log("Started init_instruction_from_name init\n");
        auto desc = ctx->find(name);
        if (!desc)
        {
            ctx->message(cecko::errors::UNDEF_IDF, ctx->line(), name);
            return InstructionWrapper();
        }

        VarMode vmode;
        cecko::CKIRValueObs instruction;
        cecko::CKTypeSafeObs vtype;

        if (desc->is_var())
        {
            vmode = LValue;
            instruction = desc->get_ir();
            vtype = desc->get_type();
            // ctx->get_pointer_type(cecko::CKTypeRefPack(desc->get_type(), false));
        }
        else if (desc->is_function())
        {
            vmode = RValue;
            instruction = desc->get_function_ir();
            vtype = desc->get_type();
        }
        else
        {
            vmode = RValue;
            instruction = desc->get_ir();
            vtype = desc->get_type();
        }

        log("Got throw init_instruction_from_name '" + name + "' init\n");

        return InstructionWrapper(
            ctx,
            vmode,
            instruction,
            vtype,
            desc->is_constant(),
            name);
    }
    InstructionWrapper init_instruction_function_call(cecko::context *ctx, const InstructionWrapper &inst, InstructionArray fargs)
    {
        // log("Started function call\n");

        assertm(inst.type->is_function(), std::string("") + "given type of instruction " + inst.name + " to call is not a funcion");
        cecko::CKFunctionTypeSafeObs ftype((cecko::CKFunctionTypeObs)((cecko::CKTypeObs)(inst.type)));
        for (std::size_t i = 0; i < ftype->get_function_arg_count(); i++)
        {
            auto ptype = ftype->get_function_arg_type(i);
            fargs[i] = fargs[i].to_type(ptype);
        }

        auto ifargs = get_args_instructions(fargs);
        if (!inst.type->is_function())
        {
            ctx->message(cecko::errors::UNDEF_IDF, ctx->line(), inst.name);
            return InstructionWrapper();
        }

        log("Init Function Call done\n");
        return InstructionWrapper(
            ctx,
            inst.mode,
            ctx->builder()->CreateCall((cecko::CKIRFunctionTypeObs)ftype->get_ir(), inst.value, ifargs),
            inst.type->get_function_return_type(),
            inst.is_const,
            inst.name + "_call");
    }
    InstructionWrapper init_instruction_const(cecko::context *ctx, int intlit)
    {
        return InstructionWrapper(
            ctx,
            RValue,
            ctx->get_int32_constant(intlit),
            ctx->get_int_type(),
            true,
            std::to_string(intlit));
    }
    InstructionWrapper init_instruction_const(cecko::context *ctx, const cecko::CIName &strlit)
    {
        // log("|.init_instruction_const| Making string \""+strlit+"\"\n");
        llvm::StringRef str_ref(strlit);
        auto global_string = ctx->builder()->CreateGlobalString(str_ref);
        return InstructionWrapper(
            ctx,
            RValue,
            global_string,
            ctx->get_pointer_type(cecko::CKTypeRefPack(ctx->get_char_type(), true)),
            true,
            strlit);
    }
    InstructionWrapper init_instruction_malloca(cecko::context *ctx, cecko::CKTypeSafeObs type, const cecko::CIName &name, std::size_t ru_count)
    {
        // auto &&type_size_num = (cecko::CKIRValueObs)ctx->get_type_size(type);
        auto &&type_size_num = (cecko::CKIRValueObs)ctx->get_int32_constant((int)ru_count * POINTER_BYTES_COUNT);
        auto &&type_size_num_wrapper = InstructionWrapper(ctx, RValue, type_size_num, ctx->get_int_type(), true, "sizeof(" + name + ")");
        // auto &&malloc_call = llvm::CallInst::CreateMalloc(
        //     ctx->builder()->GetInsertBlock(),
        //     ctx->get_int_type()->get_ir(), // type of int that will be used for sizes
        //     type->get_ir(),                // allocated type
        //     type_size_num,                 // size of allocated type
        //     nullptr,                       // implicitely 1, array with 1 element same in mem as 1 element
        //     nullptr,                       // on fail
        //     "malloc"                       // name
        // );
        auto &&malloc_call = init_instruction_function_call(ctx, init_instruction_from_name(ctx, "@malloc"), {type_size_num_wrapper});

        auto &&ret_type = ctx->get_pointer_type(cecko::CKTypeRefPack(type, false));
        cecko::CIName casted_label = "(type)malloc";
        auto &&casted = ctx->builder()->CreateBitCast(malloc_call.read_ir(), ret_type->get_ir(), casted_label);
        return InstructionWrapper(ctx, RValue, casted, ret_type, false, casted_label);
    }

    std::string get_constructor_label(const cecko::CIName &tname)
    {
        return constructor_name_template + tname;
    }
    std::string get_reuser_label(const cecko::CIName &tname)
    {
        return reuse_function_template + tname;
    }
    inline bool is_reuser_label(const cecko::CIName &fname)
    {
        return fname.substr(0, reuse_function_template.length()) == reuse_function_template;
    }

    /** Creates control flow data at start of the if statement and preares context to create control flow */
    IfControllFlowData init_if_data(cecko::context *ctx, InstructionWrapper &cond)
    {
        IfControllFlowData data;
        data.condition = cond;
        data.continue_block = ctx->builder()->GetInsertBlock();
        data.if_block = ctx->create_basic_block("if.then");
        data.if_block_back = data.if_block;
        data.end_block = ctx->create_basic_block("if.end");
        log("SWITCHING to if_block_back\n");
        ctx->builder()->SetInsertPoint(data.if_block_back);

        return data;
    }
    /**
     * @brief To the current insertion point append the if-else statement and at the end sets the basic block to a new one.
     *
     * @param condition instruction representiong the bool condition from the `if(condition)` statement, if the given instrucction isn't bool castable, simply returns the current basic block
     * @param data containes the relevant blocks for the if control flow assembly
     * @return the resulting current basic block that is the same as at the start of the function
     */
    cecko::CKIRBasicBlockObs create_if_control_flow(cecko::context *ctx, IfControllFlowData &data, bool make_if_unreachable)
    {
        log("Entered create_if_control_flow\n");
        // cecko::CKIRBasicBlockObs continue_block = ctx->builder()->GetInsertBlock();
        auto condv = data.condition.to_bool();
        if (data.continue_block == NULL)
        {
            data.continue_block = ctx->builder()->GetInsertBlock();
        }
        if (!condv.is_valid())
        {
            ctx->message(cecko::errors::SYNTAX, ctx->line(), "if condition is not bool or bool castable!");
            return data.end_block;
        }
        if (data.if_block == NULL || data.if_block_back == NULL)
        {
            ctx->message(cecko::errors::SYNTAX, ctx->line(), "The blocks needed for if control flow assembly are not set!");
            return data.end_block;
        }

        if (data.end_block == NULL)
        {
            data.end_block = ctx->create_basic_block("if_end");
        }

        // log("{create_if_control_flow} condition valid\n");
        auto cond = condv.read_ir();
        cecko::CKIRBasicBlockObs if_false_block; // = (data.else_block) ? data.else_block : data.continue_block;
        if (data.else_block != NULL)
        {
            // log("{create_if_control_flow} Choose else block as the if_false_block\n");
            if_false_block = data.else_block;
        }
        else
        {
            // log("{create_if_control_flow} Choose continue block as the if_false_block\n");
            if_false_block = data.end_block;
        }

        // log("{create_if_control_flow} if_false_block decided\n");
        ctx->builder()->CreateCondBr(cond, data.if_block, if_false_block);
        // log("SWITCHING to if_block\n");
        ctx->builder()->SetInsertPoint(data.if_block_back);

        if (make_if_unreachable)
        {
            ctx->builder()->CreateUnreachable();
        }
        else
        {
            ctx->builder()->CreateBr(data.end_block);
        }

        if (data.else_block != NULL)
        {
            // log("SWITCHING to else_block\n");
            ctx->builder()->SetInsertPoint(data.else_block_back);
            ctx->builder()->CreateBr(data.end_block);
        }

        // log("SWITCHING to end_block\n");
        ctx->builder()->SetInsertPoint(data.end_block);
        return data.end_block;
    }

    void enter_block(cecko::context *ctx)
    {
        ctx->enter_block();
        if (fip_state.is_in_fip_mode())
            fip_state.enter_fip_context();
    }
    void exit_block(cecko::context *ctx)
    {
        if (fip_state.is_in_fip_mode())
            fip_state.exit_fip_context();
        ctx->exit_block();
    }

    MatchWrapper init_match_binders_list(cecko::context *ctx, MatchBinderListHeadData &data, InstructionWrapper &conditioned_result_value)
    {
        log("|init_match_binders_list| init vars\n");
        auto &match_dt = data.head_data;
        auto &binder_data = data.binder_data;
        auto &if_data = binder_data.if_data;

        // conditioned_result_value.generate_debug_print("match_binder_if -> result = ");
        // log("|init_match_binders_list| finding res\n");
        auto res = match_dt.result; // init_instruction_from_name(ctx, match_result_template);
        // res.generate_debug_print("'match binder' match result before store");
        // log("|init_match_binders_list| storing to result\n");
        res.store(conditioned_result_value);
        // log("|init_match_binders_list| debug printing\n");
        res.generate_debug_print("'match binder' match result after store");
        // log("|init_match_binders_list| exiting block\n");
        exit_block(ctx);
        // set current insertion block as the back of the if.then block
        // log("|init_match_binders_list| setting if_block_end\n");
        if_data.if_block_back = ctx->builder()->GetInsertBlock();

        // log("|init_match_binders_list| setting continue block\n");
        ctx->builder()->SetInsertPoint(if_data.continue_block);
        // log("|init_match_binders_list| setting if controll flow\n");

        log("|init_match_binders_list| checking if this pattern check is null check\n");
        if (data.is_first_pattern_null_check)
        {
            log("|init_match_binders_list| pattern check IS null check\n");
            binder_data.if_data = IfExpressionData::init_if_else_head(ctx, if_data).if_data;
            if_data = binder_data.if_data;
            match_dt.first_pattern_null_check_data = std::make_shared<MatchBinderChackerData>(binder_data);
        }
        else
        {
            create_if_control_flow(ctx, if_data);
        }

        log("|init_match_binders_list| done\n");
        return match_dt;
    }

    WhileControllFlowData init_while_data(cecko::context *ctx, InstructionWrapper &cond)
    {
        WhileControllFlowData data;
        data.continue_block = ctx->builder()->GetInsertBlock();

        data.code_block = ctx->create_basic_block("while.body");
        data.code_block_back = data.code_block;
        data.end_block = ctx->create_basic_block("while.end");

        // init condition block
        data.condition_block = ctx->create_basic_block("while.cond");
        ctx->builder()->SetInsertPoint(data.condition_block);
        auto condv = cond.to_bool();
        if (!condv.is_valid())
        {
            ctx->message(cecko::errors::SYNTAX, ctx->line(), "if condition is not bool or bool castable!");
            return data;
        }
        auto condi = condv.read_ir();
        data.condition = condv;
        ctx->builder()->CreateCondBr(condi, data.code_block, data.end_block);
        // init condition block done

        ctx->builder()->SetInsertPoint(data.continue_block);
        ctx->builder()->CreateBr(data.condition_block);

        ctx->builder()->SetInsertPoint(data.code_block_back);
        return data;
    }
    cecko::CKIRBasicBlockObs create_while_control_flow(cecko::context *ctx, WhileControllFlowData &data)
    {
        if (data.code_block == NULL || data.code_block_back == NULL || data.condition_block == NULL)
        {
            ctx->message(cecko::errors::SYNTAX, ctx->line(), "The blocks needed for while control flow assembly are not set!");
            return data.end_block;
        }

        ctx->builder()->SetInsertPoint(data.code_block_back);
        ctx->builder()->CreateBr(data.condition_block);

        log("SWITCHING to end_block\n");
        ctx->builder()->SetInsertPoint(data.end_block);
        return data.end_block;
    }

    WhileControllFlowData init_do_data(cecko::context *ctx)
    {
        WhileControllFlowData data;
        data.continue_block = ctx->builder()->GetInsertBlock();
        data.code_block = ctx->create_basic_block("do.body");
        data.code_block_back = data.code_block;
        data.end_block = ctx->create_basic_block("do.end");

        ctx->builder()->SetInsertPoint(data.code_block_back);
        return data;
    }
    cecko::CKIRBasicBlockObs create_do_control_flow(cecko::context *ctx, WhileControllFlowData &data, InstructionWrapper &cond)
    {
        // init condition block
        data.condition_block = ctx->create_basic_block("do.cond");
        ctx->builder()->SetInsertPoint(data.condition_block);
        auto condv = cond.to_bool();
        if (!condv.is_valid())
        {
            ctx->message(cecko::errors::SYNTAX, ctx->line(), "if condition is not bool or bool castable!");
            return ctx->builder()->GetInsertBlock();
        }
        auto condi = condv.read_ir();
        data.condition = condv;
        ctx->builder()->CreateCondBr(condi, data.code_block, data.end_block);
        // init condition block done

        ctx->builder()->SetInsertPoint(data.code_block_back);
        ctx->builder()->CreateBr(data.condition_block);

        ctx->builder()->SetInsertPoint(data.continue_block);
        ctx->builder()->CreateBr(data.code_block);

        log("SWITCHING to end_block\n");
        ctx->builder()->SetInsertPoint(data.end_block);
        return data.end_block;
    }

    CKTypeRefDefPack to_ckt(const cecko::CKStructItem &other)
    {
        CKTypeRefDefPack res(other.pack.type, other.pack.is_const, false, false);
        res.name = other.name;
        return res;
    }
    void declare_type_constructor(cecko::context *ctx, const std::string &tname, const cecko::CKStructTypeSafeObs &type, const cecko::CKStructItemArray &params, bool heap_type, bool null_type)
    {
        auto &&type_tag_range = find_ttype(tname);
        log("|declare_type_constructor| found type tag value\n");
        if (type_tag_range.first < 0)
        {
            ctx->message(cecko::errors::SYNTAX, ctx->line(), "\nError: tagged type '" + tname + "' tag value was not found!\n");
            return;
        }

        std::string constructor_name = get_constructor_label(tname);

        // log("|declare_type_constructor| Parsing struct items to function args\n");
        bool ontag = true;
        cecko::CKTypeObsArray param_types;
        cecko::CKFunctionFormalPackArray param_names_pack;
        for (auto &struct_name_pack : params)
        {
            if (ontag)
            {
                ontag = false;
                continue;
            }
            cecko::CKFunctionFormalPack arg(struct_name_pack.name, true, ctx->line());
            param_names_pack.push_back(arg);
            auto &&name_pack = to_ckt(struct_name_pack);
            param_types.push_back(name_pack.type);
        }
        // log("|declare_type_constructor| parsing done, Declaring function\n");

        auto &&ret_type = ctx->get_pointer_type(cecko::CKTypeRefPack(type, false));
        auto &&ftype = ctx->get_function_type(ret_type, param_types);
        cecko::CKFunctionObs fobs = ctx->declare_function(constructor_name, ftype, ctx->line());

        InstructionWrapper global_store_locarion;
        if (!heap_type)
        {
            cecko::CIName reuse_var_label = tname + "_global_stored";
            ctx->define_var(
                reuse_var_label,
                ret_type->get_pointer_points_to(),
                ctx->line());
            global_store_locarion = &init_instruction_from_name(ctx, reuse_var_label);
        }

        // log("|declare_type_constructor| declare done, declaring function body\n");
        ctx->enter_function(fobs, param_names_pack, ctx->line());

        casem::InstructionWrapper allocated;
        if (!heap_type)
        {
            allocated = global_store_locarion;
        }
        else if (null_type)
        {
            log(std::string("") + "|declare_type_constructor| declaring null constructor\n");
            ctx->builder()->CreateRet(ctx->get_null_constant(ret_type));
            ctx->exit_function();
            return;
        }
        else
        {
            allocated = init_instruction_malloca(ctx, type, res_label, params.size());
        }

        log(std::string("") + "|declare_type_constructor| Constructing tname with " + std::to_string(params.size()) + " reuse tokens\n");
        // log("|declare_type_constructor| alloc result temporary variable\n");
        ctx->define_var(res_label, cecko::CKTypeRefPack(ret_type, false), ctx->line());
        auto &&res = init_instruction_from_name(ctx, res_label);
        // res.generate_debug_print("'declare_type_constructor' result on init is");

        // log("|declare_type_constructor| storing allocated to temporary variable\n");
        res.store(allocated);
        res.generate_debug_print("'declare_type_constructor' result after storing allocated is");

        // log("|declare_type_constructor| set tag field\n");
        auto tag_field = res.field(ttype_tag_label, ctx->get_int_type());
        // tag_field.generate_debug_print("'declare_type_constructor' tag field before set in constructor");
        // log("|declare_type_constructor| found tag field\n");
        auto &&tag_val_inst = init_instruction_const(ctx, type_tag_range.first);
        // log("|declare_type_constructor| inited tag value '" + std::to_string(type_tag_range.first) + "' constant instruction\n");
        tag_field.store(tag_val_inst);
        res.field(ttype_tag_label, ctx->get_int_type()).generate_debug_print("'declare_type_constructor' tag field after set in constructor");

        // log("|declare_type_constructor| stored tag val, Set rest fields\n");
        auto &&param_name = param_names_pack.begin();
        for (auto &&param_type = param_types.begin(); param_type < param_types.end(); ++param_name, ++param_type)
        {
            auto &&arg_name = param_name->name.value();
            auto &&field = res.field(arg_name, cecko::safe_ptr(*param_type));
            auto &&farg = init_instruction_from_name(ctx, arg_name);
            field.store(farg);
        }

        // log("|declare_type_constructor| set return\n");
        // return
        res.generate_debug_print("'declare_type_constructor'" + constructor_name + " -> " + res.name);
        ctx->builder()->CreateRet(res.read_ir());
        ctx->exit_function();

        log("|declare_type_constructor| function body done, DONE\n");
    }
    void declare_type_reuser(cecko::context *ctx, const std::string &tname, const cecko::CKStructTypeSafeObs &type, const cecko::CKStructItemArray &params, bool heap_type)
    {
        auto &&type_tag_range = find_ttype(tname);
        auto ret_type = ctx->get_pointer_type(cecko::CKTypeRefPack(type, false));
        log("|declare_type_reuser| found type tag value\n");
        if (type_tag_range.first < 0)
        {
            ctx->message(cecko::errors::SYNTAX, ctx->line(), "\nError: tagged type '" + tname + "' tag value was not found!\n");
            return;
        }

        std::string constructor_name = get_reuser_label(tname);

        // log("|declare_type_reuser| Parsing struct items to function args\n");
        std::string address_val_label = "@ru";
        cecko::CKTypeObsArray param_types = {ret_type};
        cecko::CKFunctionFormalPackArray param_names_pack = {cecko::CKFunctionFormalPack(address_val_label, true, ctx->line())};
        for (auto &struct_name_pack : params)
        {
            log(std::string("FOR => ") + struct_name_pack.name + "\n");
            if (struct_name_pack.name == ttype_tag_label)
                continue;
            log(std::string("\t-> ") + struct_name_pack.name + "\n");
            cecko::CKFunctionFormalPack arg(struct_name_pack.name, true, ctx->line());
            param_names_pack.push_back(arg);
            auto &&name_pack = to_ckt(struct_name_pack);
            param_types.push_back(name_pack.type);
        }
        // log("|declare_type_reuser| parsing done, Declaring function\n");

        auto &&ftype = ctx->get_function_type(ret_type, param_types);
        cecko::CKFunctionObs fobs = ctx->declare_function(constructor_name, ftype, ctx->line());

        // log("|declare_type_reuser| declare done, declaring function body\n");

        ctx->enter_function(fobs, param_names_pack, ctx->line());

        // log("|declare_type_reuser| set result temporary variable to the given argument\n");
        ctx->define_var(res_label, cecko::CKTypeRefPack(ret_type, false), ctx->line());
        auto &&res = init_instruction_from_name(ctx, res_label);
        auto &&allocated = init_instruction_from_name(ctx, address_val_label);
        // log("|declare_type_reuser| storing allocated to temporary variable\n");
        res.store(allocated);

        // log("|declare_type_reuser| set tag field\n");
        auto tag_field = res.field(ttype_tag_label, ctx->get_int_type());
        // tag_field.generate_debug_print("tag field before set in reuser");
        // log("|declare_type_reuser| found tag field\n");
        auto &&tag_val_inst = init_instruction_const(ctx, type_tag_range.first);
        // log("|declare_type_reuser| inited tag value '" + std::to_string(type_tag_range.first) + "' constant instruction\n");
        tag_field.store(tag_val_inst);
        res.field(ttype_tag_label, ctx->get_int_type()).generate_debug_print("tag field after set in constructor");

        // log("|declare_type_reuser| stored tag val, Set rest fields\n");
        auto &&param_name = param_names_pack.begin();
        for (auto &&param_type = param_types.begin(); param_type < param_types.end(); ++param_name, ++param_type)
        {
            log(std::string("FOR => ") + (param_name->name.value()) + "\n");
            if (param_name->name.value() == address_val_label)
                continue;
            log(std::string("\t-> ") + (param_name->name.value()) + "\n");
            auto &&arg_name = param_name->name.value();
            auto &&field = res.field(arg_name, cecko::safe_ptr(*param_type));
            auto &&farg = init_instruction_from_name(ctx, arg_name);
            field.store(farg);
        }

        // log("|declare_type_reuser| set return\n");
        // return
        res.generate_debug_print(constructor_name + " -> " + res.name);
        ctx->builder()->CreateRet(res.read_ir());
        ctx->exit_function();
        log("|declare_type_reuser| function body done, DONE\n");
    }

    TaggedTypeDecl declare_parent_ttype(cecko::context *ctx, cecko::CIName label)
    {
        // FIXME: Handle tag range
        log_name("[enumtype_decl_head:]", label);
        cecko::CKStructItemArray struct_items;
        struct_items.push_back(casem::get_tag_strauct_item(ctx));

        log("Define struct type\n");
        auto struct_obs = ctx->declare_struct_type(label, ctx->line());
        ctx->define_struct_type_open(label, ctx->line());
        ctx->define_struct_type_close(struct_obs, struct_items);

        int first_enumtype_tag = max_type_tag;
        casem::TaggedTypeDecl res(struct_obs, first_enumtype_tag);

        return res;
    }
    cecko::CKStructTypeSafeObs declare_child_ttype(cecko::context *ctx, cecko::CIName label, cecko::CKStructItemArray struct_items, bool heap_type)
    {
        struct_items.insert(struct_items.begin(), casem::get_tag_strauct_item(ctx));
        auto &&struct_obs = ctx->declare_struct_type(label, ctx->line());

        ctx->define_struct_type_open(label, ctx->line());
        ctx->define_struct_type_close(struct_obs, struct_items);

        long type_reuse_size = (heap_type) ? ((long)struct_items.size() - 1) : (-1);
        casem::insert_ttype(label, max_type_tag, type_reuse_size, type_reuse_size == 0 && heap_type);
        ++casem::max_type_tag;

        casem::declare_type_constructor(ctx, label, struct_obs, struct_items, heap_type, is_null_ttype(label));
        if (heap_type && !is_null_ttype(label))
        {
            casem::declare_type_reuser(ctx, label, struct_obs, struct_items);
        }

        return struct_obs;
    }
    void declare_support_functions(cecko::context *ctx)
    {
        log("|declare_support_functions| start\n");
        if (support_functions_defined)
            return;

        auto ttype_declaration = declare_parent_ttype(ctx, tagged_parent_type);
        declare_child_ttype(ctx, tagged_child_type);
        TaggedTypeDecl::finish_parent_ttype(ctx, ttype_declaration);
        auto pointer_ttype_pack = cecko::CKTypeRefPack(
            ctx->get_pointer_type(
                cecko::CKTypeRefPack(
                    ttype_declaration.struct_decl,
                    false)),
            false);
        auto int_ttype_pack = cecko::CKTypeRefPack(
            ctx->get_int_type(),
            false);

        cecko::CKStructItem pair_first(pointer_ttype_pack, "first", ctx->line());
        cecko::CKStructItem pair_second(pointer_ttype_pack, "second", ctx->line());
        cecko::CKStructItem pair_third(pointer_ttype_pack, "third", ctx->line());
        cecko::CKStructItem pair_forth(pointer_ttype_pack, "forth", ctx->line());
        cecko::CKStructItem num_val(int_ttype_pack, "value", ctx->line());

        declare_child_ttype(ctx, pair_type, {pair_first, pair_second}, false);
        declare_child_ttype(ctx, tupple3_type, {pair_first, pair_second, pair_third}, false);
        declare_child_ttype(ctx, tupple4_type, {pair_first, pair_second, pair_third, pair_forth}, false);
        declare_child_ttype(ctx, boolean_non_heap_type, {num_val}, false);

        support_functions_defined = true;
    }

    CKTypeRefDefPack get_variadic_type()
    {
        CKTypeRefDefPack trdp;
        trdp.is_variadic = true;
        return trdp;
    }

    std::vector<cecko::CKIRValueObs> get_args_instructions(InstructionArray iargs)
    {
        std::vector<cecko::CKIRValueObs> res_a = {};
        for (auto &&iarg : iargs)
        {
            res_a.push_back(iarg.read_ir());
        }
        return res_a;
    }

    bool is_struct_label(cecko::context *ctx, const cecko::CIName &label)
    {
        auto &&type = ctx->declare_struct_type(label, ctx->line());
        return type && type->is_defined();
    }
    bool is_constructable_type_label(cecko::context *ctx, const cecko::CIName &label)
    {
        if (!is_struct_label(ctx, label))
            return false;
        auto &tags = find_ttype(label);
        return tags.first == tags.second;
    }
    bool is_tagged_type(cecko::CKTypeSafeObs type)
    {
        // log("|.is_tagged_type|\n");
        return type->is_struct() || (type->is_pointer() && type->get_pointer_points_to().type->is_struct());
    }

    void generate_debug_print(cecko::context *ctx, const cecko::CIName &label)
    {
        if (!GENERATE_DYNAMIC_DEBUG_LOG)
            return;
        std::string text = "[DEBUG] -- line: " + std::to_string(ctx->line()) + " -- " + label;
        InstructionWrapper print_text;
        InstructionArray print_args;

        text += "\n";
        print_text = init_instruction_const(ctx, text);
        print_args = {print_text};
        init_instruction_function_call(ctx, init_instruction_from_name(ctx, "printf"), print_args);
    }
    void generate_debug_print(cecko::context *ctx, const cecko::CIName &label, InstructionArray &params)
    {
        if (!GENERATE_DYNAMIC_DEBUG_LOG)
            return;
        std::string text = "[DEBUG] -- line: " + std::to_string(ctx->line()) + " -- " + label + " (";
        InstructionWrapper print_text;
        InstructionArray print_args;

        for (auto &&param : params)
        {
            if (param.type->is_int())
            {
                text += "%s: %i, ";
                print_args.push_back(init_instruction_const(ctx, param.name));
                print_args.push_back(param);
            }
            else if (param.type->is_pointer())
            {
                text += "%s: %p, ";
                print_args.push_back(init_instruction_const(ctx, param.name));
                print_args.push_back(param);
            }
            else
            {
                text += "%s, ";
                print_args.push_back(init_instruction_const(ctx, param.name));
            }
        }

        text += ")\n";
        print_text = init_instruction_const(ctx, text);
        print_args.insert(print_args.begin(), print_text);
        init_instruction_function_call(ctx, init_instruction_from_name(ctx, "printf"), print_args);
    }

    /**
     * @brief Creates new basic block and append istructions to it, the contexts instruction block stais same as before after the function finished
     *
     * @param ctx given context with a builder
     * @param instruction_inserter a function that appends instructions to the current Insertion point of the context
     * @param name an optional name of the newly created block
     * @return cecko::CKIRBasicBlockObs newly created basic block
     */
    cecko::CKIRBasicBlockObs new_basic_block(cecko::context *ctx, std::function<void(cecko::context *)> instruction_inserter, cecko::CIName name)
    {
        cecko::CKIRBasicBlockObs continue_block = ctx->builder()->GetInsertBlock();
        cecko::CKIRBasicBlockObs end_block = ctx->create_basic_block(name);
        ctx->builder()->SetInsertPoint(end_block);
        instruction_inserter(ctx);
        ctx->builder()->SetInsertPoint(continue_block);
        return end_block;
    }
    TypeRefPack_Action GET_DEFINER(cecko::context *ctx, const cecko::CIName &name)
    {
        TypeRefPack_Action VAR_DEFINER(
            [ctx, name](CKTypeRefDefPack &rfpack, DefinerFunction definer)
            {
                rfpack.name = std::make_optional(name);
                return definer(ctx, name, rfpack);
            });

        return VAR_DEFINER;
    }

    CKTypeRefDefPack CHOOSE_AND_DEFINE(cecko::context *ctx, const cecko::CIName &name, const CKTypeRefDefPack &rfpack)
    {
        log("LAMBDA from [direct_declarator:] Choose how to init: ");
        if (rfpack.has_typedef)
        {
            log("is typedef \n");
            ctx->define_typedef(name, rfpack, ctx->line());
            log("and == TYPEDEF %s ==\n", name);
        }
        else if (rfpack.type->is_function())
        {
            log("is function \n");
            ctx->declare_function(name, rfpack.type, ctx->line()); // returns CKFunctionSafeObs
            log("and == DEFINED FUNCTION %s ==\n", name);
        }
        else
        {
            log("is variable ");
            ctx->define_var(name, rfpack, ctx->line());
            log_name("and == DEFINED VAR ==", name);
        }

        return rfpack;
    }

    CKTypeRefDefPack FETCH_FINAL_TYPEPACK(cecko::context *ctx, const cecko::CIName &name, const CKTypeRefDefPack &rfpack)
    {
        log("Found param type.\n");
        return rfpack;
    }

    TypeRefPack_Action GET_POINTER_ADDER(TypeRefPack_Convertor convertor, TypeRefPack_Action old_action)
    {
        TypeRefPack_Action wrap_in_pointer([convertor, old_action](CKTypeRefDefPack &rfpack, DefinerFunction definer)
                                           {
                log("LAMBDA from [declarator:] with pointer, ");
                CKTypeRefDefPack new_rf = convertor(rfpack);
                return old_action(new_rf, definer); });

        return wrap_in_pointer;
    }

    casem::TypeRefPack_Action GET_CALL_SEQUENCE_LINK(casem::TypeRefPack_Action previous, casem::TypeRefPack_Action next)
    {
        TypeRefPack_Action call_and_call_next([previous, next](casem::CKTypeRefDefPack &rfpack, casem::DefinerFunction definer)
                                              {
                previous(rfpack, definer);  // this can be also a kinf of CALL_AND_CALL_NEXT
                return next(rfpack, definer); });

        return call_and_call_next;
    }

    TypeRefPack_Action GET_FUNCTION_ADDER(cecko::context *ctx, TypeRefPack_Action old_action, cecko::CKTypeObsArray arg_types, bool is_variadic, cecko::CKFunctionFormalPackArray names_array)
    {
        TypeRefPack_Action wrap_in_function([ctx, old_action, arg_types, names_array, is_variadic](CKTypeRefDefPack &rfpack, DefinerFunction definer)
                                            {
            log("LAMBDA from [function_declarator:] ");
            // get_function_type(CKTypeObs ret_type, CKTypeObsArray arg_types)
            auto f_type = ctx->get_function_type(rfpack.type, arg_types, is_variadic); // FIXME: All fns are variadic now
            log("wrap in function type with argument array, "); 
            CKTypeRefDefPack new_rf(f_type, rfpack.is_const, rfpack.has_typedef, rfpack.is_fip); 
            new_rf.optinonal_param_names = names_array;
            log("create new TypeRefPack from it, ");
            auto res = old_action(new_rf, definer); 
            log("and Call on it the old action\n"); 
            return res; });

        return wrap_in_function;
    }

    TypeRefPack_Action GET_ARRAY_ADDER(cecko::context *ctx, TypeRefPack_Action old_action, cecko::CKIRConstantIntObs array_size)
    {
        TypeRefPack_Action wrap_in_array([ctx, old_action, array_size](CKTypeRefDefPack &rfpack, DefinerFunction definer)
                                         {
            log("LAMBDA from [array_declarator:] \n");
            auto a_type = ctx->get_array_type(rfpack.type, array_size);
            CKTypeRefDefPack new_rf(a_type, rfpack.is_const, rfpack.has_typedef, rfpack.is_fip); 
            auto res = old_action(new_rf, definer); 
            return res; });

        return wrap_in_array;
    }

    MatchWrapper init_match_head(cecko::context *ctx, cecko::match_type match_ty, InstructionWrapper &matched, casem::CKTypeRefDefPack &rfpack)
    {
        // if (match_ty == cecko::match_type::MATCH && fip_state.is_in_fip_mode())
        // {
        //     ctx->message(cecko::errors::SYNTAX, ctx->line(), "Can't use regular match in fip expression!");
        //     fip_state.enter_fip_mode();
        // }
        // else
        if (match_ty == cecko::match_type::DMATCH)
        {
            log("{FipState} match_head - entering DMATCH\n");
            fip_state.enter_fip_mode();
            fip_state.enter_fip_context();
        }
        log("[match_head:] MATCH IDF ARROW declaration_speci  fiers - define result var\n");
        casem::TypeRefPack_Action DEFINER_BODY = GET_DEFINER(ctx, casem::match_result_template);
        DEFINER_BODY(rfpack, std::function(CHOOSE_AND_DEFINE));
        auto rfpack_ptr = std::make_shared<casem::CKTypeRefDefPack>(rfpack);
        auto res_var = init_instruction_from_name(ctx, casem::match_result_template);
        casem::MatchWrapper mw(ctx, matched, rfpack_ptr, match_ty, res_var);
        matched.generate_debug_print("'match_head' matched argument is");
        log("match head done\n");
        return mw;
    }

    cecko::CKTypeObsArray get_types_from_tpacks(TRDArray packs)
    {
        cecko::CKTypeObsArray param_types;
        for (auto &pt : packs)
        {
            param_types.push_back(pt.type);
        }

        return param_types;
    }

    bool escape_interp(const char *y, std::string &acum)
    {
        const char c = y[0];                      // becouse of the regex pattern, at least one char is present
        std::string s = std::string(y).substr(1); // exclude the flag char like 'x' for example
        int res = 0;

        switch (c)
        {
        case 'n':
            acum += '\n';
            break;
        case 't':
            acum += '\t';
            break;
        case '\"':
            acum += '\"';
            break;
        case '\\':
            acum += '\\';
            break;
        case '\'':
            acum += '\'';
            break;
        case 'x':
        {
            res = std::stoi(s, 0, 16);
            if (s.length() > 2 && res > 0xff)
            {
                res = 0xff;
                acum += (char)res;
                return false;
            }

            acum += (char)res;
            break;
        }
        default:
            return false;
        }

        return true;
    }

    bool safe_str_to_int(const char *y, bool look_for_dec, int &result)
    {
        std::string s = std::string(y);
        if ((!look_for_dec) && y[0] == '0' && y[1] == 'x')
            s = s.substr(2);

        try
        {
            if (look_for_dec)
                result = std::stoi(s);
            else
                result = std::stoi(s, 0, 16);
        }
        catch (std::out_of_range const &ex)
        {
            result = INT_MAX;
            return false;
        }

        return true;
    }

    std::string num_prefix(const char *y, bool look_for_dec)
    {
        std::string s = std::string(y);
        if ((!look_for_dec) && y[0] == '0' && (y[1] == 'x' || y[1] == 'X'))
        {
            s = s.substr(2);
        }

        std::string n = "";
        for (char d : s)
        {
            bool is_dec = '0' <= d && d <= '9';
            bool is_hex = ('0' <= d && d <= '9') || ('a' <= d && d <= 'f');

            if (look_for_dec && is_dec)
                n += d;
            else if ((!look_for_dec) && is_hex)
                n += d;
            else
                break;
        }

        return n;
    }

    cecko::CKStructItem get_tag_strauct_item(cecko::context *ctx)
    {
        cecko::CKTypeRefPack tag_item(ctx->get_int_type(), true);
        return cecko::CKStructItem(tag_item, ttype_tag_label, ctx->line());
    }

    InstructionWrapper handle_enumeration_constant(cecko::context *ctx, cecko::CIName &label)
    {
        // TODO: IMPLEMENT REUSING
        if (!casem::is_struct_label(ctx, label))
        {
            return init_instruction_from_name(ctx, label);
        }

        assertm(false, "Calling type name! Should be handled by [postfix_expression: IDF LPAR argument_expression_list RPAR]!");
        // cecko::CIName constructor_name;
        // if (fip_state.is_in_fip_mode())
        // {
        //     constructor_name = get_reuser_label(label);
        // }
        // else
        // {
        //     constructor_name = get_constructor_label(label);
        // }
        // return init_instruction_function_call(ctx, init_instruction_from_name(ctx, constructor_name), {});
    }

    bool is_non_heap_type(cecko::CIName &label)
    {
        return label == pair_type || label == tupple3_type || label == tupple4_type;
    }

    InstructionWrapper handle_log_call(cecko::context *ctx, casem::InstructionArray params)
    {
        InstructionWrapper arg;
        switch (params.size())
        {
        case 1:
            arg = *params.begin();
            arg.generate_print("\n");
            return arg;
        case 2:
            arg = *params.begin();
            arg.generate_print(params[1]);
            return arg;

        default:
            break;
        }
        ctx->message(cecko::errors::SYNTAX, ctx->line(), "log function take expression as first argument and optionaly string label as second!");
        return init_instruction_const(ctx, 0);
    }

    InstructionWrapper handle_postfix_expression_fcall(cecko::context *ctx, cecko::CIName &label, casem::InstructionArray params)
    {
        if (label == print_label)
        {
            return handle_log_call(ctx, params);
        }
        if (!casem::is_constructable_type_label(ctx, label))
        {
            generate_debug_print(ctx, std::string("") + "Entering '" + label + "(...)' call", params);
            return init_instruction_function_call(ctx, init_instruction_from_name(ctx, label), params);
        }

        cecko::CIName constructor_name;
        auto type_rtoken_count = find_ttype_size(label);
        // FIXME: implement better the conditions for reusing
        if (fip_state.is_in_fip_mode() && type_rtoken_count > 0 && !is_non_heap_type(label)) // Types with no reuse tokens are not reused
        {
            auto &&to_be_reused = fip_state.reuse(type_rtoken_count);
            if (!to_be_reused.valid)
            {
#if ENFORCE_FIP
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "Couldn't find any reuseable variable with '" + std::to_string(type_rtoken_count) + "' reuse tokens for type '" + label + "'!");
#else
                log("{FipState} REUSE FAILED! created malloc\n");
                constructor_name = get_constructor_label(label);
#endif
            }
            else // to_be_reused is valid
            {
                params.insert(params.begin(), to_be_reused.reuseable);
                constructor_name = get_reuser_label(label);
            }
        }
        else
        {
            constructor_name = get_constructor_label(label);
        }

        generate_debug_print(ctx, std::string("") + "Entering '" + constructor_name + "(...)' call");
        return init_instruction_function_call(ctx, init_instruction_from_name(ctx, constructor_name), params);
    }
}