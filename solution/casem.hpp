#ifndef casem_hpp_
#define casem_hpp_

#include "cktables.hpp"
#include "ckcontext.hpp"
#include "ckgrptokens.hpp"
#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <cstdint>

// A swith that says if we should log
#define LOG_DEBBUG false

namespace casem
{
    void log(const char *msg, ...);
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
            if (mode == RValue)
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "Assigning to RValue");
                return InstructionWrapper();
            }

            InstructionWrapper stored;
            if (type->is_pointer())
            {
                stored = other.to_ptr();
                if (other.mode == RValue)
                {
                    ctx->builder()->CreateStore(stored.get_ir(), address);
                }
                else
                {
                    ctx->builder()->CreateStore(stored.read_ir(), address);
                }
            }
            else
            {
                stored = other.to_type(type->get_ir());
                ctx->builder()->CreateStore(stored.read_ir(), address);
            }

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

    using InstructionArray = std::vector<InstructionWrapper>;
    std::vector<cecko::CKIRValueObs> get_args_instructions(InstructionArray iargs);

    InstructionWrapper init_instruction_from_name(cecko::context *ctx, const cecko::CIName &name);
    InstructionWrapper init_instruction_function_call(cecko::context *ctx, const InstructionWrapper &inst, InstructionArray fargs);
    InstructionWrapper init_instruction_const(cecko::context *ctx, int intlit);
    InstructionWrapper init_instruction_const(cecko::context *ctx, const cecko::CIName &strlit);

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
    };

    CKTypeRefDefPack get_variadic_type();

    using DefinerFunction = std::function<CKTypeRefDefPack(cecko::context *, const cecko::CIName &, CKTypeRefDefPack &)>;
    /// @brief A function that takes TypeRefPack and does action with it
    // using CKTypeRefDefPackArray = std::vector<CKTypeRefDefPack>;
    using TypeRefPack_Action = std::function<CKTypeRefDefPack(CKTypeRefDefPack &, DefinerFunction)>;
    /// @brief A function that is used to modify TypeRefPack
    using TypeRefPack_Convertor = std::function<CKTypeRefDefPack(CKTypeRefDefPack &)>;
    using TRDArray = std::vector<casem::CKTypeRefDefPack>;
    using PrimaryExpressionType = int;

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
