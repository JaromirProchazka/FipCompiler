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





#include "ckdumper.hpp"


// Unqualified %code blocks.
#line 33 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"

// this code is emitted to ckdumper.cpp

YY_DECL;


#line 53 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"


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

#line 7 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
namespace cecko {
#line 146 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"

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
      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_token_n: // token_n
        value.YY_MOVE_OR_COPY< cecko::CIName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.YY_MOVE_OR_COPY< cecko::gt_addop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CASS: // "*=, /=, %=, +=, or -="
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

      case symbol_kind::S_token_i: // token_i
        value.YY_MOVE_OR_COPY< token_attr_i > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_token_s: // token_s
        value.YY_MOVE_OR_COPY< token_attr_s > (YY_MOVE (that.value));
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
      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_token_n: // token_n
        value.move< cecko::CIName > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.move< cecko::gt_addop > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CASS: // "*=, /=, %=, +=, or -="
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

      case symbol_kind::S_token_i: // token_i
        value.move< token_attr_i > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_token_s: // token_s
        value.move< token_attr_s > (YY_MOVE (that.value));
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
      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_token_n: // token_n
        value.copy< cecko::CIName > (that.value);
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.copy< cecko::gt_addop > (that.value);
        break;

      case symbol_kind::S_CASS: // "*=, /=, %=, +=, or -="
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

      case symbol_kind::S_token_i: // token_i
        value.copy< token_attr_i > (that.value);
        break;

      case symbol_kind::S_token_s: // token_s
        value.copy< token_attr_s > (that.value);
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
      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_token_n: // token_n
        value.move< cecko::CIName > (that.value);
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        value.move< cecko::gt_addop > (that.value);
        break;

      case symbol_kind::S_CASS: // "*=, /=, %=, +=, or -="
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

      case symbol_kind::S_token_i: // token_i
        value.move< token_attr_i > (that.value);
        break;

      case symbol_kind::S_token_s: // token_s
        value.move< token_attr_s > (that.value);
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
      case symbol_kind::S_IDF: // "identifier"
      case symbol_kind::S_TYPEIDF: // "type identifier"
      case symbol_kind::S_STRLIT: // "string literal"
      case symbol_kind::S_token_n: // token_n
        yylhs.value.emplace< cecko::CIName > ();
        break;

      case symbol_kind::S_ADDOP: // "+ or -"
        yylhs.value.emplace< cecko::gt_addop > ();
        break;

      case symbol_kind::S_CASS: // "*=, /=, %=, +=, or -="
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

      case symbol_kind::S_token_i: // token_i
        yylhs.value.emplace< token_attr_i > ();
        break;

      case symbol_kind::S_token_s: // token_s
        yylhs.value.emplace< token_attr_s > ();
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
  case 5: // token: token_n
#line 109 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
              { 
		if (yystack_[0].location)
		{
			ctx->out() << yystack_[0].location << ": ";
		}
		ctx->out() << yystack_[0].value.as < cecko::CIName > () << std::endl; 
	}
#line 782 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 6: // token: token_s
#line 116 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                 {
		if (yystack_[0].location)
		{
			ctx->out() << yystack_[0].location << ": ";
		}
		ctx->out() << yystack_[0].value.as < token_attr_s > ().first;
		if (!yystack_[0].value.as < token_attr_s > ().second.empty())
		{
			ctx->out() << " " << yystack_[0].value.as < token_attr_s > ().second;
		}
		ctx->out() << std::endl;
	}
#line 799 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 7: // token: token_i
#line 128 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                 {
		if (yystack_[0].location)
		{
			ctx->out() << yystack_[0].location << ": ";
		}
		ctx->out() << yystack_[0].value.as < token_attr_i > ().first << " " << yystack_[0].value.as < token_attr_i > ().second << std::endl;
	}
#line 811 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 8: // token_n: "typedef"
#line 138 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
            { yylhs.value.as < cecko::CIName > () = "typedef"; }
