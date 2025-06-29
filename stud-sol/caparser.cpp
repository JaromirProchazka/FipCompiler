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
#line 204 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                 {
        log("[declaration:] found enumtype_decl_specifier (line: %i)\n", (int)ctx->line());
        // $$ = $1;
    }
#line 1270 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 10: // function_definition: function_definition_head expression
#line 221 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                         {
        log("[function_definition:] with BODY, if not returned explicitely, we void return here (line: %i)\n", (int)ctx->line());

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

        auto fip_state = casem::FipState::GetFipState();
        // if we are at this point in FIP-mod, it must mean the function is FIP
        if (fip_state->is_in_fip_mode()) {
            log("{FipState} function_definition - exiting fip mod\n");
            fip_state->exit_fip_mode();
            fip_state->exit_fip_context();
        }
        ctx->exit_function();
    }
#line 1316 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 11: // function_definition: function_definition_info ";" expression_end
#line 262 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                      {
        log("[function_definition:] function_definition_info SEMIC (line: %i)\n", (int)ctx->line());
    }
#line 1324 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 12: // function_definition_info: declaration_specifiers declarator
#line 268 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                        {
        log("[function_definition_info:] (line: %i)\n", (int)ctx->line());
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
#line 1351 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 13: // function_definition_head: function_definition_info "="
#line 293 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                  {
        log("[function_definition_head:] function_definition_info ASGN (line: %i)\n", (int)ctx->line());
        casem::CKTypeRefDefPack res_tpack = (yystack_[1].value.as < casem::FunctionDeclarationData > ()).fun_type;
        auto f_observer = (yystack_[1].value.as < casem::FunctionDeclarationData > ()).fun_obs;
        auto rfpack = (yystack_[1].value.as < casem::FunctionDeclarationData > ()).fun_rfpack;
        ctx->enter_function(f_observer, res_tpack.optinonal_param_names, ctx->line());
        auto fip_state = casem::FipState::GetFipState();
        if (rfpack.is_fip) {
            log("{FipState} function_definition_info - entering fip function '"+res_tpack.name.value()+"' declaration\n");
            fip_state->enter_fip_mode();
            fip_state->enter_fip_context();
        }
        log("[function_definition_head:] function body entered\n");

        yylhs.value.as < casem::FunctionDeclarationData > () = yystack_[1].value.as < casem::FunctionDeclarationData > ();
    }
#line 1372 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 14: // primary_expression: "integer literal"
#line 326 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
              {
        //CKIRConstantIntObs
        log("[primary_expression:] Found int lit '%d' (line: %i)\n", (int)yystack_[0].value.as < int > (), (int)ctx->line());
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_const(ctx, yystack_[0].value.as < int > ());
    }
#line 1382 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 15: // primary_expression: "string literal"
#line 331 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                {
        log_name("[primary_expression:] Found string lit ", yystack_[0].value.as < cecko::CIName > ());
        // (StringRef Str, const Twine &Name = "", unsigned AddressSpace = 0, Module *M = nullptr, bool AddNull = true)	
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_const(ctx, yystack_[0].value.as < cecko::CIName > ());
    }
#line 1392 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 16: // primary_expression: "(" expression_body ")"
#line 336 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                 {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[1].value.as < casem::InstructionWrapper > ();
    }
#line 1400 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 17: // postfix_expression: primary_expression
#line 342 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                           {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1408 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 18: // postfix_expression: "identifier" "(" argument_expression_list ")"
#line 345 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                 {
        log("[postfix_expression:] FUNCTION CALL, IDF:'"+yystack_[3].value.as < cecko::CIName > ()+"' ( expression ) (line: "+std::to_string(ctx->line())+")\n");
        yylhs.value.as < casem::InstructionWrapper > () = casem::handle_postfix_expression_fcall(ctx, yystack_[3].value.as < cecko::CIName > (), yystack_[1].value.as < casem::InstructionArray > ());
    }
