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
#line 34 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"

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
      case symbol_kind::S_enumeration_constant: // enumeration_constant
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
      case symbol_kind::S_enumeration_constant: // enumeration_constant
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
      case symbol_kind::S_enumeration_constant: // enumeration_constant
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
      case symbol_kind::S_enumeration_constant: // enumeration_constant
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
      case symbol_kind::S_enumeration_constant: // enumeration_constant
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
#line 209 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                 {
        log("[declaration:] found enumtype_decl_specifier\n");
        // $$ = $1;
    }
#line 1200 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 8: // function_definition: function_definition_head expression
#line 221 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                         {
        log("[function_definition:] with BODY, if not returned explicitely, we void return here\n");

        log("jump_statement: ");
        // auto ret_obs = static_cast<cecko::CKIRConstantIntObs>($2);
        auto ret_obs = yystack_[0].value.as < casem::InstructionWrapper > ();
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
        // $$ = ctx->builder()->GetInsertBlock();

        if (! ctx->builder()->GetInsertBlock() || ctx->current_function_return_type()->is_void()) {
            ctx->builder()-> CreateRetVoid();
        }

        ctx->exit_function();
    }
#line 1231 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 9: // function_definition_info: declaration_specifiers declarator
#line 255 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                        {
        log("[function_definition_info:]\n");
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

        cecko::CKFunctionSafeObs f_observer = ctx->declare_function(res_tpack.name.value(), res_tpack.type, cur_l);
        log("[function_definition_info:] function declared\n");

        ctx->enter_function(f_observer, res_tpack.optinonal_param_names, ctx->line());
        log("[function_definition_info:] function body entered\n");
    }
#line 1257 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 10: // function_definition_head: function_definition_info "="
#line 279 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                  {
        log("[function_definition_head:]");
    }
#line 1265 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 11: // primary_expression: enumeration_constant
#line 299 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log("[primary_expression:] name\n");
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_from_name(ctx, yystack_[0].value.as < cecko::CIName > ());
    }
#line 1274 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 12: // primary_expression: "integer literal"
#line 303 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                {
        //CKIRConstantIntObs
        log("[primary_expression:] Found int lit '%d'\n", (int)yystack_[0].value.as < int > ());
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_const(ctx, yystack_[0].value.as < int > ());
    }
#line 1284 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 13: // primary_expression: "string literal"
#line 308 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                {
        log_name("[primary_expression:] Found string lit ", yystack_[0].value.as < cecko::CIName > ());
        // (StringRef Str, const Twine &Name = "", unsigned AddressSpace = 0, Module *M = nullptr, bool AddNull = true)	
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_const(ctx, yystack_[0].value.as < cecko::CIName > ());
    }
#line 1294 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 14: // primary_expression: "(" expression ")"
#line 313 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[1].value.as < casem::InstructionWrapper > ();
    }
#line 1302 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 15: // postfix_expression: primary_expression
#line 319 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                           {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1310 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 16: // postfix_expression: "identifier" "(" argument_expression_list ")"
#line 324 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                 {
        log("[postfix_expression:] FUNCTION CALL, postfix_expression ( expression )\n");
        
        if (casem::is_struct_label(ctx, yystack_[3].value.as < cecko::CIName > ())) {
            auto&& constructor_name = get_constructor_label(yystack_[3].value.as < cecko::CIName > ());
            yylhs.value.as < casem::InstructionWrapper > () = init_instruction_function_call(ctx, init_instruction_from_name(ctx, constructor_name), yystack_[1].value.as < casem::InstructionArray > ());
        }
        else {
            yylhs.value.as < casem::InstructionWrapper > () = init_instruction_function_call(ctx, init_instruction_from_name(ctx, yystack_[3].value.as < cecko::CIName > ()), yystack_[1].value.as < casem::InstructionArray > ());
        }
    }
#line 1326 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 17: // argument_expression_list: assignment_expression
#line 350 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        casem::InstructionArray args = { yystack_[0].value.as < casem::InstructionWrapper > () };
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1335 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 18: // argument_expression_list: assignment_expression "," argument_expression_list
#line 354 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                            {
        auto &args = yystack_[0].value.as < casem::InstructionArray > ();
        args.push_back(yystack_[2].value.as < casem::InstructionWrapper > ());
        yylhs.value.as < casem::InstructionArray > () = args;
    }
