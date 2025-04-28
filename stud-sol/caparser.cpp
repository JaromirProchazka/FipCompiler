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
#line 35 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"

// this code is emitted to caparser.cpp

YY_DECL;

using namespace casem;

#line 54 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"


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

#line 7 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
namespace cecko {
#line 147 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"

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
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.YY_MOVE_OR_COPY< casem::CKTypeRefDefPack > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_definition_info: // function_definition_info
      case symbol_kind::S_function_definition_head: // function_definition_head
        value.YY_MOVE_OR_COPY< casem::FunctionDeclarationData > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_if_expression_head: // if_expression_head
      case symbol_kind::S_if_non_split_expression: // if_non_split_expression
      case symbol_kind::S_if_non_split_expression_else: // if_non_split_expression_else
      case symbol_kind::S_flow_expression: // flow_expression
      case symbol_kind::S_non_split_expression: // non_split_expression
      case symbol_kind::S_split_expression: // split_expression
        value.YY_MOVE_OR_COPY< casem::IfExpressionData > (YY_MOVE (that.value));
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
      case symbol_kind::S_match_expression: // match_expression
      case symbol_kind::S_expression_body: // expression_body
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< casem::InstructionWrapper > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_match_binder_head: // match_binder_head
      case symbol_kind::S_match_binder_definer: // match_binder_definer
        value.YY_MOVE_OR_COPY< casem::MatchBinderChackerData > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_match_binders_list_head_start: // match_binders_list_head_start
      case symbol_kind::S_match_binders_list_head: // match_binders_list_head
        value.YY_MOVE_OR_COPY< casem::MatchBinderListHeadData > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_match_head: // match_head
      case symbol_kind::S_match_binders_list: // match_binders_list
        value.YY_MOVE_OR_COPY< casem::MatchWrapper > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.YY_MOVE_OR_COPY< casem::StructObservers > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.YY_MOVE_OR_COPY< casem::TRDArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
        value.YY_MOVE_OR_COPY< casem::TaggedTypeDecl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_function_declarator: // function_declarator
        value.YY_MOVE_OR_COPY< casem::TypeRefPack_Action > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.YY_MOVE_OR_COPY< casem::TypeRefPack_Convertor > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.YY_MOVE_OR_COPY< casem::UnaryOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_declared_type_name: // declared_type_name
      case symbol_kind::S_typedef_name: // typedef_name
        value.YY_MOVE_OR_COPY< cecko::CIName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.YY_MOVE_OR_COPY< cecko::CKStructItemArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumtype_decl_specifier: // enumtype_decl_specifier
      case symbol_kind::S_member_types_declaration: // member_types_declaration
        value.YY_MOVE_OR_COPY< cecko::CKStructTypeSafeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.YY_MOVE_OR_COPY< cecko::CKTypeSafeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.YY_MOVE_OR_COPY< cecko::gt_addop > (YY_MOVE (that.value));
        break;

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

      case symbol_kind::S_MATCH: // "match"
        value.YY_MOVE_OR_COPY< cecko::match_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_match_binder_arguments_list: // match_binder_arguments_list
        value.YY_MOVE_OR_COPY< std::vector<cecko::CIName> > (YY_MOVE (that.value));
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
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< casem::CKTypeRefDefPack > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_definition_info: // function_definition_info
      case symbol_kind::S_function_definition_head: // function_definition_head
        value.move< casem::FunctionDeclarationData > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_if_expression_head: // if_expression_head
      case symbol_kind::S_if_non_split_expression: // if_non_split_expression
      case symbol_kind::S_if_non_split_expression_else: // if_non_split_expression_else
      case symbol_kind::S_flow_expression: // flow_expression
      case symbol_kind::S_non_split_expression: // non_split_expression
      case symbol_kind::S_split_expression: // split_expression
        value.move< casem::IfExpressionData > (YY_MOVE (that.value));
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
      case symbol_kind::S_match_expression: // match_expression
      case symbol_kind::S_expression_body: // expression_body
      case symbol_kind::S_expression: // expression
        value.move< casem::InstructionWrapper > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_match_binder_head: // match_binder_head
      case symbol_kind::S_match_binder_definer: // match_binder_definer
        value.move< casem::MatchBinderChackerData > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_match_binders_list_head_start: // match_binders_list_head_start
      case symbol_kind::S_match_binders_list_head: // match_binders_list_head
        value.move< casem::MatchBinderListHeadData > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_match_head: // match_head
      case symbol_kind::S_match_binders_list: // match_binders_list
        value.move< casem::MatchWrapper > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.move< casem::StructObservers > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.move< casem::TRDArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
        value.move< casem::TaggedTypeDecl > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_function_declarator: // function_declarator
        value.move< casem::TypeRefPack_Action > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.move< casem::TypeRefPack_Convertor > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.move< casem::UnaryOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_declared_type_name: // declared_type_name
      case symbol_kind::S_typedef_name: // typedef_name
        value.move< cecko::CIName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.move< cecko::CKStructItemArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumtype_decl_specifier: // enumtype_decl_specifier
      case symbol_kind::S_member_types_declaration: // member_types_declaration
        value.move< cecko::CKStructTypeSafeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< cecko::CKTypeSafeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.move< cecko::gt_addop > (YY_MOVE (that.value));
        break;

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

      case symbol_kind::S_MATCH: // "match"
        value.move< cecko::match_type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_match_binder_arguments_list: // match_binder_arguments_list
        value.move< std::vector<cecko::CIName> > (YY_MOVE (that.value));
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
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.copy< casem::CKTypeRefDefPack > (that.value);
        break;

      case symbol_kind::S_function_definition_info: // function_definition_info
      case symbol_kind::S_function_definition_head: // function_definition_head
        value.copy< casem::FunctionDeclarationData > (that.value);
        break;

      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_if_expression_head: // if_expression_head
      case symbol_kind::S_if_non_split_expression: // if_non_split_expression
      case symbol_kind::S_if_non_split_expression_else: // if_non_split_expression_else
      case symbol_kind::S_flow_expression: // flow_expression
      case symbol_kind::S_non_split_expression: // non_split_expression
      case symbol_kind::S_split_expression: // split_expression
        value.copy< casem::IfExpressionData > (that.value);
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
      case symbol_kind::S_match_expression: // match_expression
      case symbol_kind::S_expression_body: // expression_body
      case symbol_kind::S_expression: // expression
        value.copy< casem::InstructionWrapper > (that.value);
        break;

      case symbol_kind::S_match_binder_head: // match_binder_head
      case symbol_kind::S_match_binder_definer: // match_binder_definer
        value.copy< casem::MatchBinderChackerData > (that.value);
        break;

      case symbol_kind::S_match_binders_list_head_start: // match_binders_list_head_start
      case symbol_kind::S_match_binders_list_head: // match_binders_list_head
        value.copy< casem::MatchBinderListHeadData > (that.value);
        break;

