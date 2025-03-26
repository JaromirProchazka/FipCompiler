#ifndef casem_hpp_
#define casem_hpp_

#include "cktables.hpp"
#include "ckcontext.hpp"
#include "ckgrptokens.hpp"
#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <cstdint>
#include <unordered_map>
#include <utility>

// A swith that says if we should log
#define LOG_DEBBUG true

namespace casem
{
    class ControllFlowData;
    class IfControllFlowData;
    class WhileControllFlowData;
    struct CKTypeRefDefPack;
    struct MatchBinderDeclarationData;
    class InstructionWrapper;

    using DefinerFunction = std::function<CKTypeRefDefPack(cecko::context *, const cecko::CIName &, CKTypeRefDefPack &)>;
    /// @brief A function that takes TypeRefPack and does action with it
    // using CKTypeRefDefPackArray = std::vector<CKTypeRefDefPack>;
    using TypeRefPack_Action = std::function<CKTypeRefDefPack(CKTypeRefDefPack &, DefinerFunction)>;
    /// @brief A function that is used to modify TypeRefPack
    using TypeRefPack_Convertor = std::function<CKTypeRefDefPack(CKTypeRefDefPack &)>;
    using TRDArray = std::vector<casem::CKTypeRefDefPack>;
    using PrimaryExpressionType = int;
    using StructObservers = std::vector<cecko::CKStructTypeSafeObs>;
    using DefDataArray = std::vector<MatchBinderDeclarationData>;

    extern int max_type_tag;
    extern const std::string ttype_tag_label;

    using InstructionArray = std::vector<InstructionWrapper>;
    std::vector<cecko::CKIRValueObs> get_args_instructions(InstructionArray iargs);

    InstructionWrapper init_instruction_from_name(cecko::context *ctx, const cecko::CIName &name);
    InstructionWrapper init_instruction_function_call(cecko::context *ctx, const InstructionWrapper &inst, InstructionArray fargs);
    InstructionWrapper init_instruction_const(cecko::context *ctx, int intlit);
    InstructionWrapper init_instruction_const(cecko::context *ctx, const cecko::CIName &strlit);

    std::string get_constructor_label(const std::string &tname);

    /// @brief for functional types defined in code, inserts the type name and its tags into lookup table
    ///
    /// The first tag is tag of the first variant of the type, the second is the next tag right after the tag of the last variant. If the subtype is inserted, the forst tag is the valid one and second must be first + 1.
    /// @param tlabel types name
    /// @param first_tag tag of first subtype or the subtype
    /// @param end_tag tag one greater than the last subtype or the subtype
    void insert_ttype(const std::string &tlabel, int first_tag, int end_tag);
    /// @brief for functional types defined in code, inserts the type name and its tags into lookup table
    ///
    /// The first tag is tag of the first variant of the type, the second is the next tag right after the tag of the last variant. If the subtype is inserted, the forst tag is the valid one and second must be first + 1.
    /// @param tlabel types name
    /// @param first_tag tag of first subtype or the subtype
    /// @param end_tag tag one greater than the last subtype or the subtype
    void insert_ttype(const std::string &tlabel, int tag);
    /// @brief Look up of the already noted types tags range
    /// @param tlabel types name
    /// @return the range of tags (the secod number is one greater than the last tag)
    const std::pair<int, int> &find_ttype(const std::string &tlabel);

    bool is_tagged_type(cecko::CKTypeSafeObs type);

    void log(const char *msg, ...);
    void log(const std::string &msgs);
    void log_name(const char *msg, const std::string &name);

    enum UnaryOperator
    {
        AMPERSANT,
        STAR,
        ADD_S,
        SUB_S,
        EXCALMATION_MARK
    };

    enum VarMode
    {
        RValue,
        LValue
    };
    class InstructionWrapper
    {
    public:
        VarMode mode;
        cecko::CIName name;
        cecko::CKIRValueObs address;
        cecko::CKIRValueObs value;
        bool is_const;
        cecko::CKTypeSafeObs type;
        bool valid;

