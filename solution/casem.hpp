#ifndef casem_hpp_
#define casem_hpp_

#include "cktables.hpp"
// #include "llvm/IR/Constants.h"
#include "ckcontext.hpp"
#include "ckgrptokens.hpp"
#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <cstdint>
#include <unordered_map>
#include <utility>
#include <cassert>
#include <set>
#include <vector>
#include <ranges>
#define assertm(exp, msg) assert((void(msg), exp))

/// A swith that says if we should log static compilation messages
#define GENERATE_STATIC_DEBUG_LOG false
/// A swith that says if we should generate dynamic runtime messages printf's
#define GENERATE_DYNAMIC_DEBUG_LOG false

/// if false, on unsuccessful reuse (not enough reuse tokens) malloc is made
#define ENFORCE_FIP false
/// if matched variable doesn't enter any binder, create message and crash
#define MANDATORY_BINDER_ENTRY_ON_MATCH false

namespace casem
{
    class ControllFlowData;
    class IfControllFlowData;
    class WhileControllFlowData;
    struct CKTypeRefDefPack;
    class MatchBinderDeclarationData;
    class InstructionWrapper;
    class MatchBinderListHeadData;
    class MatchBinderChackerData;
    class FipState;

    extern FipState *_fip_state;

    /// @brief A delegate for declaring new types
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
    extern const std::string res_label;
    extern const std::string pair_type;
    extern const std::string tupple3_type;
    extern const std::string tupple4_type;
    extern const std::string tagged_parent_type;
    extern const std::string tagged_child_type;

    using InstructionArray = std::vector<InstructionWrapper>;
    /// @brief converts InstructionArray to vector of cecko Value observers
    std::vector<cecko::CKIRValueObs> get_args_instructions(InstructionArray iargs);

    /// @brief Builder mothod for InstructionWrapper, used for wrapping variables and funitons
    InstructionWrapper init_instruction_from_name(cecko::context *ctx, const cecko::CIName &name);
    /// @brief Builder mothod for InstructionWrapper, used for wrapping function call result given a wrapped function
    InstructionWrapper init_instruction_function_call(cecko::context *ctx, const InstructionWrapper &inst, InstructionArray fargs);
    /// @brief Builder mothod for InstructionWrapper, used for wrapping literals, int in this case
    InstructionWrapper init_instruction_const(cecko::context *ctx, int intlit);
    /// @brief Builder mothod for InstructionWrapper, used for wrapping literals, string literal in this case.mode
    InstructionWrapper init_instruction_const(cecko::context *ctx, const cecko::CIName &strlit);
    /// @brief Builder mothod for InstructionWrapper, used for wrapping heap allocations of a given (enum) type
    InstructionWrapper init_instruction_malloca(cecko::context *ctx, cecko::CKTypeSafeObs type, const cecko::CIName &name);

    std::string get_constructor_label(const std::string &tname);
    std::string get_reuser_label(const cecko::CIName &tname);

    /// @brief checks is given type (sub-type) holds zero field and thus is just a label represented on heap as null
    /// @param tlabel name of the child type
    /// @return is a type with no data
    bool is_null_ttype(const std::string &tlabel);
    /// @brief for functional types defined in code, inserts the type name and its tags into lookup table
    ///
    /// The first tag is tag of the first variant of the type, the second is the next tag right after the tag of the last variant. If the subtype is inserted, the forst tag is the valid one and second must be first + 1.
    /// @param tlabel types name
    /// @param first_tag tag of first subtype or the subtype
    /// @param end_tag tag one greater than the last subtype or the subtype
    void insert_ttypes(const std::string &tlabel, int first_tag, int end_tag, long reuse_size = -1);
    /// @brief for functional types defined in code, inserts the type name and its tags into lookup table
    ///
    /// The first tag is tag of the first variant of the type, the second is the next tag right after the tag of the last variant. If the subtype is inserted, the forst tag is the valid one and second must be first + 1.
    /// @param tlabel types name
    /// @param first_tag tag of first subtype or the subtype
    /// @param end_tag tag one greater than the last subtype or the subtype
    void insert_ttype(const std::string &tlabel, int tag, long reuse_size, bool is_empty_label_type);
    /// @brief Look up of the already noted types tags range
    /// @param tlabel types name
    /// @return the range of tags (the secod number is one greater than the last tag)
    const std::pair<int, int> &find_ttype(const std::string &tlabel);
    /// @brief finds tagged type size for reuse purposes
    /// @param tlabel name of the tagged type
    /// @return number of reuse tokens the type instance holds
    long find_ttype_size(const std::string &tlabel);
    /// @brief maps subtypes tag to its label
    /// @param tag tag of the looked for type
    /// @return if found the label else label spelling "@UNKNOWN"
    std::string find_type_label(int tag);
    /// @brief retrieves the reusalbe size in Bytes on the heap of the given enum type
    long find_ttype_size(long tag);
    /// @brief retrieves the reusalbe size in Bytes on the heap of the given enum type
    long fetch_ttype_size(cecko::context *ctx, cecko::CIName &label);
    /// @brief Checks if all subtipes of given type have the same size
    /// @return if they do, returns the size, else returns -1
    long check_subtypes_has_same_size(long first_tag, long end_tag);
    /// @brief checks if given type name represents an enum parrent type
    bool ttype_is_object_abstract_type(const std::string &expected_parent_label);
    /// @brief checks if given type is placeable into parameter of the expected parent type
    bool ttype_is_parent_of_subtype(const std::string &expected_parent_label, const std::string &expected_child_label);

    /// @brief compilation time log,
    /// disabled using the GENERATE_STATIC_DEBUG_LOG static variable
    void log(const std::string &msgs);
    /// @brief compilation time log,
    /// disabled using the GENERATE_STATIC_DEBUG_LOG static variable
    void log(const char *msg, ...);
    /// @brief compilation time log,
    /// disabled using the GENERATE_STATIC_DEBUG_LOG static variable
    void log_name(const char *msg, const std::string &name);

    enum UnaryOperator
    {
        AMPERSANT,
        STAR,
        ADD_S,
        SUB_S,
        EXCALMATION_MARK
    };

    /// checks is given type is an enum type
    bool is_tagged_type(cecko::CKTypeSafeObs tagged_type);
    /// checks is given type is an enum type
    bool is_tagged_type(cecko::CKTypeObs tagged_type);

    /// @brief generates a runtime time log, it appends a call to printf library function to the current basic block
    /// disabled using the GENERATE_DYNAMIC_DEBUG_LOG static variable
    void generate_debug_print(cecko::context *ctx, const cecko::CIName &label);

    /// @brief denotes the clasic C like type of the variable where the RValue objects can't be written into unlike the LValue objects
    enum VarMode
    {
        RValue,
        LValue
    };
    /// @brief Abstracts values and variables in LLVM IR. Provides constant wrappers for the LLVM instructions on the abstracted value which are appended to the current basic block present in the ctx (context) variable given at construction.
    ///
    /// Can also be invalid initialized with an empty constructor, use the is_valid method to determin
    class InstructionWrapper
    {
        cecko::context *ctx;