      case symbol_kind::S_match_head: // match_head
      case symbol_kind::S_match_binders_list: // match_binders_list
        value.copy< casem::MatchWrapper > (that.value);
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.copy< casem::StructObservers > (that.value);
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< casem::TRDArray > (that.value);
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
        value.copy< casem::TaggedTypeDecl > (that.value);
        break;

      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_function_declarator: // function_declarator
        value.copy< casem::TypeRefPack_Action > (that.value);
        break;

      case symbol_kind::S_pointer: // pointer
        value.copy< casem::TypeRefPack_Convertor > (that.value);
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< casem::UnaryOperator > (that.value);
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_declared_type_name: // declared_type_name
      case symbol_kind::S_typedef_name: // typedef_name
        value.copy< cecko::CIName > (that.value);
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.copy< cecko::CKStructItemArray > (that.value);
        break;

      case symbol_kind::S_enumtype_decl_specifier: // enumtype_decl_specifier
      case symbol_kind::S_member_types_declaration: // member_types_declaration
        value.copy< cecko::CKStructTypeSafeObs > (that.value);
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.copy< cecko::CKTypeSafeObs > (that.value);
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.copy< cecko::gt_addop > (that.value);
        break;

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

      case symbol_kind::S_MATCH: // "match"
        value.copy< cecko::match_type > (that.value);
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_match_binder_arguments_list: // match_binder_arguments_list
        value.copy< std::vector<cecko::CIName> > (that.value);
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
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< casem::CKTypeRefDefPack > (that.value);
        break;

      case symbol_kind::S_function_definition_info: // function_definition_info
      case symbol_kind::S_function_definition_head: // function_definition_head
        value.move< casem::FunctionDeclarationData > (that.value);
        break;

      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_if_expression_head: // if_expression_head
      case symbol_kind::S_if_non_split_expression: // if_non_split_expression
      case symbol_kind::S_if_non_split_expression_else: // if_non_split_expression_else
      case symbol_kind::S_flow_expression: // flow_expression
      case symbol_kind::S_non_split_expression: // non_split_expression
      case symbol_kind::S_split_expression: // split_expression
        value.move< casem::IfExpressionData > (that.value);
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
      case symbol_kind::S_match_expression: // match_expression
      case symbol_kind::S_expression_body: // expression_body
      case symbol_kind::S_expression: // expression
        value.move< casem::InstructionWrapper > (that.value);
        break;

      case symbol_kind::S_match_binder_head: // match_binder_head
      case symbol_kind::S_match_binder_definer: // match_binder_definer
        value.move< casem::MatchBinderChackerData > (that.value);
        break;

      case symbol_kind::S_match_binders_list_head_start: // match_binders_list_head_start
      case symbol_kind::S_match_binders_list_head: // match_binders_list_head
        value.move< casem::MatchBinderListHeadData > (that.value);
        break;

      case symbol_kind::S_match_head: // match_head
      case symbol_kind::S_match_binders_list: // match_binders_list
        value.move< casem::MatchWrapper > (that.value);
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.move< casem::StructObservers > (that.value);
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.move< casem::TRDArray > (that.value);
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
        value.move< casem::TaggedTypeDecl > (that.value);
        break;

      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_function_declarator: // function_declarator
        value.move< casem::TypeRefPack_Action > (that.value);
        break;

      case symbol_kind::S_pointer: // pointer
        value.move< casem::TypeRefPack_Convertor > (that.value);
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.move< casem::UnaryOperator > (that.value);
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_declared_type_name: // declared_type_name
      case symbol_kind::S_typedef_name: // typedef_name
        value.move< cecko::CIName > (that.value);
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.move< cecko::CKStructItemArray > (that.value);
        break;

      case symbol_kind::S_enumtype_decl_specifier: // enumtype_decl_specifier
      case symbol_kind::S_member_types_declaration: // member_types_declaration
        value.move< cecko::CKStructTypeSafeObs > (that.value);
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< cecko::CKTypeSafeObs > (that.value);
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.move< cecko::gt_addop > (that.value);
        break;

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

      case symbol_kind::S_MATCH: // "match"
        value.move< cecko::match_type > (that.value);
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_match_binder_arguments_list: // match_binder_arguments_list
        value.move< std::vector<cecko::CIName> > (that.value);
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
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        yylhs.value.emplace< casem::CKTypeRefDefPack > ();
        break;

      case symbol_kind::S_function_definition_info: // function_definition_info
      case symbol_kind::S_function_definition_head: // function_definition_head
        yylhs.value.emplace< casem::FunctionDeclarationData > ();
        break;

      case symbol_kind::S_expression_statement: // expression_statement
      case symbol_kind::S_if_expression_head: // if_expression_head
      case symbol_kind::S_if_non_split_expression: // if_non_split_expression
      case symbol_kind::S_if_non_split_expression_else: // if_non_split_expression_else
      case symbol_kind::S_flow_expression: // flow_expression
      case symbol_kind::S_non_split_expression: // non_split_expression
      case symbol_kind::S_split_expression: // split_expression
        yylhs.value.emplace< casem::IfExpressionData > ();
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
      case symbol_kind::S_match_expression: // match_expression
      case symbol_kind::S_expression_body: // expression_body
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< casem::InstructionWrapper > ();
        break;

      case symbol_kind::S_match_binder_head: // match_binder_head
      case symbol_kind::S_match_binder_definer: // match_binder_definer
        yylhs.value.emplace< casem::MatchBinderChackerData > ();
        break;

      case symbol_kind::S_match_binders_list_head_start: // match_binders_list_head_start
      case symbol_kind::S_match_binders_list_head: // match_binders_list_head
        yylhs.value.emplace< casem::MatchBinderListHeadData > ();
        break;

      case symbol_kind::S_match_head: // match_head
      case symbol_kind::S_match_binders_list: // match_binders_list
        yylhs.value.emplace< casem::MatchWrapper > ();
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        yylhs.value.emplace< casem::StructObservers > ();
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        yylhs.value.emplace< casem::TRDArray > ();
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
        yylhs.value.emplace< casem::TaggedTypeDecl > ();
        break;

      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_function_declarator: // function_declarator
        yylhs.value.emplace< casem::TypeRefPack_Action > ();
        break;

      case symbol_kind::S_pointer: // pointer
        yylhs.value.emplace< casem::TypeRefPack_Convertor > ();
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        yylhs.value.emplace< casem::UnaryOperator > ();
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_declared_type_name: // declared_type_name
      case symbol_kind::S_typedef_name: // typedef_name
        yylhs.value.emplace< cecko::CIName > ();
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        yylhs.value.emplace< cecko::CKStructItemArray > ();
        break;

      case symbol_kind::S_enumtype_decl_specifier: // enumtype_decl_specifier
      case symbol_kind::S_member_types_declaration: // member_types_declaration
        yylhs.value.emplace< cecko::CKStructTypeSafeObs > ();
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        yylhs.value.emplace< cecko::CKTypeSafeObs > ();
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        yylhs.value.emplace< cecko::gt_addop > ();
        break;

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

