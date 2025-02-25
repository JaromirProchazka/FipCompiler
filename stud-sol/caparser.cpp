// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "caparser.hpp"


// Unqualified %code blocks.
#line 34 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"

// this code is emitted to caparser.cpp

YY_DECL;

using namespace casem;

#line 54 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 7 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
namespace cecko {
#line 147 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"

  /// Build a parser object.
  parser::parser (yyscan_t yyscanner_yyarg, cecko::context * ctx_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yyscanner (yyscanner_yyarg),
      ctx (ctx_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_declaration_specifier: // declaration_specifier
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_specifier_qualifier: // type_specifier_qualifier
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.YY_MOVE_OR_COPY< casem::CKTypeRefDefPack > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_statement_head: // if_statement_head
      case symbol_kind::S_if_non_split_statement: // if_non_split_statement
      case symbol_kind::S_if_non_split_statement_else: // if_non_split_statement_else
        value.YY_MOVE_OR_COPY< casem::IfControllFlowData > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.YY_MOVE_OR_COPY< casem::InstructionArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression_opt: // expression_opt
        value.YY_MOVE_OR_COPY< casem::InstructionWrapper > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.YY_MOVE_OR_COPY< casem::TRDArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
      case symbol_kind::S_init_declarator: // init_declarator
      case symbol_kind::S_member_declarator_list: // member_declarator_list
      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_array_declarator: // array_declarator
      case symbol_kind::S_function_declarator: // function_declarator
      case symbol_kind::S_abstract_declarator: // abstract_declarator
      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
      case symbol_kind::S_array_abstract_declarator: // array_abstract_declarator
      case symbol_kind::S_function_abstract_declarator: // function_abstract_declarator
        value.YY_MOVE_OR_COPY< casem::TypeRefPack_Action > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.YY_MOVE_OR_COPY< casem::TypeRefPack_Convertor > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.YY_MOVE_OR_COPY< casem::UnaryOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_statement_head: // while_statement_head
      case symbol_kind::S_do_statement_head: // do_statement_head
        value.YY_MOVE_OR_COPY< casem::WhileControllFlowData > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_enum_specifier: // enum_specifier
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.YY_MOVE_OR_COPY< cecko::CIName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_compound_statement_body: // compound_statement_body
      case symbol_kind::S_block_item_list: // block_item_list
      case symbol_kind::S_block_item: // block_item
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_non_split_statement: // non_split_statement
      case symbol_kind::S_split_statement: // split_statement
      case symbol_kind::S_jump_statement: // jump_statement
        value.YY_MOVE_OR_COPY< cecko::CKIRBasicBlockObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.YY_MOVE_OR_COPY< cecko::CKStructItemArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_decl_head: // struct_decl_head
      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.YY_MOVE_OR_COPY< cecko::CKStructTypeSafeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_name: // type_name
        value.YY_MOVE_OR_COPY< cecko::CKTypeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.YY_MOVE_OR_COPY< cecko::CKTypeSafeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.YY_MOVE_OR_COPY< cecko::gt_addop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CASS: // "*=, /=, %=, +=, or -="
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.YY_MOVE_OR_COPY< cecko::gt_cass > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CMPE: // "== or !="
        value.YY_MOVE_OR_COPY< cecko::gt_cmpe > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CMPO: // "<, >, <=, or >="
        value.YY_MOVE_OR_COPY< cecko::gt_cmpo > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DIVOP: // "/ or %"
        value.YY_MOVE_OR_COPY< cecko::gt_divop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ETYPE: // "_Bool, char, or int"
        value.YY_MOVE_OR_COPY< cecko::gt_etype > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INCDEC: // "++ or --"
        value.YY_MOVE_OR_COPY< cecko::gt_incdec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_declaration_specifier: // declaration_specifier
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_specifier_qualifier: // type_specifier_qualifier
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< casem::CKTypeRefDefPack > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_statement_head: // if_statement_head
      case symbol_kind::S_if_non_split_statement: // if_non_split_statement
      case symbol_kind::S_if_non_split_statement_else: // if_non_split_statement_else
        value.move< casem::IfControllFlowData > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< casem::InstructionArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression_opt: // expression_opt
        value.move< casem::InstructionWrapper > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.move< casem::TRDArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
      case symbol_kind::S_init_declarator: // init_declarator
      case symbol_kind::S_member_declarator_list: // member_declarator_list
      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_array_declarator: // array_declarator
      case symbol_kind::S_function_declarator: // function_declarator
      case symbol_kind::S_abstract_declarator: // abstract_declarator
      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
      case symbol_kind::S_array_abstract_declarator: // array_abstract_declarator
      case symbol_kind::S_function_abstract_declarator: // function_abstract_declarator
        value.move< casem::TypeRefPack_Action > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.move< casem::TypeRefPack_Convertor > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.move< casem::UnaryOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_while_statement_head: // while_statement_head
      case symbol_kind::S_do_statement_head: // do_statement_head
        value.move< casem::WhileControllFlowData > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_enum_specifier: // enum_specifier
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.move< cecko::CIName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_compound_statement_body: // compound_statement_body
      case symbol_kind::S_block_item_list: // block_item_list
      case symbol_kind::S_block_item: // block_item
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_non_split_statement: // non_split_statement
      case symbol_kind::S_split_statement: // split_statement
      case symbol_kind::S_jump_statement: // jump_statement
        value.move< cecko::CKIRBasicBlockObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.move< cecko::CKStructItemArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_struct_decl_head: // struct_decl_head
      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.move< cecko::CKStructTypeSafeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_name: // type_name
        value.move< cecko::CKTypeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< cecko::CKTypeSafeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.move< cecko::gt_addop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CASS: // "*=, /=, %=, +=, or -="
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< cecko::gt_cass > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CMPE: // "== or !="
        value.move< cecko::gt_cmpe > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CMPO: // "<, >, <=, or >="
        value.move< cecko::gt_cmpo > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DIVOP: // "/ or %"
        value.move< cecko::gt_divop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ETYPE: // "_Bool, char, or int"
        value.move< cecko::gt_etype > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INCDEC: // "++ or --"
        value.move< cecko::gt_incdec > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.move< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_declaration_specifier: // declaration_specifier
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_specifier_qualifier: // type_specifier_qualifier
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.copy< casem::CKTypeRefDefPack > (that.value);
        break;

      case symbol_kind::S_if_statement_head: // if_statement_head
      case symbol_kind::S_if_non_split_statement: // if_non_split_statement
      case symbol_kind::S_if_non_split_statement_else: // if_non_split_statement_else
        value.copy< casem::IfControllFlowData > (that.value);
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.copy< casem::InstructionArray > (that.value);
        break;

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression_opt: // expression_opt
        value.copy< casem::InstructionWrapper > (that.value);
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< casem::TRDArray > (that.value);
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
      case symbol_kind::S_init_declarator: // init_declarator
      case symbol_kind::S_member_declarator_list: // member_declarator_list
      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_array_declarator: // array_declarator
      case symbol_kind::S_function_declarator: // function_declarator
      case symbol_kind::S_abstract_declarator: // abstract_declarator
      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
      case symbol_kind::S_array_abstract_declarator: // array_abstract_declarator
      case symbol_kind::S_function_abstract_declarator: // function_abstract_declarator
        value.copy< casem::TypeRefPack_Action > (that.value);
        break;

      case symbol_kind::S_pointer: // pointer
        value.copy< casem::TypeRefPack_Convertor > (that.value);
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< casem::UnaryOperator > (that.value);
        break;

      case symbol_kind::S_while_statement_head: // while_statement_head
      case symbol_kind::S_do_statement_head: // do_statement_head
        value.copy< casem::WhileControllFlowData > (that.value);
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_enum_specifier: // enum_specifier
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.copy< cecko::CIName > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_compound_statement_body: // compound_statement_body
      case symbol_kind::S_block_item_list: // block_item_list
      case symbol_kind::S_block_item: // block_item
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_non_split_statement: // non_split_statement
      case symbol_kind::S_split_statement: // split_statement
      case symbol_kind::S_jump_statement: // jump_statement
        value.copy< cecko::CKIRBasicBlockObs > (that.value);
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.copy< cecko::CKStructItemArray > (that.value);
        break;

      case symbol_kind::S_struct_decl_head: // struct_decl_head
      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.copy< cecko::CKStructTypeSafeObs > (that.value);
        break;

      case symbol_kind::S_type_name: // type_name
        value.copy< cecko::CKTypeObs > (that.value);
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.copy< cecko::CKTypeSafeObs > (that.value);
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.copy< cecko::gt_addop > (that.value);
        break;

      case symbol_kind::S_CASS: // "*=, /=, %=, +=, or -="
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.copy< cecko::gt_cass > (that.value);
        break;

      case symbol_kind::S_CMPE: // "== or !="
        value.copy< cecko::gt_cmpe > (that.value);
        break;

      case symbol_kind::S_CMPO: // "<, >, <=, or >="
        value.copy< cecko::gt_cmpo > (that.value);
        break;

      case symbol_kind::S_DIVOP: // "/ or %"
        value.copy< cecko::gt_divop > (that.value);
        break;

      case symbol_kind::S_ETYPE: // "_Bool, char, or int"
        value.copy< cecko::gt_etype > (that.value);
        break;

      case symbol_kind::S_INCDEC: // "++ or --"
        value.copy< cecko::gt_incdec > (that.value);
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.copy< int > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_declaration_specifier: // declaration_specifier
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_specifier_qualifier: // type_specifier_qualifier
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< casem::CKTypeRefDefPack > (that.value);
        break;

      case symbol_kind::S_if_statement_head: // if_statement_head
      case symbol_kind::S_if_non_split_statement: // if_non_split_statement
      case symbol_kind::S_if_non_split_statement_else: // if_non_split_statement_else
        value.move< casem::IfControllFlowData > (that.value);
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        value.move< casem::InstructionArray > (that.value);
        break;

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression_opt: // expression_opt
        value.move< casem::InstructionWrapper > (that.value);
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.move< casem::TRDArray > (that.value);
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
      case symbol_kind::S_init_declarator: // init_declarator
      case symbol_kind::S_member_declarator_list: // member_declarator_list
      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_array_declarator: // array_declarator
      case symbol_kind::S_function_declarator: // function_declarator
      case symbol_kind::S_abstract_declarator: // abstract_declarator
      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
      case symbol_kind::S_array_abstract_declarator: // array_abstract_declarator
      case symbol_kind::S_function_abstract_declarator: // function_abstract_declarator
        value.move< casem::TypeRefPack_Action > (that.value);
        break;

      case symbol_kind::S_pointer: // pointer
        value.move< casem::TypeRefPack_Convertor > (that.value);
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.move< casem::UnaryOperator > (that.value);
        break;

      case symbol_kind::S_while_statement_head: // while_statement_head
      case symbol_kind::S_do_statement_head: // do_statement_head
        value.move< casem::WhileControllFlowData > (that.value);
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_enum_specifier: // enum_specifier
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.move< cecko::CIName > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_compound_statement_body: // compound_statement_body
      case symbol_kind::S_block_item_list: // block_item_list
      case symbol_kind::S_block_item: // block_item
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_non_split_statement: // non_split_statement
      case symbol_kind::S_split_statement: // split_statement
      case symbol_kind::S_jump_statement: // jump_statement
        value.move< cecko::CKIRBasicBlockObs > (that.value);
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.move< cecko::CKStructItemArray > (that.value);
        break;

      case symbol_kind::S_struct_decl_head: // struct_decl_head
      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        value.move< cecko::CKStructTypeSafeObs > (that.value);
        break;

      case symbol_kind::S_type_name: // type_name
        value.move< cecko::CKTypeObs > (that.value);
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< cecko::CKTypeSafeObs > (that.value);
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.move< cecko::gt_addop > (that.value);
        break;

      case symbol_kind::S_CASS: // "*=, /=, %=, +=, or -="
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< cecko::gt_cass > (that.value);
        break;

      case symbol_kind::S_CMPE: // "== or !="
        value.move< cecko::gt_cmpe > (that.value);
        break;

      case symbol_kind::S_CMPO: // "<, >, <=, or >="
        value.move< cecko::gt_cmpo > (that.value);
        break;

      case symbol_kind::S_DIVOP: // "/ or %"
        value.move< cecko::gt_divop > (that.value);
        break;

      case symbol_kind::S_ETYPE: // "_Bool, char, or int"
        value.move< cecko::gt_etype > (that.value);
        break;

      case symbol_kind::S_INCDEC: // "++ or --"
        value.move< cecko::gt_incdec > (that.value);
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.move< int > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (yyscanner, ctx));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_declaration_specifier: // declaration_specifier
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_specifier_qualifier: // type_specifier_qualifier
      case symbol_kind::S_type_qualifier: // type_qualifier
      case symbol_kind::S_type_qualifier_list: // type_qualifier_list
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        yylhs.value.emplace< casem::CKTypeRefDefPack > ();
        break;

      case symbol_kind::S_if_statement_head: // if_statement_head
      case symbol_kind::S_if_non_split_statement: // if_non_split_statement
      case symbol_kind::S_if_non_split_statement_else: // if_non_split_statement_else
        yylhs.value.emplace< casem::IfControllFlowData > ();
        break;

      case symbol_kind::S_argument_expression_list: // argument_expression_list
        yylhs.value.emplace< casem::InstructionArray > ();
        break;

      case symbol_kind::S_primary_expression: // primary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_cast_expression: // cast_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression_opt: // expression_opt
        yylhs.value.emplace< casem::InstructionWrapper > ();
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        yylhs.value.emplace< casem::TRDArray > ();
        break;

      case symbol_kind::S_init_declarator_list: // init_declarator_list
      case symbol_kind::S_init_declarator: // init_declarator
      case symbol_kind::S_member_declarator_list: // member_declarator_list
      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_array_declarator: // array_declarator
      case symbol_kind::S_function_declarator: // function_declarator
      case symbol_kind::S_abstract_declarator: // abstract_declarator
      case symbol_kind::S_direct_abstract_declarator: // direct_abstract_declarator
      case symbol_kind::S_array_abstract_declarator: // array_abstract_declarator
      case symbol_kind::S_function_abstract_declarator: // function_abstract_declarator
        yylhs.value.emplace< casem::TypeRefPack_Action > ();
        break;

      case symbol_kind::S_pointer: // pointer
        yylhs.value.emplace< casem::TypeRefPack_Convertor > ();
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        yylhs.value.emplace< casem::UnaryOperator > ();
        break;

      case symbol_kind::S_while_statement_head: // while_statement_head
      case symbol_kind::S_do_statement_head: // do_statement_head
        yylhs.value.emplace< casem::WhileControllFlowData > ();
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_enum_specifier: // enum_specifier
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        yylhs.value.emplace< cecko::CIName > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_compound_statement_body: // compound_statement_body
      case symbol_kind::S_block_item_list: // block_item_list
      case symbol_kind::S_block_item: // block_item
      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_non_split_statement: // non_split_statement
      case symbol_kind::S_split_statement: // split_statement
      case symbol_kind::S_jump_statement: // jump_statement
        yylhs.value.emplace< cecko::CKIRBasicBlockObs > ();
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        yylhs.value.emplace< cecko::CKStructItemArray > ();
        break;

      case symbol_kind::S_struct_decl_head: // struct_decl_head
      case symbol_kind::S_struct_or_union_specifier: // struct_or_union_specifier
        yylhs.value.emplace< cecko::CKStructTypeSafeObs > ();
        break;

      case symbol_kind::S_type_name: // type_name
        yylhs.value.emplace< cecko::CKTypeObs > ();
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        yylhs.value.emplace< cecko::CKTypeSafeObs > ();
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        yylhs.value.emplace< cecko::gt_addop > ();
        break;

      case symbol_kind::S_CASS: // "*=, /=, %=, +=, or -="
      case symbol_kind::S_assignment_operator: // assignment_operator
        yylhs.value.emplace< cecko::gt_cass > ();
        break;

      case symbol_kind::S_CMPE: // "== or !="
        yylhs.value.emplace< cecko::gt_cmpe > ();
        break;

      case symbol_kind::S_CMPO: // "<, >, <=, or >="
        yylhs.value.emplace< cecko::gt_cmpo > ();
        break;

      case symbol_kind::S_DIVOP: // "/ or %"
        yylhs.value.emplace< cecko::gt_divop > ();
        break;

      case symbol_kind::S_ETYPE: // "_Bool, char, or int"
        yylhs.value.emplace< cecko::gt_etype > ();
        break;

      case symbol_kind::S_INCDEC: // "++ or --"
        yylhs.value.emplace< cecko::gt_incdec > ();
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        yylhs.value.emplace< int > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 6: // function_definition: function_definition_head block_item_list "}"
#line 200 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                    {
        log("[function_definition:] with BODY, if not returned explicitely, we void return here\n");
        if (! ctx->builder()->GetInsertBlock() || ctx->current_function_return_type()->is_void()) {
            ctx->builder()-> CreateRetVoid();
        }

        ctx->exit_function();
    }
#line 1254 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 7: // function_definition: function_definition_head "}"
#line 208 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                      {
        log("[function_definition:] with EMPTY BODY, implicite void return\n");
        ctx->builder()-> CreateRetVoid();
        ctx->exit_function();
    }