#line 1345 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 19: // unary_expression: postfix_expression
#line 362 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
        log("[unary_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1354 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 20: // unary_expression: unary_operator cast_expression
#line 366 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1379 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 21: // unary_operator: "&"
#line 399 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = AMPERSANT; }
#line 1385 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 22: // unary_operator: "*"
#line 400 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = STAR; }
#line 1391 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 23: // unary_operator: "+ or -"
#line 401 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1406 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 24: // unary_operator: "!"
#line 411 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = EXCALMATION_MARK; }
#line 1412 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 25: // cast_expression: unary_expression
#line 415 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[cast_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1421 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 26: // multiplicative_expression: cast_expression
#line 422 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
        // log("[multiplicative_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1430 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 27: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 426 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        {
        log("[multiplicative_expression:] multiplicative_expression * cast_expression\n");
        yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) * (yystack_[0].value.as < casem::InstructionWrapper > ());
    }
#line 1439 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 28: // multiplicative_expression: multiplicative_expression "/ or %" cast_expression
#line 430 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1455 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 29: // additive_expression: multiplicative_expression
#line 444 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                {
        // log("[multiplicative_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1464 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 30: // additive_expression: additive_expression "+ or -" multiplicative_expression
#line 448 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1480 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 31: // relational_expression: additive_expression
#line 462 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[relational_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1489 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 32: // relational_expression: relational_expression "<, >, <=, or >=" additive_expression
#line 466 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                         {
        log("[relational_expression:] relational_expression <,>,<=,>= additive_expression\n");
        // $$ = $1;
    }
#line 1498 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 33: // equality_expression: relational_expression
#line 473 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[equality_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1507 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 34: // equality_expression: equality_expression "== or !=" relational_expression
#line 477 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        {
        log("[equality_expression:] equality_expression ==,!= relational_expression\n");
        // $$ = $1;
    }
#line 1516 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 35: // logical_and_expression: equality_expression
#line 485 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[logical_and_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1525 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 36: // logical_and_expression: logical_and_expression "&&" equality_expression
#line 489 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                          {
        log("[logical_and_expression:] logical_and_expression && equality_expression\n");
        // $$ = $1;
    }
#line 1534 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 37: // logical_or_expression: logical_and_expression
#line 496 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                               {
        // log("[logical_or_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1543 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 38: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 500 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                 {
        log("[logical_or_expression:] logical_or_expression || logical_and_expression\n");
        // $$ = $1;
    }
#line 1552 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 39: // assignment_expression: logical_or_expression
#line 507 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[assignment_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1561 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 40: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 511 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1590 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 41: // assignment_operator: "="
#line 538 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
          {
        yylhs.value.as < cecko::gt_cass > () = (cecko::gt_cass)1000;
    }
#line 1598 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 42: // match_head: "match" "identifier" "->" declaration_specifiers
#line 544 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                            {
        log("[match_head:] MATCH IDF ARROW declaration_speci  fiers - define result var\n");
        casem::TypeRefPack_Action DEFINER_BODY = GET_DEFINER(ctx, casem::match_result_template);
        casem::CKTypeRefDefPack rfpack = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        DEFINER_BODY(rfpack, std::function(CHOOSE_AND_DEFINE));
        auto rfpack_ptr = std::make_shared<casem::CKTypeRefDefPack>(rfpack);
        casem::MatchWrapper mw(yystack_[3].value.as < cecko::match_type > () == cecko::match_type::DMATCH, yystack_[2].value.as < cecko::CIName > (), rfpack_ptr); 
        log("match head done\n");
        yylhs.value.as < casem::MatchWrapper > () = mw;
    }
#line 1613 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 43: // match_expression: assignment_expression
#line 557 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1621 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 44: // match_expression: match_binders_list block_end
#line 560 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                      {
        log("[match_expression:] MATCH IDF ARROW declaration_specifiers block_start match_binders_list block_end\n");
        casem::MatchWrapper match_data = yystack_[1].value.as < casem::MatchWrapper > ();

        auto&& res = init_instruction_from_name(ctx, casem::match_result_template);
        yylhs.value.as < casem::InstructionWrapper > () = res;
    }