#line 817 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 9: // token_n: "void"
#line 139 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "void"; }
#line 823 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 10: // token_n: "let"
#line 140 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "let"; }
#line 829 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 11: // token_n: "match"
#line 141 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "match"; }
#line 835 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 12: // token_n: "match!"
#line 142 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "match!"; }
#line 841 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 13: // token_n: "if"
#line 143 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                                 { yylhs.value.as < cecko::CIName > () = "if"; }
#line 847 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 14: // token_n: "else"
#line 144 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "else"; }
#line 853 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 15: // token_n: "do"
#line 145 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                                 { yylhs.value.as < cecko::CIName > () = "do"; }
#line 859 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 16: // token_n: "fip"
#line 146 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "fip"; }
#line 865 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 17: // token_n: "fn"
#line 147 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                                 { yylhs.value.as < cecko::CIName > () = "fn"; }
#line 871 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 18: // token_n: "|"
#line 148 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "|"; }
#line 877 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 19: // token_n: "continue"
#line 149 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "continue"; }
#line 883 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 20: // token_n: "\n"
#line 150 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "NEW_LINE"; }
#line 889 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 21: // token_n: "return"
#line 151 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "return"; }
#line 895 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 22: // token_n: "sizeof"
#line 152 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "sizeof"; }
#line 901 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 23: // token_n: "["
#line 153 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "["; }
#line 907 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 24: // token_n: "]"
#line 154 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "]"; }
#line 913 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 25: // token_n: "("
#line 155 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "("; }
#line 919 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 26: // token_n: ")"
#line 156 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = ")"; }
#line 925 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 27: // token_n: "."
#line 157 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                                 { yylhs.value.as < cecko::CIName > () = "."; }
#line 931 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 28: // token_n: "->"
#line 158 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "->"; }
#line 937 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 29: // token_n: ","
#line 159 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = ","; }
#line 943 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 30: // token_n: "&"
#line 160 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                                 { yylhs.value.as < cecko::CIName > () = "&"; }
#line 949 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 31: // token_n: "*"
#line 161 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "*"; }
#line 955 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 32: // token_n: "!"
#line 162 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "!"; }
#line 961 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 33: // token_n: "&&"
#line 163 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "&&"; }
#line 967 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 34: // token_n: "||"
#line 164 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "||"; }
#line 973 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 35: // token_n: "="
#line 165 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "="; }
#line 979 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 36: // token_n: ";"
#line 166 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = ";"; }
#line 985 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 37: // token_n: "{"
#line 167 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "{"; }
#line 991 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 38: // token_n: "}"
#line 168 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "}"; }
#line 997 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 39: // token_n: "in"
#line 169 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                                         { yylhs.value.as < cecko::CIName > () = "in"; }
#line 1003 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 40: // token_s: "identifier"
#line 173 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
            { 
		yylhs.value.as < token_attr_s > ().first = "identifier"; 
		yylhs.value.as < token_attr_s > ().second = ! yystack_[0].value.as < cecko::CIName > ().empty() ? "[" + cecko::context::escape(yystack_[0].value.as < cecko::CIName > ()) + "]" : ""; 
	}
#line 1012 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 41: // token_s: "type identifier"
#line 177 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                  { 
		yylhs.value.as < token_attr_s > ().first = "type identifier"; 
		yylhs.value.as < token_attr_s > ().second = ! yystack_[0].value.as < cecko::CIName > ().empty() ? "[" + cecko::context::escape(yystack_[0].value.as < cecko::CIName > ()) + "]" : ""; 
	}
#line 1021 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 42: // token_s: "string literal"
#line 181 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                { 
		yylhs.value.as < token_attr_s > ().first = "string literal"; 
		yylhs.value.as < token_attr_s > ().second = "\"" + cecko::context::escape(yystack_[0].value.as < cecko::CIName > ()) + "\"";
	}
#line 1030 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 43: // token_s: "<, >, <=, or >="
#line 185 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
              { 
		yylhs.value.as < token_attr_s > ().first = "CMPO"; 
		switch (yystack_[0].value.as < cecko::gt_cmpo > ())
		{
		case cecko::gt_cmpo::LT: yylhs.value.as < token_attr_s > ().second = "<"; break;
		case cecko::gt_cmpo::LE: yylhs.value.as < token_attr_s > ().second = "<="; break;
		case cecko::gt_cmpo::GE: yylhs.value.as < token_attr_s > ().second = ">="; break;
		case cecko::gt_cmpo::GT: yylhs.value.as < token_attr_s > ().second = ">"; break;
		default: yylhs.value.as < token_attr_s > ().second = "?"; break;
		}
	}
#line 1046 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 44: // token_s: "== or !="
#line 196 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
              { 
		yylhs.value.as < token_attr_s > ().first = "CMPE"; 
		switch (yystack_[0].value.as < cecko::gt_cmpe > ())
		{
		case cecko::gt_cmpe::EQ: yylhs.value.as < token_attr_s > ().second = "=="; break;
		case cecko::gt_cmpe::NE: yylhs.value.as < token_attr_s > ().second = "!="; break;
		default: yylhs.value.as < token_attr_s > ().second = "?"; break;
		}
	}
#line 1060 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 45: // token_s: "+ or -"
#line 205 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
               { 
		yylhs.value.as < token_attr_s > ().first = "ADDOP"; 
		switch (yystack_[0].value.as < cecko::gt_addop > ())
		{
		case cecko::gt_addop::ADD: yylhs.value.as < token_attr_s > ().second = "+"; break;
		case cecko::gt_addop::SUB: yylhs.value.as < token_attr_s > ().second = "-"; break;
		default: yylhs.value.as < token_attr_s > ().second = "?"; break;
		}
	}