#line 1264 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 8: // function_definition_info: declaration_specifiers declarator
#line 216 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                        {
        log("[function_definition_info:]\n");
        auto cur_l = ctx->line();
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[1].value.as < casem::CKTypeRefDefPack > ();

        casem::CKTypeRefDefPack res_tpack = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));

        cur_l--;
        if (res_tpack.name.value() == "main" && cur_l != 0) {
            log("decrementing loc\n");
        }
        cecko::CKFunctionSafeObs f_observer = ctx->declare_function(res_tpack.name.value(), res_tpack.type, cur_l);

        ctx->enter_function(f_observer, res_tpack.optinonal_param_names, ctx->line());
    }
#line 1285 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 9: // function_definition_head: function_definition_info "{"
#line 235 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                  {
        log("[function_definition_head:]");
    }
#line 1293 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 10: // primary_expression: enumeration_constant
#line 254 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        log("[primary_expression:] name\n");
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_from_name(ctx, yystack_[0].value.as < cecko::CIName > ());
    }
#line 1302 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 11: // primary_expression: "integer literal"
#line 258 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        //CKIRConstantIntObs
        log("[primary_expression:] Found int lit '%d'\n", (int)yystack_[0].value.as < int > ());
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_const(ctx, yystack_[0].value.as < int > ());
    }
#line 1312 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 12: // primary_expression: "string literal"
#line 263 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        log_name("[primary_expression:] Found string lit ", yystack_[0].value.as < cecko::CIName > ());
        // (StringRef Str, const Twine &Name = "", unsigned AddressSpace = 0, Module *M = nullptr, bool AddNull = true)	
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_const(ctx, yystack_[0].value.as < cecko::CIName > ());
    }
#line 1322 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 13: // primary_expression: "(" expression ")"
#line 268 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[1].value.as < casem::InstructionWrapper > ();
    }
#line 1330 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 14: // postfix_expression: primary_expression
#line 274 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1338 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 15: // postfix_expression: postfix_expression "[" expression "]"
#line 277 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                {
        log("[postfix_expression:] postfix_expression [ expression ]\n");
        // $$ = $1;
    }
#line 1347 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 16: // postfix_expression: postfix_expression "(" argument_expression_list ")"
#line 281 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                                {
        log("[postfix_expression:] FUNCTION CALL, postfix_expression ( expression )\n");
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_function_call(ctx, yystack_[3].value.as < casem::InstructionWrapper > (), yystack_[1].value.as < casem::InstructionArray > ());
    }
#line 1356 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 17: // postfix_expression: postfix_expression "." "identifier"
#line 285 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                {
        log_name("[postfix_expression:] postfix_expression . IDF", yystack_[0].value.as < cecko::CIName > ());
        // $$ = $1;
    }
