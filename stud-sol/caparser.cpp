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
      case symbol_kind::S_expression_body: // expression_body
      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< casem::InstructionWrapper > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.YY_MOVE_OR_COPY< casem::StructObservers > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.YY_MOVE_OR_COPY< casem::TRDArray > (YY_MOVE (that.value));
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
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.YY_MOVE_OR_COPY< cecko::CIName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.YY_MOVE_OR_COPY< cecko::CKStructItemArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
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
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< casem::CKTypeRefDefPack > (YY_MOVE (that.value));
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
      case symbol_kind::S_expression_body: // expression_body
      case symbol_kind::S_expression: // expression
        value.move< casem::InstructionWrapper > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.move< casem::StructObservers > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.move< casem::TRDArray > (YY_MOVE (that.value));
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
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.move< cecko::CIName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.move< cecko::CKStructItemArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
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
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.copy< casem::CKTypeRefDefPack > (that.value);
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
      case symbol_kind::S_expression_body: // expression_body
      case symbol_kind::S_expression: // expression
        value.copy< casem::InstructionWrapper > (that.value);
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.copy< casem::StructObservers > (that.value);
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< casem::TRDArray > (that.value);
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
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.copy< cecko::CIName > (that.value);
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.copy< cecko::CKStructItemArray > (that.value);
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
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
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< casem::CKTypeRefDefPack > (that.value);
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
      case symbol_kind::S_expression_body: // expression_body
      case symbol_kind::S_expression: // expression
        value.move< casem::InstructionWrapper > (that.value);
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.move< casem::StructObservers > (that.value);
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.move< casem::TRDArray > (that.value);
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
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.move< cecko::CIName > (that.value);
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.move< cecko::CKStructItemArray > (that.value);
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
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
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        yylhs.value.emplace< casem::CKTypeRefDefPack > ();
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
      case symbol_kind::S_expression_body: // expression_body
      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< casem::InstructionWrapper > ();
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        yylhs.value.emplace< casem::StructObservers > ();
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        yylhs.value.emplace< casem::TRDArray > ();
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
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        yylhs.value.emplace< cecko::CIName > ();
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        yylhs.value.emplace< cecko::CKStructItemArray > ();
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
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
  case 5: // external_declaration: enumtype_decl_specifier
#line 200 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                 {
        log("[declaration:] found enumtype_decl_specifier\n");
        // $$ = $1;
    }
#line 1040 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 8: // function_definition: function_definition_head expression
#line 212 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1071 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 9: // function_definition_info: declaration_specifiers declarator
#line 246 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1092 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 10: // function_definition_head: function_definition_info "="
#line 265 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                  {
        log("[function_definition_head:]");
    }
#line 1100 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 11: // primary_expression: enumeration_constant
#line 285 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log("[primary_expression:] name\n");
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_from_name(ctx, yystack_[0].value.as < cecko::CIName > ());
    }
#line 1109 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 12: // primary_expression: "integer literal"
#line 289 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                {
        //CKIRConstantIntObs
        log("[primary_expression:] Found int lit '%d'\n", (int)yystack_[0].value.as < int > ());
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_const(ctx, yystack_[0].value.as < int > ());
    }
#line 1119 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 13: // primary_expression: "string literal"
#line 294 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                {
        log_name("[primary_expression:] Found string lit ", yystack_[0].value.as < cecko::CIName > ());
        // (StringRef Str, const Twine &Name = "", unsigned AddressSpace = 0, Module *M = nullptr, bool AddNull = true)	
        yylhs.value.as < casem::InstructionWrapper > () = init_instruction_const(ctx, yystack_[0].value.as < cecko::CIName > ());
    }
#line 1129 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 14: // primary_expression: "(" expression ")"
#line 299 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[1].value.as < casem::InstructionWrapper > ();
    }