#line 1417 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 19: // postfix_expression: "identifier"
#line 349 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
            {
        auto &&label = yystack_[0].value.as < cecko::CIName > ();    
        log("[postfix_expression:] FUNCTION CALL, IDF:'" + label + "'(line: "+std::to_string(ctx->line())+")\n");
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

  case 20: // argument_expression_list: assignment_expression
#line 375 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        casem::InstructionArray args = { yystack_[0].value.as < casem::InstructionWrapper > () };
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1442 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 21: // argument_expression_list: argument_expression_list "," assignment_expression
#line 379 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                            {
        auto &args = yystack_[2].value.as < casem::InstructionArray > ();
        args.push_back(yystack_[0].value.as < casem::InstructionWrapper > ());
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1452 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 22: // argument_expression_list: %empty
#line 384 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                              {
        casem::InstructionArray args = {};
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1461 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 23: // unary_expression: postfix_expression
#line 391 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
        // log("[unary_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1470 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 24: // unary_expression: unary_operator cast_expression
#line 395 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                        { 
        log("[unary_expression:] unary_operator cast_expression (line: %i)\n", (int)ctx->line());
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

  case 25: // unary_operator: "&"
#line 418 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = AMPERSANT; }
#line 1501 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 26: // unary_operator: "*"
#line 419 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = STAR; }
#line 1507 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 27: // unary_operator: "+ or -"
#line 420 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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

  case 28: // unary_operator: "!"
#line 430 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = EXCALMATION_MARK; }
#line 1528 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 29: // cast_expression: unary_expression
#line 434 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[cast_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1537 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 30: // multiplicative_expression: cast_expression
#line 441 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
        // log("[multiplicative_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1546 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 31: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 445 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        {
        log("[multiplicative_expression:] multiplicative_expression * cast_expression (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) * (yystack_[0].value.as < casem::InstructionWrapper > ());
    }
#line 1555 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 32: // multiplicative_expression: multiplicative_expression "/ or %" cast_expression
#line 449 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                         {
        log("[multiplicative_expression:] multiplicative_expression / cast_expression (line: %i)\n", (int)ctx->line());
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

  case 33: // additive_expression: multiplicative_expression
#line 463 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                {
        // log("[multiplicative_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1580 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 34: // additive_expression: additive_expression "+ or -" multiplicative_expression
#line 467 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                            {
        log("[additive_expression:] additive_expression + multiplicative_expression (line: %i)\n", (int)ctx->line());
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

  case 35: // relational_expression: additive_expression
#line 481 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[relational_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1605 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 36: // relational_expression: relational_expression "<, >, <=, or >=" additive_expression
#line 485 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                         {
        log("[relational_expression:] relational_expression <,>,<=,>= additive_expression (line: %i)\n", (int)ctx->line());
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

  case 37: // equality_expression: relational_expression
#line 507 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[equality_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1638 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 38: // equality_expression: equality_expression "== or !=" relational_expression
#line 511 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        {
        log("[equality_expression:] equality_expression ==,!= relational_expression (line: %i)\n", (int)ctx->line());
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

  case 39: // logical_and_expression: equality_expression
#line 526 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[logical_and_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1663 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 40: // logical_and_expression: logical_and_expression "&&" equality_expression
#line 530 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                          {
        log("[logical_and_expression:] logical_and_expression && equality_expression (line: %i)\n", (int)ctx->line());
        // $$ = $1;
    }
#line 1672 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 41: // logical_or_expression: logical_and_expression
#line 537 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                               {
        // log("[logical_or_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1681 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 42: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 541 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                 {
        log("[logical_or_expression:] logical_or_expression || logical_and_expression (line: %i)\n", (int)ctx->line());
        // $$ = $1;
    }
#line 1690 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 43: // assignment_expression: logical_or_expression
#line 548 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log(std::string("")+"[assignment_expression:]{"+(yystack_[0].value.as < casem::InstructionWrapper > ()).name+"}>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1699 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 44: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 552 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                    {
        log("[assignment_expression:] unary_expression assignment_operator assignment_expression (line: %i)", (int)ctx->line());
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
        log(std::string("")+" = "+(yystack_[2].value.as < casem::InstructionWrapper > ()).name+"\n");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[2].value.as < casem::InstructionWrapper > ();
    }
#line 1729 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 45: // assignment_operator: "="
#line 580 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
          {
        yylhs.value.as < cecko::gt_cass > () = (cecko::gt_cass)1000;
    }
#line 1737 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 46: // match_head: "match" assignment_expression "->" declaration_specifiers
#line 586 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                              {
        log(std::string("")+"[match_head:] MATCH IDF{"+(yystack_[2].value.as < casem::InstructionWrapper > ()).name+"} ARROW declaration_specifiers "+std::to_string(ctx->line())+"\n");
        yylhs.value.as < casem::MatchWrapper > () = init_match_head(ctx, yystack_[3].value.as < cecko::match_type > (), yystack_[2].value.as < casem::InstructionWrapper > (), yystack_[0].value.as < casem::CKTypeRefDefPack > ());
    }
#line 1746 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 47: // match_expression: assignment_expression
#line 593 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1754 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 48: // match_expression: match_binders_list block_end
#line 596 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                      {
        log("[match_expression:] MATCH IDF ARROW declaration_specifiers block_start match_binders_list block_end (line: %i)\n", (int)ctx->line());
        casem::MatchWrapper match_data = yystack_[1].value.as < casem::MatchWrapper > ();
        log("[match_expression:] if (match_data.is_first_pattern_null_check)\n");
        if (match_data.is_first_pattern_null_check) {
            // FIXME: implement first pattern null check if-else block
            log("[match_expression:] first pattern is null check. Finishing if-else block\n");
            auto &null_pattern_if_data = (*match_data.first_pattern_null_check_data).if_data; 
            null_pattern_if_data.else_block_back = ctx->builder()->GetInsertBlock();
            exit_block(ctx);
            // log("SWITCHING to null pattern continue_block\n");
            ctx->builder()->SetInsertPoint(null_pattern_if_data.continue_block);
            // log("[match_expression:] making null check pattern control flow\n");
            create_if_control_flow(ctx, null_pattern_if_data);
        }
        log("[match_expression:] if (match_data.is_first_pattern_null_check) Done\n");
        match_data.generate_final_match_result_check(ctx); // generates final if that check if result isn't tagged type set to null
        auto fip_state = casem::FipState::GetFipState();
        if (match_data.is_destructive) {
            log("{FipState} match_expression - exiting DMATCH\n");
            fip_state->exit_fip_mode();
            fip_state->exit_fip_context();
        }

        // auto&& res = init_instruction_from_name(ctx, casem::match_result_template);
        yylhs.value.as < casem::InstructionWrapper > () = match_data.result;
    }