        InstructionWrapper()
            : mode(LValue),
              name("-"),
              is_const(false),
              valid(false),
              ctx(NULL)
        {
            cecko::CIAbstractType *null_type = NULL;
            type = cecko::CKTypeSafeObs(null_type);
        }
        InstructionWrapper(cecko::context *vctx, VarMode vmode, cecko::CKIRValueObs instruction, cecko::CKTypeSafeObs vtype, bool vconst, const cecko::CIName &vname = "t")
            : mode(vmode),
              name(vname),
              is_const(vconst),
              type(vtype),
              valid(true),
              ctx(vctx)
        {
            switch (vmode)
            {
            case LValue:
                address = instruction;
                value = 0;
                break;

            case RValue:
                address = NULL;
                value = instruction;
                break;
            }
            log("making string done\n");
        }

        bool is_valid()
        {
            return valid;
        }

        InstructionWrapper operator*() const
        {
            if (mode == RValue)
                return *this;
            if (!type->is_pointer())
                return *this;

            auto pointed_to_pack = type->get_pointer_points_to();
            cecko::CKTypeSafeObs vtype;
            bool vconst;
            vtype = pointed_to_pack.type;
            vconst = pointed_to_pack.is_const;

            cecko::CIName vname = "*" + name;

            cecko::CKIRValueObs instruction = ctx->builder()->CreateLoad(get_ir()->getType(), get_ir(), vname);
            // if (vtype->is_pointer())
            //     instruction = ctx->builder()->CreateLoad(vtype->get_ir(), get_ir(), vname);
            // else
            //     instruction = ctx->builder()->CreateLoad(vtype->get_ir(), get_ir(), vname);

            return InstructionWrapper(
                ctx,
                LValue,
                instruction,
                vtype,
                vconst,
                vname);
        }
        InstructionWrapper operator&() const
        {
            cecko::CIName vname = cecko::CIName("&") + name;
            if (mode == RValue)
            {
                return *this;
            }
            cecko::CKTypeSafeObs vtype = ctx->get_pointer_type(cecko::CKTypeRefPack(type, false));

            return InstructionWrapper(
                ctx,
                RValue,
                get_ir(),
                vtype,
                false,
                vname);
        }
        InstructionWrapper store(const InstructionWrapper &other)
        {
            log("|store| \n");
            if (mode == RValue)
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "Assigning to RValue");
                log("|store| DONE\n");
                return InstructionWrapper();
            }

            InstructionWrapper stored;
            if (type->is_pointer())
            {
                stored = other.to_ptr();
                log("|store| storing to pointer\n");
                if (other.mode == RValue)
                {
                    log("|store| storing RValue\n");
                    ctx->builder()->CreateStore(stored.get_ir(), address);
                    log("|store| stored RValue\n");
                }
                else
                {
                    log("|store| storing LValue\n");
                    ctx->builder()->CreateStore(stored.read_ir(), address);
                }
            }
            else
            {
                log("|store| storing to NON pointer\n");
                stored = other.to_type(type->get_ir());
                ctx->builder()->CreateStore(stored.read_ir(), address);
            }