#line 1137 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 15: // postfix_expression: primary_expression
#line 305 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                           {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1145 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 16: // unary_expression: postfix_expression
#line 341 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
        log("[unary_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1154 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 17: // unary_expression: unary_operator cast_expression
#line 345 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1179 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 18: // unary_operator: "&"
#line 378 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = AMPERSANT; }
#line 1185 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 19: // unary_operator: "*"
#line 379 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = STAR; }
#line 1191 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 20: // unary_operator: "+ or -"
#line 380 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1206 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 21: // unary_operator: "!"
#line 390 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < casem::UnaryOperator > () = EXCALMATION_MARK; }
#line 1212 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 22: // cast_expression: unary_expression
#line 394 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[cast_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1221 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 23: // multiplicative_expression: cast_expression
#line 401 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
        // log("[multiplicative_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1230 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 24: // multiplicative_expression: multiplicative_expression "*" cast_expression
#line 405 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        {
        log("[multiplicative_expression:] multiplicative_expression * cast_expression\n");
        yylhs.value.as < casem::InstructionWrapper > () = (yystack_[2].value.as < casem::InstructionWrapper > ()) * (yystack_[0].value.as < casem::InstructionWrapper > ());
    }
#line 1239 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 25: // multiplicative_expression: multiplicative_expression "/ or %" cast_expression
#line 409 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1255 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 26: // additive_expression: multiplicative_expression
#line 423 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                {
        // log("[multiplicative_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1264 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 27: // additive_expression: additive_expression "+ or -" multiplicative_expression
#line 427 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1280 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 28: // relational_expression: additive_expression
#line 441 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[relational_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1289 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 29: // relational_expression: relational_expression "<, >, <=, or >=" additive_expression
#line 445 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                         {
        log("[relational_expression:] relational_expression <,>,<=,>= additive_expression\n");
        // $$ = $1;
    }
#line 1298 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 30: // equality_expression: relational_expression
#line 452 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[equality_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1307 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 31: // equality_expression: equality_expression "== or !=" relational_expression
#line 456 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                        {
        log("[equality_expression:] equality_expression ==,!= relational_expression\n");
        // $$ = $1;
    }
#line 1316 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 32: // logical_and_expression: equality_expression
#line 464 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[logical_and_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1325 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 33: // logical_and_expression: logical_and_expression "&&" equality_expression
#line 468 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                          {
        log("[logical_and_expression:] logical_and_expression && equality_expression\n");
        // $$ = $1;
    }
#line 1334 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 34: // logical_or_expression: logical_and_expression
#line 475 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                               {
        // log("[logical_or_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1343 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 35: // logical_or_expression: logical_or_expression "||" logical_and_expression
#line 479 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                 {
        log("[logical_or_expression:] logical_or_expression || logical_and_expression\n");
        // $$ = $1;
    }
#line 1352 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 36: // assignment_expression: logical_or_expression
#line 486 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        // log("[assignment_expression:]>");
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1361 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 37: // assignment_expression: unary_expression assignment_operator assignment_expression
#line 490 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1390 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 38: // assignment_operator: "="
#line 517 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
          {
        yylhs.value.as < cecko::gt_cass > () = (cecko::gt_cass)1000;
    }
#line 1398 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 39: // expression_body: assignment_expression
#line 523 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                           {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[0].value.as < casem::InstructionWrapper > ();
    }
#line 1406 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 40: // expression: expression_body expression_end
#line 533 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                   {
        yylhs.value.as < casem::InstructionWrapper > () = yystack_[1].value.as < casem::InstructionWrapper > ();
    }
#line 1414 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 41: // declaration_specifiers: declaration_specifier
#line 562 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            { 
            log("[declaration_specifiers:] ^ simply give refpack from declaration_specifier to the list\n");
            yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        }
#line 1423 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 42: // declaration_specifiers: declaration_specifier declaration_specifiers
#line 566 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1448 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 43: // declaration_specifier: type_specifier_qualifier
#line 594 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1474 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 44: // type_specifier: "_Bool, char, or int"
#line 641 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1496 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 45: // type_specifier: typedef_name
#line 658 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1512 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 46: // enumtype_decl_head: "typedef" "identifier"
#line 672 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        // FIXME: Handle tag range
        log_name("[enumtype_decl_head:]", yystack_[0].value.as < cecko::CIName > ());
        auto struct_obs = ctx->declare_struct_type(yystack_[0].value.as < cecko::CIName > (), ctx->line()); 
        int first_enumtype_tag = max_type_tag;

        yylhs.value.as < cecko::CKStructTypeSafeObs > () = struct_obs;
    }