      case symbol_kind::S_MATCH: // "match"
        yylhs.value.emplace< cecko::match_type > ();
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_match_binder_arguments_list: // match_binder_arguments_list
        yylhs.value.emplace< std::vector<cecko::CIName> > ();
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
  case 5: // external_declaration: enumtype_decl_specifier
#line 201 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                 {
        log("[declaration:] found enumtype_decl_specifier\n");
        // $$ = $1;
    }
#line 1270 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 8: // function_definition: function_definition_head expression
#line 213 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                         {
        log("[function_definition:] with BODY, if not returned explicitely, we void return here\n");

        log("jump_statement: ");
        // auto ret_obs = static_cast<cecko::CKIRConstantIntObs>($2);
        auto ret_obs = yystack_[0].value.as < casem::InstructionWrapper > ();
        if (ret_obs.is_valid()) {
            log("return val\n");
            casem::InstructionWrapper ret_inst;
            if (ret_obs.type != ctx->current_function_return_type())
                ret_inst = ret_obs.to_type(ctx->current_function_return_type());
            else
                ret_inst = ret_obs;
            
            // FunctionDeclarationData fdata = $1;
            // cecko::CIName funtion_name = fdata.get_function_name();
            ret_inst.generate_debug_print(std::string("") + "Retruning from fucntion a non void result '" + ret_inst.name + "': ");       
            ctx->builder()->CreateRet(ret_inst.read_ir());
        }
        else {
            log("return void\n");
            // generate_debug_print(ctx, std::string("") + "Retruning from fucntion a void result");
            ctx->builder()->CreateRetVoid();
        }
        ctx->builder()->ClearInsertionPoint();
        // $$ = ctx->builder()->GetInsertBlock();

        if (! ctx->builder()->GetInsertBlock() || ctx->current_function_return_type()->is_void()) {
            // generate_debug_print(ctx, std::string("") + "Retruning from fucntion a void result");
            ctx->builder()-> CreateRetVoid();
        }

        // if we are at this point in FIP-mod, it must mean the function is FIP
        if (fip_state.is_in_fip_mode()) {
            log("{FipState} function_definition - exiting fip mod\n");
            fip_state.exit_fip_mode();
            fip_state.exit_fip_context();
        }
        ctx->exit_function();
    }
#line 1315 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 9: // function_definition: function_definition_info ";" expression_end
#line 253 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                      {
        log("[function_definition:] function_definition_info SEMIC\n");
    }
#line 1323 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 10: // function_definition_info: declaration_specifiers declarator
#line 259 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                        {
        log("[function_definition_info:]\n");
        casem::declare_support_functions(ctx);
        auto cur_l = ctx->line();
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[1].value.as < casem::CKTypeRefDefPack > ();

        casem::CKTypeRefDefPack res_tpack = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));
        log("[function_definition_info:] function type made\n");

        --cur_l;
        if (res_tpack.name.value() == "main" && cur_l != 0) {
            log("[function_definition_info:] decrementing loc\n");
        }
        log("[function_definition_info:] handled main current line\n");

        auto f_observer = ctx->declare_function(res_tpack.name.value(), res_tpack.type, cur_l);
        log("[function_definition_info:] function declared\n");

        casem::FunctionDeclarationData res(f_observer, res_tpack, rfpack);
        yylhs.value.as < casem::FunctionDeclarationData > () = res;
    }
#line 1350 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 11: // function_definition_head: function_definition_info "="
#line 284 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                  {
        log("[function_definition_head:] function_definition_info ASGN\n");
        casem::CKTypeRefDefPack res_tpack = (yystack_[1].value.as < casem::FunctionDeclarationData > ()).fun_type;
        auto f_observer = (yystack_[1].value.as < casem::FunctionDeclarationData > ()).fun_obs;
        auto rfpack = (yystack_[1].value.as < casem::FunctionDeclarationData > ()).fun_rfpack;
        ctx->enter_function(f_observer, res_tpack.optinonal_param_names, ctx->line());
        if (rfpack.is_fip) {
            log("{FipState} function_definition_info - entering fip function '"+res_tpack.name.value()+"' declaration\n");
            fip_state.enter_fip_mode();
            fip_state.enter_fip_context();
            // fip_state.insert_reusables_function_args(ctx, res_tpack.optinonal_param_names);
        }
        log("[function_definition_head:] function body entered\n");

        yylhs.value.as < casem::FunctionDeclarationData > () = yystack_[1].value.as < casem::FunctionDeclarationData > ();
    }
#line 1371 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 12: // primary_expression: "integer literal"
#line 317 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
              {
        //CKIRConstantIntObs
        log("[primary_expression:] Found int lit '%d'\n", (int)yystack_[0].value.as < int > ());
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_const(ctx, yystack_[0].value.as < int > ());
    }
#line 1381 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 13: // primary_expression: "string literal"
#line 322 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                {
        log_name("[primary_expression:] Found string lit ", yystack_[0].value.as < cecko::CIName > ());
        // (StringRef Str, const Twine &Name = "", unsigned AddressSpace = 0, Module *M = nullptr, bool AddNull = true)	
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_const(ctx, yystack_[0].value.as < cecko::CIName > ());
    }
#line 1391 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 14: // primary_expression: "(" expression_body ")"
#line 327 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                 {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[1].value.as < casem::InstructionWrapper > ();
    }
#line 1399 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 15: // postfix_expression: primary_expression
#line 333 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                           {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1407 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 16: // postfix_expression: "identifier" "(" argument_expression_list ")"
#line 336 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                 {
        // TODO: IMPLEMENT REUSING
        log("[postfix_expression:] FUNCTION CALL, IDF:'"+yystack_[3].value.as < cecko::CIName > ()+"' ( expression )\n");
        yylhs.value.as < casem::InstructionWrapper > () = casem::handle_postfix_expression_fcall(ctx, yystack_[3].value.as < cecko::CIName > (), yystack_[1].value.as < casem::InstructionArray > ());
    }
#line 1417 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 17: // postfix_expression: "identifier"
#line 341 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
            {
        auto &&label = yystack_[0].value.as < cecko::CIName > ();
        log("[postfix_expression:] FUNCTION CALL, IDF:'" + label + "'\n");
        if (casem::is_struct_label(ctx, label))
        {
            yylhs.value.as < casem::InstructionWrapper > () = casem::handle_postfix_expression_fcall(ctx, label, {});
        }
        else {
            yylhs.value.as < casem::InstructionWrapper > () = casem::init_instruction_from_name(ctx, label);
        }
    }