#line 1633 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 45: // match_binders_list: match_binders_list_head_start expression_body
#line 570 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                   {
        log("[match_binders_list:] match_binders_list_head_start expression_body\n");
        auto&& data = yystack_[1].value.as < casem::MatchBinderListHeadData > ();
        auto&& match_dt = data.head_data;
        auto&& binder_data = data.binder_data;
        auto& if_data = binder_data.if_data;
        auto&& conditioned_result_value = yystack_[0].value.as < casem::InstructionWrapper > ();

        init_instruction_from_name(ctx, match_result_template)
            .store(conditioned_result_value);
        ctx->exit_block();
        ctx->builder()->SetInsertPoint(if_data.continue_block);
        create_if_control_flow(ctx, if_data);
        
        yylhs.value.as < casem::MatchWrapper > () = match_dt;
    }
#line 1654 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 46: // match_binders_list: match_binders_list_head expression_body
#line 586 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                               {
        log("[match_binders_list:] match_binders_list_head expression_body\n");
        auto&& data = yystack_[1].value.as < casem::MatchBinderListHeadData > ();
        auto&& match_dt = data.head_data;
        auto&& binder_data = data.binder_data;
        auto& if_data = binder_data.if_data;
        auto&& conditioned_result_value = yystack_[0].value.as < casem::InstructionWrapper > ();

        init_instruction_from_name(ctx, match_result_template)
            .store(conditioned_result_value);
        ctx->exit_block();
        ctx->builder()->SetInsertPoint(if_data.continue_block);
        create_if_control_flow(ctx, if_data);
        
        yylhs.value.as < casem::MatchWrapper > () = match_dt;
    }
#line 1675 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 47: // match_binders_list_head_start: match_head block_start match_binder_head
#line 605 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                             {
        log("[match_binders_list_head_start:] match_head block_start match_binder_head\n");
        auto&& match_dt = yystack_[2].value.as < casem::MatchWrapper > ();
        auto&& binder_data = yystack_[0].value.as < casem::MatchBinderChackerData > ();
        binder_data.create_if_statement(ctx, match_dt);
        ctx->enter_block();
        binder_data.init_binder_vars(ctx, match_dt);

        yylhs.value.as < casem::MatchBinderListHeadData > () = casem::MatchBinderListHeadData(match_dt, yystack_[0].value.as < casem::MatchBinderChackerData > ());
    }
#line 1690 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 48: // match_binders_list_head: match_binders_list match_binder_head
#line 618 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                         {
        log("[match_binders_list_head:] match_binders_list match_binder_head\n");
        auto&& match_dt = yystack_[1].value.as < casem::MatchWrapper > ();
        auto&& binder_data = yystack_[0].value.as < casem::MatchBinderChackerData > ();
        binder_data.create_if_statement(ctx, match_dt);
        ctx->enter_block();
        binder_data.init_binder_vars(ctx, match_dt);

        yylhs.value.as < casem::MatchBinderListHeadData > () = casem::MatchBinderListHeadData(match_dt, yystack_[0].value.as < casem::MatchBinderChackerData > ());
    }
#line 1705 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 49: // match_binder_head: "|" match_binder_definer "->"
#line 631 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                        {
        log("[match_binder_head:] VERT match_binder_definer ARROW\n");
        yylhs.value.as < casem::MatchBinderChackerData > () = yystack_[1].value.as < casem::MatchBinderChackerData > ();
    }
#line 1714 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 50: // match_binder_definer: "identifier" "(" match_binder_arguments_list ")"
#line 638 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                {
        log("[match_binder_definer:] IDF LPAR match_binder_arguments_list RPAR\n");
        yylhs.value.as < casem::MatchBinderChackerData > () = casem::MatchBinderChackerData(yystack_[3].value.as < cecko::CIName > ()).set_args(ctx, yystack_[1].value.as < std::vector<cecko::CIName> > ());
    }