#line 1365 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 18: // postfix_expression: postfix_expression "->" "identifier"
#line 289 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                {
        log_name("[postfix_expression:] postfix_expression -> IDF", yystack_[0].value.as < cecko::CIName > ());
        // $$ = $1;
    }
#line 1374 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 19: // postfix_expression: postfix_expression "++ or --"
#line 293 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                {
        log("[postfix_expression:] postfix_expression ++,--\n");
        switch (yystack_[0].value.as < cecko::gt_incdec > ()) {
        case cecko::gt_incdec::INC:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[1].value.as < casem::InstructionWrapper > ())++;
            break;
        case cecko::gt_incdec::DEC:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[1].value.as < casem::InstructionWrapper > ())--;
            break;
        }
    }
#line 1390 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 20: // argument_expression_list: assignment_expression
#line 307 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        casem::InstructionArray args = { yystack_[0].value.as < casem::InstructionWrapper > () };
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1399 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 21: // argument_expression_list: argument_expression_list "," assignment_expression
#line 311 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                            {
        casem::InstructionArray args = yystack_[2].value.as < casem::InstructionArray > ();
        args.push_back(yystack_[0].value.as < casem::InstructionWrapper > ());
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1409 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 22: // argument_expression_list: %empty
#line 316 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        casem::InstructionArray args = {};
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1418 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 23: // unary_expression: postfix_expression
#line 323 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                        {
        log("[unary_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1427 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 24: // unary_expression: "++ or --" unary_expression
#line 327 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                        {
        log("[unary_expression:] INCDEC unary_expression\n");
        switch (yystack_[1].value.as < cecko::gt_incdec > ()) {
        case cecko::gt_incdec::INC:
            yylhs.value.as < casem::InstructionWrapper > () = ++(yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        case cecko::gt_incdec::DEC:
            yylhs.value.as < casem::InstructionWrapper > () = --(yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        }
    }
#line 1443 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 25: // unary_expression: unary_operator cast_expression
#line 338 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                        {
        log("[unary_expression:] unary_operator cast_expression\n");
        switch (yystack_[1].value.as < casem::UnaryOperator > ()) {
        case AMPERSANT:
            yylhs.value.as < casem::InstructionWrapper > () = &(yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        case STAR:
            yylhs.value.as < casem::InstructionWrapper > () = *(yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        case SUB_S:
            yylhs.value.as < casem::InstructionWrapper > () = -(yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        case ADD_S:
            yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > (); 
            break;
        case EXCALMATION_MARK:
            yylhs.value.as < casem::InstructionWrapper > () = !(yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        }
    }
#line 1468 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 26: // unary_expression: "sizeof" "(" type_name ")"
#line 358 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                        {
        log("[unary_expression:] SIZEOF LPAR type_name RPAR\n");
        yylhs.value.as < casem::InstructionWrapper > () = InstructionWrapper(
            ctx,
            RValue,
            ctx->get_type_size(yystack_[1].value.as < cecko::CKTypeObs > ()),
            ctx->get_int_type(),
            true,
            "size_of");
    }
#line 1483 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 27: // unary_operator: "&"
#line 371 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = AMPERSANT; }
#line 1489 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 28: // unary_operator: "*"
#line 372 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = STAR; }
#line 1495 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 29: // unary_operator: "+ or -"
#line 373 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                { 
        switch (yystack_[0].value.as < cecko::gt_addop > ()) {
        case cecko::gt_addop::ADD:
            yylhs.value.as < casem::UnaryOperator > () = ADD_S;
            break;
        case cecko::gt_addop::SUB:
            yylhs.value.as < casem::UnaryOperator > () = SUB_S;
            break;
        }
    }
#line 1510 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 30: // unary_operator: "!"
#line 383 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = EXCALMATION_MARK; }
#line 1516 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 31: // cast_expression: unary_expression
#line 387 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        // log("[cast_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1525 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 32: // multiplicative_expression: cast_expression
#line 394 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                        {
        // log("[multiplicative_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1534 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 33: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 398 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                        {
        log("[multiplicative_expression:] multiplicative_expression * cast_expression\n");
        yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) * (yystack_[0].value.as < casem::InstructionWrapper > ());
    }
#line 1543 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 34: // multiplicative_expression: multiplicative_expression "/ or %" cast_expression
#line 402 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                         {
        log("[multiplicative_expression:] multiplicative_expression / cast_expression\n");
        switch (yystack_[1].value.as < cecko::gt_divop > ()) {
        case cecko::gt_divop::DIV: 
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) / (yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        case cecko::gt_divop::MOD:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) % (yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        }
    }
#line 1559 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 35: // additive_expression: multiplicative_expression
#line 416 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                {
        // log("[multiplicative_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1568 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 36: // additive_expression: additive_expression "+ or -" multiplicative_expression
#line 420 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                            {
        log("[additive_expression:] additive_expression + multiplicative_expression\n");
        switch (yystack_[1].value.as < cecko::gt_addop > ()) {
        case cecko::gt_addop::ADD:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) + (yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        case cecko::gt_addop::SUB:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) - (yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        }
    }
#line 1584 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 37: // relational_expression: additive_expression
#line 434 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        // log("[relational_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1593 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 38: // relational_expression: relational_expression "<, >, <=, or >=" additive_expression
#line 438 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                         {
        log("[relational_expression:] relational_expression <,>,<=,>= additive_expression\n");
        // $$ = $1;
    }
#line 1602 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 39: // equality_expression: relational_expression
#line 445 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        // log("[equality_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1611 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 40: // equality_expression: equality_expression "== or !=" relational_expression
#line 449 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                        {
        log("[equality_expression:] equality_expression ==,!= relational_expression\n");
        // $$ = $1;
    }
#line 1620 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 41: // logical_and_expression: equality_expression
#line 457 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        // log("[logical_and_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1629 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 42: // logical_and_expression: logical_and_expression "&&" equality_expression
#line 461 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                          {
        log("[logical_and_expression:] logical_and_expression && equality_expression\n");
        // $$ = $1;
    }
#line 1638 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 43: // logical_or_expression: logical_and_expression
#line 468 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                               {
        // log("[logical_or_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1647 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 44: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 472 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                                 {
        log("[logical_or_expression:] logical_or_expression || logical_and_expression\n");
        // $$ = $1;
    }
#line 1656 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 45: // assignment_expression: logical_or_expression
#line 479 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        // log("[assignment_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1665 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 46: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 483 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                                    {
        log("[assignment_expression:] unary_expression assignment_operator assignment_expression\n");
        switch (yystack_[1].value.as < cecko::gt_cass > ()) {
        case cecko::gt_cass::MULA:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()).store(yystack_[2].value.as < casem::InstructionWrapper > () * yystack_[0].value.as < casem::InstructionWrapper > ());
            break; 
        case cecko::gt_cass::DIVA:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()).store(yystack_[2].value.as < casem::InstructionWrapper > () / yystack_[0].value.as < casem::InstructionWrapper > ());
            break; 
        case cecko::gt_cass::MODA:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()).store(yystack_[2].value.as < casem::InstructionWrapper > () % yystack_[0].value.as < casem::InstructionWrapper > ());
            break; 
        case cecko::gt_cass::ADDA:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()).store(yystack_[2].value.as < casem::InstructionWrapper > () + yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        case cecko::gt_cass::SUBA:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()).store(yystack_[2].value.as < casem::InstructionWrapper > () - yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        default:
            // normal assignment =
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()).store(yystack_[0].value.as < casem::InstructionWrapper > ());
        }
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[2].value.as < casem::InstructionWrapper > ();
    }
#line 1694 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 47: // assignment_operator: "*=, /=, %=, +=, or -="
#line 510 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
            {
        yylhs.value.as < cecko::gt_cass > () = yystack_[0].value.as < cecko::gt_cass > ();
    }
#line 1702 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 48: // assignment_operator: "="
#line 513 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
            {
        yylhs.value.as < cecko::gt_cass > () = (cecko::gt_cass)1000;
    }
#line 1710 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 49: // expression: assignment_expression
#line 519 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1718 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 52: // no_leading_attribute_declaration: declaration_specifiers init_declarator_list ";"
#line 537 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                        {
        log("[no_leading_attribute_declaration:] > call lambda\n");
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[1].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[2].value.as < casem::CKTypeRefDefPack > ();

        DEFINER_BODY(rfpack, std::function(CHOOSE_AND_DEFINE)); // returns the final type of the defined
        log("\n\n");
    }
#line 1731 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 53: // declaration_specifiers: declaration_specifier
#line 548 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            { 
            log("[declaration_specifiers:] ^ simply give refpack from declaration_specifier to the list\n");
            yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        }
#line 1740 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 54: // declaration_specifiers: declaration_specifier declaration_specifiers
#line 552 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                    {
            log("[declaration_specifiers:] take the list and update its info by the new element\n");
            casem::CKTypeRefDefPack rfpack = yystack_[0].value.as < casem::CKTypeRefDefPack > ();

            if (rfpack.type == NULL && (yystack_[1].value.as < casem::CKTypeRefDefPack > ()).type != NULL) {
                rfpack.type = (yystack_[1].value.as < casem::CKTypeRefDefPack > ()).type;
            }
            else if (rfpack.is_const == false && (yystack_[1].value.as < casem::CKTypeRefDefPack > ()).is_const == true) {
                rfpack.is_const = true;
            }
            else if (rfpack.has_typedef == false && (yystack_[1].value.as < casem::CKTypeRefDefPack > ()).has_typedef == true) {
                casem::CKTypeRefDefPack new_rfpack(rfpack.type, rfpack.is_const, true);
                rfpack = new_rfpack;
            }
            else {
                ctx->message(errors::INVALID_SPECIFIERS, ctx->line());
            }

            yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
        }
#line 1765 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 55: // declaration_specifier: storage_class_specifier
#line 575 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            { 
            casem::CKTypeRefDefPack rfpack;
            rfpack.has_typedef = true;
            yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
        }