#line 1433 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 18: // argument_expression_list: assignment_expression
#line 367 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        casem::InstructionArray args = { yystack_[0].value.as < casem::InstructionWrapper > () };
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1442 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 19: // argument_expression_list: argument_expression_list "," assignment_expression
#line 371 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                            {
        auto &args = yystack_[2].value.as < casem::InstructionArray > ();
        args.push_back(yystack_[0].value.as < casem::InstructionWrapper > ());
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1452 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 20: // argument_expression_list: %empty
#line 376 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                              {
        casem::InstructionArray args = {};
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1461 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 21: // unary_expression: postfix_expression
#line 383 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
        log("[unary_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1470 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 22: // unary_expression: unary_operator cast_expression
#line 387 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1495 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 23: // unary_operator: "&"
#line 410 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = AMPERSANT; }
#line 1501 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 24: // unary_operator: "*"
#line 411 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = STAR; }
#line 1507 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 25: // unary_operator: "+ or -"
#line 412 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1522 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 26: // unary_operator: "!"
#line 422 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = EXCALMATION_MARK; }
#line 1528 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 27: // cast_expression: unary_expression
#line 426 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[cast_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1537 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 28: // multiplicative_expression: cast_expression
#line 433 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
        // log("[multiplicative_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1546 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 29: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 437 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        {
        log("[multiplicative_expression:] multiplicative_expression * cast_expression\n");
        yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) * (yystack_[0].value.as < casem::InstructionWrapper > ());
    }
#line 1555 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 30: // multiplicative_expression: multiplicative_expression "/ or %" cast_expression
#line 441 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1571 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 31: // additive_expression: multiplicative_expression
#line 455 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                {
        // log("[multiplicative_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1580 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 32: // additive_expression: additive_expression "+ or -" multiplicative_expression
#line 459 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1596 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 33: // relational_expression: additive_expression
#line 473 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[relational_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1605 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 34: // relational_expression: relational_expression "<, >, <=, or >=" additive_expression
#line 477 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                         {
        log("[relational_expression:] relational_expression <,>,<=,>= additive_expression\n");
        switch (yystack_[1].value.as < cecko::gt_cmpo > ()) {
        case cecko::gt_cmpo::LT:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) < (yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        case cecko::gt_cmpo::LE:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) <= (yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        case cecko::gt_cmpo::GT:
            log("[relational_expression:] GT -- found t0 > t1\n");
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) > (yystack_[0].value.as < casem::InstructionWrapper > ());
            log("[relational_expression:] GT -- returnsed instruction\n");
            break;
        case cecko::gt_cmpo::GE:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) >= (yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        }
    }
#line 1629 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 35: // equality_expression: relational_expression
#line 499 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[equality_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1638 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 36: // equality_expression: equality_expression "== or !=" relational_expression
#line 503 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        {
        log("[equality_expression:] equality_expression ==,!= relational_expression\n");
        switch (yystack_[1].value.as < cecko::gt_cmpe > ()) {
        case cecko::gt_cmpe::EQ:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) == (yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        case cecko::gt_cmpe::NE:
            yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) != (yystack_[0].value.as < casem::InstructionWrapper > ());
            break;
        }
    }
#line 1654 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 37: // logical_and_expression: equality_expression
#line 518 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[logical_and_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1663 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 38: // logical_and_expression: logical_and_expression "&&" equality_expression
#line 522 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                          {
        log("[logical_and_expression:] logical_and_expression && equality_expression\n");
        // $$ = $1;
    }
#line 1672 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 39: // logical_or_expression: logical_and_expression
#line 529 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                               {
        // log("[logical_or_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1681 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 40: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 533 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                 {
        log("[logical_or_expression:] logical_or_expression || logical_and_expression\n");
        // $$ = $1;
    }
#line 1690 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 41: // assignment_expression: logical_or_expression
#line 540 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[assignment_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1699 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 42: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 544 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1728 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 43: // assignment_operator: "="
#line 571 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
          {
        yylhs.value.as < cecko::gt_cass > () = (cecko::gt_cass)1000;
    }
#line 1736 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 44: // match_head: "match" assignment_expression "->" declaration_specifiers
#line 577 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                              {
        log("[match_head:] MATCH IDF ARROW declaration_specifiers\n");
        yylhs.value.as < casem::MatchWrapper > () = init_match_head(ctx, yystack_[3].value.as < cecko::match_type > (), yystack_[2].value.as < casem::InstructionWrapper > (), yystack_[0].value.as < casem::CKTypeRefDefPack > ());
    }
#line 1745 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 45: // match_expression: assignment_expression
#line 584 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1753 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 46: // match_expression: match_binders_list block_end
#line 587 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                      {
        log("[match_expression:] MATCH IDF ARROW declaration_specifiers block_start match_binders_list block_end\n");
        casem::MatchWrapper match_data = yystack_[1].value.as < casem::MatchWrapper > ();
        match_data.generate_final_match_result_check(ctx); // generates final if that check if result isn't tagged type set to null
        if (match_data.is_destructive) {
            log("{FipState} match_expression - exiting DMATCH\n");
            fip_state.exit_fip_mode();
            fip_state.exit_fip_context();
        }

        // auto&& res = init_instruction_from_name(ctx, casem::match_result_template);
        yylhs.value.as < casem::InstructionWrapper > () = match_data.result;
    }
#line 1771 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 47: // match_binders_list: match_binders_list_head_start expression_body
#line 603 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                   {
        log("[match_binders_list:] match_binders_list_head_start expression_body\n");
        yylhs.value.as < casem::MatchWrapper > () = init_match_binders_list(ctx, yystack_[1].value.as < casem::MatchBinderListHeadData > (), yystack_[0].value.as < casem::InstructionWrapper > ());
    }
#line 1780 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 48: // match_binders_list: match_binders_list_head expression_body
#line 607 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                               {
        log("[match_binders_list:] match_binders_list_head expression_body\n");
        yylhs.value.as < casem::MatchWrapper > () = init_match_binders_list(ctx, yystack_[1].value.as < casem::MatchBinderListHeadData > (), yystack_[0].value.as < casem::InstructionWrapper > ());
    }
#line 1789 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 49: // match_binders_list_head_start: match_head block_start match_binder_head
#line 614 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                             {
        log("[match_binders_list_head_start:] match_head block_start match_binder_head\n");
        yylhs.value.as < casem::MatchBinderListHeadData > () = MatchBinderListHeadData::init_match_binders_list_head(ctx, yystack_[2].value.as < casem::MatchWrapper > (), yystack_[0].value.as < casem::MatchBinderChackerData > ());
    }
#line 1798 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 50: // match_binders_list_head: match_binders_list match_binder_head
#line 621 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                         {
        log("[match_binders_list_head:] match_binders_list match_binder_head\n");
        yylhs.value.as < casem::MatchBinderListHeadData > () = MatchBinderListHeadData::init_match_binders_list_head(ctx, yystack_[1].value.as < casem::MatchWrapper > (), yystack_[0].value.as < casem::MatchBinderChackerData > ());
    }
#line 1807 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 51: // match_binder_head: "|" match_binder_definer "->"
#line 628 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                        {
        log("[match_binder_head:] VERT match_binder_definer ARROW\n");
        yylhs.value.as < casem::MatchBinderChackerData > () = yystack_[1].value.as < casem::MatchBinderChackerData > ();
    }
#line 1816 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 52: // match_binder_definer: "identifier" "(" match_binder_arguments_list ")"
#line 635 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                {
        log("[match_binder_definer:] IDF LPAR match_binder_arguments_list RPAR\n");
        yylhs.value.as < casem::MatchBinderChackerData > () = casem::MatchBinderChackerData(yystack_[3].value.as < cecko::CIName > ()).set_args(ctx, yystack_[1].value.as < std::vector<cecko::CIName> > ());
    }