#line 1723 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 51: // match_binder_definer: "identifier"
#line 642 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
            {
        log("[match_binder_definer:] IDF\n");
        yylhs.value.as < casem::MatchBinderChackerData > () = casem::MatchBinderChackerData(yystack_[0].value.as < cecko::CIName > ());
    }
#line 1732 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 52: // match_binder_arguments_list: "identifier"
#line 649 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
           { // FIXME: switch for `match_binder_definer`
        log("[match_binder_arguments_list:] IDF\n");
        yylhs.value.as < std::vector<cecko::CIName> > () = { yystack_[0].value.as < cecko::CIName > () };
    }
#line 1741 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 53: // match_binder_arguments_list: match_binder_arguments_list "," "identifier"
#line 653 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                            {
        log("[match_binder_arguments_list:] match_binder_arguments_list COMMA IDF\n");
        (yystack_[2].value.as < std::vector<cecko::CIName> > ()).push_back(yystack_[0].value.as < cecko::CIName > ());
        yylhs.value.as < std::vector<cecko::CIName> > () = yystack_[2].value.as < std::vector<cecko::CIName> > ();
    }
#line 1751 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 54: // expression_body: match_expression
#line 661 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                      {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1759 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 55: // expression: expression_body expression_end
#line 671 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                   {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[1].value.as < casem::InstructionWrapper > ();
    }
#line 1767 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 56: // declaration_specifiers: declaration_specifier
#line 700 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            { 
            log("[declaration_specifiers:] ^ simply give refpack from declaration_specifier to the list\n");
            yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        }
#line 1776 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 57: // declaration_specifiers: declaration_specifier declaration_specifiers
#line 704 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1801 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 58: // declaration_specifier: type_specifier_qualifier
#line 732 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1827 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 59: // type_specifier: "_Bool, char, or int"
#line 779 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1849 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 60: // type_specifier: declared_type_name
#line 796 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1864 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 61: // type_specifier: typedef_name
#line 806 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1880 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 62: // declared_type_name: "type" "identifier"
#line 820 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        log_name("[declared_type_name:] TYPEDEF IDF", yystack_[0].value.as < cecko::CIName > ());
        yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > ();
    }
#line 1889 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 63: // enumtype_decl_head: "type" "identifier"
#line 827 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        // FIXME: Handle tag range
        log_name("[enumtype_decl_head:]", yystack_[0].value.as < cecko::CIName > ());
        cecko::CKStructItemArray struct_items;
        struct_items.push_back(casem::get_tag_strauct_item(ctx)); 

        log("Define struct type\n");
        auto struct_obs = ctx->declare_struct_type(yystack_[0].value.as < cecko::CIName > (), ctx->line());
        ctx->define_struct_type_open(yystack_[0].value.as < cecko::CIName > (), ctx->line());
        ctx->define_struct_type_close(struct_obs, struct_items);

        int first_enumtype_tag = max_type_tag;
        casem::TaggedTypeDecl res(struct_obs, first_enumtype_tag);

        yylhs.value.as < casem::TaggedTypeDecl > () = res;
    }
#line 1910 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 68: // enumtype_decl_specifier: enumtype_decl_head block_start member_types_declaration_list block_end "NEW_LINE"
#line 856 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                                    {
        // FIXME: Handle tag range
        log("[enumtype_decl_specifier:] enumtype_decl_head block_start member_types_declaration_list block_end NEWLINE\n");
        auto&& type_data = yystack_[4].value.as < casem::TaggedTypeDecl > ();
        int enumtype_tag_end = max_type_tag;
        casem::insert_ttype(type_data.name() , type_data.first_tag, enumtype_tag_end);
        log("Inserted father type tag range\n");
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = type_data.struct_decl;
    }
#line 1924 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 69: // member_types_declaration_list: member_types_declaration
#line 868 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                 {
        log("[member_types_declaration_list:] member_types_declaration\n");
        StructObservers vec = { yystack_[0].value.as < cecko::CKStructTypeSafeObs > () };
        yylhs.value.as < casem::StructObservers > () = vec;
    }