            log("|store| DONE\n");
            return stored;
        }
        cecko::CKIRValueObs get_ir() const
        {
            switch (mode)
            {
            case RValue:
                return value;
            case LValue:
                return address;
            }

            // unreachable
            return address;
        }
        cecko::CKIRValueObs read_ir(cecko::CKTypeSafeObs vtype) const
        {
            switch (mode)
            {
            case RValue:
                return value;
            case LValue:
                return ctx->builder()->CreateLoad(vtype->get_ir(), address, "load_" + name);
            }

            // unreachable
            return value;
        }
        cecko::CKIRValueObs read_ir() const
        {
            switch (mode)
            {
            case RValue:
                return value;
            case LValue:
                return ctx->builder()->CreateLoad(type->get_ir(), address, "sload_" + name);
            }

            // unreachable
            return value;
        }

        InstructionWrapper operator+(const InstructionWrapper &other) const
        {
            cecko::CKIRValueObs t0;
            cecko::CKIRValueObs t1;
            auto vname = name + "+" + other.name;
            cecko::CKIRValueObs instruction;
            auto this_to_pointer = to_ptr();
            if (this_to_pointer.is_valid())
            {
                t0 = this_to_pointer.get_ir();
                t1 = other.to_int().read_ir();
                instruction = ctx->builder()->CreateGEP(
                    this_to_pointer.type->get_ir(),
                    t0,
                    {t1},
                    vname);
                return InstructionWrapper(
                    ctx,
                    LValue,
                    instruction,
                    type,
                    is_const,
                    vname);
            }
            else
            {
                auto conv = to_num();
                t0 = conv.read_ir();
                t1 = other.to_type(conv.type->get_ir()).read_ir();
                instruction = ctx->builder()->CreateAdd(t0, t1, vname);

                return InstructionWrapper(
                    ctx,
                    RValue,
                    instruction,
                    conv.type,
                    true,
                    vname);
            }
        }
        InstructionWrapper operator-(const InstructionWrapper &other) const
        {
            cecko::CKIRValueObs t0;
            cecko::CKIRValueObs t1;
            auto vname = name + "-" + other.name;
            cecko::CKIRValueObs instruction;
            auto this_to_pointer = to_ptr();
            auto other_to_pointer = other.to_ptr();
            if (this_to_pointer.is_valid() && other_to_pointer.is_valid())
            {
                t0 = this_to_pointer.get_ir();
                t1 = other_to_pointer.get_ir();
                instruction = ctx->builder()->CreatePtrDiff(
                    this_to_pointer.type->get_ir(),
                    t0,
                    t1,
                    vname);
                return InstructionWrapper(
                    ctx,
                    LValue,
                    instruction,
                    type,
                    is_const,
                    vname);
            }
            else if (this_to_pointer.is_valid())
            {
                t0 = this_to_pointer.get_ir();
                t1 = other.to_int().read_ir();
                instruction = ctx->builder()->CreateGEP(
                    this_to_pointer.type->get_ir(),
                    t0,
                    {t1},
                    vname);
                return InstructionWrapper(
                    ctx,
                    LValue,
                    instruction,
                    type,
                    is_const,
                    vname);
            }
            else
            {
                auto conv = to_num();
                t0 = conv.read_ir();
                t1 = other.to_type(conv.type->get_ir()).read_ir();
                instruction = ctx->builder()->CreateSub(t0, t1, vname);

                return InstructionWrapper(
                    ctx,
                    RValue,
                    instruction,
                    conv.type,
                    true,
                    vname);
            }
        }
        InstructionWrapper operator-() const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto vname = "-" + name;
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateNeg(t0, vname),
                conv.type,
                true,
                vname);
        }
        InstructionWrapper operator!() const
        {
            auto instruction = to_bool().read_ir();
            auto vname = "!" + name;
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateNot(instruction, vname),
                ctx->get_bool_type(),
                true,
                vname);
        }
        InstructionWrapper operator*(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type->get_ir()).read_ir();
            auto vname = name + "*" + other.name;
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateMul(t0, t1, vname),
                conv.type,
                true,
                vname);
        }
        InstructionWrapper operator/(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type->get_ir()).read_ir();
            auto vname = name + "/" + other.name;
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateSDiv(t0, t1, vname),
                conv.type,
                true,
                vname);
        }
        InstructionWrapper operator%(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type->get_ir()).read_ir();
            auto vname = name + "%" + other.name;
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateSRem(t0, t1, vname),
                conv.type,
                true,
                vname);
        }
        InstructionWrapper operator++()
        {
            auto res = InstructionWrapper(
                ctx,
                RValue,
                read_ir(),
                type,
                true,
                "load_" + name);
            store(*this + get_int_const(1));
            return res;
        }
        InstructionWrapper operator++(int)
        {
            auto res = *this + get_int_const(1);
            store(res);
            return res;
        }
        InstructionWrapper operator--()
        {
            auto res = InstructionWrapper(
                ctx,
                RValue,
                read_ir(),
                type,
                true,
                "load_" + name);
            store(*this - get_int_const(1));
            return res;
        }
        InstructionWrapper operator--(int)
        {
            auto res = *this - get_int_const(1);
            store(res);
            return res;
        }
        InstructionWrapper field(const cecko::CIName &field_name, cecko::CKTypeSafeObs field_type)
        {
            cecko::CKTypeObs struct_type = (type->is_pointer()) ? type->get_pointer_points_to().type : type;
            if (!struct_type->is_struct())
            {
                std::string e_msg = std::string("Error: can't reference field on non-struct type instance! (field: '") + field_name + "')";
                ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
                return *this;
            }

            log("finding field index\n");
            unsigned int field_id = struct_type
                                        ->find_struct_element(field_name)
                                        ->get_idx();
            log("found field index " + std::to_string(field_id) + " for " + field_name + "\n");

            return InstructionWrapper(
                ctx,
                LValue,
                ctx->builder()->CreateStructGEP(struct_type->get_ir(), read_ir(), field_id, field_name),
                // FIXME: maybe should't be pointer type to the field
                // ctx->get_pointer_type(cecko::CKTypeRefPack(field_type, false)),
                field_type,
                false,
                field_name);
        }
        InstructionWrapper field(unsigned int field_id, cecko::CKTypeSafeObs field_type)
        {
            cecko::CKTypeObs struct_type = (type->is_pointer()) ? type->get_pointer_points_to().type : type;
            if (!struct_type->is_struct())
            {
                std::string e_msg = std::string("Error: can't reference field on non-struct type instance! (field id: '") + std::to_string(field_id) + "')";
                ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
                return *this;
            }

            auto field_name = name + ".field_id(" + std::to_string(field_id) + ")";
            return InstructionWrapper(
                ctx,
                LValue,
                ctx->builder()->CreateStructGEP(struct_type->get_ir(), read_ir(), field_id, field_name),
                // FIXME: maybe should't be pointer type to the field
                // ctx->get_pointer_type(cecko::CKTypeRefPack(field_type, false)),
                field_type,
                false,
                field_name);
        }
        /// @brief generates instruction representing bool value, which says wether this Tagged type pointer has given tag value
        /// @param tag the expected tag of this type
        /// @exception SYNTAX_ERROR: if this isn't Tagged type
        /// @return the tag of this type is equil to the given tag
        InstructionWrapper has_tag(int tag)
        {
            std::string label = name + "==" + std::to_string(tag);
            if (!is_tagged_type(type))
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), name + " isn't a Defined type!");

                auto false_bool_inst = init_instruction_const(ctx, 0)
                                           .to_bool()
                                           .read_ir();
                return InstructionWrapper(ctx, RValue, false_bool_inst, ctx->get_bool_type(), true, label);
            }
            auto expected_tag = init_instruction_const(ctx, tag);
            auto &&this_tag = field(0, ctx->get_int_type());

            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateICmpEQ(this_tag.read_ir(), expected_tag.read_ir(), label),
                ctx->get_bool_type(),
                true,
                label);
        }

        InstructionWrapper to_int() const
        {
            if (type->is_int())
            {
                return *this;
            }
            if (!(type->is_bool() || type->is_char()))
            {
                // ctx->message(cecko::errors::NOT_NUMBER, ctx->line());
                return InstructionWrapper();
            }

            auto instruction = read_ir();
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateZExt(instruction, ctx->get_int_type()->get_ir(), "toint_" + name),
                ctx->get_int_type(),
                true,
                "(int)" + name);
        }
        InstructionWrapper to_char() const
        {
            if (type->is_char())
            {
                return *this;
            }
            if (!(type->is_bool() || type->is_int()))
            {
                // ctx->message(cecko::errors::NOT_NUMBER, ctx->line());
                return InstructionWrapper();
            }

            auto instruction = to_int().read_ir();
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateTrunc(instruction, ctx->get_char_type()->get_ir(), "tochar_" + name),
                ctx->get_int_type(),
                true,
                "(char)" + name);
        }
        InstructionWrapper to_ptr() const
        {
            if (type->is_pointer())
            {
                return *this;
            }
            if (!(type->is_array()))
            {
                // ctx->message(cecko::errors::NOT_POINTER, ctx->line());
                return InstructionWrapper();
            }

            auto instruction = read_ir();
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateConstInBoundsGEP2_32(type->get_ir(), instruction, 0, 0),
                ctx->get_int_type(),
                true,
                "(ptr)" + name);
        }
        InstructionWrapper to_num() const
        {
            if (type->is_char() || type->is_int())
                return *this;
            auto conv = to_int();
            if (!conv.is_valid())
                ctx->message(cecko::errors::NOT_NUMBER, ctx->line());

            return conv;
        }
        InstructionWrapper to_bool() const
        {
            if (type->is_bool())
            {
                return *this;
            }

            auto vname = "(bool)" + name;
            cecko::CKIRValueObs instruction;
            if (type->is_char())
            {
                instruction = ctx->builder()->CreateICmpNE(read_ir(), ctx->get_int8_constant(0), vname);
            }
            else if (type->is_int())
            {
                instruction = ctx->builder()->CreateICmpNE(read_ir(), ctx->get_int32_constant(0), vname);
            }
            else if (type->is_pointer())
            {
                instruction = ctx->builder()->CreateIsNotNull(read_ir(), vname);
            }
            else
            {
                // ctx->message(cecko::errors::NOT_NUMBER, ctx->line());
                return InstructionWrapper();
            }

            return InstructionWrapper(
                ctx,
                RValue,
                instruction,
                ctx->get_bool_type(),
                true,
                vname);
        }
        InstructionWrapper to_type(cecko::CKIRTypeObs to_type) const
        {
            if (type->get_ir() == to_type)
                return *this;

            if (to_type->isPointerTy())
                return to_ptr();
            else if (to_type->isIntegerTy(1)) // bool
                return to_bool();
            else if (to_type->isIntegerTy(8)) // char
                return to_char();
            else if (to_type->isIntegerTy(32)) // int
                return to_int();
            else
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "Couldn't cast to wanted type!");
            return InstructionWrapper();
        }

    private:
        cecko::context *ctx;

        InstructionWrapper get_int_const(int i) const
        {
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->get_int32_constant(i),
                ctx->get_int_type(),
                true,
                std::to_string(i));
        }
    };

    class BasicBlockWrap
    {
    public:
        cecko::CKIRBasicBlockObs block;

        BasicBlockWrap() : block(NULL) {}
        BasicBlockWrap(cecko::CKIRBasicBlockObs b) : block(b) {}

        constexpr operator cecko::CKIRBasicBlockObs() const noexcept
        {
            return block;
        }
    };

    class TaggedTypeDecl
    {
    public:
        cecko::CKStructTypeSafeObs struct_decl;
        int first_tag;

        TaggedTypeDecl(cecko::CKStructTypeSafeObs &s_decl, int starting_tag) : struct_decl(s_decl), first_tag(starting_tag) {}
        TaggedTypeDecl() : struct_decl(nullptr), first_tag() {}
        // TaggedTypeDecl(const TaggedTypeDecl &other) : struct_decl(other.struct_decl), first_tag(other.first_tag) {}

        std::string name() const
        {
            return struct_decl->get_name();
        }
    };

    class ControllFlowData
    {
    public:
        InstructionWrapper condition;
        cecko::CKIRBasicBlockObs continue_block = NULL;
        cecko::CKIRBasicBlockObs end_block = NULL;
    };
    class IfControllFlowData : public ControllFlowData
    {
    public:
        cecko::CKIRBasicBlockObs if_block = NULL;
        cecko::CKIRBasicBlockObs if_block_back = NULL;
        cecko::CKIRBasicBlockObs else_block = NULL;
        cecko::CKIRBasicBlockObs else_block_back = NULL;
    };
    IfControllFlowData init_if_data(cecko::context *ctx, InstructionWrapper &cond);
    cecko::CKIRBasicBlockObs create_if_control_flow(cecko::context *ctx, IfControllFlowData &data);

    const std::string match_result_template = "@result";
    class MatchWrapper
    {
    public:
        bool is_destructive;
        std::string matched_var_name;
        std::shared_ptr<casem::CKTypeRefDefPack> return_type;

        MatchWrapper(bool _is_destructive, std::string &_matched_var_name, std::shared_ptr<casem::CKTypeRefDefPack> _return_type)
            : is_destructive(_is_destructive),
              matched_var_name(_matched_var_name),
              return_type(std::move(_return_type))
        {
        }

        MatchWrapper()
            : is_destructive(false),
              matched_var_name(""),
              return_type(nullptr)
        {
        }
    };
    struct MatchBinderDeclarationData
    {
        cecko::CKTypeRefPack type;
        cecko::CIName label;

        MatchBinderDeclarationData() : type(), label() {}
        MatchBinderDeclarationData(const cecko::CKTypeRefPack &_type, const cecko::CIName &_label)
            : type(_type), label(_label) {}
        void declare(cecko::context *ctx)
        {
            ctx->define_var(label, type, ctx->line());
        }
    };
    class MatchBinderChackerData
    {
    public:
        cecko::CIName type_label;
        DefDataArray declarations;
        IfControllFlowData if_data;

        MatchBinderChackerData()
            : type_label(), declarations(), if_data() {}
        MatchBinderChackerData(const cecko::CIName &_type_label)
            : type_label(_type_label), declarations(), if_data() {}
        MatchBinderChackerData(const cecko::CIName &_type_label, const DefDataArray &data)
            : type_label(_type_label), declarations(data), if_data() {}

        MatchBinderChackerData &set_args(cecko::context *ctx, const std::vector<cecko::CIName> &param_names)
        {
            auto &&constructor = ctx->find(get_constructor_label(type_label));
            if (!constructor->is_function())
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "In match binder, given type label '" + type_label + "' in the binder isn't defined type");
                return *this;
            }
            auto &&constructor_type = constructor->get_type();
            auto expected_arg_count = constructor_type->get_function_arg_count();
            auto actual_arg_count = param_names.size();
            if (expected_arg_count != actual_arg_count)
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "In match binder, number of items of type '" + type_label + "' is wrong, should be '" + std::to_string(expected_arg_count) + "' but is '" + std::to_string(actual_arg_count) + "'!");
                return *this;
            }

            for (std::size_t i = 0; i < actual_arg_count; i++)
            {
                declarations.emplace_back(
                    cecko::CKTypeRefPack(constructor_type->get_function_arg_type(i), false),
                    param_names[i]);
            }

            return *this;
        }
        /// @brief inits the if statement and sets the InsertPoint to the if.then block end
        MatchBinderChackerData &create_if_statement(cecko::context *ctx, MatchWrapper &match_data)
        {
            auto &&matched = init_instruction_from_name(ctx, match_data.matched_var_name);
            auto &&cond = matched.has_tag(find_ttype(type_label).first);
            if_data = init_if_data(ctx, cond);

            // auto match_than = ctx->create_basic_block(std::string("match_") + type_label + ".then");
            // ctx->builder()->SetInsertPoint(match_than);

            return *this;
        }
        MatchBinderChackerData &init_binder_vars(cecko::context *ctx, MatchWrapper &match_data)
        {
            for (std::size_t i = 0; i < declarations.size(); ++i)
            {
                auto &decl = declarations[i];
                decl.declare(ctx);
                auto declared = init_instruction_from_name(ctx, decl.label);
                auto matched = init_instruction_from_name(ctx, match_data.matched_var_name);
                unsigned int field_id = (unsigned int)i + 1; // since the id 0 is the Tag
                auto field_stored_type = decl.type.type;
                declared.store(matched.field(field_id, cecko::safe_ptr(field_stored_type)));
            }

            return *this;
        }
    };
    struct MatchBinderListHeadData
    {
        MatchWrapper head_data;
        MatchBinderChackerData binder_data;

        MatchBinderListHeadData() : head_data(), binder_data() {}
        MatchBinderListHeadData(MatchWrapper &head, MatchBinderChackerData &binder)
            : head_data(head), binder_data(binder) {}
    };

    class WhileControllFlowData : public ControllFlowData
    {
    public:
        cecko::CKIRBasicBlockObs code_block = NULL;
        cecko::CKIRBasicBlockObs code_block_back = NULL;
        cecko::CKIRBasicBlockObs condition_block = NULL;
    };
    WhileControllFlowData init_while_data(cecko::context *ctx, InstructionWrapper &cond);
    cecko::CKIRBasicBlockObs create_while_control_flow(cecko::context *ctx, WhileControllFlowData &data);
    WhileControllFlowData init_do_data(cecko::context *ctx);
    cecko::CKIRBasicBlockObs create_do_control_flow(cecko::context *ctx, WhileControllFlowData &data, InstructionWrapper &cond);

    bool is_struct_label(cecko::context *ctx, const cecko::CIName &label);

    /// @brief A cecko::CKTypeRefPack with an information about wether the type is typedef.
    struct CKTypeRefDefPack : public cecko::CKTypeRefPack
    {
        bool has_typedef;
        bool is_variadic;
        cecko::CKFunctionFormalPackArray optinonal_param_names;
        std::optional<cecko::CIName> name;

        CKTypeRefDefPack(cecko::CKTypeObs t, bool is_c, bool is_td)
            : cecko::CKTypeRefPack(t, is_c), has_typedef(is_td), is_variadic(false), optinonal_param_names() {}

        CKTypeRefDefPack()
            : cecko::CKTypeRefPack(), has_typedef(false), is_variadic(false), optinonal_param_names() {}

        // CKTypeRefDefPack(const CKTypeRefDefPack &other) : cecko::CKTypeRefPack(other.type, other.is_const),
        //                                                   has_typedef(other.has_typedef),
        //                                                   is_variadic(other.is_variadic),
        //                                                   optinonal_param_names(other.optinonal_param_names)
        // {
        // }
    };
    CKTypeRefDefPack to_ckt(const cecko::CKStructItem &other);

    void declare_type_constructor(cecko::context *ctx, const std::string &tname, const cecko::CKStructTypeSafeObs &type, const cecko::CKStructItemArray &params);

    CKTypeRefDefPack get_variadic_type();

    cecko::CKStructItem get_tag_strauct_item(cecko::context *ctx);

    cecko::CKIRBasicBlockObs new_basic_block(cecko::context *ctx, std::function<void(cecko::context *)> instruction_inserter, cecko::CIName name = "basic_block");
    /// @brief Get lambda that defines var in given context.
    /// @param ctx The current context instance pointer
    /// @param name the variable name
    /// @return the lambda that from context and type pack defiens a variable of correct name
    TypeRefPack_Action GET_DEFINER(cecko::context *ctx, const cecko::CIName &name);
    /// @brief A DefinerFunction that chooses how to define/declare the given type
    /// @param ctx the current context instance pointer
    /// @param name the variable name
    /// @param rfpack the type information of the given object
    /// @return the final type represented in CKTypeRefDefPack
    CKTypeRefDefPack CHOOSE_AND_DEFINE(cecko::context *ctx, const cecko::CIName &name, const CKTypeRefDefPack &rfpack);
    /// @brief A DefinerFunction that simply fatches the final type without defining anything.
    /// @param ctx the current context instance pointer
    /// @param name the variable name
    /// @param rfpack the type information of the given object
    /// @return the final type represented in CKTypeRefDefPack
    CKTypeRefDefPack FETCH_FINAL_TYPEPACK(cecko::context *ctx, const cecko::CIName &name, const CKTypeRefDefPack &rfpack);
    /// @brief Is used to take an action on CKTypeRefDefPack and convert it to anoter action on a wrapped TypeRefPack
    /// @param ctx The current context instance pointer
    /// @param convertor function used to convert the CKTypeRefDefPack
    /// @param old_action function that does action with CKTypeRefDefPack
    /// @return the old_action on the CKTypeRefDefPack that was wrapped by convertor in some nested pointer type
    TypeRefPack_Action GET_POINTER_ADDER(TypeRefPack_Convertor convertor, TypeRefPack_Action old_action);
    /// @brief Creates new action, that calls to given actioins in sequence creating a kind of list if chained
    /// @param previous the first action to be called
    /// @param next the next actionn to be called
    /// @return the new action which calles the two given ones
    casem::TypeRefPack_Action GET_CALL_SEQUENCE_LINK(casem::TypeRefPack_Action previous, casem::TypeRefPack_Action next);
    /// @brief Is used to take an action on CKTypeRefDefPack and convert it to anoter action on a wrapped TypeRefPack
    /// @param ctx The current context instance pointer
    /// @param old_action function that does action with CKTypeRefDefPack
    /// @param arg_types an array of types that are the ordered function arguments
    /// @return the old_action on the CKTypeRefDefPack that was modified by convertor in some function type
    TypeRefPack_Action GET_FUNCTION_ADDER(cecko::context *ctx, TypeRefPack_Action old_action, cecko::CKTypeObsArray arg_types, bool is_variadic, cecko::CKFunctionFormalPackArray names_array = {});
    /// @brief Is used to take an action on CKTypeRefDefPack and convert it to anoter action on a wrapped TypeRefPack
    /// @param ctx The current context instance pointer
    /// @param old_action function that does action with CKTypeRefDefPack
    /// @param array_size the size information of the array
    /// @return the old_action on the CKTypeRefDefPack that was modified by convertor in some array type
    TypeRefPack_Action GET_ARRAY_ADDER(cecko::context *ctx, TypeRefPack_Action old_action, cecko::CKIRConstantIntObs array_size);

    /// @brief Converts a vector of CKTypeRefDefPack to cecko::CKTypeObsArray
    /// @param packs the CKTypeRefDefPack vector
    /// @return cecko::CKTypeObsArray
    cecko::CKTypeObsArray get_types_from_tpacks(TRDArray packs);

    /// @brief takes an escape sequence after the '\' and adds the reesulting char to the end of acum parameter
    /// @param acum: a string to which end the result is appended, if the process ends successfuly
    /// @returns a status of the interpretations. If true, the resulting char is in the acum, else the escape sequence is invalid.
    bool
    escape_interp(const char *y, std::string &acum);

    /// @brief converts safely an input string into an int in the result parameter.
    /// @param y: input string
    /// @param look_for_dec: says if the given num is decimal, otherwise interpreted as hex.
    /// @param result:
    /// @return if the int conversion fails, returns false and in INT_MAX to the result. Else true.
    bool safe_str_to_int(const char *y, bool look_for_dec, int &result);

    /// @brief takes string and ruturns the longest prefix that is a valid number
    /// @param y the string to be converted
    /// @param look_for_dec if true, the number is decimal, else hex
    /// @return a string that is the longest prefix
    std::string num_prefix(const char *y, bool look_for_dec);
}

#endif