#line 1825 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 53: // match_binder_definer: "identifier"
#line 639 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
            {
        log("[match_binder_definer:] IDF\n");
        yylhs.value.as < casem::MatchBinderChackerData > () = casem::MatchBinderChackerData(yystack_[0].value.as < cecko::CIName > ());
    }
#line 1834 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 54: // match_binder_arguments_list: "identifier"
#line 646 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
           { // FIXME: switch for `match_binder_definer`
        log("[match_binder_arguments_list:] IDF\n");
        yylhs.value.as < std::vector<cecko::CIName> > () = { yystack_[0].value.as < cecko::CIName > () };
    }
#line 1843 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 55: // match_binder_arguments_list: match_binder_arguments_list "," "identifier"
#line 650 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                            {
        log("[match_binder_arguments_list:] match_binder_arguments_list COMMA IDF\n");
        (yystack_[2].value.as < std::vector<cecko::CIName> > ()).push_back(yystack_[0].value.as < cecko::CIName > ());
        yylhs.value.as < std::vector<cecko::CIName> > () = yystack_[2].value.as < std::vector<cecko::CIName> > ();
    }
#line 1853 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 56: // expression_body: match_expression
#line 658 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                      {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1861 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 57: // expression_body: flow_expression
#line 661 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                      {
        yylhs.value.as < casem::InstructionWrapper > () = (yystack_[0].value.as < casem::IfExpressionData > ()).result;
    }
#line 1869 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 58: // expression: expression_body expression_end
#line 667 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                   {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[1].value.as < casem::InstructionWrapper > ();
    }
#line 1877 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 59: // declaration_specifiers: declaration_specifier
#line 677 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            { 
            log("[declaration_specifiers:] ^ simply give refpack from declaration_specifier to the list\n");
            yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        }
#line 1886 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 60: // declaration_specifiers: declaration_specifier declaration_specifiers
#line 681 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
                casem::CKTypeRefDefPack new_rfpack(rfpack.type, rfpack.is_const, true, rfpack.is_fip);
                rfpack = new_rfpack;
            }
            else if ( !rfpack.is_fip && (yystack_[1].value.as < casem::CKTypeRefDefPack > ()).is_fip) {
                rfpack.is_fip = (yystack_[1].value.as < casem::CKTypeRefDefPack > ()).is_fip;
            }
            else {
                ctx->message(errors::INVALID_SPECIFIERS, ctx->line());
            }

            yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
        }
#line 1914 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 61: // declaration_specifier: type_specifier_qualifier
#line 707 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1940 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 62: // declaration_specifier: "fip"
#line 728 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
            {
        log("[declaration_specifier:] Found FIP\n");
        casem::CKTypeRefDefPack rfpack;
        rfpack.is_fip = true;
        yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
    }
#line 1951 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 63: // type_specifier: "_Bool, char, or int"
#line 737 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1973 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 64: // type_specifier: declared_type_name
#line 754 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        auto&& type = ctx->declare_struct_type(yystack_[0].value.as < cecko::CIName > (), ctx->line());
        if (type && type->is_defined())  {
            yylhs.value.as < cecko::CKTypeSafeObs > () = ctx->get_pointer_type(cecko::CKTypeRefPack(type, false));
        }
        else {
            std::string e_msg = "Undefined type '" + yystack_[0].value.as < cecko::CIName > () + "'!\n";
            ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
        }
    }
#line 1988 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 65: // type_specifier: typedef_name
#line 764 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2004 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 66: // declared_type_name: "type" "identifier"
#line 778 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        log_name("[declared_type_name:] TYPEDEF IDF", yystack_[0].value.as < cecko::CIName > ());
        yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > ();
    }
#line 2013 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 67: // enumtype_decl_head: "type" "identifier"
#line 785 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        casem::declare_support_functions(ctx);
        yylhs.value.as < casem::TaggedTypeDecl > () = declare_parent_ttype(ctx, yystack_[0].value.as < cecko::CIName > ());
    }
#line 2022 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 72: // enumtype_decl_specifier: enumtype_decl_head block_start member_types_declaration_list block_end "NEW_LINE"
#line 802 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                                    {
        // FIXME: Handle tag range
        log("[enumtype_decl_specifier:] enumtype_decl_head block_start member_types_declaration_list block_end NEWLINE\n");
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = TaggedTypeDecl::finish_parent_ttype(ctx, yystack_[4].value.as < casem::TaggedTypeDecl > ());
    }
#line 2032 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 73: // member_types_declaration_list: member_types_declaration
#line 810 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                 {
        log("[member_types_declaration_list:] member_types_declaration\n");
        StructObservers vec = { yystack_[0].value.as < cecko::CKStructTypeSafeObs > () };
        yylhs.value.as < casem::StructObservers > () = vec;
    }
#line 2042 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 74: // member_types_declaration_list: member_types_declaration_list member_types_declaration
#line 815 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                  {
        log("[member_types_declaration_list:] member_types_declaration_list member_types_declaration\n");
        auto&& vec = yystack_[1].value.as < casem::StructObservers > (); 
        vec.push_back(yystack_[0].value.as < cecko::CKStructTypeSafeObs > ());
        yylhs.value.as < casem::StructObservers > () = vec;
    }
#line 2053 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 75: // member_types_declaration: "identifier" "(" member_declaration_list ")" ";"
#line 824 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                    {
        log_name("[member_types_declaration:] includes member_declaration_list", yystack_[4].value.as < cecko::CIName > ());
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = casem::declare_child_ttype(ctx, yystack_[4].value.as < cecko::CIName > (), yystack_[2].value.as < cecko::CKStructItemArray > ());
    }
#line 2062 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 76: // member_types_declaration: "identifier" ";"
#line 828 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                   {
        log_name("[member_types_declaration:] found IDF SEMIC", yystack_[1].value.as < cecko::CIName > ());
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = casem::declare_child_ttype(ctx, yystack_[1].value.as < cecko::CIName > ());
    }
#line 2071 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 77: // member_declaration_list: member_declaration
#line 835 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log("[member_declaration_list:] member_declaration\n");
        yylhs.value.as < cecko::CKStructItemArray > () = yystack_[0].value.as < cecko::CKStructItemArray > ();
    }
#line 2080 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 78: // member_declaration_list: member_declaration_list "," member_declaration
#line 839 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                          {
        log("[member_declaration_list:] member_declaration_list COMMA member_declaration\n");
        cecko::CKStructItemArray s_items = yystack_[2].value.as < cecko::CKStructItemArray > ();
        s_items.push_back(yystack_[0].value.as < cecko::CKStructItemArray > ()[0]);
        yylhs.value.as < cecko::CKStructItemArray > () = s_items;
    }