#line 1934 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 70: // member_types_declaration_list: member_types_declaration_list member_types_declaration
#line 873 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                  {
        log("[member_types_declaration_list:] member_types_declaration_list member_types_declaration\n");
        auto&& vec = yystack_[1].value.as < casem::StructObservers > (); 
        vec.push_back(yystack_[0].value.as < cecko::CKStructTypeSafeObs > ());
        yylhs.value.as < casem::StructObservers > () = vec;
    }
#line 1945 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 71: // member_types_declaration: "identifier" "(" member_declaration_list ")" ";"
#line 882 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                    {
        log_name("[member_types_declaration:] includes member_declaration_list", yystack_[4].value.as < cecko::CIName > ());
        auto&& struct_items = yystack_[2].value.as < cecko::CKStructItemArray > ();
        struct_items.insert(struct_items.begin(), casem::get_tag_strauct_item(ctx));
        auto&& struct_obs = ctx->declare_struct_type(yystack_[4].value.as < cecko::CIName > (), ctx->line());

        ctx->define_struct_type_open(yystack_[4].value.as < cecko::CIName > (), ctx->line());
        ctx->define_struct_type_close(struct_obs, struct_items);
        casem::insert_ttype(yystack_[4].value.as < cecko::CIName > (), max_type_tag);
        ++casem::max_type_tag;

        casem::declare_type_constructor(ctx, yystack_[4].value.as < cecko::CIName > (), struct_obs, struct_items);

        yylhs.value.as < cecko::CKStructTypeSafeObs > () = struct_obs;
    }
#line 1965 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 72: // member_types_declaration: "identifier" ";"
#line 897 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                   {
        log_name("[member_types_declaration:] found IDF SEMIC", yystack_[1].value.as < cecko::CIName > ());
        auto struct_obs = ctx->declare_struct_type(yystack_[1].value.as < cecko::CIName > (), ctx->line()); 
        ctx->define_struct_type_open(yystack_[1].value.as < cecko::CIName > (), ctx->line());
        cecko::CKStructItemArray struct_items = { casem::get_tag_strauct_item(ctx) };

        ctx->define_struct_type_close(struct_obs, struct_items);
        casem::insert_ttype(yystack_[1].value.as < cecko::CIName > (), max_type_tag);
        ++casem::max_type_tag;

        casem::declare_type_constructor(ctx, yystack_[1].value.as < cecko::CIName > (), struct_obs, struct_items);

        yylhs.value.as < cecko::CKStructTypeSafeObs > () = struct_obs;
    }
#line 1984 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 73: // member_declaration_list: member_declaration
#line 914 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log("[member_declaration_list:] member_declaration\n");
        yylhs.value.as < cecko::CKStructItemArray > () = yystack_[0].value.as < cecko::CKStructItemArray > ();
    }
#line 1993 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 74: // member_declaration_list: member_declaration_list "," member_declaration
#line 918 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                          {
        log("[member_declaration_list:] member_declaration_list COMMA member_declaration\n");
        cecko::CKStructItemArray s_items = yystack_[2].value.as < cecko::CKStructItemArray > ();
        s_items.push_back(yystack_[0].value.as < cecko::CKStructItemArray > ()[0]);
        yylhs.value.as < cecko::CKStructItemArray > () = s_items;
    }
#line 2004 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 75: // member_declaration: specifier_qualifier_list member_declarator
#line 927 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                 { 
        log("[member_declaration:] give refpack to member_declarator_list\n");
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[1].value.as < casem::CKTypeRefDefPack > ();

        casem::CKTypeRefDefPack final_type = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));
        cecko::CKStructItem s_item(final_type, final_type.name.value(), ctx->line());

        cecko::CKStructItemArray s_items = { s_item };
        yylhs.value.as < cecko::CKStructItemArray > () = s_items;
     }
#line 2020 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 76: // specifier_qualifier_list: type_specifier_qualifier
#line 941 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                { 
        log("[specifier_qualifier_list:] ^ type_specifier_qualifier\n");
        yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
     }
#line 2029 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 77: // specifier_qualifier_list: type_specifier_qualifier specifier_qualifier_list
#line 945 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2050 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 78: // type_specifier_qualifier: type_specifier
#line 964 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    { 
            log("[type_specifier_qualifier:] ^ Found type_specifier\n"); 
            casem::CKTypeRefDefPack t(yystack_[0].value.as < cecko::CKTypeSafeObs > (), false, false);
            yylhs.value.as < casem::CKTypeRefDefPack > () = t;
        }
