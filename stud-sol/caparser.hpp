// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.hpp
 ** Define the cecko::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_MNT_C_USERS_JAROM_DESKTOP_PG_EXER_BAKA_TEST_FILES_FIPCOMPILER_STUD_SOL_CAPARSER_HPP_INCLUDED
# define YY_YY_MNT_C_USERS_JAROM_DESKTOP_PG_EXER_BAKA_TEST_FILES_FIPCOMPILER_STUD_SOL_CAPARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 17 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"

// this code is emitted to caparser.hpp

#include "ckbisonflex.hpp"
#include <iostream>
#include <vector>

// adjust YYLLOC_DEFAULT macro for our api.location.type
#define YYLLOC_DEFAULT(res,rhs,N)	(res = (N)?YYRHSLOC(rhs, 1):YYRHSLOC(rhs, 0))

#include "ckgrptokens.hpp"
#include "ckcontext.hpp"
#include "casem.hpp"
#include <functional>

#line 65 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 7 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
namespace cecko {
#line 206 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.hpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // declaration_specifiers
      // declaration_specifier
      // specifier_qualifier_list
      // type_specifier_qualifier
      // parameter_declaration
      char dummy1[sizeof (casem::CKTypeRefDefPack)];

      // primary_expression
      // postfix_expression
      // unary_expression
      // cast_expression
      // multiplicative_expression
      // additive_expression
      // relational_expression
      // equality_expression
      // logical_and_expression
      // logical_or_expression
      // assignment_expression
      // expression_body
      // expression
      char dummy2[sizeof (casem::InstructionWrapper)];

      // member_types_declaration_list
      char dummy3[sizeof (casem::StructObservers)];

      // parameter_type_list
      // parameter_list
      char dummy4[sizeof (casem::TRDArray)];

      // member_declarator
      // declarator
      // direct_declarator
      // function_declarator
      char dummy5[sizeof (casem::TypeRefPack_Action)];

      // pointer
      char dummy6[sizeof (casem::TypeRefPack_Convertor)];

      // unary_operator
      char dummy7[sizeof (casem::UnaryOperator)];

      // "identifier"
      // "type identifier"
      // "string literal"
      // enumeration_constant
      // typedef_name
      char dummy8[sizeof (cecko::CIName)];

      // member_declaration_list
      // member_declaration
      char dummy9[sizeof (cecko::CKStructItemArray)];

      // enumtype_decl_head
      // enumtype_decl_specifier
      // member_types_declaration
      char dummy10[sizeof (cecko::CKStructTypeSafeObs)];

      // type_specifier
      char dummy11[sizeof (cecko::CKTypeSafeObs)];

      // "+ or -"
      char dummy12[sizeof (cecko::gt_addop)];

      // assignment_operator
      char dummy13[sizeof (cecko::gt_cass)];

      // "== or !="
      char dummy14[sizeof (cecko::gt_cmpe)];

      // "<, >, <=, or >="
      char dummy15[sizeof (cecko::gt_cmpo)];

      // "/ or %"
      char dummy16[sizeof (cecko::gt_divop)];

      // "_Bool, char, or int"
      char dummy17[sizeof (cecko::gt_etype)];