#line 2091 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 79: // member_declaration: specifier_qualifier_list member_declarator
#line 848 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                 { 
        log("[member_declaration:] give refpack to member_declarator_list\n");
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[1].value.as < casem::CKTypeRefDefPack > ();

        casem::CKTypeRefDefPack final_type = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));
        cecko::CKStructItem s_item(final_type, final_type.name.value(), ctx->line());

        cecko::CKStructItemArray s_items = { s_item };
        yylhs.value.as < cecko::CKStructItemArray > () = s_items;
     }
#line 2107 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 80: // specifier_qualifier_list: type_specifier_qualifier
#line 862 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                { 
        log("[specifier_qualifier_list:] ^ type_specifier_qualifier\n");
        yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
     }
#line 2116 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 81: // specifier_qualifier_list: type_specifier_qualifier specifier_qualifier_list
#line 866 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2137 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 82: // type_specifier_qualifier: type_specifier
#line 885 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    { 
            log("[type_specifier_qualifier:] ^ Found type_specifier\n"); 
            casem::CKTypeRefDefPack t(yystack_[0].value.as < cecko::CKTypeSafeObs > (), false, false, false);
            yylhs.value.as < casem::CKTypeRefDefPack > () = t;
        }
#line 2147 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 83: // member_declarator: declarator
#line 893 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2155 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 84: // declarator: pointer direct_declarator
#line 899 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                              {
        log("[declarator:] >v found pointer direct_declarator define LAMBDA\n");
        auto DEFINER_F = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        auto POINTER_F = yystack_[1].value.as < casem::TypeRefPack_Convertor > ();

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_POINTER_ADDER(POINTER_F, DEFINER_F);
    }
#line 2167 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 85: // declarator: direct_declarator
#line 906 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
            log("[declarator:] v found direct_declarator, gave refpack to it\n");
            yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();    // giving the casem::CKTypeRefDefPack(type, is_const, has_typedef)
        }
#line 2176 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 86: // pointer: "*" pointer
#line 913 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                  {
        auto LOWER_POINTER = yystack_[0].value.as < casem::TypeRefPack_Convertor > ();
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            POINTER_TO_DEFINER = [LOWER_POINTER, this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, false, rfpack.has_typedef, rfpack.is_fip);
                return LOWER_POINTER(pointer_pack);
            };

        yylhs.value.as < casem::TypeRefPack_Convertor > () = POINTER_TO_DEFINER;
    }
#line 2192 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 87: // pointer: "*"
#line 924 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                {
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            POINTER_TO_DEFINER = [this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, false, rfpack.has_typedef, rfpack.is_fip);
                return pointer_pack;
            };

        yylhs.value.as < casem::TypeRefPack_Convertor > () = POINTER_TO_DEFINER;
    }
#line 2207 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 88: // direct_declarator: "identifier"
#line 937 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
        { 
        auto name = yystack_[0].value.as < cecko::CIName > ();
        log_name("[direct_declarator:] .() found IDF and define LAMBDA", name);

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_DEFINER(ctx, name);
    }
#line 2218 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 89: // direct_declarator: function_declarator
#line 943 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log("[direct_declarator:] v found function_declarator\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2227 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 90: // function_declarator: direct_declarator "[" parameter_type_list "]"
#line 950 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                     {
        log("[function_declarator:] direct_declarator LBRA parameter_type_list RBRA -- v< wrap current lambdas rfpack in function\n");
        //ctx->get_function_type(CKTypeObs ret_type, CKTypeObsArray arg_types, bool variadic=false)
        // GET_FUNCTION_ADDER(cecko::context *ctx, TypeRefPack_Action old_action, CKTypeObsArray arg_types);
        bool is_variadic = ((yystack_[1].value.as < casem::TRDArray > ()).empty()) ? false : (yystack_[1].value.as < casem::TRDArray > ()).back().is_variadic;
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


        yylhs.value.as < casem::TypeRefPack_Action > () = GET_FUNCTION_ADDER(ctx, yystack_[3].value.as < casem::TypeRefPack_Action > (), param_types, is_variadic, param_names);
    }
#line 2252 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 91: // parameter_type_list: parameter_list
#line 973 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                   {
        log("[parameter_type_list:] ^ parameter_list\n");
        yylhs.value.as < casem::TRDArray > () = yystack_[0].value.as < casem::TRDArray > ();
    }
#line 2261 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 92: // parameter_type_list: %empty
#line 977 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                  {
        std::vector<casem::CKTypeRefDefPack> empty_param_array;
        yylhs.value.as < casem::TRDArray > () = empty_param_array;
    }
#line 2270 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 93: // parameter_list: parameter_declaration
#line 984 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2286 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 94: // parameter_list: parameter_list "," parameter_declaration
#line 995 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2309 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 95: // parameter_declaration: declaration_specifiers declarator
#line 1016 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2340 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 96: // parameter_declaration: declaration_specifiers
#line 1042 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                    {
        log("[parameter_declaration:] ^ found declaration_specifiers\n");
        casem::CKTypeRefDefPack rfpack = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
    }
#line 2350 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 97: // typedef_name: "type identifier"
#line 1050 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > (); }
#line 2356 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 98: // expression_statement: match_expression ";"
#line 1059 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                              {
        log("[expression_statement:] expression_opt SEMIC\n");
        IfExpressionData res;
        res.result = yystack_[1].value.as < casem::InstructionWrapper > ();
        res.block = ctx->builder()->GetInsertBlock();

        yylhs.value.as < casem::IfExpressionData > () = res;
    }
#line 2369 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 99: // if_expression_head: "if" "(" expression_body ")"
#line 1072 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                     {
        log("[if_expression_head:] IF LPAR expression RPAR\n");
        yylhs.value.as < casem::IfExpressionData > () = IfExpressionData::init_if_head(ctx, yystack_[1].value.as < casem::InstructionWrapper > ());
    }
#line 2378 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 100: // if_non_split_expression: if_expression_head non_split_expression
#line 1079 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                              {
        log("[if_non_split_expression:] if_expression_head non_split_statement\n");
        auto &&expression_data = yystack_[1].value.as < casem::IfExpressionData > ();
        auto &data = expression_data.if_data;
        data.if_block_back = ctx->builder()->GetInsertBlock();
        expression_data.store_to_result(ctx, yystack_[0].value.as < casem::IfExpressionData > ());
        casem::exit_block(ctx);
        yylhs.value.as < casem::IfExpressionData > () = expression_data;
    }
#line 2392 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 101: // if_non_split_expression_else: if_non_split_expression "else"
#line 1091 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                   {
        log("[if_non_split_expression_else:] if_non_split_expression ELSE: \n");
        yylhs.value.as < casem::IfExpressionData > () = IfExpressionData::init_if_else_head(ctx, yystack_[1].value.as < casem::IfExpressionData > ());
    }
#line 2401 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 102: // flow_expression: non_split_expression
#line 1098 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
    { yylhs.value.as < casem::IfExpressionData > () = yystack_[0].value.as < casem::IfExpressionData > (); }
#line 2407 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 103: // flow_expression: split_expression
#line 1099 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
      { yylhs.value.as < casem::IfExpressionData > () = yystack_[0].value.as < casem::IfExpressionData > (); }