#line 1786 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 49: // match_binders_list: match_binders_list_head_start expression_body
#line 626 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                   {
        log("[match_binders_list:] match_binders_list_head_start expression_body (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::MatchWrapper > () = init_match_binders_list(ctx, yystack_[1].value.as < casem::MatchBinderListHeadData > (), yystack_[0].value.as < casem::InstructionWrapper > ());
    }
#line 1795 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 50: // match_binders_list: match_binders_list_head expression_body
#line 630 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                               {
        log("[match_binders_list:] match_binders_list_head expression_body (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::MatchWrapper > () = init_match_binders_list(ctx, yystack_[1].value.as < casem::MatchBinderListHeadData > (), yystack_[0].value.as < casem::InstructionWrapper > ());
    }
#line 1804 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 51: // match_binders_list_head_start: match_head block_start match_binder_head
#line 637 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                             {
        log("[match_binders_list_head_start:] match_head block_start match_binder_head (line: %i)\n", (int)ctx->line());
        log(std::string("")+"[match_binders_list_head_start:] the checked label is "+(yystack_[0].value.as < casem::MatchBinderChackerData > ()).type_label+" which null ttype is "+std::to_string(casem::is_null_ttype((yystack_[0].value.as < casem::MatchBinderChackerData > ()).type_label))+"\n");
        yylhs.value.as < casem::MatchBinderListHeadData > () = MatchBinderListHeadData::init_match_binders_list_head(ctx, yystack_[2].value.as < casem::MatchWrapper > (), yystack_[0].value.as < casem::MatchBinderChackerData > (), casem::is_null_ttype((yystack_[0].value.as < casem::MatchBinderChackerData > ()).type_label));
    }
#line 1814 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 52: // match_binders_list_head: match_binders_list match_binder_head
#line 645 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                         {
        log("[match_binders_list_head:] match_binders_list match_binder_head (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::MatchBinderListHeadData > () = MatchBinderListHeadData::init_match_binders_list_head(ctx, yystack_[1].value.as < casem::MatchWrapper > (), yystack_[0].value.as < casem::MatchBinderChackerData > ());
    }
#line 1823 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 53: // match_binder_head: "|" match_binder_definer "->"
#line 652 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                        {
        log(std::string("")+"[match_binder_head:] VERT match_binder_definer{"+(yystack_[1].value.as < casem::MatchBinderChackerData > ()).type_label+"} ARROW (line: "+std::to_string(ctx->line())+")\n");
        yylhs.value.as < casem::MatchBinderChackerData > () = yystack_[1].value.as < casem::MatchBinderChackerData > ();
    }
#line 1832 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 54: // match_binder_definer: "identifier" "(" match_binder_arguments_list ")"
#line 659 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                {
        log("[match_binder_definer:] IDF LPAR match_binder_arguments_list RPAR (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::MatchBinderChackerData > () = casem::MatchBinderChackerData(yystack_[3].value.as < cecko::CIName > ()).set_args(ctx, yystack_[1].value.as < std::vector<cecko::CIName> > ());
    }
#line 1841 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 55: // match_binder_definer: "identifier"
#line 663 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
            {
        log("[match_binder_definer:] IDF (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::MatchBinderChackerData > () = casem::MatchBinderChackerData(yystack_[0].value.as < cecko::CIName > ());
    }
#line 1850 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 56: // match_binder_arguments_list: "identifier"
#line 670 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
           { // FIXME: switch for `match_binder_definer`
        log("[match_binder_arguments_list:] IDF (line: %i)\n", (int)ctx->line());
        yylhs.value.as < std::vector<cecko::CIName> > () = { yystack_[0].value.as < cecko::CIName > () };
    }
#line 1859 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 57: // match_binder_arguments_list: match_binder_arguments_list "," "identifier"
#line 674 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                            {
        log("[match_binder_arguments_list:] match_binder_arguments_list COMMA IDF (line: %i)\n", (int)ctx->line());
        (yystack_[2].value.as < std::vector<cecko::CIName> > ()).push_back(yystack_[0].value.as < cecko::CIName > ());
        yylhs.value.as < std::vector<cecko::CIName> > () = yystack_[2].value.as < std::vector<cecko::CIName> > ();
    }
#line 1869 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 58: // expression_body: match_expression
#line 682 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                      {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1877 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 59: // expression_body: flow_expression
#line 685 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                      {
        yylhs.value.as < casem::InstructionWrapper > () = (yystack_[0].value.as < casem::IfExpressionData > ()).result;
    }
#line 1885 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 60: // expression: expression_body expression_end
#line 691 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                   {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[1].value.as < casem::InstructionWrapper > ();
    }
#line 1893 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 61: // declaration_specifiers: declaration_specifier
#line 701 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            { 
            log("[declaration_specifiers:] ^ simply give refpack from declaration_specifier to the list (line: %i)\n", (int)ctx->line());
            yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        }