#line 1525 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 51: // enumtype_decl_specifier: enumtype_decl_head enumtype_decl_block_start member_types_declaration_list enumtype_decl_block_end "NEW_LINE"
#line 693 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                                                                {
        // FIXME: Handle tag range
        int enumtype_tag_end = max_type_tag;
        yylhs.value.as < cecko::CKStructTypeSafeObs > () = yystack_[4].value.as < cecko::CKStructTypeSafeObs > ();
    }
#line 1535 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 52: // member_types_declaration_list: member_types_declaration
#line 701 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                 {
        StructObservers vec = { yystack_[0].value.as < cecko::CKStructTypeSafeObs > () };
        yylhs.value.as < casem::StructObservers > () = vec;
    }
#line 1544 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 53: // member_types_declaration_list: member_types_declaration_list member_types_declaration
#line 705 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                                  {
        auto&& vec = yystack_[1].value.as < casem::StructObservers > (); 
        vec.push_back(yystack_[0].value.as < cecko::CKStructTypeSafeObs > ());
        yylhs.value.as < casem::StructObservers > () = vec;
    }
#line 1554 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 54: // member_types_declaration: "identifier" "(" member_declaration_list ")" ";"
#line 713 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                    {
        log_name("[member_types_declaration:]", yystack_[4].value.as < cecko::CIName > ());
        auto struct_obs = ctx->declare_struct_type(yystack_[4].value.as < cecko::CIName > (), ctx->line()); 
        ctx->define_struct_type_open(yystack_[4].value.as < cecko::CIName > (), ctx->line());

        ctx->define_struct_type_close(struct_obs, yystack_[2].value.as < cecko::CKStructItemArray > ());
        ++max_type_tag;

        yylhs.value.as < cecko::CKStructTypeSafeObs > () = struct_obs;
    }
#line 1569 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 55: // member_types_declaration: "identifier" ";"
#line 723 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                   {
        log_name("[member_types_declaration:]", yystack_[1].value.as < cecko::CIName > ());
        auto struct_obs = ctx->declare_struct_type(yystack_[1].value.as < cecko::CIName > (), ctx->line()); 
        ctx->define_struct_type_open(yystack_[1].value.as < cecko::CIName > (), ctx->line());

        ctx->define_struct_type_close(struct_obs, {});
        ++max_type_tag;

        yylhs.value.as < cecko::CKStructTypeSafeObs > () = struct_obs;
    }
#line 1584 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 56: // member_declaration_list: member_declaration
#line 736 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        yylhs.value.as < cecko::CKStructItemArray > () = yystack_[0].value.as < cecko::CKStructItemArray > ();
    }
#line 1592 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 57: // member_declaration_list: member_declaration_list "," member_declaration
#line 739 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                          {
        cecko::CKStructItemArray s_items = yystack_[2].value.as < cecko::CKStructItemArray > ();
        s_items.push_back(yystack_[0].value.as < cecko::CKStructItemArray > ()[0]);
        yylhs.value.as < cecko::CKStructItemArray > () = s_items;
    }
#line 1602 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 58: // member_declaration: specifier_qualifier_list member_declarator
#line 747 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                 { 
        log("[member_declaration:] give refpack to member_declarator_list\n");
        casem::TypeRefPack_Action DEFINER_BODY = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        casem::CKTypeRefDefPack rfpack = yystack_[1].value.as < casem::CKTypeRefDefPack > ();

        casem::CKTypeRefDefPack final_type = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));
        cecko::CKStructItem s_item(final_type, final_type.name.value(), ctx->line());

        cecko::CKStructItemArray s_items = { s_item };
        yylhs.value.as < cecko::CKStructItemArray > () = s_items;
     }