#line 2060 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 79: // member_declarator: declarator
#line 985 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2068 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 80: // enumeration_constant: "identifier"
#line 1005 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
            {
        log_name("[enumeration_constant:]", yystack_[0].value.as < cecko::CIName > ());
        yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > ();
    }
#line 2077 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 81: // declarator: pointer direct_declarator
#line 1012 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                              {
        log("[declarator:] >v found pointer direct_declarator define LAMBDA\n");
        auto DEFINER_F = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        auto POINTER_F = yystack_[1].value.as < casem::TypeRefPack_Convertor > ();

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_POINTER_ADDER(POINTER_F, DEFINER_F);
    }
#line 2089 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 82: // declarator: direct_declarator
#line 1019 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
            log("[declarator:] v found direct_declarator, gave refpack to it\n");
            yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();    // giving the casem::CKTypeRefDefPack(type, is_const, has_typedef)
        }
#line 2098 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 83: // pointer: "*" pointer
#line 1026 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2114 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 84: // pointer: "*"
#line 1037 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                {
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            POINTER_TO_DEFINER = [this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, false, rfpack.has_typedef);
                return pointer_pack;
            };

        yylhs.value.as < casem::TypeRefPack_Convertor > () = POINTER_TO_DEFINER;
    }
#line 2129 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 85: // direct_declarator: "identifier"
#line 1050 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
        { 
        auto name = yystack_[0].value.as < cecko::CIName > ();
        log_name("[direct_declarator:] .() found IDF and define LAMBDA", name);

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_DEFINER(ctx, name);
    }
#line 2140 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 86: // direct_declarator: function_declarator
#line 1065 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log("[direct_declarator:] v found function_declarator\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 2149 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 87: // function_declarator: direct_declarator "[" parameter_type_list "]"
#line 1085 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                     {
        log("[function_declarator:] v< wrap current lambdas rfpack in function\n");
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

        // TypeRefPack_Convertor UNPACK_PARAMETERS([](casem::CKTypeRefDefPack &rfpack) {
        // }); 


        yylhs.value.as < casem::TypeRefPack_Action > () = GET_FUNCTION_ADDER(ctx, yystack_[3].value.as < casem::TypeRefPack_Action > (), param_types, is_variadic, param_names);
    }
#line 2177 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 88: // parameter_type_list: parameter_list
#line 1111 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                   {
        log("[parameter_type_list:] ^ parameter_list\n");
        yylhs.value.as < casem::TRDArray > () = yystack_[0].value.as < casem::TRDArray > ();
    }
#line 2186 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 89: // parameter_type_list: %empty
#line 1115 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                  {
        std::vector<casem::CKTypeRefDefPack> empty_param_array;
        yylhs.value.as < casem::TRDArray > () = empty_param_array;
    }
#line 2195 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 90: // parameter_list: parameter_declaration
#line 1122 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2211 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 91: // parameter_list: parameter_list "," parameter_declaration
#line 1133 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2234 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 92: // parameter_declaration: declaration_specifiers declarator
#line 1154 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 2265 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 93: // parameter_declaration: declaration_specifiers
#line 1189 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                    {
        log("[parameter_declaration:] ^ found declaration_specifiers\n");
        casem::CKTypeRefDefPack rfpack = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
    }
#line 2275 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 94: // typedef_name: "type identifier"
#line 1258 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > (); }
#line 2281 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;