#line 1074 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 46: // token_s: "++ or --"
#line 214 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
                { 
		yylhs.value.as < token_attr_s > ().first = "INCDEC"; 
		switch (yystack_[0].value.as < cecko::gt_incdec > ())
		{
		case cecko::gt_incdec::INC: yylhs.value.as < token_attr_s > ().second = "++"; break;
		case cecko::gt_incdec::DEC: yylhs.value.as < token_attr_s > ().second = "--"; break;
		default: yylhs.value.as < token_attr_s > ().second = "?"; break;
		}
	}
#line 1088 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 47: // token_s: "/ or %"
#line 223 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
               { 
		yylhs.value.as < token_attr_s > ().first = "DIVOP"; 
		switch (yystack_[0].value.as < cecko::gt_divop > ())
		{
		case cecko::gt_divop::MOD: yylhs.value.as < token_attr_s > ().second = "%"; break;
		case cecko::gt_divop::DIV: yylhs.value.as < token_attr_s > ().second = "/"; break;
		default: yylhs.value.as < token_attr_s > ().second = "?"; break;
		}
	}
#line 1102 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 48: // token_s: "_Bool, char, or int"
#line 232 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
               { 
		yylhs.value.as < token_attr_s > ().first = "ETYPE"; 
		switch (yystack_[0].value.as < cecko::gt_etype > ())
		{
		case cecko::gt_etype::BOOL: yylhs.value.as < token_attr_s > ().second = "_Bool"; break;
		case cecko::gt_etype::CHAR: yylhs.value.as < token_attr_s > ().second = "char";  break;
		case cecko::gt_etype::INT: yylhs.value.as < token_attr_s > ().second = "int";  break;
		default: yylhs.value.as < token_attr_s > ().second = "?"; break;
		}
	}
#line 1117 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 49: // token_s: "*=, /=, %=, +=, or -="
#line 242 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
              { 
		yylhs.value.as < token_attr_s > ().first = "CASS"; 
		switch (yystack_[0].value.as < cecko::gt_cass > ())
		{
		case cecko::gt_cass::MULA: yylhs.value.as < token_attr_s > ().second = "*="; break;
		case cecko::gt_cass::DIVA: yylhs.value.as < token_attr_s > ().second = "/=";  break;
		case cecko::gt_cass::MODA: yylhs.value.as < token_attr_s > ().second = "%=";  break;
		case cecko::gt_cass::ADDA: yylhs.value.as < token_attr_s > ().second = "+=";  break;
		case cecko::gt_cass::SUBA: yylhs.value.as < token_attr_s > ().second = "-=";  break;
		default: yylhs.value.as < token_attr_s > ().second = "?"; break;
		}
	}
#line 1134 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;

  case 50: // token_i: "integer literal"
#line 257 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
              { yylhs.value.as < token_attr_i > ().first = "integer literal"; yylhs.value.as < token_attr_i > ().second = yystack_[0].value.as < int > (); }
#line 1140 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"
    break;


#line 1144 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"

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


  const signed char parser::yypact_ninf_ = -4;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -4,    43,    -3,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4
  };

  const signed char
  parser::yydefact_[] =
  {
       4,     0,     2,     1,    23,    24,    25,    26,    27,    28,
      46,    29,    30,    31,    45,    32,    47,    43,    44,    33,
      34,    35,    49,    36,    37,    38,    39,     8,     9,    48,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    40,    41,    50,    42,     3,     5,     6,
       7
  };

  const signed char
  parser::yypgoto_[] =
  {
      -4,    -4,    -4,    -4,    -4,    -4,    -4
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    47,    48,    49,    50
  };

  const signed char
  parser::yytable_[] =
  {
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     3
  };

  const signed char
  parser::yycheck_[] =
  {
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0
  };

  const signed char
  parser::yystos_[] =
  {
       0,    47,    48,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    49,    50,    51,
      52
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    47,    48,    48,    49,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      52
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
  "\";\"", "\"{\"", "\"}\"", "\"in\"", "\"typedef\"", "\"void\"",
  "\"_Bool, char, or int\"", "\"let\"", "\"match\"", "\"match!\"",
  "\"if\"", "\"else\"", "\"do\"", "\"fip\"", "\"fn\"", "\"|\"",
  "\"continue\"", "\"break\"", "\"return\"", "\"sizeof\"",
  "\"identifier\"", "\"type identifier\"", "\"integer literal\"",
  "\"string literal\"", "$accept", "translation_unit", "tokens", "token",
  "token_n", "token_s", "token_i", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   102,   102,   105,   106,   109,   116,   128,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     173,   177,   181,   185,   196,   205,   214,   223,   232,   242,
     257
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


#line 7 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"
} // cecko
#line 1651 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.cpp"

#line 262 "/mnt/c/Users/jarom/Desktop/PG_EXER/baka_test_files/FipCompiler/fmwk/ckdumper.y"


namespace cecko {

	void parser::error(const location_type& l, const std::string& m)
	{
		ctx->message(cecko::errors::SYNTAX, l, m);
	}

}