#line 1775 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 56: // declaration_specifier: type_specifier_qualifier
#line 580 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                               {
            log("[declaration_specifier:] ^ Found type_specifier_qualifier ");
            casem::CKTypeRefDefPack rpack;
            if ((yystack_[0].value.as < casem::CKTypeRefDefPack > ()).type) {
                log("with set type, ");
                rpack.type = (yystack_[0].value.as < casem::CKTypeRefDefPack > ()).type;
            }
            else {
                log("with not set type, ");
            }
            if ((yystack_[0].value.as < casem::CKTypeRefDefPack > ()).is_const) {
                log("with set const");
                rpack.is_const = true;
            }
            else {
                log("with not set const");
                rpack.is_const = false;
            }
            log("\n");
            yylhs.value.as < casem::CKTypeRefDefPack > () = rpack;
        }
#line 1801 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 57: // init_declarator_list: init_declarator
#line 604 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                        { 
        log("[init_declarator_list:] v \n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 1810 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 58: // init_declarator_list: init_declarator_list "," init_declarator
#line 608 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                    {
        log("[init_declarator_list:] v give refpack to init_declarator and the list\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = GET_CALL_SEQUENCE_LINK(yystack_[2].value.as < casem::TypeRefPack_Action > (), yystack_[0].value.as < casem::TypeRefPack_Action > ());
    }
#line 1819 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 59: // init_declarator: declarator
#line 616 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        log("[init_declarator:] v found declarator and gave it refpack\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 1828 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 61: // type_specifier: "void"
#line 627 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
            {
        log("[type_specifier:] ^ found VOID\n");
        yylhs.value.as < cecko::CKTypeSafeObs > () = ctx->get_void_type();
    }
#line 1837 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 62: // type_specifier: "_Bool, char, or int"
#line 631 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
            { 
        log("[type_specifier:] ^ Found ETYPE '"); 
        switch (yystack_[0].value.as < cecko::gt_etype > ()) {
            case cecko::gt_etype::INT:
                log("INT'\n");
                yylhs.value.as < cecko::CKTypeSafeObs > () = ctx->get_int_type();
                break;
            case cecko::gt_etype::CHAR:
                log("CHAR'\n");
                yylhs.value.as < cecko::CKTypeSafeObs > () = ctx->get_char_type();
                break;
            case cecko::gt_etype::BOOL:
                log("BOOL'\n");
                yylhs.value.as < cecko::CKTypeSafeObs > () = ctx->get_bool_type();
                break;
        }
     }
#line 1859 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 63: // type_specifier: struct_or_union_specifier
#line 648 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                {
            log("[type_specifier:] found struct_or_union_specifier\n");
            yylhs.value.as < cecko::CKTypeSafeObs > () = yystack_[0].value.as < cecko::CKStructTypeSafeObs > ();
        }
#line 1868 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 64: // type_specifier: enum_specifier
#line 652 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                        {
            log("[type_specifier:] ^ found enum_specifier\n");
            yylhs.value.as < cecko::CKTypeSafeObs > () = ctx->declare_enum_type(yystack_[0].value.as < cecko::CIName > (), ctx->line());
        }
#line 1877 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 65: // type_specifier: typedef_name
#line 656 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                    {
            log("[type_specifier:] ^ found typedef_name '%s'\n", (yystack_[0].value.as < cecko::CIName > ()).c_str());
            auto type_def_data = ctx->find_typedef(yystack_[0].value.as < cecko::CIName > ());
            if (type_def_data) {
                yylhs.value.as < cecko::CKTypeSafeObs > () = type_def_data->get_type_pack().type;
            }
            else {
                std::string e_msg = "Undefined type '" + yystack_[0].value.as < cecko::CIName > () + "'!\n";
                ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
            }
        }
#line 1893 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 66: // struct_decl_head: struct_or_union "identifier"
#line 670 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            { 
        log_name("[struct_decl_head:]", yystack_[0].value.as < cecko::CIName > ());
        auto struct_obs = ctx->declare_struct_type(yystack_[0].value.as < cecko::CIName > (), ctx->line()); 
        ctx->define_struct_type_open(yystack_[0].value.as < cecko::CIName > (), ctx->line());

        yylhs.value.as < cecko::CKStructTypeSafeObs > () = struct_obs;
    }
#line 1905 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 67: // struct_or_union_specifier: struct_decl_head "{" member_declaration_list "}"
#line 680 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                            {
        ctx->define_struct_type_close(yystack_[3].value.as < cecko::CKStructTypeSafeObs > (), yystack_[1].value.as < cecko::CKStructItemArray > ());
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = yystack_[3].value.as < cecko::CKStructTypeSafeObs > ();
    }
#line 1914 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 68: // struct_or_union_specifier: struct_decl_head "{" "}"
#line 684 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                    {
        ctx->define_struct_type_close(yystack_[2].value.as < cecko::CKStructTypeSafeObs > (), {});
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = yystack_[2].value.as < cecko::CKStructTypeSafeObs > ();
    }
#line 1923 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 69: // struct_or_union_specifier: struct_decl_head
#line 688 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        ctx->define_struct_type_close(yystack_[0].value.as < cecko::CKStructTypeSafeObs > (), {});
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = yystack_[0].value.as < cecko::CKStructTypeSafeObs > ();
    }
#line 1932 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 71: // member_declaration_list: member_declaration
#line 699 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        yylhs.value.as < cecko::CKStructItemArray > () = yystack_[0].value.as < cecko::CKStructItemArray > ();
    }
#line 1940 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 72: // member_declaration_list: member_declaration_list member_declaration
#line 702 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                    {
        cecko::CKStructItemArray s_items = yystack_[1].value.as < cecko::CKStructItemArray > ();
        s_items.push_back(yystack_[0].value.as < cecko::CKStructItemArray > ()[0]);
        yylhs.value.as < cecko::CKStructItemArray > () = s_items;
    }
#line 1950 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 73: // member_declaration: specifier_qualifier_list member_declarator_list ";"
#line 710 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                            { 
        log("[member_declaration:] give refpack to member_declarator_list\n");
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[1].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[2].value.as < casem::CKTypeRefDefPack > ();

        casem::CKTypeRefDefPack final_type = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));
        cecko::CKStructItem s_item(final_type, final_type.name.value(), ctx->line());

        cecko::CKStructItemArray s_items = { s_item };
        yylhs.value.as < cecko::CKStructItemArray > () = s_items;
     }
#line 1966 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 74: // specifier_qualifier_list: type_specifier_qualifier
#line 724 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                { 
        log("[specifier_qualifier_list:] ^ type_specifier_qualifier\n");
        yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
     }
#line 1975 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 75: // specifier_qualifier_list: type_specifier_qualifier specifier_qualifier_list
#line 728 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                        { 
        log("[specifier_qualifier_list:] ^ type_specifier_qualifier specifier_qualifier_list\n");
        auto t = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        auto nt = yystack_[1].value.as < casem::CKTypeRefDefPack > ();
        if (!t.is_const && nt.is_const) {
            t.is_const = true;
        }
        else if (t.type == NULL && nt.type) {
            t.type = nt.type;
        }
        else {
            ctx->message(errors::INVALID_SPECIFIERS, ctx->line());
        }

        yylhs.value.as < casem::CKTypeRefDefPack > () = t;
     }
#line 1996 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 76: // type_specifier_qualifier: type_specifier
#line 747 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                    { 
            log("[type_specifier_qualifier:] ^ Found type_specifier\n"); 
            casem::CKTypeRefDefPack t(yystack_[0].value.as < cecko::CKTypeSafeObs > (), false, false);
            yylhs.value.as < casem::CKTypeRefDefPack > () = t;
        }
#line 2006 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 77: // type_specifier_qualifier: type_qualifier
#line 752 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                        { 
            log("[type_specifier_qualifier:] ^ Found type_qualifier\n"); 
            casem::CKTypeRefDefPack t;
            t.is_const = true;
            yylhs.value.as < casem::CKTypeRefDefPack > () = t;
        }
#line 2017 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 78: // member_declarator_list: member_declarator
#line 761 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                        {
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2025 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 79: // member_declarator_list: member_declarator_list "," member_declarator
#line 764 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                        {
        yylhs.value.as < casem::TypeRefPack_Action > () = GET_CALL_SEQUENCE_LINK(yystack_[2].value.as < casem::TypeRefPack_Action > (), yystack_[0].value.as < casem::TypeRefPack_Action > ());
    }
#line 2033 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 80: // member_declarator: declarator
#line 773 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                    {
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2041 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 81: // enum_specifier: "enum" "identifier" "{" enumerator_list "}"
#line 779 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                            {
        log_name("[enum_specifier:]", yystack_[3].value.as < cecko::CIName > ());
    }
#line 2049 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 82: // enum_specifier: "enum" "identifier" "{" enumerator_list "," "}"
#line 782 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                {
        log_name("[enum_specifier:]", yystack_[4].value.as < cecko::CIName > ());
    }
#line 2057 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 83: // enum_specifier: "enum" "identifier"
#line 785 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                    {
        yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > ();
        log_name("[enum_specifier:]", yystack_[0].value.as < cecko::CIName > ());
    }
#line 2066 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 86: // enumerator: enumeration_constant
#line 797 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                         {
        log("[enumerator:] constant\n");
    }
#line 2074 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 87: // enumerator: enumeration_constant "=" constant_expression
#line 800 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                    {
        log("[enumerator:] ASGN\n");
    }
#line 2082 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 88: // enumeration_constant: "identifier"
#line 806 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
            {
        log_name("[enumeration_constant:]", yystack_[0].value.as < cecko::CIName > ());
        yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > ();
    }
#line 2091 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 89: // type_qualifier: "const"
#line 813 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
            {
        casem::CKTypeRefDefPack rfpack;
        rfpack.is_const = true;
        yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
    }
#line 2101 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 90: // declarator: pointer direct_declarator
#line 821 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                              {
            log("[declarator:] >v found pointer direct_declarator define LAMBDA\n");
            auto DEFINER_F = yystack_[0].value.as < casem::TypeRefPack_Action > ();
            auto POINTER_F = yystack_[1].value.as < casem::TypeRefPack_Convertor > ();

            yylhs.value.as < casem::TypeRefPack_Action > () = GET_POINTER_ADDER(POINTER_F, DEFINER_F);
        }