#line 2413 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 104: // non_split_expression: if_non_split_expression_else non_split_expression
#line 1103 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                         {
        log("[non_split_expression:] if_non_split_expression_else non_split_expression: \n");
        auto &&expression_data = yystack_[1].value.as < casem::IfExpressionData > ();
        auto &data = expression_data.if_data;
        expression_data.store_to_result(ctx, yystack_[0].value.as < casem::IfExpressionData > ());
        data.else_block_back = ctx->builder()->GetInsertBlock();
        exit_block(ctx);
        log("SWITCHING to continue_block\n");
        ctx->builder()->SetInsertPoint(data.continue_block);
        expression_data.block = create_if_control_flow(ctx, data);

        yylhs.value.as < casem::IfExpressionData > () = expression_data;
    }
#line 2431 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 105: // non_split_expression: expression_statement
#line 1116 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                              {
        log("[non_split_statement:] expression_statement\n");
        yylhs.value.as < casem::IfExpressionData > () = yystack_[0].value.as < casem::IfExpressionData > ();
    }
#line 2440 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 106: // split_expression: if_expression_head expression_body
#line 1123 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                           {
        log("[split_statement:] if_statement_head statement\n");
        auto &&expression_data = yystack_[1].value.as < casem::IfExpressionData > ();
        auto &data = expression_data.if_data;
        expression_data.store_to_result(ctx, yystack_[0].value.as < casem::InstructionWrapper > ());
        data.if_block_back = ctx->builder()->GetInsertBlock();
        exit_block(ctx);
        ctx->builder()->SetInsertPoint(data.continue_block);
        
        expression_data.block = create_if_control_flow(ctx, data);
        yylhs.value.as < casem::IfExpressionData > () = expression_data;
     }
#line 2457 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 107: // split_expression: if_non_split_expression_else split_expression
#line 1135 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        {
        log("[split_statement:] if_non_split_statement_else split_statement\n");
        auto &&expression_data = yystack_[1].value.as < casem::IfExpressionData > ();
        auto &data = expression_data.if_data;
        expression_data.store_to_result(ctx, yystack_[0].value.as < casem::IfExpressionData > ());
        data.else_block_back = ctx->builder()->GetInsertBlock();
        exit_block(ctx);
        ctx->builder()->SetInsertPoint(data.continue_block);
         
        expression_data.block = create_if_control_flow(ctx, data);
        yylhs.value.as < casem::IfExpressionData > () = expression_data;
     }
#line 2474 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;