#line 1902 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 62: // declaration_specifiers: declaration_specifier declaration_specifiers
#line 705 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                    {
            log("[declaration_specifiers:] take the list and update its info by the new element (line: %i)\n", (int)ctx->line());
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
#line 1930 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 63: // declaration_specifier: type_specifier_qualifier
#line 731 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1956 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 64: // declaration_specifier: "fip"
#line 752 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
            {
        log("[declaration_specifier:] Found FIP (line: %i)\n", (int)ctx->line());
        casem::CKTypeRefDefPack rfpack;
        rfpack.is_fip = true;
        yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
    }
#line 1967 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 65: // type_specifier: "_Bool, char, or int"
#line 761 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
          { 
        log("[type_specifier:] ^ Found ETYPE '"); 
        switch (yystack_[0].value.as < cecko::gt_etype > ()) {
            case cecko::gt_etype::INT:
                log("INT' (line: %i)\n", (int)ctx->line());
                yylhs.value.as < cecko::CKTypeSafeObs > () = ctx->get_int_type();
                break;
            case cecko::gt_etype::CHAR:
                log("CHAR' (line: %i)\n", (int)ctx->line());
                yylhs.value.as < cecko::CKTypeSafeObs > () = ctx->get_char_type();
                break;
            case cecko::gt_etype::BOOL:
                log("BOOL' (line: %i)\n", (int)ctx->line());
                yylhs.value.as < cecko::CKTypeSafeObs > () = ctx->get_bool_type();
                break;
        }
     }
#line 1989 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 66: // type_specifier: declared_type_name
#line 778 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2004 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 67: // type_specifier: typedef_name
#line 788 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
            log("[type_specifier:] ^ found typedef_name '%s' (line: %i)\n", (yystack_[0].value.as < cecko::CIName > ()).c_str(), (int)ctx->line());
            auto type_def_data = ctx->find_typedef(yystack_[0].value.as < cecko::CIName > ());
            if (type_def_data) {
                yylhs.value.as < cecko::CKTypeSafeObs > () = type_def_data->get_type_pack().type;
            }
            else {
                std::string e_msg = "Undefined type '" + yystack_[0].value.as < cecko::CIName > () + "'!\n";
                ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
            }
        }
#line 2020 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 68: // declared_type_name: "type" "identifier"
#line 802 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        log_name("[declared_type_name:] TYPEDEF IDF", yystack_[0].value.as < cecko::CIName > ());
        yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > ();
    }
#line 2029 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 69: // enumtype_decl_head: "type" "identifier"
#line 809 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        casem::declare_support_functions(ctx);
        yylhs.value.as < casem::TaggedTypeDecl > () = declare_parent_ttype(ctx, yystack_[0].value.as < cecko::CIName > ());
    }
#line 2038 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 74: // enumtype_decl_specifier: enumtype_decl_head block_start member_types_declaration_list block_end new_lines
#line 826 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                                      {
        log("[enumtype_decl_specifier:] enumtype_decl_head block_start member_types_declaration_list block_end new_lines (line: %i)\n", (int)ctx->line());
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = TaggedTypeDecl::finish_parent_ttype(ctx, yystack_[4].value.as < casem::TaggedTypeDecl > ());
    }
#line 2047 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 75: // member_types_declaration_list: member_types_declaration
#line 833 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                 {
        log("[member_types_declaration_list:] member_types_declaration (line: %i)\n", (int)ctx->line());
        StructObservers vec = { yystack_[0].value.as < cecko::CKStructTypeSafeObs > () };
        yylhs.value.as < casem::StructObservers > () = vec;
    }
#line 2057 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 76: // member_types_declaration_list: member_types_declaration_list member_types_declaration
#line 838 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                  {
        log("[member_types_declaration_list:] member_types_declaration_list member_types_declaration (line: %i)\n", (int)ctx->line());
        auto&& vec = yystack_[1].value.as < casem::StructObservers > (); 
        vec.push_back(yystack_[0].value.as < cecko::CKStructTypeSafeObs > ());
        yylhs.value.as < casem::StructObservers > () = vec;
    }
#line 2068 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 77: // member_types_declaration: "identifier" "(" member_declaration_list ")" ";"
#line 847 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                    {
        log_name("[member_types_declaration:] includes member_declaration_list", yystack_[4].value.as < cecko::CIName > ());
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = casem::declare_child_ttype(ctx, yystack_[4].value.as < cecko::CIName > (), yystack_[2].value.as < cecko::CKStructItemArray > ());
    }
#line 2077 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 78: // member_types_declaration: "identifier" ";"
#line 851 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                   {
        log_name("[member_types_declaration:] found IDF SEMIC", yystack_[1].value.as < cecko::CIName > ());
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = casem::declare_child_ttype(ctx, yystack_[1].value.as < cecko::CIName > ());
    }
#line 2086 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 79: // member_declaration_list: member_declaration
#line 858 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log("[member_declaration_list:] member_declaration (line: %i)\n", (int)ctx->line());
        yylhs.value.as < cecko::CKStructItemArray > () = yystack_[0].value.as < cecko::CKStructItemArray > ();
    }