#line 2113 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 91: // declarator: direct_declarator
#line 828 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                        {
            log("[declarator:] v found direct_declarator, gave refpack to it\n");
            yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();    // giving the casem::CKTypeRefDefPack(type, is_const, has_typedef)
        }
#line 2122 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 92: // direct_declarator: "identifier"
#line 835 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
        { 
        auto name = yystack_[0].value.as < cecko::CIName > ();
        log_name("[direct_declarator:] .() found IDF and define LAMBDA", name);

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_DEFINER(ctx, name);
    }
#line 2133 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 93: // direct_declarator: "(" declarator ")"
#line 841 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        log("[direct_declarator:] ^ found (declarator) and gave it refpack\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[1].value.as < casem::TypeRefPack_Action > ();
    }
#line 2142 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 94: // direct_declarator: array_declarator
#line 845 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        log("[direct_declarator:] v found array_declarator\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2151 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 95: // direct_declarator: function_declarator
#line 849 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        log("[direct_declarator:] v found function_declarator\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2160 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 96: // array_declarator: direct_declarator "[" assignment_expression "]"
#line 856 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                        {
        log("[array_declarator:] direct_declarator [ assignment_expression ]\n");
        if ((yystack_[1].value.as < casem::InstructionWrapper > ()).mode != casem::VarMode::LValue) {
            auto value = static_cast<cecko::CKIRConstantIntObs>((yystack_[1].value.as < casem::InstructionWrapper > ()).value);
            yylhs.value.as < casem::TypeRefPack_Action > () = GET_ARRAY_ADDER(ctx, yystack_[3].value.as < casem::TypeRefPack_Action > (), value);
        }
        else {
            // FIXME: Handle LVal
        }
    }
#line 2175 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 97: // function_declarator: direct_declarator "(" parameter_type_list ")"
#line 869 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                    {
        log("[function_declarator:] v< wrap current lambdas rfpack in function\n");
        //ctx->get_function_type(CKTypeObs ret_type, CKTypeObsArray arg_types, bool variadic=false)
        // GET_FUNCTION_ADDER(cecko::context *ctx, TypeRefPack_Action old_action, CKTypeObsArray arg_types);
        bool is_variadic = (yystack_[1].value.as < casem::TRDArray > ()).back().is_variadic;
        if (is_variadic) log("FOUND VARIADIC ... on args len = %d\n", (int)(yystack_[1].value.as < casem::TRDArray > ()).size());
        cecko::CKFunctionFormalPackArray param_names;
        for (auto& name_pack : (yystack_[1].value.as < casem::TRDArray > ())) {
            if (name_pack.optinonal_param_names.size() > 0)
                param_names.push_back(name_pack.optinonal_param_names[0]);
        }
        cecko::CKTypeObsArray param_types;
        for (auto& pt : (yystack_[1].value.as < casem::TRDArray > ())) {
            if (pt.is_variadic) break; 
            param_types.push_back(pt.type);
        }

        // TypeRefPack_Convertor UNPACK_PARAMETERS([](casem::CKTypeRefDefPack &rfpack) {
        // }); 

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_FUNCTION_ADDER(ctx, yystack_[3].value.as < casem::TypeRefPack_Action > (), param_types, is_variadic, param_names);
    }
#line 2202 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 98: // pointer: "*" type_qualifier_list pointer
#line 894 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                        {
        auto LOWER_POINTER = yystack_[0].value.as < casem::TypeRefPack_Convertor > ();
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            CONST_POINTER_TO_DEFINER = [LOWER_POINTER, this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, true, rfpack.has_typedef);
                return LOWER_POINTER(pointer_pack);
            };

        yylhs.value.as < casem::TypeRefPack_Convertor > () = CONST_POINTER_TO_DEFINER;
    }
#line 2218 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 99: // pointer: "*" pointer
#line 905 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                    {
        auto LOWER_POINTER = yystack_[0].value.as < casem::TypeRefPack_Convertor > ();
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            POINTER_TO_DEFINER = [LOWER_POINTER, this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, false, rfpack.has_typedef);
                return LOWER_POINTER(pointer_pack);
            };

        yylhs.value.as < casem::TypeRefPack_Convertor > () = POINTER_TO_DEFINER;
    }
#line 2234 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 100: // pointer: "*" type_qualifier_list
#line 916 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                    { 
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            CONST_POINTER_TO_DEFINER = [this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, true, rfpack.has_typedef);
                return pointer_pack;
            };

        yylhs.value.as < casem::TypeRefPack_Convertor > () = CONST_POINTER_TO_DEFINER;
    }
#line 2249 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 101: // pointer: "*"
#line 926 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            POINTER_TO_DEFINER = [this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, false, rfpack.has_typedef);
                return pointer_pack;
            };

        yylhs.value.as < casem::TypeRefPack_Convertor > () = POINTER_TO_DEFINER;
    }
#line 2264 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 102: // type_qualifier_list: type_qualifier
#line 939 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                    {
            casem::CKTypeRefDefPack rfpack;
            rfpack.is_const = true;
            yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack; 
        }
#line 2274 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 103: // type_qualifier_list: type_qualifier_list type_qualifier
#line 944 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                            {
            ctx->message(errors::INVALID_SPECIFIERS, ctx->line());
            yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[1].value.as < casem::CKTypeRefDefPack > ();
        }
#line 2283 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 104: // parameter_type_list: parameter_list
#line 951 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                   {
        log("[parameter_type_list:] ^ parameter_list\n");
        yylhs.value.as < casem::TRDArray > () = yystack_[0].value.as < casem::TRDArray > ();
    }
#line 2292 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 105: // parameter_list: parameter_declaration
#line 958 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        log("[parameter_list:] ^ init parameter_list\n");
        if ((yystack_[0].value.as < casem::CKTypeRefDefPack > ()).type->is_void()) {
            std::vector<casem::CKTypeRefDefPack> empty_param_array;
            yylhs.value.as < casem::TRDArray > () = empty_param_array;
        }
        else {
            std::vector<casem::CKTypeRefDefPack> param_array = { yystack_[0].value.as < casem::CKTypeRefDefPack > () };
            yylhs.value.as < casem::TRDArray > () = param_array;
        }
    }
#line 2308 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 106: // parameter_list: parameter_list "," parameter_declaration
#line 969 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                 {
        log("[parameter_list:] ^ push_back to parameter_list\n");
        if ((yystack_[0].value.as < casem::CKTypeRefDefPack > ()).type->is_void()) {
            log("ERROR: non-first void argument!\n");
            ctx->message(cecko::errors::INVALID_FUNCTION_TYPE, ctx->line());
        }
        else {
            auto param_array = yystack_[2].value.as < casem::TRDArray > ();
            if (param_array.back().is_variadic) {
                log("ERROR: non-last variadic argument!\n");
                ctx->message(cecko::errors::INVALID_FUNCTION_TYPE, ctx->line());
            }
            else {
                param_array.push_back(yystack_[0].value.as < casem::CKTypeRefDefPack > ());
                yylhs.value.as < casem::TRDArray > () = param_array;
            }
        }
    }
#line 2331 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 107: // parameter_declaration: declaration_specifiers declarator
#line 990 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                        { 
        // FIXME: Send also the cecko::CKFunctionFormalPackArray to the function_definition 
        // and from it to declarator and up

        log("[parameter_declaration:] ^ found declaration_specifiers declarator, sent up the type observer\n");
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[1].value.as < casem::CKTypeRefDefPack > ();

        // TODO: Add the param name to the rfpack.optinonal_param_names
        // We give declarator a definer, that just adds to the 
        // rfpack.optinonal_param_names the name and returs the rfpack back 
        DefinerFunction PARAM_NAME_ADDER([](cecko::context *ctx, const cecko::CIName &name, CKTypeRefDefPack &rfpack) {
            log("lambda from [parameter_declaration:] add named param to rfpack.optinonal_param_names and return it\n");
            CKFunctionFormalPack param(std::make_optional(name), rfpack.is_const, ctx->line());
            rfpack.optinonal_param_names.push_back(param);

            return rfpack;
        });

        auto param_typepack = DEFINER_BODY(rfpack, PARAM_NAME_ADDER);
        if (param_typepack.has_typedef) {
            ctx->message(errors::INVALID_SPECIFIERS, ctx->line());
        }

        yylhs.value.as < casem::CKTypeRefDefPack > () = param_typepack;
    }
#line 2362 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 108: // parameter_declaration: declaration_specifiers abstract_declarator
#line 1016 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                    {
        log("[parameter_declaration:] ^ found declaration_specifiers abstract_declarator\n");
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[1].value.as < casem::CKTypeRefDefPack > ();

        auto param_typepack = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));

        yylhs.value.as < casem::CKTypeRefDefPack > () = param_typepack;
    }
#line 2376 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 109: // parameter_declaration: declaration_specifiers
#line 1025 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                    {
        log("[parameter_declaration:] ^ found declaration_specifiers\n");
        casem::CKTypeRefDefPack rfpack = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
    }
#line 2386 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 110: // parameter_declaration: "." "." "."
#line 1030 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                  {
        yylhs.value.as < casem::CKTypeRefDefPack > () = get_variadic_type();
    }
#line 2394 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 111: // type_name: specifier_qualifier_list abstract_declarator
#line 1036 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                    {
        log("[member_declaration:] give refpack to member_declarator_list\n");
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[1].value.as < casem::CKTypeRefDefPack > ();

        casem::CKTypeRefDefPack final_type = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));

        yylhs.value.as < cecko::CKTypeObs > () = final_type.type;
    }
#line 2408 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 112: // type_name: specifier_qualifier_list
#line 1045 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                {
        yylhs.value.as < cecko::CKTypeObs > () = (yystack_[0].value.as < casem::CKTypeRefDefPack > ()).type;
    }
