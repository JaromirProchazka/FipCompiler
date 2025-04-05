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
    const std::string ttype_tag_label = "@tag";
    bool support_functions_defined = false;

#if LOG_DEBBUG
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
    void log_name(const char *msg, const std::string &name) {}
#endif

    void insert_ttype(const std::string &tlabel, int first_tag, int end_tag)
    {
        type_to_id.emplace(tlabel, std::make_pair(first_tag, end_tag));
    }
    void insert_ttype(const std::string &tlabel, int tag)
    {
        type_to_id.emplace(tlabel, std::make_pair(tag, tag));
    }
    const std::pair<int, int> &find_ttype(const std::string &tlabel)
    {
        auto it = type_to_id.find(tlabel);
        if (it != type_to_id.end())
            return it->second;
        static const std::pair<int, int> empty_pair(-1, -1);
        return empty_pair;
    }

    // void declare_support_functions(cecko::context *ctx)
    // {
    //     log("|declare_support_functions| start\n");
    //     if (support_functions_defined)
    //         return;
    //     auto malloc_ret_t = ctx->get_pointer_type(cecko::CKTypeRefPack(ctx->get_void_type(), false));
    //     cecko::CKTypeObsArray malloc_args_ts = {ctx->get_int_type()};
    //     auto malloc_t = ctx->get_function_type(malloc_ret_t, malloc_args_ts, false);

    //     ctx->declare_function("malloc", malloc_t, 0);
    //     // ctx->module()->getOrInsertFunction("malloc", malloc_t->get_ir());
    //     log("|declare_support_functions| declare malloc\n");
    //     support_functions_defined = true;
    // }
    InstructionWrapper init_instruction_from_name(cecko::context *ctx, const cecko::CIName &name)
    {
        log("Started init_instruction_from_name init\n");
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
        log("Started function call\n");

        assertm(inst.type->is_function(), "given type to call is not a funcion");
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

        log("Call done\n");
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
        log("making string started\n");
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
    InstructionWrapper init_instruction_malloca(cecko::context *ctx, cecko::CKTypeSafeObs type, const cecko::CIName &name)
    {
        // declare_support_functions(ctx);
        auto &&type_size_num = (cecko::CKIRValueObs)ctx->get_type_size(type);
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
        const std::string constructor_name_template = "@const_";
        return constructor_name_template + tname;
    }
    std::string get_reuser_label(const cecko::CIName &tname)
    {
        const std::string constructor_name_template = "@reuse_";
        return constructor_name_template + tname;
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
    cecko::CKIRBasicBlockObs create_if_control_flow(cecko::context *ctx, IfControllFlowData &data)
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

        log("{create_if_control_flow} condition valid\n");
        auto cond = condv.read_ir();
        cecko::CKIRBasicBlockObs if_false_block; // = (data.else_block) ? data.else_block : data.continue_block;
        if (data.else_block != NULL)
        {
            log("{create_if_control_flow} Choose else block as the if_false_block\n");
            if_false_block = data.else_block;
        }
        else
        {
            log("{create_if_control_flow} Choose continue block as the if_false_block\n");
            if_false_block = data.end_block;
        }

        log("{create_if_control_flow} if_false_block decided\n");
        ctx->builder()->CreateCondBr(cond, data.if_block, if_false_block);
        log("SWITCHING to if_block\n");
        ctx->builder()->SetInsertPoint(data.if_block_back);
        ctx->builder()->CreateBr(data.end_block);
        if (data.else_block != NULL)
        {
            log("SWITCHING to else_block\n");
            ctx->builder()->SetInsertPoint(data.else_block_back);
            ctx->builder()->CreateBr(data.end_block);
        }

        log("SWITCHING to end_block\n");
        ctx->builder()->SetInsertPoint(data.end_block);
        return data.end_block;
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
        CKTypeRefDefPack res(other.pack.type, other.pack.is_const, false);
        res.name = other.name;
        return res;
    }

    void declare_type_constructor(cecko::context *ctx, const std::string &tname, const cecko::CKStructTypeSafeObs &type, const cecko::CKStructItemArray &params)
    {
        auto &&type_tag_range = find_ttype(tname);
        log("|declare_type_constructor| found type tag value\n");
        if (type_tag_range.first < 0)
        {
            ctx->message(cecko::errors::SYNTAX, ctx->line(), "\nError: tagged type '" + tname + "' tag value was not found!\n");
            return;
        }

        std::string constructor_name = get_constructor_label(tname);

        log("|declare_type_constructor| Parsing struct items to function args\n");
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
        log("|declare_type_constructor| parsing done, Declaring function\n");

        auto &&ret_type = ctx->get_pointer_type(cecko::CKTypeRefPack(type, false));
        auto &&ftype = ctx->get_function_type(ret_type, param_types);
        cecko::CKFunctionObs fobs = ctx->declare_function(constructor_name, ftype, ctx->line());

        log("|declare_type_constructor| declare done, declaring function body\n");

        const std::string res_label = "@result";
        ctx->enter_function(fobs, param_names_pack, ctx->line());

        auto &&allocated = init_instruction_malloca(ctx, type, res_label);
        log("|declare_type_constructor| alloc result temporary variable\n");
        ctx->define_var(res_label, cecko::CKTypeRefPack(ret_type, false), ctx->line());
        auto &&res = init_instruction_from_name(ctx, res_label);
        res.generate_debug_print("'declare_type_constructor' result on init is");

        log("|declare_type_constructor| storing allocated to temporary variable\n");
        res.store(allocated);
        res.generate_debug_print("'declare_type_constructor' result after storing allocated is");

        log("|declare_type_constructor| set tag field\n");
        auto tag_field = res.field(ttype_tag_label, ctx->get_int_type());
        tag_field.generate_debug_print("'declare_type_constructor' tag field before set in constructor");
        log("|declare_type_constructor| found tag field\n");
        auto &&tag_val_inst = init_instruction_const(ctx, type_tag_range.first);
        log("|declare_type_constructor| inited tag value '" + std::to_string(type_tag_range.first) + "' constant instruction\n");
        tag_field.store(tag_val_inst);
        res.field(ttype_tag_label, ctx->get_int_type()).generate_debug_print("'declare_type_constructor' tag field after set in constructor");

        log("|declare_type_constructor| stored tag val, Set rest fields\n");
        auto &&param_name = param_names_pack.begin();
        for (auto &&param_type = param_types.begin(); param_type < param_types.end(); ++param_name, ++param_type)
        {
            auto &&arg_name = param_name->name.value();
            auto &&field = res.field(arg_name, cecko::safe_ptr(*param_type));
            auto &&farg = init_instruction_from_name(ctx, arg_name);
            field.store(farg);
        }

        log("|declare_type_constructor| set return\n");
        // return
        res.generate_debug_print("'declare_type_constructor'" + constructor_name + " -> " + res.name);
        ctx->builder()->CreateRet(res.read_ir());
        ctx->exit_function();

        log("|declare_type_constructor| function body done, DONE\n");
    }
    void declare_type_reuser(cecko::context *ctx, const std::string &tname, const cecko::CKStructTypeSafeObs &type, const cecko::CKStructItemArray &params)
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

        log("|declare_type_reuser| Parsing struct items to function args\n");
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
        log("|declare_type_reuser| parsing done, Declaring function\n");

        auto &&ftype = ctx->get_function_type(ret_type, param_types);
        cecko::CKFunctionObs fobs = ctx->declare_function(constructor_name, ftype, ctx->line());

        log("|declare_type_reuser| declare done, declaring function body\n");

        const std::string res_label = "@result";
        ctx->enter_function(fobs, param_names_pack, ctx->line());

        log("|declare_type_reuser| set result temporary variable to the given argument\n");
        ctx->define_var(res_label, cecko::CKTypeRefPack(ret_type, false), ctx->line());
        auto &&res = init_instruction_from_name(ctx, res_label);
        auto &&allocated = init_instruction_from_name(ctx, address_val_label);
        log("|declare_type_reuser| storing allocated to temporary variable\n");
        res.store(allocated);

        log("|declare_type_reuser| set tag field\n");
        auto tag_field = res.field(ttype_tag_label, ctx->get_int_type());
        tag_field.generate_debug_print("tag field before set in constructor");
        log("|declare_type_reuser| found tag field\n");
        auto &&tag_val_inst = init_instruction_const(ctx, type_tag_range.first);
        log("|declare_type_reuser| inited tag value '" + std::to_string(type_tag_range.first) + "' constant instruction\n");
        tag_field.store(tag_val_inst);
        res.field(ttype_tag_label, ctx->get_int_type()).generate_debug_print("tag field after set in constructor");

        log("|declare_type_reuser| stored tag val, Set rest fields\n");
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

        log("|declare_type_reuser| set return\n");
        // return
        res.generate_debug_print(constructor_name + " -> " + res.name);
        ctx->builder()->CreateRet(res.read_ir());
        ctx->exit_function();
        log("|declare_type_reuser| function body done, DONE\n");
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
    bool is_tagged_type(cecko::CKTypeSafeObs type)
    {
        log("|.is_tagged_type|\n");
        return type->is_struct() || (type->is_pointer() && type->get_pointer_points_to().type->is_struct());
    }

    void generate_debug_print(cecko::context *ctx, const cecko::CIName &label)
    {
        if (!LOG_DEBBUG)
            return;
        std::string text = "|" + label + "| '";
        InstructionWrapper print_text;
        InstructionArray print_args;

        text += "'\n";
        print_text = init_instruction_const(ctx, text);
        print_args = {print_text};
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
            CKTypeRefDefPack new_rf(f_type, rfpack.is_const, rfpack.has_typedef); 
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
            CKTypeRefDefPack new_rf(a_type, rfpack.is_const, rfpack.has_typedef); 
            auto res = old_action(new_rf, definer); 
            return res; });

        return wrap_in_array;
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
}