#line 2478 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"

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


  const signed char parser::yypact_ninf_ = -111;

  const signed char parser::yytable_ninf_ = -101;

  const signed char
  parser::yypact_[] =
  {
      41,     6,  -111,  -111,  -111,     4,  -111,  -111,    69,     1,
      -9,    45,  -111,  -111,    20,  -111,  -111,  -111,    24,  -111,
    -111,  -111,     9,     1,  -111,  -111,  -111,  -111,     7,    44,
      63,  -111,  -111,  -111,  -111,    53,     7,  -111,    67,    62,
      70,    75,    73,    76,  -111,    20,    72,    54,     1,     1,
       9,  -111,  -111,     1,    64,     1,  -111,  -111,  -111,    84,
    -111,  -111,    65,    94,  -111,    68,  -111,    92,    71,  -111,
    -111,  -111,    96,    97,     1,     7,  -111,     7,  -111,  -111,
       7,     7,     7,     7,     7,     7,     7,    93,  -111,    83,
      80,  -111,  -111,  -111,  -111,  -111,  -111,  -111,    77,  -111,
      72,  -111,  -111,  -111,    94,    45,  -111,  -111,     3,    -2,
    -111,  -111,    45,   102,    74,  -111,  -111,  -111,  -111,    67,
      62,    70,    75,    73,  -111,  -111,   104,   105,    -9,   106,
     107,  -111,    38,  -111,   110,  -111,  -111,  -111,  -111,     7,
      85,  -111,  -111,  -111,    45,    78,  -111,    -9,    38,  -111,
    -111,  -111,    79,  -111,    98,    38,  -111,  -111,  -111,  -111,
      86,  -111,  -111,  -111
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,    63,    62,    97,     0,     2,     4,     0,     0,
       0,    59,    82,    64,     0,     5,    61,    65,    66,     1,
       3,    11,     0,     0,    23,    24,    25,    26,     0,     0,
      17,    12,    13,    15,    21,    27,     0,    28,    31,    33,
      35,    37,    39,    41,    45,     0,    56,     0,     0,     0,
       0,     8,   105,     0,     0,     0,    57,   102,   103,    87,
      88,    10,     0,    85,    89,     0,    60,    68,     0,     7,
       6,     9,     0,     0,     0,    20,    43,     0,    27,    22,
       0,     0,     0,     0,     0,     0,     0,     0,    98,     0,
       0,    70,    50,    46,    47,    48,    58,   106,   102,   101,
       0,   104,   107,    86,    84,    92,    66,    69,     0,     0,
      73,    14,     0,     0,     0,    18,    42,    29,    30,    32,
      34,    36,    38,    40,    49,    71,    53,     0,    96,     0,
      91,    93,     0,    76,     0,    74,    44,    99,    16,     0,
       0,    51,    95,    90,     0,     0,    77,     0,    80,    72,
      19,    54,     0,    94,     0,     0,    79,    83,    81,    52,
       0,    75,    78,    55
  };

  const signed char
  parser::yypgoto_[] =
  {
    -111,  -111,   109,    81,  -111,  -111,  -111,  -111,  -111,  -111,
     -26,  -111,   -29,    36,    39,    40,    42,    37,  -111,   -27,
    -111,  -111,    82,  -111,  -111,  -111,    43,  -111,  -111,   -21,
    -111,   -11,  -111,  -111,  -111,  -111,    87,    16,  -111,  -111,
      17,  -111,   -20,   -19,   -86,  -111,  -110,    88,    66,  -111,
    -111,  -111,   -10,  -111,  -111,  -111,  -111,  -111,  -111,   -30,
      89
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     5,     6,    71,     7,     8,     9,    33,    34,   114,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      77,    45,    46,    47,    48,    49,    92,   127,   152,    50,
      51,    10,    11,    12,    13,    14,    68,    93,    15,   109,
     110,   145,   146,   147,    16,   156,    61,    62,    63,    64,
     129,   130,   131,    17,    52,    53,    54,    55,    56,    57,
      58
  };

  const short
  parser::yytable_[] =
  {
      66,    73,    72,    59,    19,    89,    23,    79,   132,    69,
      78,    24,    23,    25,    26,    27,    70,    24,   142,    25,
      26,    27,    91,    98,   133,   101,    60,    94,    95,     1,
       2,    28,    97,   108,    29,     3,    30,   157,    31,    32,
       4,    18,    30,    67,    31,    32,   148,   -67,   115,    74,
     116,   117,   118,   113,    78,    78,    78,    78,    78,    78,
      78,    89,   148,    65,     2,    90,     1,     2,    75,   148,
      65,     2,     3,    76,     4,    82,     3,     4,    91,    80,
     138,     4,    81,   139,   154,   159,    83,   155,   160,    21,
      22,    85,    84,    88,   128,    86,    59,   105,    99,   107,
      60,   136,   111,   106,    90,   112,   108,   125,   137,   140,
     143,  -100,   150,   141,    20,   126,   144,   149,   119,   161,
     151,   163,   120,   123,   121,   134,   135,   122,   104,   158,
     124,    96,    87,   128,   153,   162,     0,   100,     0,     0,
       0,     0,     0,     0,   102,     0,     0,   103
  };

  const short
  parser::yycheck_[] =
  {
      11,    28,    23,    12,     0,     7,     5,    36,     5,     0,
      36,    10,     5,    12,    13,    14,     7,    10,   128,    12,
      13,    14,    24,    53,    21,    55,    35,    48,    49,    25,
      26,    30,    53,    35,    33,    31,    35,   147,    37,    38,
      36,    35,    35,    23,    37,    38,   132,    23,    75,     5,
      77,    80,    81,    74,    80,    81,    82,    83,    84,    85,
      86,     7,   148,    25,    26,    11,    25,    26,     5,   155,
      25,    26,    31,    20,    36,    13,    31,    36,    24,    12,
       6,    36,    15,     9,     6,     6,    16,     9,     9,    20,
      21,    18,    17,    21,   105,    19,    12,     3,    34,     7,
      35,   112,     6,    35,    11,     8,    35,    24,     6,     5,
       4,    34,   139,     8,     5,    35,     9,     7,    82,    21,
      35,    35,    83,    86,    84,   109,   109,    85,    62,   148,
      87,    50,    45,   144,   144,   155,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    59
  };

  const signed char
  parser::yystos_[] =
  {
       0,    25,    26,    31,    36,    40,    41,    43,    44,    45,
      70,    71,    72,    73,    74,    77,    83,    92,    35,     0,
      41,    20,    21,     5,    10,    12,    13,    14,    30,    33,
      35,    37,    38,    46,    47,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    60,    61,    62,    63,    64,
      68,    69,    93,    94,    95,    96,    97,    98,    99,    12,
      35,    85,    86,    87,    88,    25,    70,    23,    75,     0,
       7,    42,    68,    58,     5,     5,    20,    59,    49,    51,
      12,    15,    13,    16,    17,    18,    19,    75,    21,     7,
      11,    24,    65,    76,    68,    68,    42,    68,    98,    34,
      61,    98,    99,    86,    87,     3,    35,     7,    35,    78,
      79,     6,     8,    68,    48,    58,    58,    51,    51,    52,
      53,    54,    55,    56,    65,    24,    35,    66,    70,    89,
      90,    91,     5,    21,    76,    79,    70,     6,     6,     9,
       5,     8,    85,     4,     9,    80,    81,    82,    83,     7,
      58,    35,    67,    91,     6,     9,    84,    85,    82,     6,
       9,    21,    81,    35
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    39,    40,    40,    41,    41,    42,    42,    43,    43,
      44,    45,    46,    46,    46,    47,    47,    47,    48,    48,
      48,    49,    49,    50,    50,    50,    50,    51,    52,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    60,    61,    61,    62,    62,    63,
      64,    65,    66,    66,    67,    67,    68,    68,    69,    70,
      70,    71,    71,    72,    72,    72,    73,    74,    75,    75,
      76,    76,    77,    78,    78,    79,    79,    80,    80,    81,
      82,    82,    83,    84,    85,    85,    86,    86,    87,    87,
      88,    89,    89,    90,    90,    91,    91,    92,    93,    94,
      95,    96,    97,    97,    98,    98,    99,    99
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     2,     3,
       2,     2,     1,     1,     3,     1,     4,     1,     1,     3,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     4,     1,     2,     2,     2,     3,
       2,     3,     4,     1,     1,     3,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     2,     5,     1,     2,     5,     2,     1,     3,     2,
       1,     2,     1,     1,     2,     1,     2,     1,     1,     1,
       4,     1,     0,     1,     3,     2,     1,     1,     2,     4,
       2,     2,     1,     1,     2,     1,     2,     2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"[\"", "\"]\"",
  "\"(\"", "\")\"", "\"NEW_LINE\"", "\"->\"", "\",\"", "\"&\"", "\"|\"",
  "\"*\"", "\"+ or -\"", "\"!\"", "\"/ or %\"", "\"<, >, <=, or >=\"",
  "\"== or !=\"", "\"&&\"", "\"||\"", "\"=\"", "\";\"", "\":\"", "\"{\"",
  "\"}\"", "\"type\"", "\"_Bool, char, or int\"", "\"sizeof\"", "\"in\"",
  "\"let\"", "\"match\"", "\"fip\"", "\"fn\"", "\"if\"", "\"else\"",
  "\"identifier\"", "\"type identifier\"", "\"integer literal\"",
  "\"string literal\"", "$accept", "translation_unit",
  "external_declaration", "expression_end", "function_definition",
  "function_definition_info", "function_definition_head",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "assignment_expression", "assignment_operator",
  "match_head", "match_expression", "match_binders_list",
  "match_binders_list_head_start", "match_binders_list_head",
  "match_binder_head", "match_binder_definer",
  "match_binder_arguments_list", "expression_body", "expression",
  "declaration_specifiers", "declaration_specifier", "type_specifier",
  "declared_type_name", "enumtype_decl_head", "block_start", "block_end",
  "enumtype_decl_specifier", "member_types_declaration_list",
  "member_types_declaration", "member_declaration_list",
  "member_declaration", "specifier_qualifier_list",
  "type_specifier_qualifier", "member_declarator", "declarator", "pointer",
  "direct_declarator", "function_declarator", "parameter_type_list",
  "parameter_list", "parameter_declaration", "typedef_name",
  "expression_statement", "if_expression_head", "if_non_split_expression",
  "if_non_split_expression_else", "flow_expression",
  "non_split_expression", "split_expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   195,   195,   196,   200,   201,   208,   209,   213,   253,
     259,   284,   317,   322,   327,   333,   336,   341,   367,   371,
     376,   383,   387,   410,   411,   412,   422,   426,   433,   437,
     441,   455,   459,   473,   477,   499,   503,   518,   522,   529,
     533,   540,   544,   571,   577,   584,   587,   603,   607,   614,
     621,   628,   635,   639,   646,   650,   658,   661,   667,   677,
     681,   707,   728,   737,   754,   764,   778,   785,   792,   793,
     797,   798,   802,   810,   815,   824,   828,   835,   839,   848,
     862,   866,   885,   893,   899,   906,   913,   924,   937,   943,
     950,   973,   977,   984,   995,  1016,  1042,  1050,  1059,  1072,
    1079,  1091,  1098,  1099,  1103,  1116,  1123,  1135
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


#line 7 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
} // cecko
#line 3084 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"

#line 1152 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"


namespace cecko {

	void parser::error(const location_type& l, const std::string& m)
	{
		ctx->message(cecko::errors::SYNTAX, l, m);
	}
}