#line 2095 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 80: // member_declaration_list: member_declaration_list "," member_declaration
#line 862 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                          {
        log("[member_declaration_list:] member_declaration_list COMMA member_declaration (line: %i)\n", (int)ctx->line());
        cecko::CKStructItemArray s_items = yystack_[2].value.as < cecko::CKStructItemArray > ();
        s_items.push_back(yystack_[0].value.as < cecko::CKStructItemArray > ()[0]);
        yylhs.value.as < cecko::CKStructItemArray > () = s_items;
    }
#line 2106 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 81: // member_declaration: specifier_qualifier_list member_declarator
#line 871 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                 { 
        log("[member_declaration:] give refpack to member_declarator_list (line: %i)\n", (int)ctx->line());
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[1].value.as < casem::CKTypeRefDefPack > ();

        casem::CKTypeRefDefPack final_type = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));
        cecko::CKStructItem s_item(final_type, final_type.name.value(), ctx->line());

        cecko::CKStructItemArray s_items = { s_item };
        yylhs.value.as < cecko::CKStructItemArray > () = s_items;
     }
#line 2122 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 82: // specifier_qualifier_list: type_specifier_qualifier
#line 885 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                { 
        log("[specifier_qualifier_list:] ^ type_specifier_qualifier (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
     }
#line 2131 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 83: // specifier_qualifier_list: type_specifier_qualifier specifier_qualifier_list
#line 889 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        { 
        log("[specifier_qualifier_list:] ^ type_specifier_qualifier specifier_qualifier_list (line: %i)\n", (int)ctx->line());
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
#line 2152 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 84: // type_specifier_qualifier: type_specifier
#line 908 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    { 
            log("[type_specifier_qualifier:] ^ Found type_specifier (line: %i)\n", (int)ctx->line()); 
            casem::CKTypeRefDefPack t(yystack_[0].value.as < cecko::CKTypeSafeObs > (), false, false, false);
            yylhs.value.as < casem::CKTypeRefDefPack > () = t;
        }
#line 2162 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 85: // member_declarator: declarator
#line 916 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2170 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 86: // declarator: pointer direct_declarator
#line 922 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                              {
        log("[declarator:] >v found pointer direct_declarator define LAMBDA (line: %i)\n", (int)ctx->line());
        auto DEFINER_F = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        auto POINTER_F = yystack_[1].value.as < casem::TypeRefPack_Convertor > ();

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_POINTER_ADDER(POINTER_F, DEFINER_F);
    }
#line 2182 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 87: // declarator: direct_declarator
#line 929 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
        log("[declarator:] v found direct_declarator, gave refpack to it (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();    // giving the casem::CKTypeRefDefPack(type, is_const, has_typedef)
    }
#line 2191 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 88: // pointer: "*" pointer
#line 936 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2207 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 89: // pointer: "*"
#line 947 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                {
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            POINTER_TO_DEFINER = [this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, false, rfpack.has_typedef, rfpack.is_fip);
                return pointer_pack;
            };

        yylhs.value.as < casem::TypeRefPack_Convertor > () = POINTER_TO_DEFINER;
    }
#line 2222 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 90: // direct_declarator: "identifier"
#line 960 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
        { 
        auto name = yystack_[0].value.as < cecko::CIName > ();
        log_name("[direct_declarator:] .() found IDF and define LAMBDA", name);

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_DEFINER(ctx, name);
    }
#line 2233 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 91: // direct_declarator: function_declarator
#line 966 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log("[direct_declarator:] v found function_declarator (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2242 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 92: // function_declarator: direct_declarator "[" parameter_type_list "]"
#line 973 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                     {
        log("[function_declarator:] direct_declarator LBRA parameter_type_list RBRA -- v< wrap current lambdas rfpack in function (line: %i)\n", (int)ctx->line());
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
#line 2267 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 93: // parameter_type_list: parameter_list
#line 996 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                   {
        log("[parameter_type_list:] ^ parameter_list (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::TRDArray > () = yystack_[0].value.as < casem::TRDArray > ();
    }
#line 2276 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 94: // parameter_type_list: %empty
#line 1000 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                  {
        std::vector<casem::CKTypeRefDefPack> empty_param_array;
        yylhs.value.as < casem::TRDArray > () = empty_param_array;
    }
#line 2285 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 95: // parameter_list: parameter_declaration
#line 1007 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log("[parameter_list:] ^ init parameter_list (line: %i)\n", (int)ctx->line());
        if ((yystack_[0].value.as < casem::CKTypeRefDefPack > ()).type->is_void()) {
            std::vector<casem::CKTypeRefDefPack> empty_param_array;
            yylhs.value.as < casem::TRDArray > () = empty_param_array;
        }
        else {
            std::vector<casem::CKTypeRefDefPack> param_array = { yystack_[0].value.as < casem::CKTypeRefDefPack > () };
            yylhs.value.as < casem::TRDArray > () = param_array;
        }
    }