#line 2416 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 113: // abstract_declarator: pointer
#line 1051 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        log("[abstract_declarator:] found pointer\n");
        auto POINTER_F = yystack_[0].value.as < casem::TypeRefPack_Convertor > ();

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_POINTER_ADDER(POINTER_F, GET_DEFINER(ctx, ""));
    }
#line 2427 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 114: // abstract_declarator: pointer direct_abstract_declarator
#line 1057 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                             {
        log("[abstract_declarator:] found pointer direct_abstract_declarator\n");
        auto DEFINER_F = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        auto POINTER_F = yystack_[1].value.as < casem::TypeRefPack_Convertor > ();

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_POINTER_ADDER(POINTER_F, DEFINER_F);
    }
#line 2439 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 115: // abstract_declarator: direct_abstract_declarator
#line 1064 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                     {
        log("[abstract_declarator:] found direct_abstract_declarator\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2448 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 116: // direct_abstract_declarator: "(" abstract_declarator ")"
#line 1071 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                    {
        log("[direct_abstract_declarator:] ( abstract_declarator )\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[1].value.as < casem::TypeRefPack_Action > ();
    }
#line 2457 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 117: // direct_abstract_declarator: array_abstract_declarator
#line 1075 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                    {
        log("[direct_abstract_declarator:] array_abstract_declarator\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2466 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 118: // direct_abstract_declarator: function_abstract_declarator
#line 1079 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                    {
        log("[direct_abstract_declarator:] function_abstract_declarator\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2475 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 119: // array_abstract_declarator: direct_abstract_declarator "[" assignment_expression "]"
#line 1086 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                                {
        log("[array_abstract_declarator:] direct_abstract_declarator [ assignment_expression ]\n");
        auto value = static_cast<cecko::CKIRConstantIntObs>((yystack_[1].value.as < casem::InstructionWrapper > ()).value);
        yylhs.value.as < casem::TypeRefPack_Action > () = GET_ARRAY_ADDER(ctx, yystack_[3].value.as < casem::TypeRefPack_Action > (), value);
    }
#line 2485 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 120: // array_abstract_declarator: "[" assignment_expression "]"
#line 1091 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                        {
        log("[array_abstract_declarator:] [ assignment_expression ]\n");
        auto value = static_cast<cecko::CKIRConstantIntObs>((yystack_[1].value.as < casem::InstructionWrapper > ()).value);
        yylhs.value.as < casem::TypeRefPack_Action > () = GET_ARRAY_ADDER(ctx, GET_DEFINER(ctx, ""), value);
    }
#line 2495 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 121: // function_abstract_declarator: direct_abstract_declarator "(" parameter_type_list ")"
#line 1099 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                                {
        log("[function_abstract_declarator:] direct_abstract_declarator LPAR parameter_type_list RPAR\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = GET_FUNCTION_ADDER(ctx, yystack_[3].value.as < casem::TypeRefPack_Action > (), casem::get_types_from_tpacks(yystack_[1].value.as < casem::TRDArray > ()), false);
    }
#line 2504 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 122: // function_abstract_declarator: "(" parameter_type_list ")"
#line 1103 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                    {
        log("[function_abstract_declarator:] LPAR parameter_type_list RPAR\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = GET_FUNCTION_ADDER(ctx, GET_DEFINER(ctx, ""), casem::get_types_from_tpacks(yystack_[1].value.as < casem::TRDArray > ()), false);
    }
#line 2513 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 123: // typedef_name: "type identifier"
#line 1110 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                { yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > (); }
#line 2519 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 124: // statement: non_split_statement
#line 1118 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        log("[statement:] non_split_statement\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
    }
#line 2528 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 125: // statement: split_statement
#line 1122 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        log("[statement:] split_statement\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
    }
#line 2537 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 126: // compound_statement_head: "{"
#line 1129 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        log("ENTER BLOCK\n");
        ctx->enter_block();
    }
#line 2546 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 127: // compound_statement: compound_statement_head compound_statement_body
#line 1136 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                      {
        log("[compound_statement:] found { block_item_list }\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
    }
#line 2555 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 128: // compound_statement_body: block_item_list "}"
#line 1143 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                {
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = yystack_[1].value.as < cecko::CKIRBasicBlockObs > ();

        ctx->exit_block();
        log("EXITING BLOCK\n");
    }
#line 2566 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 129: // compound_statement_body: "}"
#line 1149 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        ctx->exit_block();
        log("EXITING BLOCK\n");

        yylhs.value.as < cecko::CKIRBasicBlockObs > () = ctx->builder()->GetInsertBlock();
    }
#line 2577 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 130: // block_item_list: block_item
#line 1158 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                    {
        log("[block_item_list:] block_item\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
    }
#line 2586 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 131: // block_item_list: block_item_list block_item
#line 1162 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                    {
        log("[block_item_list:] block_item_list block_item\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
    }
#line 2595 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 132: // block_item: declaration
#line 1169 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        log("[block_item:] declaration\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = ctx->builder()->GetInsertBlock();
    }
#line 2604 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 133: // block_item: statement
#line 1173 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        log("[block_item:] statement\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
    }
#line 2613 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 134: // expression_statement: expression_opt ";"
#line 1180 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        log("[expression_statement:] expression_opt SEMIC\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = ctx->builder()->GetInsertBlock();
    }
#line 2622 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 135: // expression_opt: expression
#line 1187 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 2630 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 136: // expression_opt: %empty
#line 1190 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                {
        
    }
#line 2638 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 137: // if_statement_head: "if" "(" expression ")"
#line 1197 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                {
        log("[if_statement_head:] IF LPAR expression RPAR\n");
        yylhs.value.as < casem::IfControllFlowData > () = init_if_data(ctx, yystack_[1].value.as < casem::InstructionWrapper > ());
    }
#line 2647 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 138: // if_non_split_statement: if_statement_head non_split_statement
#line 1204 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                            {
        log("[if_non_split_statement:] if_statement_head non_split_statement\n");
        auto data = yystack_[1].value.as < casem::IfControllFlowData > ();
        if (yystack_[0].value.as < cecko::CKIRBasicBlockObs > () != NULL) data.if_block_back = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
        yylhs.value.as < casem::IfControllFlowData > () = data;
    }
#line 2658 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 139: // if_non_split_statement_else: if_non_split_statement "else"
#line 1213 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                  {
        log("[if_non_split_statement_else:] if_non_split_statement ELSE: ");
        auto data = yystack_[1].value.as < casem::IfControllFlowData > ();
        data.else_block = ctx->create_basic_block("if.else");
        data.else_block_back = data.else_block;
        log("SWITCHING to else_block_back\n");
        ctx->builder()->SetInsertPoint(data.else_block_back);

        yylhs.value.as < casem::IfControllFlowData > () = data;
    }
#line 2673 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 140: // while_statement_head: "while" "(" expression ")"
#line 1227 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                {
        yylhs.value.as < casem::WhileControllFlowData > () = init_while_data(ctx, yystack_[1].value.as < casem::InstructionWrapper > ());
    }
#line 2681 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 141: // do_statement_head: "do"
#line 1233 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
        {
        yylhs.value.as < casem::WhileControllFlowData > () = init_do_data(ctx);
    }
#line 2689 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 142: // non_split_statement: if_non_split_statement_else non_split_statement
#line 1240 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                       {
        log("non_split_statement: if_non_split_statement_else non_split_statement: ");
        auto data = yystack_[1].value.as < casem::IfControllFlowData > ();
        if (yystack_[0].value.as < cecko::CKIRBasicBlockObs > () != NULL) data.else_block_back = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
        log("SWITCHING to continue_block\n");
        ctx->builder()->SetInsertPoint(data.continue_block);
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = create_if_control_flow(ctx, data);
    }
#line 2702 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 143: // non_split_statement: while_statement_head non_split_statement
#line 1248 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                  {
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = create_while_control_flow(ctx, yystack_[1].value.as < casem::WhileControllFlowData > ());
    }
#line 2710 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 144: // non_split_statement: "for" "(" expression_opt ";" expression_opt ";" expression_opt ")" non_split_statement
#line 1251 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                                                                    {
        // FIXME: Implement
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = ctx->builder()->GetInsertBlock();
    }
#line 2719 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 145: // non_split_statement: do_statement_head non_split_statement "while" "(" expression ")" ";"
#line 1255 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                                                {
        auto data = yystack_[6].value.as < casem::WhileControllFlowData > ();
        data.code_block_back = yystack_[5].value.as < cecko::CKIRBasicBlockObs > ();
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = create_do_control_flow(ctx, yystack_[6].value.as < casem::WhileControllFlowData > (), yystack_[2].value.as < casem::InstructionWrapper > ());
    }
#line 2729 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 146: // non_split_statement: jump_statement
#line 1260 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                        {
        log("[non_split_statement:] jump_statement\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
    }
#line 2738 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 147: // non_split_statement: expression_statement
#line 1264 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                              {
        log("[non_split_statement:] jump_statement\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
    }
#line 2747 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 148: // non_split_statement: compound_statement
#line 1268 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                            {
        log("[non_split_statement:] jump_statement\n");
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
    }
#line 2756 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 149: // split_statement: if_statement_head statement
#line 1275 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                   {
        log("[split_statement:] if_statement_head statement\n");
        auto data = yystack_[1].value.as < casem::IfControllFlowData > ();
        if (yystack_[0].value.as < cecko::CKIRBasicBlockObs > () != NULL) data.if_block_back = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
        ctx->builder()->SetInsertPoint(data.continue_block);
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = create_if_control_flow(ctx, data);
    }
#line 2768 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 150: // split_statement: if_non_split_statement_else split_statement
#line 1282 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                     {
        log("[split_statement:] if_non_split_statement_else split_statement\n");
        auto data = yystack_[1].value.as < casem::IfControllFlowData > ();
        if (yystack_[0].value.as < cecko::CKIRBasicBlockObs > () != NULL) data.else_block_back = yystack_[0].value.as < cecko::CKIRBasicBlockObs > ();
        ctx->builder()->SetInsertPoint(data.continue_block);
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = create_if_control_flow(ctx, data);
    }