#line 1618 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 59: // specifier_qualifier_list: type_specifier_qualifier
#line 761 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                { 
        log("[specifier_qualifier_list:] ^ type_specifier_qualifier\n");
        yylhs.value.as < casem::CKTypeRefDefPack > () = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
     }
#line 1627 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 60: // specifier_qualifier_list: type_specifier_qualifier specifier_qualifier_list
#line 765 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1648 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 61: // type_specifier_qualifier: type_specifier
#line 784 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    { 
            log("[type_specifier_qualifier:] ^ Found type_specifier\n"); 
            casem::CKTypeRefDefPack t(yystack_[0].value.as < cecko::CKTypeSafeObs > (), false, false);
            yylhs.value.as < casem::CKTypeRefDefPack > () = t;
        }
#line 1658 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 62: // member_declarator: declarator
#line 805 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                    {
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 1666 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 63: // enumeration_constant: "identifier"
#line 825 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
            {
        log_name("[enumeration_constant:]", yystack_[0].value.as < cecko::CIName > ());
        yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > ();
    }
#line 1675 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 64: // declarator: pointer direct_declarator
#line 832 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                              {
        log("[declarator:] >v found pointer direct_declarator define LAMBDA\n");
        auto DEFINER_F = yystack_[0].value.as < casem::TypeRefPack_Action > ();
        auto POINTER_F = yystack_[1].value.as < casem::TypeRefPack_Convertor > ();

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_POINTER_ADDER(POINTER_F, DEFINER_F);
    }
#line 1687 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 65: // declarator: direct_declarator
#line 839 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                        {
            log("[declarator:] v found direct_declarator, gave refpack to it\n");
            yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();    // giving the casem::CKTypeRefDefPack(type, is_const, has_typedef)
        }
#line 1696 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 66: // pointer: "*" pointer
#line 846 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1712 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 67: // pointer: "*"
#line 857 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                {
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            POINTER_TO_DEFINER = [this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, false, rfpack.has_typedef);
                return pointer_pack;
            };

        yylhs.value.as < casem::TypeRefPack_Convertor > () = POINTER_TO_DEFINER;
    }
#line 1727 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 68: // direct_declarator: "identifier"
#line 870 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
        { 
        auto name = yystack_[0].value.as < cecko::CIName > ();
        log_name("[direct_declarator:] .() found IDF and define LAMBDA", name);

        yylhs.value.as < casem::TypeRefPack_Action > () = GET_DEFINER(ctx, name);
    }
#line 1738 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 69: // direct_declarator: function_declarator
#line 885 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                            {
        log("[direct_declarator:] v found function_declarator\n");
        yylhs.value.as < casem::TypeRefPack_Action > () = yystack_[0].value.as < casem::TypeRefPack_Action > ();
    }
#line 1747 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 70: // function_declarator: direct_declarator "[" parameter_type_list "]"
#line 905 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1775 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 71: // parameter_type_list: parameter_list
#line 931 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                   {
        log("[parameter_type_list:] ^ parameter_list\n");
        yylhs.value.as < casem::TRDArray > () = yystack_[0].value.as < casem::TRDArray > ();
    }
#line 1784 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 72: // parameter_type_list: %empty
#line 935 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                  {
        std::vector<casem::CKTypeRefDefPack> empty_param_array;
        yylhs.value.as < casem::TRDArray > () = empty_param_array;
    }
#line 1793 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 73: // parameter_list: parameter_declaration
#line 942 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1809 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 74: // parameter_list: parameter_list "," parameter_declaration
#line 953 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1832 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 75: // parameter_declaration: declaration_specifiers declarator
#line 974 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
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
#line 1863 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 76: // parameter_declaration: declaration_specifiers
#line 1009 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                                                    {
        log("[parameter_declaration:] ^ found declaration_specifiers\n");
        casem::CKTypeRefDefPack rfpack = yystack_[0].value.as < casem::CKTypeRefDefPack > ();
        yylhs.value.as < casem::CKTypeRefDefPack > () = rfpack;
    }