#line 2285 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"

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


  const signed char parser::yypact_ninf_ = -109;

  const signed char parser::yytable_ninf_ = -64;

  const signed char
  parser::yypact_[] =
  {
      37,   -25,  -109,  -109,     3,  -109,  -109,    -8,    12,    -3,
      42,  -109,  -109,   -13,  -109,  -109,  -109,    -2,  -109,  -109,
    -109,    12,  -109,  -109,  -109,  -109,   -17,    41,  -109,  -109,
    -109,  -109,    30,    39,  -109,    21,    43,    38,    47,    48,
      46,  -109,   -13,  -109,     8,    12,    12,    11,  -109,  -109,
      66,  -109,  -109,    49,    76,  -109,    50,  -109,    73,    53,
      75,    77,    39,  -109,    39,  -109,  -109,    39,    39,    39,
      39,    39,    39,    39,    78,    63,    55,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,    76,    42,  -109,  -109,
       2,    36,  -109,  -109,    42,    84,    82,  -109,  -109,  -109,
      21,    43,    38,    47,    48,  -109,  -109,    87,    85,    -3,
      90,    86,  -109,    42,  -109,    89,  -109,  -109,  -109,    39,
      65,  -109,  -109,  -109,    42,    52,  -109,    -3,    42,  -109,
    -109,  -109,    64,  -109,    79,    42,  -109,  -109,  -109,  -109,
      68,  -109,  -109,  -109
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,    59,    94,     0,     2,     4,     0,     0,     0,
      56,    78,    60,     0,     5,    58,    61,    62,     1,     3,
      10,     0,    21,    22,    23,    24,     0,    80,    12,    13,
      15,    19,    25,     0,    26,    29,    31,    33,    35,    37,
      39,    43,     0,    54,     0,     0,     0,     0,     8,    11,
      84,    85,     9,     0,    82,    86,     0,    57,    64,     0,
       0,     0,     0,    41,     0,    25,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    48,    44,
      45,    46,     7,     6,    55,    83,    81,    89,    62,    65,
       0,     0,    69,    14,     0,     0,    17,    40,    27,    28,
      30,    32,    34,    36,    38,    47,    67,    51,     0,    93,
       0,    88,    90,     0,    72,     0,    70,    42,    16,     0,
       0,    49,    92,    87,     0,     0,    73,     0,    76,    68,
      18,    52,     0,    91,     0,     0,    75,    79,    77,    50,
       0,    71,    74,    53
  };

  const signed char
  parser::yypgoto_[] =
  {
    -109,  -109,    93,  -109,  -109,  -109,  -109,  -109,  -109,   -20,
      -7,  -109,   -27,    33,    34,    32,    35,    40,  -109,   -60,
    -109,  -109,  -109,  -109,  -109,  -109,    31,  -109,  -109,   -11,
      88,   -10,  -109,  -109,  -109,  -109,    69,    15,  -109,  -109,
      17,  -109,   -19,   -18,  -108,  -109,  -109,   -96,    67,    62,
    -109,  -109,  -109,    -6,  -109
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     4,     5,    84,     6,     7,     8,    30,    31,    95,
      65,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      64,    42,    43,    44,    45,    46,    78,   108,   132,    47,
      48,     9,    10,    11,    12,    13,    59,    79,    14,    91,
      92,   125,   126,   127,    15,   136,    49,    52,    53,    54,
      55,   110,   111,   112,    16
  };

  const short
  parser::yytable_[] =
  {
      57,    32,    96,    18,    97,   128,    66,   113,    17,    50,
      58,    82,    20,   122,    32,    75,    61,    21,    83,    76,
     128,   -63,    22,   114,    23,    24,    25,   128,     1,     2,
      51,   137,    77,    67,    80,    81,    68,     3,    32,    32,
      98,    99,    26,    75,    21,    27,    62,    28,    29,    22,
      63,    23,    24,    25,    70,    32,    69,    32,   134,    96,
      77,   135,     1,     2,    71,    73,    72,    56,     2,    90,
     139,     3,    27,   140,    28,    29,     3,   109,    50,    87,
      89,    93,    51,    88,   117,    94,    90,   106,   107,    76,
     118,   119,   120,   121,   123,   124,   129,    19,   131,   130,
     141,   143,   100,   102,   101,   105,   115,   103,   116,    60,
     138,    74,    32,   104,   109,    86,   142,    85,   133
  };

  const unsigned char
  parser::yycheck_[] =
  {
      10,     8,    62,     0,    64,   113,    33,     5,    33,    12,
      23,     0,    20,   109,    21,     7,    33,     5,     7,    11,
     128,    23,    10,    21,    12,    13,    14,   135,    25,    26,
      33,   127,    24,    12,    45,    46,    15,    34,    45,    46,
      67,    68,    30,     7,     5,    33,     5,    35,    36,    10,
      20,    12,    13,    14,    16,    62,    13,    64,     6,   119,
      24,     9,    25,    26,    17,    19,    18,    25,    26,    33,
       6,    34,    33,     9,    35,    36,    34,    87,    12,     3,
       7,     6,    33,    33,    94,     8,    33,    24,    33,    11,
       6,     9,     5,     8,     4,     9,     7,     4,    33,   119,
      21,    33,    69,    71,    70,    74,    91,    72,    91,    21,
     128,    42,   119,    73,   124,    53,   135,    50,   124
  };

  const signed char
  parser::yystos_[] =
  {
       0,    25,    26,    34,    38,    39,    41,    42,    43,    68,
      69,    70,    71,    72,    75,    81,    91,    33,     0,    39,
      20,     5,    10,    12,    13,    14,    30,    33,    35,    36,
      44,    45,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    58,    59,    60,    61,    62,    66,    67,    83,
      12,    33,    84,    85,    86,    87,    25,    68,    23,    73,
      67,    33,     5,    20,    57,    47,    49,    12,    15,    13,
      16,    17,    18,    19,    73,     7,    11,    24,    63,    74,
      66,    66,     0,     7,    40,    85,    86,     3,    33,     7,
      33,    76,    77,     6,     8,    46,    56,    56,    49,    49,
      50,    51,    52,    53,    54,    63,    24,    33,    64,    68,
      88,    89,    90,     5,    21,    74,    77,    68,     6,     9,
       5,     8,    84,     4,     9,    78,    79,    80,    81,     7,
      46,    33,    65,    90,     6,     9,    82,    84,    80,     6,
       9,    21,    79,    33
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    37,    38,    38,    39,    39,    40,    40,    41,    42,
      43,    44,    44,    44,    44,    45,    45,    46,    46,    47,
      47,    48,    48,    48,    48,    49,    50,    50,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    58,    59,    59,    60,    60,    61,    62,    63,
      64,    64,    65,    65,    66,    67,    68,    68,    69,    70,
      70,    70,    71,    72,    73,    73,    74,    74,    75,    76,
      76,    77,    77,    78,    78,    79,    80,    80,    81,    82,
      83,    84,    84,    85,    85,    86,    86,    87,    88,    88,
      89,    89,    90,    90,    91
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     2,     2,
       2,     1,     1,     1,     3,     1,     4,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     4,     1,     2,     2,     2,     3,     2,     3,
       4,     1,     1,     3,     1,     2,     1,     2,     1,     1,
       1,     1,     2,     2,     1,     2,     1,     2,     5,     1,
       2,     5,     2,     1,     3,     2,     1,     2,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     4,     1,     0,
       1,     3,     2,     1,     1
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
  "\"let\"", "\"match\"", "\"fip\"", "\"fn\"", "\"identifier\"",
  "\"type identifier\"", "\"integer literal\"", "\"string literal\"",
  "$accept", "translation_unit", "external_declaration", "expression_end",
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
  "type_specifier_qualifier", "member_declarator", "enumeration_constant",
  "declarator", "pointer", "direct_declarator", "function_declarator",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "typedef_name", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   203,   203,   204,   208,   209,   216,   217,   221,   255,
     279,   299,   303,   308,   313,   319,   324,   350,   354,   362,
     366,   399,   400,   401,   411,   415,   422,   426,   430,   444,
     448,   462,   466,   473,   477,   485,   489,   496,   500,   507,
     511,   538,   544,   557,   560,   570,   586,   605,   618,   631,
     638,   642,   649,   653,   661,   671,   700,   704,   732,   779,
     796,   806,   820,   827,   846,   847,   851,   852,   856,   868,
     873,   882,   897,   914,   918,   927,   941,   945,   964,   985,
    1005,  1012,  1019,  1026,  1037,  1050,  1065,  1085,  1111,  1115,
    1122,  1133,  1154,  1189,  1258
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
#line 2871 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"

#line 1475 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"


namespace cecko {

	void parser::error(const location_type& l, const std::string& m)
	{
		ctx->message(cecko::errors::SYNTAX, l, m);
	}
}