#line 2301 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 96: // parameter_list: parameter_list "," parameter_declaration
#line 1018 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                 {
        log("[parameter_list:] ^ push_back to parameter_list (line: %i)\n", (int)ctx->line());
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
#line 2324 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 97: // parameter_declaration: declaration_specifiers declarator
#line 1039 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                        { 
        // FIXME: Send also the cecko::CKFunctionFormalPackArray to the function_definition 
        // and from it to declarator and up

        log("[parameter_declaration:] ^ found declaration_specifiers declarator, sent up the type observer (line: %i)\n", (int)ctx->line());
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[1].value.as < casem::CKTypeRefDefPack > ();

        // TODO: Add the param name to the rfpack.optinonal_param_names
        // We give declarator a definer, that just adds to the 
        // rfpack.optinonal_param_names the name and returs the rfpack back 
        DefinerFunction PARAM_NAME_ADDER([](cecko::context *ctx, const cecko::CIName &name, CKTypeRefDefPack &rfpack) {
            log("lambda from [parameter_declaration:] add named param to rfpack.optinonal_param_names and return it (line: %i)\n", (int)ctx->line());
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
#line 2355 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 98: // parameter_declaration: declaration_specifiers
#line 1065 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                    {
        log("[parameter_declaration:] ^ found declaration_specifiers (line: %i)\n", (int)ctx->line());
        casem::CKTypeRefDefPack rfpack = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
    }
#line 2365 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 99: // typedef_name: "type identifier"
#line 1073 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > (); }
#line 2371 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 100: // expression_statement: match_expression ";"
#line 1082 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                              {
        log("[expression_statement:] expression_opt SEMIC (line: %i)\n", (int)ctx->line());
        IfExpressionData res;
        res.result = yystack_[1].value.as < casem::InstructionWrapper > ();
        res.block = ctx->builder()->GetInsertBlock();

        yylhs.value.as < casem::IfExpressionData > () = res;
    }
#line 2384 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 101: // if_expression_head: "if" "(" expression_body ")"
#line 1095 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                     {
        log(std::string("")+"[if_expression_head:] IF LPAR expression{"+(yystack_[1].value.as < casem::InstructionWrapper > ()).name+"} RPAR ("+std::to_string(ctx->line())+")\n");
        yylhs.value.as < casem::IfExpressionData > () = IfExpressionData::init_if_head(ctx, yystack_[1].value.as < casem::InstructionWrapper > ());
    }
#line 2393 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 102: // if_non_split_expression: if_expression_head non_split_expression
#line 1102 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                              {
        log("[if_non_split_expression:] if_expression_head non_split_statement (line: %i)\n", (int)ctx->line());
        auto &&expression_data = yystack_[1].value.as < casem::IfExpressionData > ();
        auto &data = expression_data.if_data;
        data.if_block_back = ctx->builder()->GetInsertBlock();
        expression_data.store_to_result(ctx, yystack_[0].value.as < casem::IfExpressionData > ());
        casem::exit_block(ctx);
        yylhs.value.as < casem::IfExpressionData > () = expression_data;
    }
#line 2407 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 103: // if_non_split_expression_else: if_non_split_expression "else"
#line 1114 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                   {
        log("[if_non_split_expression_else:] if_non_split_expression ELSE: (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::IfExpressionData > () = IfExpressionData::init_if_else_head(ctx, yystack_[1].value.as < casem::IfExpressionData > ());
    }
#line 2416 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 104: // flow_expression: non_split_expression
#line 1121 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
    { yylhs.value.as < casem::IfExpressionData > () = yystack_[0].value.as < casem::IfExpressionData > (); }
#line 2422 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 105: // flow_expression: split_expression
#line 1122 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
      { yylhs.value.as < casem::IfExpressionData > () = yystack_[0].value.as < casem::IfExpressionData > (); }
#line 2428 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 106: // non_split_expression: if_non_split_expression_else non_split_expression
#line 1126 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                         {
        log("[non_split_expression:] if_non_split_expression_else non_split_expression:  (line: %i)\n", (int)ctx->line());
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
#line 2446 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 107: // non_split_expression: expression_statement
#line 1139 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                              {
        log("[non_split_statement:] expression_statement (line: %i)\n", (int)ctx->line());
        yylhs.value.as < casem::IfExpressionData > () = yystack_[0].value.as < casem::IfExpressionData > ();
    }
#line 2455 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 108: // split_expression: if_expression_head expression_body
#line 1146 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                           {
        log("[split_statement:] if_statement_head statement (line: %i)\n", (int)ctx->line());
        auto &&expression_data = yystack_[1].value.as < casem::IfExpressionData > ();
        auto &data = expression_data.if_data;
        expression_data.store_to_result(ctx, yystack_[0].value.as < casem::InstructionWrapper > ());
        data.if_block_back = ctx->builder()->GetInsertBlock();
        exit_block(ctx);
        ctx->builder()->SetInsertPoint(data.continue_block);
        
        expression_data.block = create_if_control_flow(ctx, data);
        yylhs.value.as < casem::IfExpressionData > () = expression_data;
     }
#line 2472 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 109: // split_expression: if_non_split_expression_else split_expression
#line 1158 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        {
        log("[split_statement:] if_non_split_statement_else split_statement (line: %i)\n", (int)ctx->line());
        auto &&expression_data = yystack_[1].value.as < casem::IfExpressionData > ();
        auto &data = expression_data.if_data;
        expression_data.store_to_result(ctx, yystack_[0].value.as < casem::IfExpressionData > ());
        data.else_block_back = ctx->builder()->GetInsertBlock();
        exit_block(ctx);
        ctx->builder()->SetInsertPoint(data.continue_block);
         
        expression_data.block = create_if_control_flow(ctx, data);
        yylhs.value.as < casem::IfExpressionData > () = expression_data;
     }