#line 2780 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 151: // split_statement: while_statement_head split_statement
#line 1289 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                              {
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = create_while_control_flow(ctx, yystack_[1].value.as < casem::WhileControllFlowData > ());
    }
#line 2788 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 152: // split_statement: "for" "(" expression_opt ";" expression_opt ";" expression_opt ")" split_statement
#line 1292 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                                                                {
        // FIXME: Implement
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = ctx->builder()->GetInsertBlock();
    }
#line 2797 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 153: // split_statement: do_statement_head split_statement "while" "(" expression ")" ";"
#line 1296 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                                                            {
        auto data = yystack_[6].value.as < casem::WhileControllFlowData > ();
        data.code_block_back = yystack_[5].value.as < cecko::CKIRBasicBlockObs > ();
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = create_do_control_flow(ctx, yystack_[6].value.as < casem::WhileControllFlowData > (), yystack_[2].value.as < casem::InstructionWrapper > ());
    }
#line 2807 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;

  case 154: // jump_statement: "return" expression_opt ";"
#line 1304 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
                                {
        log("[jump_statement:] ");
        // auto ret_obs = static_cast<cecko::CKIRConstantIntObs>($2);
        auto ret_obs = yystack_[1].value.as < casem::InstructionWrapper > ();
        if (ret_obs.is_valid()) {
            log("return val\n");
            if (ret_obs.type != ctx->current_function_return_type())
                ctx->builder()->CreateRet(ret_obs.to_type(ctx->current_function_return_type()->get_ir()).read_ir());
            else
                ctx->builder()->CreateRet(ret_obs.read_ir());
        }
        else {
            log("return void\n");
            ctx->builder()->CreateRetVoid();
        }

        ctx->builder()->ClearInsertionPoint();
        yylhs.value.as < cecko::CKIRBasicBlockObs > () = ctx->builder()->GetInsertBlock();
    }
#line 2831 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"
    break;