      // "integer literal"
      char dummy18[sizeof (int)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef cecko::loc_t location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOK_YYEMPTY = -2,
    TOK_EOF = 0,                   // "end of file"
    TOK_YYerror = 256,             // error
    TOK_YYUNDEF = 257,             // "invalid token"
    TOK_LBRA = 258,                // "["
    TOK_RBRA = 259,                // "]"
    TOK_LPAR = 260,                // "("
    TOK_RPAR = 261,                // ")"
    TOK_NEWLINE = 262,             // "NEW_LINE"
    TOK_ARROW = 263,               // "->"
    TOK_COMMA = 264,               // ","
    TOK_AMP = 265,                 // "&"
    TOK_VERT = 266,                // "|"
    TOK_STAR = 267,                // "*"
    TOK_ADDOP = 268,               // "+ or -"
    TOK_EMPH = 269,                // "!"
    TOK_DIVOP = 270,               // "/ or %"
    TOK_CMPO = 271,                // "<, >, <=, or >="
    TOK_CMPE = 272,                // "== or !="
    TOK_DAMP = 273,                // "&&"
    TOK_DVERT = 274,               // "||"
    TOK_ASGN = 275,                // "="
    TOK_SEMIC = 276,               // ";"
    TOK_LCUR = 277,                // "{"
    TOK_RCUR = 278,                // "}"
    TOK_TYPEDEF = 279,             // "typedef"
    TOK_ETYPE = 280,               // "_Bool, char, or int"
    TOK_SIZEOF = 281,              // "sizeof"
    TOK_IN = 282,                  // "in"
    TOK_LET = 283,                 // "let"
    TOK_MATCH = 284,               // "match"
    TOK_DMATCH = 285,              // "match!"
    TOK_FIP = 286,                 // "fip"
    TOK_FN = 287,                  // "fn"
    TOK_IDF = 288,                 // "identifier"
    TOK_TYPEIDF = 289,             // "type identifier"
    TOK_INTLIT = 290,              // "integer literal"
    TOK_STRLIT = 291               // "string literal"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 37, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_LBRA = 3,                              // "["
        S_RBRA = 4,                              // "]"
        S_LPAR = 5,                              // "("
        S_RPAR = 6,                              // ")"
        S_NEWLINE = 7,                           // "NEW_LINE"
        S_ARROW = 8,                             // "->"
        S_COMMA = 9,                             // ","
        S_AMP = 10,                              // "&"
        S_VERT = 11,                             // "|"
        S_STAR = 12,                             // "*"
        S_ADDOP = 13,                            // "+ or -"
        S_EMPH = 14,                             // "!"
        S_DIVOP = 15,                            // "/ or %"
        S_CMPO = 16,                             // "<, >, <=, or >="
        S_CMPE = 17,                             // "== or !="
        S_DAMP = 18,                             // "&&"
        S_DVERT = 19,                            // "||"
        S_ASGN = 20,                             // "="
        S_SEMIC = 21,                            // ";"
        S_LCUR = 22,                             // "{"
        S_RCUR = 23,                             // "}"
        S_TYPEDEF = 24,                          // "typedef"
        S_ETYPE = 25,                            // "_Bool, char, or int"
        S_SIZEOF = 26,                           // "sizeof"
        S_IN = 27,                               // "in"
        S_LET = 28,                              // "let"
        S_MATCH = 29,                            // "match"
        S_DMATCH = 30,                           // "match!"
        S_FIP = 31,                              // "fip"
        S_FN = 32,                               // "fn"
        S_IDF = 33,                              // "identifier"
        S_TYPEIDF = 34,                          // "type identifier"
        S_INTLIT = 35,                           // "integer literal"
        S_STRLIT = 36,                           // "string literal"
        S_YYACCEPT = 37,                         // $accept
        S_translation_unit = 38,                 // translation_unit
        S_external_declaration = 39,             // external_declaration
        S_expression_end = 40,                   // expression_end
        S_function_definition = 41,              // function_definition
        S_function_definition_info = 42,         // function_definition_info
        S_function_definition_head = 43,         // function_definition_head
        S_primary_expression = 44,               // primary_expression
        S_postfix_expression = 45,               // postfix_expression
        S_unary_expression = 46,                 // unary_expression
        S_unary_operator = 47,                   // unary_operator
        S_cast_expression = 48,                  // cast_expression
        S_multiplicative_expression = 49,        // multiplicative_expression
        S_additive_expression = 50,              // additive_expression
        S_relational_expression = 51,            // relational_expression
        S_equality_expression = 52,              // equality_expression
        S_logical_and_expression = 53,           // logical_and_expression
        S_logical_or_expression = 54,            // logical_or_expression
        S_assignment_expression = 55,            // assignment_expression
        S_assignment_operator = 56,              // assignment_operator
        S_expression_body = 57,                  // expression_body
        S_expression = 58,                       // expression
        S_declaration_specifiers = 59,           // declaration_specifiers
        S_declaration_specifier = 60,            // declaration_specifier
        S_type_specifier = 61,                   // type_specifier
        S_enumtype_decl_head = 62,               // enumtype_decl_head
        S_enumtype_decl_block_start = 63,        // enumtype_decl_block_start
        S_enumtype_decl_block_end = 64,          // enumtype_decl_block_end
        S_enumtype_decl_specifier = 65,          // enumtype_decl_specifier
        S_member_types_declaration_list = 66,    // member_types_declaration_list
        S_member_types_declaration = 67,         // member_types_declaration
        S_member_declaration_list = 68,          // member_declaration_list
        S_member_declaration = 69,               // member_declaration
        S_specifier_qualifier_list = 70,         // specifier_qualifier_list
        S_type_specifier_qualifier = 71,         // type_specifier_qualifier
        S_member_declarator = 72,                // member_declarator
        S_enumeration_constant = 73,             // enumeration_constant
        S_declarator = 74,                       // declarator
        S_pointer = 75,                          // pointer
        S_direct_declarator = 76,                // direct_declarator
        S_function_declarator = 77,              // function_declarator
        S_parameter_type_list = 78,              // parameter_type_list
        S_parameter_list = 79,                   // parameter_list
        S_parameter_declaration = 80,            // parameter_declaration
        S_typedef_name = 81                      // typedef_name
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_declaration_specifier: // declaration_specifier
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_specifier_qualifier: // type_specifier_qualifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< casem::CKTypeRefDefPack > (std::move (that.value));
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
        value.move< casem::InstructionWrapper > (std::move (that.value));
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.move< casem::StructObservers > (std::move (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.move< casem::TRDArray > (std::move (that.value));
        break;

      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_function_declarator: // function_declarator
        value.move< casem::TypeRefPack_Action > (std::move (that.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.move< casem::TypeRefPack_Convertor > (std::move (that.value));
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.move< casem::UnaryOperator > (std::move (that.value));
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.move< cecko::CIName > (std::move (that.value));
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.move< cecko::CKStructItemArray > (std::move (that.value));
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
      case symbol_kind::S_enumtype_decl_specifier: // enumtype_decl_specifier
      case symbol_kind::S_member_types_declaration: // member_types_declaration
        value.move< cecko::CKStructTypeSafeObs > (std::move (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< cecko::CKTypeSafeObs > (std::move (that.value));
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.move< cecko::gt_addop > (std::move (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< cecko::gt_cass > (std::move (that.value));
        break;

      case symbol_kind::S_CMPE: // "== or !="
        value.move< cecko::gt_cmpe > (std::move (that.value));
        break;

      case symbol_kind::S_CMPO: // "<, >, <=, or >="
        value.move< cecko::gt_cmpo > (std::move (that.value));
        break;

      case symbol_kind::S_DIVOP: // "/ or %"
        value.move< cecko::gt_divop > (std::move (that.value));
        break;

      case symbol_kind::S_ETYPE: // "_Bool, char, or int"
        value.move< cecko::gt_etype > (std::move (that.value));
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.move< int > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, casem::CKTypeRefDefPack&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const casem::CKTypeRefDefPack& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, casem::InstructionWrapper&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const casem::InstructionWrapper& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, casem::StructObservers&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const casem::StructObservers& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, casem::TRDArray&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const casem::TRDArray& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, casem::TypeRefPack_Action&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const casem::TypeRefPack_Action& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, casem::TypeRefPack_Convertor&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const casem::TypeRefPack_Convertor& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, casem::UnaryOperator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const casem::UnaryOperator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cecko::CIName&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cecko::CIName& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cecko::CKStructItemArray&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cecko::CKStructItemArray& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cecko::CKStructTypeSafeObs&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cecko::CKStructTypeSafeObs& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cecko::CKTypeSafeObs&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cecko::CKTypeSafeObs& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cecko::gt_addop&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cecko::gt_addop& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cecko::gt_cass&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cecko::gt_cass& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cecko::gt_cmpe&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cecko::gt_cmpe& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cecko::gt_cmpo&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cecko::gt_cmpo& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cecko::gt_divop&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cecko::gt_divop& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, cecko::gt_etype&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const cecko::gt_etype& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_declaration_specifier: // declaration_specifier
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_specifier_qualifier: // type_specifier_qualifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.template destroy< casem::CKTypeRefDefPack > ();
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
        value.template destroy< casem::InstructionWrapper > ();
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.template destroy< casem::StructObservers > ();
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.template destroy< casem::TRDArray > ();
        break;

      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_function_declarator: // function_declarator
        value.template destroy< casem::TypeRefPack_Action > ();
        break;

      case symbol_kind::S_pointer: // pointer
        value.template destroy< casem::TypeRefPack_Convertor > ();
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.template destroy< casem::UnaryOperator > ();
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.template destroy< cecko::CIName > ();
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.template destroy< cecko::CKStructItemArray > ();
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
      case symbol_kind::S_enumtype_decl_specifier: // enumtype_decl_specifier
      case symbol_kind::S_member_types_declaration: // member_types_declaration
        value.template destroy< cecko::CKStructTypeSafeObs > ();
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.template destroy< cecko::CKTypeSafeObs > ();
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.template destroy< cecko::gt_addop > ();
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.template destroy< cecko::gt_cass > ();
        break;

      case symbol_kind::S_CMPE: // "== or !="
        value.template destroy< cecko::gt_cmpe > ();
        break;

      case symbol_kind::S_CMPO: // "<, >, <=, or >="
        value.template destroy< cecko::gt_cmpo > ();
        break;

      case symbol_kind::S_DIVOP: // "/ or %"
        value.template destroy< cecko::gt_divop > ();
        break;

      case symbol_kind::S_ETYPE: // "_Bool, char, or int"
        value.template destroy< cecko::gt_etype > ();
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.template destroy< int > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_EOF
                   || (token::TOK_YYerror <= tok && tok <= token::TOK_STAR)
                   || tok == token::TOK_EMPH
                   || (token::TOK_DAMP <= tok && tok <= token::TOK_TYPEDEF)
                   || (token::TOK_SIZEOF <= tok && tok <= token::TOK_FN));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, cecko::CIName v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const cecko::CIName& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::TOK_IDF <= tok && tok <= token::TOK_TYPEIDF)
                   || tok == token::TOK_STRLIT);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, cecko::gt_addop v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const cecko::gt_addop& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_ADDOP);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, cecko::gt_cmpe v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const cecko::gt_cmpe& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_CMPE);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, cecko::gt_cmpo v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const cecko::gt_cmpo& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_CMPO);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, cecko::gt_divop v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const cecko::gt_divop& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_DIVOP);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, cecko::gt_etype v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const cecko::gt_etype& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_ETYPE);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const int& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_INTLIT);
#endif
      }
    };

    /// Build a parser object.
    parser (yyscan_t yyscanner_yyarg, cecko::context * ctx_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EOF (location_type l)
      {
        return symbol_type (token::TOK_EOF, std::move (l));
      }
#else
      static
      symbol_type
      make_EOF (const location_type& l)
      {
        return symbol_type (token::TOK_EOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOK_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOK_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOK_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOK_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRA (location_type l)
      {
        return symbol_type (token::TOK_LBRA, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRA (const location_type& l)
      {
        return symbol_type (token::TOK_LBRA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRA (location_type l)
      {
        return symbol_type (token::TOK_RBRA, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRA (const location_type& l)
      {
        return symbol_type (token::TOK_RBRA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAR (location_type l)
      {
        return symbol_type (token::TOK_LPAR, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAR (const location_type& l)
      {
        return symbol_type (token::TOK_LPAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAR (location_type l)
      {
        return symbol_type (token::TOK_RPAR, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAR (const location_type& l)
      {
        return symbol_type (token::TOK_RPAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEWLINE (location_type l)
      {
        return symbol_type (token::TOK_NEWLINE, std::move (l));
      }
#else
      static
      symbol_type
      make_NEWLINE (const location_type& l)
      {
        return symbol_type (token::TOK_NEWLINE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROW (location_type l)
      {
        return symbol_type (token::TOK_ARROW, std::move (l));
      }
#else
      static
      symbol_type
      make_ARROW (const location_type& l)
      {
        return symbol_type (token::TOK_ARROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::TOK_COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::TOK_COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMP (location_type l)
      {
        return symbol_type (token::TOK_AMP, std::move (l));
      }
#else
      static
      symbol_type
      make_AMP (const location_type& l)
      {
        return symbol_type (token::TOK_AMP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VERT (location_type l)
      {
        return symbol_type (token::TOK_VERT, std::move (l));
      }
#else
      static
      symbol_type
      make_VERT (const location_type& l)
      {
        return symbol_type (token::TOK_VERT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (location_type l)
      {
        return symbol_type (token::TOK_STAR, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const location_type& l)
      {
        return symbol_type (token::TOK_STAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDOP (cecko::gt_addop v, location_type l)
      {
        return symbol_type (token::TOK_ADDOP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ADDOP (const cecko::gt_addop& v, const location_type& l)
      {
        return symbol_type (token::TOK_ADDOP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EMPH (location_type l)
      {
        return symbol_type (token::TOK_EMPH, std::move (l));
      }
#else
      static
      symbol_type
      make_EMPH (const location_type& l)
      {
        return symbol_type (token::TOK_EMPH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVOP (cecko::gt_divop v, location_type l)
      {
        return symbol_type (token::TOK_DIVOP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIVOP (const cecko::gt_divop& v, const location_type& l)
      {
        return symbol_type (token::TOK_DIVOP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CMPO (cecko::gt_cmpo v, location_type l)
      {
        return symbol_type (token::TOK_CMPO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CMPO (const cecko::gt_cmpo& v, const location_type& l)
      {
        return symbol_type (token::TOK_CMPO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CMPE (cecko::gt_cmpe v, location_type l)
      {
        return symbol_type (token::TOK_CMPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CMPE (const cecko::gt_cmpe& v, const location_type& l)
      {
        return symbol_type (token::TOK_CMPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAMP (location_type l)
      {
        return symbol_type (token::TOK_DAMP, std::move (l));
      }
#else
      static
      symbol_type
      make_DAMP (const location_type& l)
      {
        return symbol_type (token::TOK_DAMP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DVERT (location_type l)
      {
        return symbol_type (token::TOK_DVERT, std::move (l));
      }
#else
      static
      symbol_type
      make_DVERT (const location_type& l)
      {
        return symbol_type (token::TOK_DVERT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASGN (location_type l)
      {
        return symbol_type (token::TOK_ASGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASGN (const location_type& l)
      {
        return symbol_type (token::TOK_ASGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMIC (location_type l)
      {
        return symbol_type (token::TOK_SEMIC, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMIC (const location_type& l)
      {
        return symbol_type (token::TOK_SEMIC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LCUR (location_type l)
      {
        return symbol_type (token::TOK_LCUR, std::move (l));
      }
#else
      static
      symbol_type
      make_LCUR (const location_type& l)
      {
        return symbol_type (token::TOK_LCUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCUR (location_type l)
      {
        return symbol_type (token::TOK_RCUR, std::move (l));
      }
#else
      static
      symbol_type
      make_RCUR (const location_type& l)
      {
        return symbol_type (token::TOK_RCUR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF (location_type l)
      {
        return symbol_type (token::TOK_TYPEDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPEDEF (const location_type& l)
      {
        return symbol_type (token::TOK_TYPEDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ETYPE (cecko::gt_etype v, location_type l)
      {
        return symbol_type (token::TOK_ETYPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ETYPE (const cecko::gt_etype& v, const location_type& l)
      {
        return symbol_type (token::TOK_ETYPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZEOF (location_type l)
      {
        return symbol_type (token::TOK_SIZEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_SIZEOF (const location_type& l)
      {
        return symbol_type (token::TOK_SIZEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN (location_type l)
      {
        return symbol_type (token::TOK_IN, std::move (l));
      }
#else
      static
      symbol_type
      make_IN (const location_type& l)
      {
        return symbol_type (token::TOK_IN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LET (location_type l)
      {
        return symbol_type (token::TOK_LET, std::move (l));
      }
#else
      static
      symbol_type
      make_LET (const location_type& l)
      {
        return symbol_type (token::TOK_LET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MATCH (location_type l)
      {
        return symbol_type (token::TOK_MATCH, std::move (l));
      }
#else
      static
      symbol_type
      make_MATCH (const location_type& l)
      {
        return symbol_type (token::TOK_MATCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DMATCH (location_type l)
      {
        return symbol_type (token::TOK_DMATCH, std::move (l));
      }
#else
      static
      symbol_type
      make_DMATCH (const location_type& l)
      {
        return symbol_type (token::TOK_DMATCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIP (location_type l)
      {
        return symbol_type (token::TOK_FIP, std::move (l));
      }
#else
      static
      symbol_type
      make_FIP (const location_type& l)
      {
        return symbol_type (token::TOK_FIP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FN (location_type l)
      {
        return symbol_type (token::TOK_FN, std::move (l));
      }
#else
      static
      symbol_type
      make_FN (const location_type& l)
      {
        return symbol_type (token::TOK_FN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDF (cecko::CIName v, location_type l)
      {
        return symbol_type (token::TOK_IDF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDF (const cecko::CIName& v, const location_type& l)
      {
        return symbol_type (token::TOK_IDF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEIDF (cecko::CIName v, location_type l)
      {
        return symbol_type (token::TOK_TYPEIDF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPEIDF (const cecko::CIName& v, const location_type& l)
      {
        return symbol_type (token::TOK_TYPEIDF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTLIT (int v, location_type l)
      {
        return symbol_type (token::TOK_INTLIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTLIT (const int& v, const location_type& l)
      {
        return symbol_type (token::TOK_INTLIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRLIT (cecko::CIName v, location_type l)
      {
        return symbol_type (token::TOK_STRLIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRLIT (const cecko::CIName& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRLIT, v, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 85,     ///< Last index in yytable_.
      yynnts_ = 45,  ///< Number of nonterminal symbols.
      yyfinal_ = 17 ///< Termination state number.
    };


    // User arguments.
    yyscan_t yyscanner;
    cecko::context * ctx;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
    };
    // Last valid token kind.
    const int code_max = 291;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_declaration_specifier: // declaration_specifier
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_specifier_qualifier: // type_specifier_qualifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.copy< casem::CKTypeRefDefPack > (YY_MOVE (that.value));
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
        value.copy< casem::InstructionWrapper > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.copy< casem::StructObservers > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< casem::TRDArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_function_declarator: // function_declarator
        value.copy< casem::TypeRefPack_Action > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.copy< casem::TypeRefPack_Convertor > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< casem::UnaryOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.copy< cecko::CIName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.copy< cecko::CKStructItemArray > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
      case symbol_kind::S_enumtype_decl_specifier: // enumtype_decl_specifier
      case symbol_kind::S_member_types_declaration: // member_types_declaration
        value.copy< cecko::CKStructTypeSafeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.copy< cecko::CKTypeSafeObs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.copy< cecko::gt_addop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.copy< cecko::gt_cass > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CMPE: // "== or !="
        value.copy< cecko::gt_cmpe > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CMPO: // "<, >, <=, or >="
        value.copy< cecko::gt_cmpo > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DIVOP: // "/ or %"
        value.copy< cecko::gt_divop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ETYPE: // "_Bool, char, or int"
        value.copy< cecko::gt_etype > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.copy< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_declaration_specifiers: // declaration_specifiers
      case symbol_kind::S_declaration_specifier: // declaration_specifier
      case symbol_kind::S_specifier_qualifier_list: // specifier_qualifier_list
      case symbol_kind::S_type_specifier_qualifier: // type_specifier_qualifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
        value.move< casem::CKTypeRefDefPack > (YY_MOVE (s.value));
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
        value.move< casem::InstructionWrapper > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_member_types_declaration_list: // member_types_declaration_list
        value.move< casem::StructObservers > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_type_list: // parameter_type_list
      case symbol_kind::S_parameter_list: // parameter_list
        value.move< casem::TRDArray > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_member_declarator: // member_declarator
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_direct_declarator: // direct_declarator
      case symbol_kind::S_function_declarator: // function_declarator
        value.move< casem::TypeRefPack_Action > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pointer: // pointer
        value.move< casem::TypeRefPack_Convertor > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_unary_operator: // unary_operator
        value.move< casem::UnaryOperator > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_enumeration_constant: // enumeration_constant
      case symbol_kind::S_typedef_name: // typedef_name
        value.move< cecko::CIName > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_member_declaration_list: // member_declaration_list
      case symbol_kind::S_member_declaration: // member_declaration
        value.move< cecko::CKStructItemArray > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_enumtype_decl_head: // enumtype_decl_head
      case symbol_kind::S_enumtype_decl_specifier: // enumtype_decl_specifier
      case symbol_kind::S_member_types_declaration: // member_types_declaration
        value.move< cecko::CKStructTypeSafeObs > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< cecko::CKTypeSafeObs > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.move< cecko::gt_addop > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< cecko::gt_cass > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CMPE: // "== or !="
        value.move< cecko::gt_cmpe > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CMPO: // "<, >, <=, or >="
        value.move< cecko::gt_cmpo > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_DIVOP: // "/ or %"
        value.move< cecko::gt_divop > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ETYPE: // "_Bool, char, or int"
        value.move< cecko::gt_etype > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTLIT: // "integer literal"
        value.move< int > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 7 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/solution/caparser.y"
} // cecko
#line 2715 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/stud-sol/caparser.hpp"




#endif // !YY_YY_MNT_C_USERS_JAROM_DESKTOP_PG_EXER_BAKA_TEST_FILES_FIPCOMPILER_STUD_SOL_CAPARSER_HPP_INCLUDED