#line 2489 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;


#line 2493 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"

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


  const signed char parser::yypact_ninf_ = -126;

  const signed char parser::yytable_ninf_ = -103;

  const signed char
  parser::yypact_[] =
  {
      49,   -21,  -126,  -126,  -126,     5,  -126,  -126,    18,     7,
      -8,    51,  -126,  -126,    25,  -126,  -126,  -126,    43,  -126,
    -126,  -126,    47,     7,  -126,  -126,  -126,  -126,    59,    65,
      74,  -126,  -126,  -126,  -126,    69,    59,  -126,    -2,    79,
      82,    76,    81,    83,  -126,    25,    80,    39,     7,     7,
      47,  -126,  -126,     7,    66,     7,  -126,  -126,  -126,    92,
    -126,  -126,    70,   103,  -126,    72,  -126,   101,    78,  -126,
    -126,   102,  -126,   104,   107,     7,    59,  -126,    59,  -126,
    -126,    59,    59,    59,    59,    59,    59,    59,   100,  -126,
      84,  -126,    19,  -126,  -126,  -126,  -126,  -126,  -126,    86,
    -126,    80,  -126,  -126,  -126,   103,    51,  -126,   102,     3,
      -1,  -126,  -126,  -126,    51,   106,     9,  -126,  -126,  -126,
    -126,    -2,    79,    82,    76,    81,  -126,   111,   109,  -126,
      -8,   114,   112,  -126,    42,  -126,   101,  -126,  -126,  -126,
    -126,    59,    87,  -126,  -126,  -126,    51,    75,  -126,    -8,
      42,   102,  -126,  -126,    77,  -126,   105,    42,  -126,  -126,
    -126,  -126,    88,  -126,  -126,  -126
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,    65,    64,    99,     0,     2,     4,     0,     0,
       0,    61,    84,    66,     0,     5,    63,    67,    68,     1,
       3,    13,     0,     0,    25,    26,    27,    28,     0,     0,
      19,    14,    15,    17,    23,    29,     0,    30,    33,    35,
      37,    39,    41,    43,    47,     0,    58,     0,     0,     0,
       0,    10,   107,     0,     0,     0,    59,   104,   105,    89,
      90,    12,     0,    87,    91,     0,    62,    70,     0,     9,
       6,     8,    11,     0,     0,     0,    22,    45,     0,    29,
      24,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,    72,     0,    52,    48,    49,    50,    60,   108,   104,
     103,     0,   106,   109,    88,    86,    94,    68,    71,     0,
       0,    75,     7,    16,     0,     0,     0,    20,    44,    31,
      32,    34,    36,    38,    40,    42,    51,    55,     0,    73,
      98,     0,    93,    95,     0,    78,     0,    76,    46,   101,
      18,     0,     0,    53,    97,    92,     0,     0,    79,     0,
      82,    74,    21,    56,     0,    96,     0,     0,    81,    85,
      83,    54,     0,    77,    80,    57
  };

  const signed char
  parser::yypgoto_[] =
  {
    -126,  -126,   119,   -45,    89,  -126,  -126,  -126,  -126,  -126,
    -126,   -25,  -126,   -29,    44,    41,    45,    46,    50,  -126,
     -27,  -126,  -126,    73,  -126,  -126,  -126,    48,  -126,  -126,
     -20,  -126,   -11,  -126,  -126,  -126,  -126,    93,    21,  -126,
    -126,    23,  -126,   -28,   -16,  -125,  -126,  -114,    85,    90,
    -126,  -126,  -126,    -6,  -126,  -126,  -126,  -126,  -126,  -126,
      35,    91
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     5,     6,    71,    72,     7,     8,     9,    33,    34,
     116,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    78,    45,    46,    47,    48,    49,    93,   128,   154,
      50,    51,    10,    11,    12,    13,    14,    68,    94,    15,
     110,   111,   147,   148,   149,    16,   158,    61,    62,    63,
      64,   131,   132,   133,    17,    52,    53,    54,    55,    56,
      57,    58
  };

  const short
  parser::yytable_[] =
  {
      66,    74,    92,    73,    59,    19,    70,    80,   134,   150,
      81,    79,    23,    82,    18,   140,   144,    24,   141,    25,
      26,    27,   108,    91,   135,   150,   112,    60,    95,    96,
       1,     2,   150,    98,   109,   159,     3,    28,    21,    22,
      29,     4,    30,   129,    31,    32,    70,    69,    67,   117,
      90,   118,   119,   120,    70,   115,    79,    79,    79,    79,
      79,    79,    79,    91,    23,    92,   -69,    65,     2,    24,
      75,    25,    26,    27,     1,     2,    65,     2,     4,    76,
       3,   156,     3,   161,   157,     4,   162,     4,    99,    77,
     102,   151,    83,    85,    30,   130,    31,    32,    84,    86,
     100,    89,    87,   138,    59,    60,   106,   107,    70,   112,
     113,    90,   139,   109,   152,   114,   142,   143,   145,   127,
    -102,   146,   153,   165,    20,   122,   163,   121,   101,   164,
     123,   136,   124,   137,   160,   130,   126,   125,    88,    97,
     155,     0,     0,     0,   104,     0,   103,     0,     0,     0,
       0,     0,   105
  };

  const short
  parser::yycheck_[] =
  {
      11,    28,    47,    23,    12,     0,     7,    36,     5,   134,
      12,    36,     5,    15,    35,     6,   130,    10,     9,    12,
      13,    14,    67,    24,    21,   150,     7,    35,    48,    49,
      25,    26,   157,    53,    35,   149,    31,    30,    20,    21,
      33,    36,    35,    24,    37,    38,     7,     0,    23,    76,
      11,    78,    81,    82,     7,    75,    81,    82,    83,    84,
      85,    86,    87,    24,     5,   110,    23,    25,    26,    10,
       5,    12,    13,    14,    25,    26,    25,    26,    36,     5,
      31,     6,    31,     6,     9,    36,     9,    36,    53,    20,
      55,   136,    13,    17,    35,   106,    37,    38,    16,    18,
      34,    21,    19,   114,    12,    35,     3,    35,     7,     7,
       6,    11,     6,    35,   141,     8,     5,     8,     4,    35,
      34,     9,    35,    35,     5,    84,    21,    83,    55,   157,
      85,   110,    86,   110,   150,   146,    88,    87,    45,    50,
     146,    -1,    -1,    -1,    59,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    62
  };

  const signed char
  parser::yystos_[] =
  {
       0,    25,    26,    31,    36,    40,    41,    44,    45,    46,
      71,    72,    73,    74,    75,    78,    84,    93,    35,     0,
      41,    20,    21,     5,    10,    12,    13,    14,    30,    33,
      35,    37,    38,    47,    48,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    61,    62,    63,    64,    65,
      69,    70,    94,    95,    96,    97,    98,    99,   100,    12,
      35,    86,    87,    88,    89,    25,    71,    23,    76,     0,
       7,    42,    43,    69,    59,     5,     5,    20,    60,    50,
      52,    12,    15,    13,    16,    17,    18,    19,    76,    21,
      11,    24,    42,    66,    77,    69,    69,    43,    69,    99,
      34,    62,    99,   100,    87,    88,     3,    35,    42,    35,
      79,    80,     7,     6,     8,    69,    49,    59,    59,    52,
      52,    53,    54,    55,    56,    57,    66,    35,    67,    24,
      71,    90,    91,    92,     5,    21,    77,    80,    71,     6,
       6,     9,     5,     8,    86,     4,     9,    81,    82,    83,
      84,    42,    59,    35,    68,    92,     6,     9,    85,    86,
      83,     6,     9,    21,    82,    35
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    39,    40,    40,    41,    41,    42,    42,    43,    43,
      44,    44,    45,    46,    47,    47,    47,    48,    48,    48,
      49,    49,    49,    50,    50,    51,    51,    51,    51,    52,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    61,    62,    62,    63,
      63,    64,    65,    66,    67,    67,    68,    68,    69,    69,
      70,    71,    71,    72,    72,    73,    73,    73,    74,    75,
      76,    76,    77,    77,    78,    79,    79,    80,    80,    81,
      81,    82,    83,    83,    84,    85,    86,    86,    87,    87,
      88,    88,    89,    90,    90,    91,    91,    92,    92,    93,
      94,    95,    96,    97,    98,    98,    99,    99,   100,   100
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     2,     1,     1,
       2,     3,     2,     2,     1,     1,     3,     1,     4,     1,
       1,     3,     0,     1,     2,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     4,     1,     2,     2,
       2,     3,     2,     3,     4,     1,     1,     3,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     1,     2,     5,     1,     2,     5,     2,     1,
       3,     2,     1,     2,     1,     1,     2,     1,     2,     1,
       1,     1,     4,     1,     0,     1,     3,     2,     1,     1,
       2,     4,     2,     2,     1,     1,     2,     1,     2,     2
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
  "external_declaration", "new_lines", "expression_end",
  "function_definition", "function_definition_info",
  "function_definition_head", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
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
       0,   198,   198,   199,   203,   204,   211,   212,   216,   217,
     221,   262,   268,   293,   326,   331,   336,   342,   345,   349,
     375,   379,   384,   391,   395,   418,   419,   420,   430,   434,
     441,   445,   449,   463,   467,   481,   485,   507,   511,   526,
     530,   537,   541,   548,   552,   580,   586,   593,   596,   626,
     630,   637,   645,   652,   659,   663,   670,   674,   682,   685,
     691,   701,   705,   731,   752,   761,   778,   788,   802,   809,
     816,   817,   821,   822,   826,   833,   838,   847,   851,   858,
     862,   871,   885,   889,   908,   916,   922,   929,   936,   947,
     960,   966,   973,   996,  1000,  1007,  1018,  1039,  1065,  1073,
    1082,  1095,  1102,  1114,  1121,  1122,  1126,  1139,  1146,  1158
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
#line 3101 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"

#line 1175 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"


namespace cecko {

	void parser::error(const location_type& l, const std::string& m)
	{
		ctx->message(cecko::errors::SYNTAX, l, m);
	}
}