#line 2835 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -158;

  const short parser::yytable_ninf_ = -139;

  const short
  parser::yypact_[] =
  {
     221,  -158,  -158,  -158,  -158,    -7,  -158,  -158,    31,  -158,
    -158,    33,   190,  -158,  -158,    25,   221,  -158,  -158,    78,
    -158,     6,  -158,  -158,  -158,  -158,    84,  -158,  -158,  -158,
     128,   128,  -158,  -158,  -158,  -158,  -158,  -158,   118,  -158,
     123,   126,   128,   141,  -158,  -158,  -158,  -158,   112,   114,
     128,  -158,    34,   138,   134,   139,   142,   140,  -158,  -158,
    -158,    25,  -158,  -158,   231,  -158,   272,  -158,  -158,   149,
     113,   148,   113,   113,   113,  -158,  -158,  -158,    25,    11,
    -158,    19,  -158,   162,    72,  -158,  -158,    38,  -158,    68,
    -158,   150,   185,  -158,   128,   128,   128,   167,   147,   128,
     128,   154,   155,  -158,  -158,  -158,   128,  -158,  -158,   128,
     128,   128,   128,   128,   128,   128,  -158,  -158,  -158,   313,
    -158,  -158,  -158,  -158,   165,  -158,  -158,  -158,  -158,  -158,
     170,   177,   209,  -158,  -158,    11,    25,  -158,   128,   180,
      72,  -158,   137,  -158,    25,   147,    42,  -158,   207,  -158,
     222,   223,   215,  -158,    97,   232,   235,    98,  -158,  -158,
    -158,  -158,  -158,  -158,    34,   138,   134,   139,   142,  -158,
     236,   241,  -158,  -158,  -158,  -158,   249,   261,    22,   250,
     259,  -158,  -158,  -158,    83,  -158,  -158,  -158,     9,  -158,
     128,  -158,  -158,   128,   128,   362,   109,  -158,   183,  -158,
    -158,  -158,  -158,  -158,   128,   128,   128,  -158,   263,   356,
    -158,    23,  -158,  -158,   180,    25,  -158,  -158,  -158,   140,
    -158,   256,   275,   274,   276,   183,   128,   180,  -158,   281,
     282,  -158,  -158,  -158,   128,  -158,  -158,  -158,   285,   284,
     269,   270,   287,  -158,  -158,  -158,  -158,   113,  -158,  -158
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    60,    61,    62,    70,     0,    89,   123,     0,     2,
       4,     0,   136,     5,    51,     0,    53,    55,    76,    69,
      63,     0,    56,    64,    77,    65,    83,     1,     3,     9,
       0,     0,    27,    28,    29,    30,   126,     7,     0,   141,
       0,     0,   136,     0,    88,    11,    12,    14,    23,    31,
       0,    32,    35,    37,    39,    41,    43,    45,    49,   135,
     132,     0,    10,   133,   136,   148,   136,   130,   147,     0,
     136,     0,   136,   136,   136,   124,   125,   146,     0,   101,
      92,     0,    57,    59,    91,    94,    95,     0,    54,     0,
      66,     0,     0,    24,     0,     0,   136,     0,     0,     0,
      22,     0,     0,    19,    48,    47,     0,    31,    25,     0,
       0,     0,     0,     0,     0,     0,    59,   129,   127,   136,
       6,   131,   134,   149,   124,   139,   142,   150,   143,   151,
       0,     0,     0,   102,    99,   100,     0,    52,     0,     0,
      90,    68,     0,    71,     0,    74,     0,    84,    86,    13,
       0,     0,     0,   154,   112,     0,     0,     0,    20,    17,
      18,    46,    33,    34,    36,    38,    40,    42,    44,   128,
       0,     0,    93,   103,    98,    58,     0,     0,   109,     0,
     104,   105,    67,    72,     0,    78,    80,    75,     0,    81,
       0,   137,   140,   136,     0,     0,   113,   111,   115,   117,
     118,    26,    15,    16,     0,     0,     0,    96,     0,     0,
     107,   113,   108,    97,     0,     0,    73,    82,    85,    50,
      87,     0,     0,     0,     0,   114,     0,     0,    21,     0,
       0,   110,   106,    79,   136,   120,   122,   116,     0,     0,
       0,     0,     0,   119,   121,   145,   153,   136,   144,   152
  };

  const short
  parser::yypgoto_[] =
  {
    -158,  -158,   286,  -158,  -158,  -158,  -158,  -158,  -158,   -28,
    -158,   -31,   186,   193,   196,   197,   195,   129,   -88,  -158,
     -23,  -158,    45,  -158,    24,  -158,  -158,   184,  -158,  -158,
    -158,  -158,  -158,  -158,   179,   -77,   -51,  -158,   108,  -158,
    -158,   143,   -78,   -62,   -15,   -79,  -158,  -158,   -65,  -158,
    -124,  -158,   115,  -158,  -134,  -157,  -158,  -158,  -158,   258,
    -158,  -158,  -158,   266,   -50,  -158,   -41,  -158,  -158,  -158,
    -158,  -158,   -68,   -63,  -158
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     8,     9,    10,    11,    12,    47,    48,   157,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,   106,
      59,   220,    60,    14,   178,    16,    81,    82,    17,    18,
      19,    20,    21,   142,   143,   144,    22,   184,   185,    23,
     146,   147,    62,    24,   116,    84,    85,    86,    87,   135,
     223,   180,   181,   155,   224,   198,   199,   200,    25,    63,
      64,    65,   118,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77
  };

  const short
  parser::yytable_[] =
  {
      83,    97,   124,    93,   126,   128,   130,    92,   140,   127,
     129,   131,   158,   148,   134,   179,   121,   133,   161,   108,
     197,   154,   107,    79,    15,   194,   194,   209,   209,   136,
      78,    27,    15,   217,    79,    26,    61,    79,   145,   225,
      88,   137,     6,    78,   212,    13,   109,   145,    90,   110,
     176,    44,   188,    13,   225,   152,    29,     1,     2,     3,
       4,     5,     6,   132,    80,    80,   189,    80,   187,   121,
     174,   150,   151,   173,     7,   138,   156,   139,   162,   163,
      80,   107,   107,   107,   107,   107,   107,   107,    61,   196,
      61,   145,   141,   215,   145,     2,     3,     4,     5,     6,
     194,    89,   195,   239,   203,   216,   222,    91,   204,    79,
     148,     7,   194,   211,   195,    99,   228,   100,    30,   101,
     102,   103,    31,    94,    32,    33,    34,    35,    95,   186,
     196,    96,   140,    30,   104,   105,    36,    31,   238,    32,
      33,    34,    35,    61,   211,    38,    98,    39,    40,    41,
     112,   111,   221,    42,    43,    44,   113,    45,    46,   115,
     114,   182,   107,   210,     2,     3,     4,     5,     6,    43,
      44,   122,    45,    46,     2,     3,     4,     5,     6,   248,
       7,   125,   229,   230,   249,    -8,   226,   177,   227,   153,
       7,   149,    44,   242,   132,    30,   159,   160,  -138,    31,
     186,    32,    33,    34,    35,   170,     1,     2,     3,     4,
       5,     6,   171,    36,    37,   172,     1,     2,     3,     4,
       5,     6,    38,     7,    39,    40,    41,   190,   191,   192,
      42,    43,    44,     7,    45,    46,    30,   193,   201,   202,
      31,   205,    32,    33,    34,    35,   206,     1,     2,     3,
       4,     5,     6,   207,    36,   117,   213,     1,     2,     3,
       4,     5,     6,    38,     7,    39,    40,    41,   208,   214,
     231,    42,    43,    44,     7,    45,    46,    30,   234,   235,
     236,    31,   237,    32,    33,    34,    35,   240,   241,   243,
     244,   245,   246,   247,    28,    36,   120,   164,     1,     2,
       3,     4,     5,     6,    38,   165,    39,    40,    41,   166,
     168,   167,    42,    43,    44,     7,    45,    46,    30,   219,
     175,   183,    31,   233,    32,    33,    34,    35,   123,   232,
     119,   218,     0,     0,     0,     0,    36,   169,     0,     1,
       2,     3,     4,     5,     6,    38,     0,    39,    40,    41,
       0,     0,     0,    42,    43,    44,     7,    45,    46,   194,
       0,   209,     0,   177,     0,   194,     0,   195,    79,   177,
       0,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     0,    80,     7,
       0,     0,     0,     0,     0,     7
  };

  const short
  parser::yycheck_[] =
  {
      15,    42,    70,    31,    72,    73,    74,    30,    87,    72,
      73,    74,   100,    91,    79,   139,    66,    79,   106,    50,
     154,    98,    50,    12,     0,     3,     3,     5,     5,    10,
       5,     0,     8,    24,    12,    42,    12,    12,    89,   196,
      16,    22,    31,     5,   178,     0,    12,    98,    42,    15,
     138,    42,    10,     8,   211,    96,    23,    26,    27,    28,
      29,    30,    31,    78,    42,    42,    24,    42,   145,   119,
     135,    94,    95,   135,    43,     3,    99,     5,   109,   110,
      42,   109,   110,   111,   112,   113,   114,   115,    64,   154,
      66,   142,    24,    10,   145,    27,    28,    29,    30,    31,
       3,    23,     5,   227,     6,    22,   194,    23,    10,    12,
     188,    43,     3,   178,     5,     3,   204,     5,     5,     7,
       8,     9,     9,     5,    11,    12,    13,    14,     5,   144,
     195,     5,   211,     5,    20,    21,    23,     9,   226,    11,
      12,    13,    14,   119,   209,    32,     5,    34,    35,    36,
      16,    13,   193,    40,    41,    42,    17,    44,    45,    19,
      18,    24,   190,   178,    27,    28,    29,    30,    31,    41,
      42,    22,    44,    45,    27,    28,    29,    30,    31,   247,
      43,    33,   205,   206,   247,    23,     3,     7,     5,    22,
      43,     6,    42,   234,   209,     5,    42,    42,    33,     9,
     215,    11,    12,    13,    14,    35,    26,    27,    28,    29,
      30,    31,    35,    23,    24,     6,    26,    27,    28,    29,
      30,    31,    32,    43,    34,    35,    36,    20,     6,     6,
      40,    41,    42,    43,    44,    45,     5,    22,     6,     4,
       9,     5,    11,    12,    13,    14,     5,    26,    27,    28,
      29,    30,    31,     4,    23,    24,     6,    26,    27,    28,
      29,    30,    31,    32,    43,    34,    35,    36,     7,    10,
       7,    40,    41,    42,    43,    44,    45,     5,    22,     4,
       6,     9,     6,    11,    12,    13,    14,     6,     6,     4,
       6,    22,    22,     6,     8,    23,    24,   111,    26,    27,
      28,    29,    30,    31,    32,   112,    34,    35,    36,   113,
     115,   114,    40,    41,    42,    43,    44,    45,     5,   190,
     136,   142,     9,   215,    11,    12,    13,    14,    70,   214,
      64,   188,    -1,    -1,    -1,    -1,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,     3,
      -1,     5,    -1,     7,    -1,     3,    -1,     5,    12,     7,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    26,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    -1,    43
  };

  const signed char
  parser::yystos_[] =
  {
       0,    26,    27,    28,    29,    30,    31,    43,    47,    48,
      49,    50,    51,    68,    69,    70,    71,    74,    75,    76,
      77,    78,    82,    85,    89,   104,    42,     0,    48,    23,
       5,     9,    11,    12,    13,    14,    23,    24,    32,    34,
      35,    36,    40,    41,    42,    44,    45,    52,    53,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    66,
      68,    70,    88,   105,   106,   107,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,     5,    12,
      42,    72,    73,    90,    91,    92,    93,    94,    70,    23,
      42,    23,    66,    55,     5,     5,     5,   112,     5,     3,
       5,     7,     8,     9,    20,    21,    65,    55,    57,    12,
      15,    13,    16,    17,    18,    19,    90,    24,   108,   109,
      24,   110,    22,   105,   118,    33,   118,   119,   118,   119,
     118,   119,    90,    89,    94,    95,    10,    22,     3,     5,
      91,    24,    79,    80,    81,    82,    86,    87,    88,     6,
      66,    66,   112,    22,    81,    99,    66,    54,    64,    42,
      42,    64,    57,    57,    58,    59,    60,    61,    62,    24,
      35,    35,     6,    89,    94,    73,    64,     7,    70,    96,
      97,    98,    24,    80,    83,    84,    90,    81,    10,    24,
      20,     6,     6,    22,     3,     5,    94,   100,   101,   102,
     103,     6,     4,     6,    10,     5,     5,     4,     7,     5,
      90,    94,   100,     6,    10,    10,    22,    24,    87,    63,
      67,   112,    64,    96,   100,   101,     3,     5,    64,    66,
      66,     7,    98,    84,    22,     4,     6,     6,    64,    96,
       6,     6,   112,     4,     6,    22,    22,     6,   118,   119
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    47,    47,    48,    48,    49,    49,    50,    51,
      52,    52,    52,    52,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    55,    55,    55,    55,    56,    56,    56,
      56,    57,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      67,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      74,    75,    75,    75,    75,    75,    76,    77,    77,    77,
      78,    79,    79,    80,    81,    81,    82,    82,    83,    83,
      84,    85,    85,    85,    86,    86,    87,    87,    88,    89,
      90,    90,    91,    91,    91,    91,    92,    93,    94,    94,
      94,    94,    95,    95,    96,    97,    97,    98,    98,    98,
      98,    99,    99,   100,   100,   100,   101,   101,   101,   102,
     102,   103,   103,   104,   105,   105,   106,   107,   108,   108,
     109,   109,   110,   110,   111,   112,   112,   113,   114,   115,
     116,   117,   118,   118,   118,   118,   118,   118,   118,   119,
     119,   119,   119,   119,   120
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     3,     2,     2,     2,
       1,     1,     1,     3,     1,     4,     4,     3,     3,     2,
       1,     3,     0,     1,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     3,     1,     2,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     3,     1,
       1,     1,     2,     3,     1,     2,     1,     1,     1,     3,
       1,     5,     6,     2,     1,     3,     1,     3,     1,     1,
       2,     1,     1,     3,     1,     1,     4,     4,     3,     2,
       2,     1,     1,     2,     1,     1,     3,     2,     2,     1,
       3,     2,     1,     1,     2,     1,     3,     1,     1,     4,
       3,     4,     3,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     1,     1,     2,     1,     0,     4,     2,     2,
       4,     1,     2,     2,     9,     7,     1,     1,     1,     2,
       2,     2,     9,     7,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"[\"", "\"]\"",
  "\"(\"", "\")\"", "\".\"", "\"->\"", "\"++ or --\"", "\",\"", "\"&\"",
  "\"*\"", "\"+ or -\"", "\"!\"", "\"/ or %\"", "\"<, >, <=, or >=\"",
  "\"== or !=\"", "\"&&\"", "\"||\"", "\"=\"", "\"*=, /=, %=, +=, or -=\"",
  "\";\"", "\"{\"", "\"}\"", "\":\"", "\"typedef\"", "\"void\"",
  "\"_Bool, char, or int\"", "\"struct\"", "\"enum\"", "\"const\"",
  "\"if\"", "\"else\"", "\"do\"", "\"while\"", "\"for\"", "\"goto\"",
  "\"continue\"", "\"break\"", "\"return\"", "\"sizeof\"",
  "\"identifier\"", "\"type identifier\"", "\"integer literal\"",
  "\"string literal\"", "$accept", "translation_unit",
  "external_declaration", "function_definition",
  "function_definition_info", "function_definition_head",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "no_leading_attribute_declaration", "declaration_specifiers",
  "declaration_specifier", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_decl_head",
  "struct_or_union_specifier", "struct_or_union",
  "member_declaration_list", "member_declaration",
  "specifier_qualifier_list", "type_specifier_qualifier",
  "member_declarator_list", "member_declarator", "enum_specifier",
  "enumerator_list", "enumerator", "enumeration_constant",
  "type_qualifier", "declarator", "direct_declarator", "array_declarator",
  "function_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "array_abstract_declarator", "function_abstract_declarator",
  "typedef_name", "statement", "compound_statement_head",
  "compound_statement", "compound_statement_body", "block_item_list",
  "block_item", "expression_statement", "expression_opt",
  "if_statement_head", "if_non_split_statement",
  "if_non_split_statement_else", "while_statement_head",
  "do_statement_head", "non_split_statement", "split_statement",
  "jump_statement", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   190,   190,   191,   195,   196,   200,   208,   216,   235,
     254,   258,   263,   268,   274,   277,   281,   285,   289,   293,
     307,   311,   316,   323,   327,   338,   358,   371,   372,   373,
     383,   387,   394,   398,   402,   416,   420,   434,   438,   445,
     449,   457,   461,   468,   472,   479,   483,   510,   513,   519,
     525,   533,   537,   548,   552,   575,   580,   604,   608,   616,
     623,   627,   631,   648,   652,   656,   670,   680,   684,   688,
     695,   699,   702,   710,   724,   728,   747,   752,   761,   764,
     773,   779,   782,   785,   792,   793,   797,   800,   806,   813,
     821,   828,   835,   841,   845,   849,   856,   869,   894,   905,
     916,   926,   939,   944,   951,   958,   969,   990,  1016,  1025,
    1030,  1036,  1045,  1051,  1057,  1064,  1071,  1075,  1079,  1086,
    1091,  1099,  1103,  1110,  1118,  1122,  1129,  1136,  1143,  1149,
    1158,  1162,  1169,  1173,  1180,  1187,  1190,  1197,  1204,  1213,
    1227,  1233,  1240,  1248,  1251,  1255,  1260,  1264,  1268,  1275,
    1282,  1289,  1292,  1296,  1304
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 7 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"
} // cecko
#line 3542 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/stud-sol/caparser.cpp"

#line 1327 "/mnt/c/Users/jarom/Desktop/PG_EXER/Compilers/prochj30/solution/caparser.y"


namespace cecko {

	void parser::error(const location_type& l, const std::string& m)
	{
		ctx->message(cecko::errors::SYNTAX, l, m);
	}
}