    public:
        VarMode mode = LValue;
        cecko::CIName name;
        cecko::CKIRValueObs address = NULL;
        cecko::CKIRValueObs value = NULL;
        bool is_const;
        bool valid;
        cecko::CKTypeSafeObs type;

        /// @brief Initilize an invlid instance, also used in case of use invalid opereration on an instance of InstructionWrapper. This can happen for instance when the instance has an uncompatible type with the operation.
        InstructionWrapper()
            : ctx(NULL),
              mode(LValue),
              name("-"),
              is_const(false),
              valid(false),
              type((cecko::CIAbstractType *)NULL)
        {
        }
        InstructionWrapper(cecko::context *vctx, VarMode vmode, cecko::CKIRValueObs instruction, cecko::CKTypeSafeObs vtype, bool vconst, const cecko::CIName &vname = "t")
            : ctx(vctx),
              mode(vmode),
              name(vname),
              is_const(vconst),
              valid(true),
              type(vtype)
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
            // log("making string done\n");
        }

        /// @brief If in casem debug mod, Generates a call to printf with the label info and the value of instruction
        void generate_debug_print(const cecko::CIName &label)
        {
            if (!GENERATE_DYNAMIC_DEBUG_LOG)
                return;
            std::string text = "[DEBUG] -- line: " + std::to_string(ctx->line()) + "\t-- " + label + " '";
            InstructionWrapper print_text;
            InstructionArray print_args;
            bool printable_type = false;

            if (type->is_pointer())
            {
                text += "%p";
                printable_type = true;
            }
            else if (type->is_int())
            {
                text += "%i";
                printable_type = true;
            }

            text += "'\n";
            print_text = init_instruction_const(ctx, text);
            if (printable_type)
                print_args = {print_text, *this};
            else
                print_args = {print_text};
            init_instruction_function_call(ctx, init_instruction_from_name(ctx, "printf"), print_args);
        }
        void generate_print(const cecko::CIName &label)
        {
            std::string text;
            InstructionWrapper print_text;
            InstructionArray print_args;
            bool printable_type = false;

            if (type->is_pointer())
            {
                text += "%p";
                printable_type = true;
            }
            else if (type->is_int())
            {
                text += "%i";
                printable_type = true;
            }

            text += " " + label;
            print_text = init_instruction_const(ctx, text);
            if (printable_type)
                print_args = {print_text, *this};
            else
                print_args = {print_text};
            init_instruction_function_call(ctx, init_instruction_from_name(ctx, "printf"), print_args);
        }
        void generate_print(InstructionWrapper &label)
        {
            std::string text;
            InstructionWrapper print_text;
            InstructionArray print_args;
            bool printable_type = false;

            if (type->is_pointer())
            {
                text += "%p";
                printable_type = true;
            }
            else if (type->is_int())
            {
                text += "%i";
                printable_type = true;
            }
#if GENERATE_DYNAMIC_DEBUG_LOG
            text += " %s\n";
#else
            text += " %s";
#endif
            print_text = init_instruction_const(ctx, text);
            if (printable_type)
                print_args = {print_text, *this, label};
            else
                print_args = {print_text, label};
            init_instruction_function_call(ctx, init_instruction_from_name(ctx, "printf"), print_args);
        }