#line 1873 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;

  case 77: // typedef_name: "type identifier"
#line 1078 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
                { yylhs.value.as < cecko::CIName > () = yystack_[0].value.as < cecko::CIName > (); }
#line 1879 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"
    break;


#line 1883 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"

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


  const signed char parser::yypact_ninf_ = -83;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      14,   -14,   -83,   -83,     2,   -83,   -83,    17,    -2,    -5,
      10,   -83,    20,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
      -2,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
      25,    -2,   -83,     3,    11,    27,    29,    31,    32,   -83,
      16,   -83,   -83,    38,   -83,   -83,    19,    50,   -83,   -83,
      47,    22,    51,   -83,    -2,   -83,   -83,    -2,    -2,    -2,
      -2,    -2,    -2,    -2,   -83,   -83,   -83,   -83,    50,    10,
     -83,     4,    -3,   -83,   -83,   -83,   -83,   -83,     3,    11,
      27,    29,    31,    -5,    52,    49,   -83,    10,   -83,    37,
     -83,    54,   -83,   -83,   -83,    10,    23,   -83,    -5,    10,
     -83,   -83,   -83,    41,    10,   -83,   -83,   -83,   -83,   -83
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,    44,    77,     0,     2,     4,     0,     0,     0,
      41,    61,     0,     5,    43,    45,    46,     1,     3,    10,
       0,    18,    19,    20,    21,    63,    12,    13,    15,    16,
      22,     0,    23,    26,    28,    30,    32,    34,    36,    39,
       0,     8,    11,    67,    68,     9,     0,    65,    69,    42,
      47,     0,     0,    38,     0,    22,    17,     0,     0,     0,
       0,     0,     0,     0,     7,     6,    40,    66,    64,    72,
      48,     0,     0,    52,    14,    37,    24,    25,    27,    29,
      31,    33,    35,    76,     0,    71,    73,     0,    55,     0,
      49,     0,    53,    75,    70,     0,     0,    56,     0,    59,
      50,    51,    74,     0,     0,    58,    62,    60,    54,    57
  };

  const signed char
  parser::yypgoto_[] =
  {
     -83,   -83,    59,   -83,   -83,   -83,   -83,   -83,   -83,    -7,
     -83,   -17,     5,     6,     7,     8,     9,   -83,    13,   -83,
     -83,    45,   -10,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
      -1,   -83,   -35,   -26,   -82,   -83,   -83,   -77,    33,    28,
     -83,   -83,   -83,   -20,   -83
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     4,     5,    66,     6,     7,     8,    28,    29,    55,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    54,
      40,    41,     9,    10,    11,    12,    51,    91,    13,    72,
      73,    96,    97,    98,    14,   105,    42,    45,    46,    47,
      48,    84,    85,    86,    15
  };

  const signed char
  parser::yytable_[] =
  {
      49,    30,    17,    20,    89,    99,    93,    43,    21,    87,
      22,    23,    24,    30,    56,    57,    64,    99,    58,    16,
      90,   106,    99,    65,    59,    88,     1,     2,    44,   103,
      71,    25,   104,    26,    27,     2,     3,    19,     1,     2,
      76,    77,    50,    60,     3,    53,    61,    30,     3,    62,
      43,    63,    44,    69,    70,    71,    94,    74,    95,    83,
     100,   101,   108,    18,    78,    52,    79,    75,    80,   109,
      81,    92,    82,   107,    68,   102,    67,     0,     0,     0,
       0,     0,     0,     0,     0,    83
  };

  const signed char
  parser::yycheck_[] =
  {
      10,     8,     0,     5,     7,    87,    83,    12,    10,     5,
      12,    13,    14,    20,    31,    12,     0,    99,    15,    33,
      23,    98,   104,     7,    13,    21,    24,    25,    33,     6,
      33,    33,     9,    35,    36,    25,    34,    20,    24,    25,
      57,    58,    22,    16,    34,    20,    17,    54,    34,    18,
      12,    19,    33,     3,     7,    33,     4,     6,     9,    69,
      23,     7,    21,     4,    59,    20,    60,    54,    61,   104,
      62,    72,    63,    99,    46,    95,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95
  };

  const signed char
  parser::yystos_[] =
  {
       0,    24,    25,    34,    38,    39,    41,    42,    43,    59,
      60,    61,    62,    65,    71,    81,    33,     0,    39,    20,
       5,    10,    12,    13,    14,    33,    35,    36,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      57,    58,    73,    12,    33,    74,    75,    76,    77,    59,
      22,    63,    58,    20,    56,    46,    48,    12,    15,    13,
      16,    17,    18,    19,     0,     7,    40,    75,    76,     3,
       7,    33,    66,    67,     6,    55,    48,    48,    49,    50,
      51,    52,    53,    59,    78,    79,    80,     5,    21,     7,
      23,    64,    67,    74,     4,     9,    68,    69,    70,    71,
      23,     7,    80,     6,     9,    72,    74,    70,    21,    69
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    37,    38,    38,    39,    39,    40,    40,    41,    42,
      43,    44,    44,    44,    44,    45,    46,    46,    47,    47,
      47,    47,    48,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    57,
      58,    59,    59,    60,    61,    61,    62,    63,    63,    64,
      64,    65,    66,    66,    67,    67,    68,    68,    69,    70,
      70,    71,    72,    73,    74,    74,    75,    75,    76,    76,
      77,    78,    78,    79,    79,    80,    80,    81
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     2,     2,
       2,     1,     1,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       2,     1,     2,     1,     1,     1,     2,     1,     2,     1,
       2,     5,     1,     2,     5,     2,     1,     3,     2,     1,
       2,     1,     1,     1,     2,     1,     2,     1,     1,     1,
       4,     1,     0,     1,     3,     2,     1,     1
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
  "\"== or !=\"", "\"&&\"", "\"||\"", "\"=\"", "\";\"", "\"{\"", "\"}\"",
  "\"typedef\"", "\"_Bool, char, or int\"", "\"sizeof\"", "\"in\"",
  "\"let\"", "\"match\"", "\"match!\"", "\"fip\"", "\"fn\"",
  "\"identifier\"", "\"type identifier\"", "\"integer literal\"",
  "\"string literal\"", "$accept", "translation_unit",
  "external_declaration", "expression_end", "function_definition",
  "function_definition_info", "function_definition_head",
  "primary_expression", "postfix_expression", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_and_expression", "logical_or_expression",
  "assignment_expression", "assignment_operator", "expression_body",
  "expression", "declaration_specifiers", "declaration_specifier",
  "type_specifier", "enumtype_decl_head", "enumtype_decl_block_start",
  "enumtype_decl_block_end", "enumtype_decl_specifier",
  "member_types_declaration_list", "member_types_declaration",
  "member_declaration_list", "member_declaration",
  "specifier_qualifier_list", "type_specifier_qualifier",
  "member_declarator", "enumeration_constant", "declarator", "pointer",
  "direct_declarator", "function_declarator", "parameter_type_list",
  "parameter_list", "parameter_declaration", "typedef_name", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   194,   194,   195,   199,   200,   207,   208,   212,   246,
     265,   285,   289,   294,   299,   305,   341,   345,   378,   379,
     380,   390,   394,   401,   405,   409,   423,   427,   441,   445,
     452,   456,   464,   468,   475,   479,   486,   490,   517,   523,
     533,   562,   566,   594,   641,   658,   672,   683,   684,   688,
     689,   693,   701,   705,   713,   723,   736,   739,   747,   761,
     765,   784,   805,   825,   832,   839,   846,   857,   870,   885,
     905,   931,   935,   942,   953,   974,  1009,  1078
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
#line 2440 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.cpp"

#line 1295 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"


namespace cecko {

	void parser::error(const location_type& l, const std::string& m)
	{
		ctx->message(cecko::errors::SYNTAX, l, m);
	}
}