        /// @brief determines if this holds valid instance of InstructionWrapper
        /// @return
        bool is_valid()
        {
            return valid;
        }
        /// @brief tries to dereference this instance.
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new InstructionWrapper representing the dereferenced value
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
        /// @brief tries to reference this instance.
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new InstructionWrapper representing the pointer to this value
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
        /// @brief tries to store to the address of this LValue instance.
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new InstructionWrapper representing this value changed by store
        InstructionWrapper store(const InstructionWrapper &other)
        {
            // log("|store| \n");
            if (mode == RValue)
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "Assigning to RValue!");
                // log("|store| DONE\n");
                return InstructionWrapper();
                // return other;
            }
            if (!other.valid)
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "The stored variable is invalid!");
                return InstructionWrapper();
            }

            InstructionWrapper stored;
            if (type->is_pointer())
            {
                stored = other.to_ptr();
                // log("|store| storing to pointer\n");
                if (other.mode == RValue)
                {
                    // log("|store| storing RValue\n");
                    ctx->builder()->CreateStore(stored.get_ir(), address);
                    // log("|store| stored RValue\n");
                }
                else
                {
                    // log("|store| storing LValue\n");
                    ctx->builder()->CreateStore(stored.read_ir(), address);
                }
            }
            else
            {
                stored = other.to_type(type);
                ctx->builder()->CreateStore(stored.read_ir(), address);
            }

            // log("|store| DONE\n");
            return stored;
        }
        /// @brief Unwrapps this InstructionWrapper to the cecko library representation (which wraps the LLVM representation)
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
        /// @brief reads this instance and unwraps it to the cecko representation.
        /// if this instance represents an LVaue, a load instruction is generated, in case of RValue simply gets the value.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// @return new InstructionWrapper representing the pointer to this value
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
        /// @brief reads this instance and unwraps it to the cecko representation.
        /// if this instance represents an LVaue, a load instruction is generated, in case of RValue simply gets the value.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// @return new InstructionWrapper representing the pointer to this value
        cecko::CKIRValueObs read_ir() const
        {
            switch (mode)
            {
            case RValue:
                return value;
            case LValue:
                // return ctx->builder()->CreateLoad(type->get_ir(), address, "sload_" + name);
                return ctx->builder()->CreateLoad(type->get_ir(), address, "$" + name);
            }

            // unreachable
            return value;
        }

        /// @brief tries to create a addition operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric or pointer type.
        /// @return new InstructionWrapper representing the summed value
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
                t1 = other.to_type(conv.type).read_ir();
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
        /// @brief tries to create a subtraction operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric or pointer type.
        /// @return new InstructionWrapper representing the subtracted value
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
                t1 = other.to_type(conv.type).read_ir();
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
        /// @brief tries to create a unary minus operation on this instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric type.
        /// @return new InstructionWrapper representing the negated value
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
        /// @brief tries to create a unary negation operation on this instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a bool type.
        /// @return new InstructionWrapper representing the negated value
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
        /// @brief tries to create a multiplication operation on this instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric type.
        /// @return new InstructionWrapper representing the multiplied value
        InstructionWrapper operator*(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type).read_ir();
            auto vname = name + "*" + other.name;
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateMul(t0, t1, vname),
                conv.type,
                true,
                vname);
        }
        /// @brief tries to create a dividion operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric type.
        /// @return new InstructionWrapper representing the divided value
        InstructionWrapper operator/(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type).read_ir();
            auto vname = name + "/" + other.name;
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateSDiv(t0, t1, vname),
                conv.type,
                true,
                vname);
        }
        /// @brief tries to create a modulo operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric type.
        /// @return new InstructionWrapper representing the modulod value
        InstructionWrapper operator%(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type).read_ir();
            auto vname = name + "%" + other.name;
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateSRem(t0, t1, vname),
                conv.type,
                true,
                vname);
        }
        /// @brief tries to create a less operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric type.
        /// @return new InstructionWrapper representing the comparison value
        InstructionWrapper operator<(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type).read_ir();
            auto vname = name + "<" + other.name;
            assert(t0->getType() == t1->getType());
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateICmpSLT(t0, t1, vname),
                ctx->get_bool_type(),
                true,
                vname);
        }
        /// @brief tries to create a greater operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric type.
        /// @return new InstructionWrapper representing the comparison value
        InstructionWrapper operator>(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_int().read_ir();
            auto vname = name + ">" + other.name;
            log("|InstructionWrapper::operator>| made casts\n");
            assert(t0->getType() == t1->getType());
            InstructionWrapper res(
                ctx,
                RValue,
                ctx->builder()->CreateICmpSGT(t0, t1, vname),
                ctx->get_bool_type(),
                true,
                vname);
            log("|InstructionWrapper::operator>| made instruction\n");
            return res;
        }
        /// @brief tries to create a greater or equil operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric type.
        /// @return new InstructionWrapper representing the comparison value
        InstructionWrapper operator>=(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type).read_ir();
            auto vname = name + ">=" + other.name;
            assert(t0->getType() == t1->getType());
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateICmpSGE(t0, t1, vname),
                ctx->get_bool_type(),
                true,
                vname);
        }
        /// @brief tries to create a less or equil operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric type.
        /// @return new InstructionWrapper representing the comparison value
        InstructionWrapper operator<=(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type).read_ir();
            auto vname = name + "<=" + other.name;
            assert(t0->getType() == t1->getType());
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateICmpSLE(t0, t1, vname),
                ctx->get_bool_type(),
                true,
                vname);
        }
        /// @brief tries to create a equil operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric type.
        /// @return new InstructionWrapper representing the comparison value
        InstructionWrapper operator==(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type).read_ir();
            auto vname = name + "==" + other.name;
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateICmpEQ(t0, t1, vname),
                ctx->get_bool_type(),
                true,
                vname);
        }
        /// @brief tries to create a not equil operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// First tries to cast this to a numeric type.
        /// @return new InstructionWrapper representing the comparison value
        InstructionWrapper operator!=(const InstructionWrapper &other) const
        {
            auto conv = to_num();
            auto t0 = conv.read_ir();
            auto t1 = other.to_type(conv.type).read_ir();
            auto vname = name + "!=" + other.name;
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateICmpNE(t0, t1, vname),
                ctx->get_bool_type(),
                true,
                vname);
        }
        /// @brief tries to create a post incrementation operation on this instance and other instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// @return new InstructionWrapper representing the incremented value
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
        /// @brief tries to create a pre-incrementation operation on this instance.
        /// If valid, places this operation to the end of current basic block in ctx.
        /// @return new InstructionWrapper representing the incremented value
        InstructionWrapper operator++(int)
        {
            auto res = *this + get_int_const(1);
            store(res);
            return res;
        }
        /// @brief tries to create a post decrementation operation on this instance.
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new InstructionWrapper representing the decremented value
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
        /// @brief tries to create a pre decrementation operation on this instance.
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new InstructionWrapper representing the decremented value
        InstructionWrapper operator--(int)
        {
            auto res = *this - get_int_const(1);
            store(res);
            return res;
        }
        /// @brief tries to get a field value on this instance (if it is of an composite type).
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new InstructionWrapper representing the multiplied value
        InstructionWrapper field(const cecko::CIName &field_name, cecko::CKTypeSafeObs field_type) const
        {
            cecko::CKTypeObs struct_type = (type->is_pointer()) ? type->get_pointer_points_to().type : type;
            if (!struct_type->is_struct())
            {
                std::string e_msg = std::string("Error: can't reference field on non-struct type instance! (field: '") + field_name + "')";
                ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
                return *this;
            }

            log("finding field index\n");
            auto field_id_obs = struct_type->find_struct_element(field_name);
            if (!field_id_obs)
            {
                std::string e_msg = name + " has no field: '" + field_name + "'!";
                ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
                return *this;
            }
            unsigned int field_id = field_id_obs->get_idx();
            log("found field index " + std::to_string(field_id) + " for " + field_name + "\n");

            std::string inst_label = name + "." + field_name;
            InstructionWrapper result(
                ctx,
                LValue,
                ctx->builder()->CreateStructGEP(struct_type->get_ir(), read_ir(), field_id, inst_label),
                field_type,
                false,
                inst_label);
            // result.generate_debug_print("field[" + std::to_string(field_id) + "] == ");

            return result;
        }
        InstructionWrapper field(unsigned int field_id, cecko::CKTypeSafeObs field_type) const
        {
            cecko::CKTypeObs struct_type = (type->is_pointer()) ? type->get_pointer_points_to().type : type;
            if (!struct_type->is_struct())
            {
                std::string e_msg = std::string("Error: can't reference field on non-struct type instance! (field id: '") + std::to_string(field_id) + "')";
                ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
                return *this;
            }

            std::string field_name;
            if (field_id == 0)
                field_name = name + ".tag";
            else
                field_name = name + ".[" + std::to_string(field_id) + "]";
            InstructionWrapper result(
                ctx,
                LValue,
                ctx->builder()->CreateStructGEP(struct_type->get_ir(), read_ir(), field_id, field_name),
                // FIXME: maybe should't be pointer type to the field
                // ctx->get_pointer_type(cecko::CKTypeRefPack(field_type, false)),
                field_type,
                false,
                field_name);
            // result.generate_debug_print("field[" + std::to_string(field_id) + "] == ");

            return result;
        }
        /// @brief generates instruction representing bool value, which says wether this Tagged type pointer has given tag value
        /// @param tag the expected tag of this type
        /// @exception SYNTAX_ERROR: if this isn't Tagged type
        /// @return the tag of this type is equil to the given tag
        InstructionWrapper has_tag(int tag) const
        {
            log("|.has_tag| \n");
            std::string label = name + "==" + std::to_string(tag);
            // generate_debug_print("'.has_tag' entered");
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
            this_tag.generate_debug_print("'.has_tag' expecting tag to be {" + find_type_label(tag) + "}'" + std::to_string(tag) + "' and found tag is");

            log("|.has_tag| done, returning...\n");

            return InstructionWrapper(
                ctx,
                RValue,
                ctx->builder()->CreateICmpEQ(this_tag.read_ir(), expected_tag.read_ir(), label),
                ctx->get_bool_type(),
                true,
                label);
        }

        // cast functions

        /// @brief tries to cast to an int32
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new instnce representing the result of the cast operation
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
                // return *this;
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
        /// @brief tries to cast to an int8
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new instnce representing the result of the cast operation
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
                // return *this;
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
        /// @brief tries to cast to a pointer
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new instnce representing the result of the cast operation
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
                // return *this;
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
        /// @brief tries to cast to a numeric type, if it already is int8 or int32, the result is simply unchanged this instance, otherwise casts to int32.
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new instnce representing the result of the cast operation
        InstructionWrapper to_num() const
        {
            if (type->is_char() || type->is_int())
                return *this;
            auto conv = to_int();
            if (!conv.is_valid())
                ctx->message(cecko::errors::NOT_NUMBER, ctx->line());

            return conv;
        }
        /// @brief tries to cast to a int1 type
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new instnce representing the result of the cast operation
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
                // log("|.to_bool| comparing char to i8\n");
                instruction = ctx->builder()->CreateICmpNE(read_ir(), ctx->get_int8_constant(0), vname);
            }
            else if (type->is_int())
            {
                // log("|.to_bool| comparing int to i32\n");
                instruction = ctx->builder()->CreateICmpNE(read_ir(), ctx->get_int32_constant(0), vname);
            }
            else if (type->is_pointer())
            {
                // log("|.to_bool| checking ptr for null\n");
                instruction = ctx->builder()->CreateIsNotNull(read_ir(), vname);
            }
            else
            {
                // ctx->message(cecko::errors::NOT_NUMBER, ctx->line());
                return InstructionWrapper();
                // return *this;
            }

            return InstructionWrapper(
                ctx,
                RValue,
                instruction,
                ctx->get_bool_type(),
                true,
                vname);
        }
        /// @brief tries to cast to the given type.
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new instnce representing the result of the cast operation
        InstructionWrapper to_type(cecko::CKTypeSafeObs to_type) const
        {
            // log("|.to_type| \n");
            if (type == to_type)
            {
                return *this;
            }

            if (is_tagged_type(to_type))
            { // Tagged type
                return to_tagged(to_type);
            }
            else if (to_type->is_pointer())
            {
                return to_ptr();
            }
            else if (to_type->get_ir()->isIntegerTy(1))
            { // bool
                return to_bool();
            }
            else if (to_type->get_ir()->isIntegerTy(8))
            { // char
                return to_char();
            }
            else if (to_type->get_ir()->isIntegerTy(32))
            { // int
                return to_int();
            }
            else
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "Couldn't cast to wanted type!");
            }
            return *this;
        }
        /// @brief tries to cast to the given enum type
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new instnce representing the result of the cast operation
        InstructionWrapper to_tagged(cecko::CKTypeSafeObs tagged_type) const
        {
            // log("|.to_tagged(cecko::CKTypeSafeObs tagged_type)| started\n");
            if (is_tagged_type(type) && is_tagged_type(tagged_type))
            {
                // log("|.to_tagged(cecko::CKTypeSafeObs tagged_type)| both this type and casted to type are tagged\n");
                auto check_res = check_tagged_cast_safety(tagged_type);
                auto to_type_label = InstructionWrapper::get_struct_type_name(tagged_type);
                auto from_type_label = InstructionWrapper::get_struct_type_name(type);
                std::string error_start = "Cast of '" + name + "' from type '" + from_type_label + "' to type '" + to_type_label + "' failed! ";
                switch (check_res)
                {
                case EOK:
                    // log("|.to_tagged(cecko::CKTypeSafeObs tagged_type)| done OK");
                    return InstructionWrapper(
                        ctx,
                        mode,
                        ctx->builder()->CreateBitCast(get_ir(), tagged_type->get_ir(), name),
                        tagged_type,
                        is_const,
                        name);
                case DIFFERENT_SUBTYPES:
                    ctx->message(cecko::errors::SYNTAX, ctx->line(),
                                 error_start + "They are both different subtypes!");
                    break;
                case FROM_NOT_TO_ITS_SUBTYPE:
                    ctx->message(cecko::errors::SYNTAX, ctx->line(),
                                 error_start + "Casting parent type not to its subtype!");
                    break;
                case TO_NOT_FROM_ITS_SUBTYPE:
                    ctx->message(cecko::errors::SYNTAX, ctx->line(),
                                 error_start + "Casting subtype not to its parent type!");
                    break;
                case NOT_SAME_PARRENT_TYPES:
                    ctx->message(cecko::errors::SYNTAX, ctx->line(),
                                 error_start + "They are both different parent types!");
                    break;
                }
            }

            // log("|.to_tagged(cecko::CKTypeSafeObs tagged_type)| done not OK");
            return *this;
        }
        /// @brief tries to cast to the given enum type
        /// If valid, places this operation to the end of current basic block in ctx
        /// @return new instnce representing the result of the cast operation
        InstructionWrapper to_tagged(const std::string &tagged_type_label) const
        {
            // log("|.to_tagged(const std::string &tagged_type_label)| started\n");
            auto struct_type = ctx->declare_struct_type(tagged_type_label, ctx->line());
            if (!struct_type->is_defined())
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(),
                             std::string("Casting to undefined type '") + tagged_type_label + "'!");
            }
            cecko::CKTypeRefPack struct_type_pack(struct_type, false);
            cecko::CKTypeSafeObs tagged_type = ctx->get_pointer_type(struct_type_pack);
            // log("|.to_tagged(const std::string &tagged_type_label)| calling to_tagged(tagged_type)\n");
            auto &&res = to_tagged(tagged_type);
            // log("|.to_tagged(const std::string &tagged_type_label)| done\n");
            return res;
        }

        static std::string get_struct_type_name(cecko::CKTypeSafeObs t)
        {
            // log("|.get_struct_type_name| started\n");
            cecko::CKTypeObs t_ptr;
            if (t->is_struct())
            {
                t_ptr = t;
            }
            else if (t->is_pointer())
            {
                t_ptr = t->get_pointer_points_to().type;
            }
            else
            {
                assertm(false, "trying to get struct type name but given type isn't struct or struct pointer!");
            }
            // log("|.get_struct_type_name| casted t to CKTypeObs\n");
            auto res = ((cecko::CKStructTypeObs)t_ptr)->get_name();
            // log("|.get_struct_type_name| return res, done...\n");
            return res;
        }
        static InstructionWrapper null_inst(cecko::context *ctx, cecko::CKPtrTypeSafeObs expected_type)
        {
            // return llvm::ConstantPointerNull::get(expected_type->get_ir());
            return InstructionWrapper(
                ctx,
                RValue,
                ctx->get_null_constant(expected_type),
                expected_type,
                true,
                "null");
        }

    private:
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
        enum tagged_cast_safety_result
        {
            EOK,
            DIFFERENT_SUBTYPES,
            FROM_NOT_TO_ITS_SUBTYPE,
            TO_NOT_FROM_ITS_SUBTYPE,
            NOT_SAME_PARRENT_TYPES
        };
        /// @brief check is this tagged type and given tagged type are safe to cast (only type check, no istructions generated)
        /// @param tagged_type tagged type to be casted to
        /// @return Resulting enum (EOK means that cast is safe)
        tagged_cast_safety_result check_tagged_cast_safety(cecko::CKTypeSafeObs tagged_type) const
        {
            // log("|.check_tagged_cast_safety| started\n");
            auto to_type_label = InstructionWrapper::get_struct_type_name(tagged_type);
            auto from_type_label = InstructionWrapper::get_struct_type_name(type);
            // log(std::string("|.check_tagged_cast_safety| '") + from_type_label + "' casted to '" + to_type_label + "'\n");

            // casting to and from abstract object type is allowed
            if (ttype_is_object_abstract_type(to_type_label) || ttype_is_object_abstract_type(from_type_label))
            {
                return EOK;
            }

            auto to_tags = find_ttype(to_type_label);
            auto from_tags = find_ttype(from_type_label);

            auto to_tag_min = to_tags.first;
            auto to_tag_max = to_tags.second;
            auto from_tag_min = from_tags.first;
            auto from_tag_max = from_tags.second;

            bool to_is_subtype = to_tag_min == to_tag_max;
            bool from_is_subtype = from_tag_min == from_tag_max;
            bool both_are_subtypes = to_is_subtype && from_is_subtype;

            if (both_are_subtypes)
            {
                if (from_tag_min == to_tag_min)
                    return EOK; // same type
                else
                    return (find_ttype_size(to_type_label) == find_ttype_size(from_type_label)) ? EOK : DIFFERENT_SUBTYPES; // different subtypes, possible only if they have same number of reuse tokens
            }
            else if (to_is_subtype)
            {                             // from parent -> to subtype (from must be parrent type)
                auto to_tag = to_tag_min; // sice to is subtype
                if (from_tag_min <= to_tag && to_tag < from_tag_max)
                    return EOK; // to_tag is in bounds (necessary to check tag field)
                else
                    // FIXME: aloving to cast from different perent to subtype
                    return FROM_NOT_TO_ITS_SUBTYPE; // to is not subtype of from type
            }
            else if (from_is_subtype)
            {                                 // from subtype -> to parent (to must be parrent type)
                auto from_tag = from_tag_min; // sice from is subtype
                if (to_tag_min <= from_tag && from_tag < to_tag_max)
                    return EOK; // from_tag is in bounds (necessary to check tag field)
                else
                    return TO_NOT_FROM_ITS_SUBTYPE; // from is not subtype of to type
            }
            else
            { // both are parrent types
                return NOT_SAME_PARRENT_TYPES;
            }
        }
    };

    struct ReuseInstructionComparator;
    /// @brief Wrapps an InstructionWrapper enqued to the reuseable enum value queue. In the queue is compared using the ReuseInstructionComparator
    class ReuseInstruction
    {
    public:
        bool valid;
        cecko::CIName type_label;
        InstructionWrapper reuseable;
        long size;

        ReuseInstruction(InstructionWrapper &inst, cecko::CIName &_type_label, std::size_t _size)
            : valid(true), type_label(_type_label), reuseable(inst), size(_size)
        {
        }
        ReuseInstruction(InstructionWrapper &inst, cecko::CKTypeSafeObs _type_obs, std::size_t _size)
        {
            assertm(is_tagged_type(_type_obs), "Non-Tagged type was given for reuse!");
            valid = true;
            type_label = InstructionWrapper::get_struct_type_name(_type_obs);
            reuseable = inst;
            size = _size;
            if (size < 0)
                valid = false;
        }
        ReuseInstruction(cecko::context *ctx, InstructionWrapper &inst, cecko::CKTypeSafeObs _type_obs)
        {
            assertm(is_tagged_type(_type_obs), "Non-Tagged type was given for reuse!");
            valid = true;
            type_label = InstructionWrapper::get_struct_type_name(_type_obs);
            reuseable = inst;
            size = fetch_ttype_size(ctx, type_label);
            log("{FipState} creating ReuseInstruction of '" + inst.name + "' of type '" + type_label + "' and for it found size '" + std::to_string(size) + "'\n");
            if (size < 0)
                valid = false;
        }
        ReuseInstruction()
            : valid(false), type_label(""), reuseable(), size(0)
        {
        }
    };
    /// @brief Used for comperion of the ReuseInstruction in the reusable instructions queue
    struct ReuseInstructionComparator
    {
        // comperison operation
        bool operator()(const ReuseInstruction &lhs, const ReuseInstruction &rhs) const
        {
            if (lhs.size != rhs.size)
                return lhs.size < rhs.size;
            if (lhs.valid && rhs.valid)
                return lhs.reuseable.name < rhs.reuseable.name;
            return lhs.size < rhs.size;
        }
    };

    /// @brief Calls ctx->enter_block() and also manages the fip state
    /// @param ctx curretn llvm context
    void enter_block(cecko::context *ctx);
    /// @brief Calls ctx->exit_block() and also manages the fip state
    /// @param ctx curretn llvm context
    void exit_block(cecko::context *ctx);

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
    /// @brief Wrapps data needed for compiling declaraiton of a new enum type
    class TaggedTypeDecl
    {
    public:
        cecko::CKStructTypeSafeObs struct_decl;
        int first_tag;

        TaggedTypeDecl(cecko::CKStructTypeSafeObs &s_decl, int starting_tag) : struct_decl(s_decl), first_tag(starting_tag) {}
        TaggedTypeDecl() : struct_decl(nullptr), first_tag() {}
        // TaggedTypeDecl(const TaggedTypeDecl &other) : struct_decl(other.struct_decl), first_tag(other.first_tag) {}

        /// @brief retrieve the name of the type
        std::string name() const
        {
            return struct_decl->get_name();
        }

        /// @brief based on the given data and the data stored here finishes the enum type declaration
        static cecko::CKStructTypeSafeObs finish_parent_ttype(cecko::context *ctx, TaggedTypeDecl &type_data)
        {
            int enumtype_tag_end = max_type_tag;
            // long parrent_type_size = casem::check_subtypes_has_same_size(type_data.first_tag, max_type_tag);
            long parrent_type_size = -1;
            casem::insert_ttypes(type_data.name(), type_data.first_tag, enumtype_tag_end, parrent_type_size);
            log("Inserted father type tag range\n");
            return type_data.struct_decl;
        }
    };
    /// @brief fetches a TaggedTypeDecl instance with data for a enum type decalration
    TaggedTypeDecl declare_parent_ttype(cecko::context *ctx, cecko::CIName label);
    /// @brief used for child type declaration in enum type declaration
    /// @param struct_items a list of fields the child type holds
    /// @param heap_type if the type is represented by a heap allocated block, expected that a type with more than zero field is a heap type
    cecko::CKStructTypeSafeObs declare_child_ttype(cecko::context *ctx, cecko::CIName label, cecko::CKStructItemArray struct_items = {}, bool heap_type = true);

    /// @brief A data class with information needed for compiling the if-else head
    class ControllFlowData
    {
    public:
        InstructionWrapper condition;
        cecko::CKIRBasicBlockObs continue_block = NULL;
        cecko::CKIRBasicBlockObs end_block = NULL;
    };
    /// @brief A data class with information needed for compiling the if-else statements.
    /// holds the basic block pointers that will be at the end of compilation connected through conditional jumps.
    class IfControllFlowData : public ControllFlowData
    {
    public:
        cecko::CKIRBasicBlockObs if_block = NULL;
        cecko::CKIRBasicBlockObs if_block_back = NULL;
        cecko::CKIRBasicBlockObs else_block = NULL;
        cecko::CKIRBasicBlockObs else_block_back = NULL;
    };
    /// @brief using a condition InstructionWrapper (bool castable), initializes the if controll flow data class
    IfControllFlowData init_if_data(cecko::context *ctx, InstructionWrapper &cond);
    /// @brief given the if control flow data connects the build basic blocks of the if-else statement using the conditional jumps
    cecko::CKIRBasicBlockObs create_if_control_flow(cecko::context *ctx, IfControllFlowData &data, bool make_if_unreachable = false);

    /// @brief Wrapps the data class IfControllFlowData to implement the if-else expression implementation
    ///
    /// The if-else expression is implemented using the if-else statement, where the code `if (cond) if_then_statement; else else_then_statement;` representing the if-else statement is used like followed to implement the if-else expression: `auto res; if (cond) res=if_then_expression; else res=else_then_expression; forward res;`.
    class IfExpressionData
    {
    public:
        IfControllFlowData if_data;
        /// @brief the variable representing the result of the evaluated expression
        InstructionWrapper result;
        /// @brief The basic block the if-else expression result continues
        cecko::CKIRBasicBlockObs block;

        IfExpressionData(IfControllFlowData _if_data, InstructionWrapper _result)
            : if_data(_if_data), result(_result), block()
        {
        }
        IfExpressionData(IfControllFlowData _if_data)
            : if_data(_if_data), result(), block()
        {
        }
        IfExpressionData()
            : if_data(), result(), block()
        {
        }

        /// @brief initializes the if expression head needed for if expression compilation
        static IfExpressionData init_if_head(cecko::context *ctx, InstructionWrapper &cond)
        {
            IfExpressionData new_data(init_if_data(ctx, cond));
            auto if_result_label = res_label + "_if";

            new_data.block = ctx->builder()->GetInsertBlock();
            auto &&ret_type =
                ctx->get_pointer_type(
                    cecko::CKTypeRefPack(ctx->declare_struct_type(tagged_parent_type, ctx->line()),
                                         false));
            ctx->define_var(if_result_label, cecko::CKTypeRefPack(ret_type, false), ctx->line());
            auto &&res = init_instruction_from_name(ctx, if_result_label);
            new_data.result = res;

            enter_block(ctx);
            return new_data;
        }
        /// @brief initializes the if-else expression head needed for if expression compilation
        static IfExpressionData init_if_else_head(cecko::context *ctx, IfExpressionData &_data)
        {
            auto &&expression_data = _data;
            auto &data = expression_data.if_data;
            data.else_block = ctx->create_basic_block("if.else");
            data.else_block_back = data.else_block;
            log("SWITCHING to else_block_back\n");
            ctx->builder()->SetInsertPoint(data.else_block_back);

            enter_block(ctx);
            return expression_data;
        }
        /// @brief initializes the if-else expression head needed for if expression compilation
        static IfExpressionData init_if_else_head(cecko::context *ctx, IfControllFlowData &_data)
        {
            auto &data = _data;
            data.else_block = ctx->create_basic_block("if.else");
            data.else_block_back = data.else_block;
            log("SWITCHING to else_block_back\n");
            ctx->builder()->SetInsertPoint(data.else_block_back);

            enter_block(ctx);
            return IfExpressionData(data);
        }

        /// @brief generates instructions to current basicblock that set the resutl of the evaluated if/if-else expression
        InstructionWrapper store_to_result(cecko::context *ctx, InstructionWrapper &stored)
        {
            if (!is_tagged_type(stored.type))
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "If/if-else expression can only have tagged type but stored '" + stored.name + "' is not Tagged type!");
                return stored;
            }
            return result.store(stored);
        }

        /// @brief generates instructions to current basicblock that set the resutl of the evaluated if/if-else expression
        InstructionWrapper store_to_result(cecko::context *ctx, IfExpressionData &child_expression)
        {
            return store_to_result(ctx, child_expression.result);
        }
    };

    /// @brief singleton implementing the FIP calculus and dkeeps track of the reuseable heap blocks at any point of the code compilation
    class FipState
    {
        using ContextReuseable = std::set<ReuseInstruction, ReuseInstructionComparator>;

        int fip_counter;
        std::vector<ContextReuseable> reusables;
        FipState()
            : fip_counter(0), reusables({{}})
        {
        }

    public:
        /// @brief fetch the instance of the FipState Singleton
        static FipState *GetFipState()
        {
            if (!_fip_state)
            {
                _fip_state = new FipState();
            }
            return _fip_state;
        }

        FipState(FipState &&other) = delete;
        FipState(const FipState &other) = delete;
        FipState &operator=(const FipState &other) = delete;
        FipState &operator=(FipState &&other) = delete;

        /// @brief a debugging function for logging the current state of queue of reausables
        /// @param label an optional messege dislpayed in the log
        void log_reusables(const std::string &label = "")
        {

            log(std::string("{FipState} Logging reuseables stack: ") + label + ": { ");
            for (auto &&fip_context : reusables)
            {
                log_context(fip_context);
                log(", ");
            }
            log("}\n");
        }

        /// @brief sets the compiler (FipState) into the FIP state.
        /// implemented with the spin lock, the FIP state can be entered multiple times but to exit it, the exit_fip_mode must be called the same amount of time this method was called.
        void enter_fip_mode()
        {
            log("{FipState} enter_fip_mode\n");
            ++fip_counter;
        }
        /// @brief unsets the compiler (FipState) from the FIP state.
        /// If called when not is FIP mode, emits an ERROR.
        void exit_fip_mode()
        {
            log("{FipState} exit_fip_mode\n");
            --fip_counter;
            assertm(fip_counter >= 0, "FipState ERROR, fip_counter is negative!");
        }
        /// @brief checks state of the spin lock to determine if compiler is in FIP state
        bool is_in_fip_mode()
        {
            return fip_counter > 0;
        }

        /// @brief Takes given instruction as pointer to reuseable space and emplaces it to the current reusable context
        /// @param ...args: arguments for ReuseInstruction class constructor
        template <class... Args>
        void emplace_reusable(Args &...args)
        {
            log("{FipState} adding reuseable var into context '" + std::to_string(reusables.size()) + "'\n");
            reusables.back().emplace(args...);

            log_reusables("emplace_reusable");
        }
        /// @brief Takes given instruction as pointer to reuseable space and places it to the current reusable context
        void insert_reusable(ReuseInstruction &inst)
        {
            if (inst.valid)
                log("{FipState} adding reuseable var '" + inst.reuseable.name + "' into context '" + std::to_string(reusables.size()) + "' currentaly with '" + std::to_string(reusables.back().size()) + "'\n");
            else
            {
                log("{FipState} not adding INVALID reuseable var into context '" + std::to_string(reusables.size()) + "'\n");
                return;
            }
            reusables.back().insert(inst);

            log_reusables("insert_reusable");
        }
        /// @brief looks up a reusable instruction (pointer to heap space), removes it from the pool of reuseable instructions from the the closet possible context and returns it to caller
        /// @param required_size the targeted size of the reuser
        /// @return the reuse data including the instruction. If none was found, returns instance with valid field set to false.
        ReuseInstruction reuse(std::size_t required_size)
        {
            log_reusables(std::string("before reuse searches of size ") + std::to_string(required_size) + ": ");

            auto &&fip_context = reusables.back();
            log_context(fip_context, "{FipState} reuse() searching in: ");
            log("\n");
            auto it = std::find_if(fip_context.begin(), fip_context.end(),
                                   [required_size](const ReuseInstruction &item)
                                   { return item.size == (long)required_size; });

            if (it != fip_context.end())
            {
                ReuseInstruction res = *it;
                fip_context.erase(it);
                log("{FipState} reusing var '" + res.reuseable.name + "' and removed from context '" + std::to_string(reusables.size()) + "'\n");
                return res;
            }

            log("{FipState} couldn't find suteable reuseable variable of size '" + std::to_string(required_size) + "' up to context '" + std::to_string(reusables.size()) + "', returning INVALID\n");
            return ReuseInstruction();

            log_reusables("after reuse");
        }

        void enter_fip_context(bool exiting_function = false)
        {
            ContextReuseable empty;
            ContextReuseable &last = (exiting_function) ? empty : reusables.back();
            reusables.push_back(last);
            log("{FipState} entered new fip context '" + std::to_string(reusables.size()) + "'\n");

            log_reusables("enter_fip_context");
        }
        void exit_fip_context()
        {
            log("{FipState} exited current fip context '" + std::to_string(reusables.size()) + "'\n");
            reusables.pop_back();

            log_reusables("exit_fip_context");
        }

    private:
        void log_context(const ContextReuseable &fip_context, const char *label = "") const
        {
            log(label);
            log("( ");
            for (auto &&r : fip_context)
            {
                if (r.valid)
                    log(std::string("[") + r.reuseable.name + "|" + std::to_string(r.size) + "], ");
                else
                    log("invalid, ");
            }
            log(")");
        }
    };

    const std::string match_result_template = res_label + "match";
    /// @brief A data class holding information important for compiling a match expression
    class MatchWrapper
    {
    public:
        /// @brief denotes if the match is using the FIP optimalization
        bool is_destructive;
        /// @brief The expression thah is pattern matched
        InstructionWrapper matched_var;
        /// @brief type of the evaluated match expression
        std::shared_ptr<casem::CKTypeRefDefPack> return_type;
        /// @brief the mode of the match (destructive or sharing)
        cecko::match_type fip_mod;
        /// @brief represents the value of the evaluated match expression
        casem::InstructionWrapper result;

        bool is_first_pattern_null_check = false;
        /// @brief Binder data of the first if pattern, which checks if matched var is null. It's validity is conditioned by MatchWrapper::is_first_pattern_null_check being true.
        std::shared_ptr<MatchBinderChackerData> first_pattern_null_check_data = nullptr;

        MatchWrapper(cecko::context *ctx, InstructionWrapper &_matched_var, std::shared_ptr<casem::CKTypeRefDefPack> _return_type, cecko::match_type mode, casem::InstructionWrapper &result_var)
            : is_destructive(mode == cecko::match_type::DMATCH),
              matched_var(_matched_var),
              return_type(std::move(_return_type)),
              fip_mod(mode),
              result(result_var)
        {
            if (!_matched_var.type->is_pointer())
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), std::string("") + "Matched type must be a pointer but '" + _matched_var.name + "' is not a pointer!");
                matched_var = InstructionWrapper();
            }
        }
        MatchWrapper()
            : is_destructive(false),
              matched_var(),
              return_type(nullptr),
              fip_mod(),
              result()
        {
        }

        /// @brief generates a code that checks in the match expression evaluation, that at least one branch of the mathing was entered
        /// is disabled by the MANDATORY_BINDER_ENTRY_ON_MATCH static variable
        void generate_final_match_result_check(cecko::context *ctx)
        {
#if MANDATORY_BINDER_ENTRY_ON_MATCH
            if (!is_tagged_type(result.type))
            {
                return;
            }
            auto cond = !result;
            auto data = init_if_data(ctx, cond);
            data.if_block_back = ctx->builder()->GetInsertBlock();

            enter_block(ctx);
            result.generate_debug_print(std::string("") + "[WARNING] matched variable '" + matched_var.name + "' did not any af the given binders!");
            result.field(0, ctx->get_int_type()).generate_debug_print("[WARNING] is the tag value of '" + matched_var.name + "' matched variable!");
            exit_block(ctx);

            ctx->builder()->SetInsertPoint(data.continue_block);
            create_if_control_flow(ctx, data, true);
#else
            log("|generate_final_match_result_check| Not generated\n");
            return;
#endif
        }
    };

    /// @brief Holds data neessary for compiling the match pattern information, the individual pattern variable
    class MatchBinderDeclarationData
    {
    public:
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
    /// @brief Holds data neessary for compiling the match pattern information
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

        /// @brief given a list of labels of the pattern variables, it initializes these variables in the MatchBinderChackerData class
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
                // return *this;
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
            // log("|MatchBinderChackerData::create_if_statement| started creating if statement");
            auto matched = match_data.matched_var;
            matched.generate_debug_print("'match binder' matched var pointer is");
            auto &type_tag_range = find_ttype(type_label);

            if (type_tag_range.first != type_tag_range.second)
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "Can't pattern match to a parent type '" + type_label + "'!");
            }

            casem::InstructionWrapper cond;
            if (!is_null_ttype(type_label))
            {
                cond = matched.has_tag(type_tag_range.first);
            }
            else
            {
                cond = !matched.to_bool();
            }
            // log("|MatchBinderChackerData::create_if_statement| initalizing if block\n");
            // cond.generate_debug_print("cond in match");
            if_data = init_if_data(ctx, cond);

            // auto match_than = ctx->create_basic_block(std::string("match_") + type_label + ".then");
            // ctx->builder()->SetInsertPoint(match_than);

            // log("|MatchBinderChackerData::create_if_statement| DONE\n");
            return *this;
        }

        /// @brief given a list of labels of the pattern variables, it initializes these variables in the cecko library context and generates instructions to the current basic block end which set the values of these variables to the matched expression field values.
        MatchBinderChackerData &init_binder_vars(cecko::context *ctx, MatchWrapper &match_data)
        {
            // log("|MatchBinderChackerData::init_binder_vars| started\n");
            auto matched = match_data.matched_var
                               .to_tagged(type_label);
            // log("|MatchBinderChackerData::init_binder_vars| casted matched to the binders type\n");
            for (std::size_t i = 0; i < declarations.size(); ++i)
            {
                auto &decl = declarations[i];
                decl.declare(ctx);
                auto declared = init_instruction_from_name(ctx, decl.label);
                unsigned int field_id = (unsigned int)i + 1; // since the id 0 is the Tag
                auto field_stored_type = decl.type.type;
                declared.store(matched.field(field_id, cecko::safe_ptr(field_stored_type)));
            }

            return *this;
        }
    };

    /// @brief encapsulates data necessary for compiling match expression head
    class MatchBinderListHeadData
    {
    public:
        MatchWrapper head_data;
        MatchBinderChackerData binder_data;
        bool is_first_pattern_null_check = false;

        MatchBinderListHeadData() : head_data(), binder_data() {}
        MatchBinderListHeadData(MatchWrapper &head, MatchBinderChackerData &binder)
            : head_data(head), binder_data(binder) {}

        static inline MatchBinderListHeadData init_match_binders_list_head(cecko::context *ctx, MatchWrapper &match_dt, MatchBinderChackerData &binder_data, bool is_first_pattern_null_check = false)
        {
            binder_data.create_if_statement(ctx, match_dt);
            auto fip_state = FipState::GetFipState();

            auto matched_type_label = InstructionWrapper::get_struct_type_name(match_dt.matched_var.type);
            if (!ttype_is_parent_of_subtype(matched_type_label, binder_data.type_label))
            {
                ctx->message(cecko::errors::SYNTAX, ctx->line(), "Unexpected binder label! The given checked type is '" + binder_data.type_label + "' while the type of the matched variable is '" + matched_type_label + "'!");
                // assert(0);
            }

            enter_block(ctx);
            if (match_dt.is_destructive)
            {
                auto to_be_reused = match_dt.matched_var
                                        .to_tagged(binder_data.type_label);
                auto reuse_type_size = fetch_ttype_size(ctx, binder_data.type_label);
                ReuseInstruction inserted_inst(
                    to_be_reused,
                    binder_data.type_label,
                    reuse_type_size);
                fip_state->insert_reusable(inserted_inst);
            }

            binder_data.init_binder_vars(ctx, match_dt);
            generate_debug_print(ctx, std::string("") + "Enterign Match binder branch: Matched is '" + match_dt.matched_var.name + "', Binder type is '" + binder_data.type_label + "'.");

            bool res_is_null_check = false;
            if (is_first_pattern_null_check)
            {
                match_dt.is_first_pattern_null_check = true;
                res_is_null_check = true;
                match_dt.first_pattern_null_check_data = std::make_shared<MatchBinderChackerData>(binder_data);
            }
            casem::MatchBinderListHeadData res(match_dt, binder_data);
            res.is_first_pattern_null_check = res_is_null_check;

            return res;
        }
    };

    /// @brief takes the match binder list head and the current pattern result expression and generates a code that given the matched expression fits the type pattern sets the result variable to the given conditional_result_value.
    MatchWrapper init_match_binders_list(cecko::context *ctx, MatchBinderListHeadData &data, InstructionWrapper &conditional_result_value);

    /// @brief a data calss used for compiling while block
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

    /// @brief checks if given label corresponds to some declared struct type
    bool is_struct_label(cecko::context *ctx, const cecko::CIName &label);

    /// @brief A cecko::CKTypeRefPack with an information about wether the type is typedef.
    struct CKTypeRefDefPack : public cecko::CKTypeRefPack
    {
        bool has_typedef;
        bool is_fip;
        bool is_variadic;
        cecko::CKFunctionFormalPackArray optinonal_param_names;
        std::optional<cecko::CIName> name;

        CKTypeRefDefPack(cecko::CKTypeObs t, bool is_c, bool is_td, bool fip)
            : cecko::CKTypeRefPack(t, is_c), has_typedef(is_td), is_fip(fip), is_variadic(false), optinonal_param_names() {}

        CKTypeRefDefPack()
            : cecko::CKTypeRefPack(), has_typedef(false), is_fip(false), is_variadic(false), optinonal_param_names() {}

        // CKTypeRefDefPack(const CKTypeRefDefPack &other) : cecko::CKTypeRefPack(other.type, other.is_const),
        //                                                   has_typedef(other.has_typedef),
        //                                                   is_fip(false),
        //                                                   is_variadic(other.is_variadic),
        //                                                   optinonal_param_names(other.optinonal_param_names)
        // {
        // }
    };
    CKTypeRefDefPack to_ckt(const cecko::CKStructItem &other);

    /// @brief function wrapping the function declaration data
    struct FunctionDeclarationData
    {
        cecko::CKFunctionSafeObs fun_obs;
        casem::CKTypeRefDefPack fun_type;
        casem::CKTypeRefDefPack fun_rfpack;

        FunctionDeclarationData(cecko::CKFunctionSafeObs _fun_obs, casem::CKTypeRefDefPack &_fun_type, casem::CKTypeRefDefPack &_fun_rfpack)
            : fun_obs(_fun_obs), fun_type(_fun_type), fun_rfpack(_fun_rfpack)
        {
        }

        FunctionDeclarationData()
            : fun_obs(), fun_type(), fun_rfpack()
        {
        }

        cecko::CIName get_function_name() const
        {
            return ((cecko::CINamePtr)fun_obs).get_name();
        }
    };

    /// @brief function used in the enum type declaration, used for declaring the child types constructor based on its fields.
    void declare_type_constructor(cecko::context *ctx, const std::string &tname, const cecko::CKStructTypeSafeObs &type, const cecko::CKStructItemArray &params, bool heap_type = true, bool null_type = false);
    /// @brief function used in the enum type declaration, used for declaring the child types reuser function based on its fields.
    void declare_type_reuser(cecko::context *ctx, const std::string &tname, const cecko::CKStructTypeSafeObs &type, const cecko::CKStructItemArray &params, bool heap_type = true);
    void declare_support_functions(cecko::context *ctx);

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

    MatchWrapper init_match_head(cecko::context *ctx, cecko::match_type match_ty, InstructionWrapper &matched, casem::CKTypeRefDefPack &rfpack);

    /// @brief Converts a vector of CKTypeRefDefPack to cecko::CKTypeObsArray
    /// @param packs the CKTypeRefDefPack vector
    /// @return cecko::CKTypeObsArray
    cecko::CKTypeObsArray get_types_from_tpacks(TRDArray packs);
    /// @brief takes an escape sequence after the '\' and adds the reesulting char to the end of acum parameter
    /// @param acum: a string to which end the result is appended, if the process ends successfuly
    /// @returns a status of the interpretations. If true, the resulting char is in the acum, else the escape sequence is invalid.
    bool escape_interp(const char *y, std::string &acum);
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

    InstructionWrapper generate_ttype_construction(cecko::context *ctx, cecko::CIName &label, casem::InstructionArray params);
    InstructionWrapper handle_enumeration_constant(cecko::context *ctx, cecko::CIName &label);
    InstructionWrapper handle_postfix_expression_fcall(cecko::context *ctx, cecko::CIName &label, casem::InstructionArray params);
}

#endif
