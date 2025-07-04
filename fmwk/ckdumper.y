%language "c++"
%require "3.4"
// NEVER SET THIS INTERNALLY - SHALL BE SET BY CMAKE: %defines "../private/ckdumper.hpp"
// NEVER SET THIS INTERNALLY - SHALL BE SET BY CMAKE: %output "../private/ckdumper.cpp"
%locations
%define api.location.type {cecko::loc_t}
%define api.namespace {cecko}
%define api.value.type variant
%define api.token.constructor
%define api.parser.class {parser}
%define api.token.prefix {TOK_}
//%define parse.trace
%define parse.assert
%define parse.error verbose

%code requires
{
// this code is emitted to ckdumper.hpp

#include "ckbisonflex.hpp"

// adjust YYLLOC_DEFAULT macro for our api.location.type
#define YYLLOC_DEFAULT(res,rhs,N)	(res = (N)?YYRHSLOC(rhs, 1):YYRHSLOC(rhs, 0))

#include "ckgrptokens.hpp"
#include "ckcontext.hpp"

using token_attr_s = std::pair< cecko::CIName, std::string>;
using token_attr_i = std::pair< cecko::CIName, int>;
}

%code
{
// this code is emitted to ckdumper.cpp

YY_DECL;

}

%param {yyscan_t yyscanner}		// the name yyscanner is enforced by Flex
%param {cecko::context * ctx}

%start translation_unit

%token EOF		0				"end of file"

%token						LBRA		"["
%token						RBRA		"]"
%token						LPAR		"("
%token						RPAR		")"
%token						DOT			"."
%token						NEWLINE		"NEW_LINE"
%token						ARROW		"->"
%token						COMMA		","
%token						AMP			"&"
%token						STAR		"*"
%token<cecko::gt_addop>		ADDOP		"+ or -"
%token						EMPH		"!"
%token<cecko::gt_divop>		DIVOP		"/ or %"
%token<cecko::gt_cmpo>		CMPO		"<, >, <=, or >="
%token<cecko::gt_cmpe>		CMPE		"== or !="
%token						DAMP		"&&"
%token						DVERT		"||"
%token						ASGN		"="
%token						SEMIC		";"
%token						COLON		":"
%token						LCUR		"{"
%token						RCUR		"}"
%token						IN			"in"

%token						TYPEDEF		"type"
%token						VOID		"void"
%token<cecko::gt_etype>		ETYPE		"_Bool, char, or int"
%token						LET			"let"
%token<cecko::match_type> 	MATCH		"match"
%token						IF			"if"
%token						ELSE		"else"
%token						DO			"do"
%token						FIP			"fip"
%token						FN			"fn"
%token						VERT		"|"
%token						CONTINUE	"continue"
%token						BREAK		"break"
%token						RETURN		"return"
%token						SIZEOF		"sizeof"

%token<cecko::CIName>				IDF			"identifier"
%token<cecko::CIName>				TYPEIDF		"type identifier"
%token<int>					INTLIT		"integer literal"
%token<cecko::CIName>				STRLIT		"string literal"

%type<cecko::CIName>					token_n
%type<token_attr_s>			token_s
%type<token_attr_i>					token_i

/////////////////////////////////

%%

translation_unit: 
	tokens
	;

tokens: tokens token
	|
	;

token: token_n{ 
		if (@1)
		{
			ctx->out() << @1 << ": ";
		}
		ctx->out() << $1 << std::endl; 
	}
	| token_s{
		if (@1)
		{
			ctx->out() << @1 << ": ";
		}
		ctx->out() << $1.first;
		if (!$1.second.empty())
		{
			ctx->out() << " " << $1.second;
		}
		ctx->out() << std::endl;
	}
	| token_i{
		if (@1)
		{
			ctx->out() << @1 << ": ";
		}
		ctx->out() << $1.first << " " << $1.second << std::endl;
	}
	;

token_n:
    TYPEDEF { $$ = "typedef"; }
    | VOID				 { $$ = "void"; }
    | LET				 { $$ = "let"; }
    | IF					 { $$ = "if"; }
    | ELSE				 { $$ = "else"; }
    | DO					 { $$ = "do"; }
    | FIP				 { $$ = "fip"; }
    | FN					 { $$ = "fn"; }
    | VERT				 { $$ = "|"; }
    | CONTINUE				 { $$ = "continue"; }
    | NEWLINE				 { $$ = "NEW_LINE"; }
    | RETURN				 { $$ = "return"; }
    | SIZEOF				 { $$ = "sizeof"; }
    | LBRA				 { $$ = "["; }
    | RBRA				 { $$ = "]"; }
    | LPAR				 { $$ = "("; }
    | RPAR				 { $$ = ")"; }
    | DOT					 { $$ = "."; }
    | ARROW				 { $$ = "->"; }
    | COMMA				 { $$ = ","; }
    | AMP					 { $$ = "&"; }
    | STAR				 { $$ = "*"; }
    | EMPH				 { $$ = "!"; }
    | DAMP				 { $$ = "&&"; }
    | DVERT				 { $$ = "||"; }
    | ASGN				 { $$ = "="; }
    | SEMIC				 { $$ = ";"; }
    | LCUR				 { $$ = "{"; }
    | RCUR				 { $$ = "}"; }
    | IN				 { $$ = "in"; }
	| COLON				 { $$ = ":"; }
;

token_s:
	IDF { 
		$$.first = "identifier"; 
		$$.second = ! $1.empty() ? "[" + cecko::context::escape($1) + "]" : ""; 
	}
	| TYPEIDF { 
		$$.first = "type identifier"; 
		$$.second = ! $1.empty() ? "[" + cecko::context::escape($1) + "]" : ""; 
	}
	| STRLIT{ 
		$$.first = "string literal"; 
		$$.second = "\"" + cecko::context::escape($1) + "\"";
	}
    | MATCH				 { 
		$$.first = "match"; 
		switch ($1)
		{
		case cecko::match_type::MATCH: $$.second = ""; break;
		case cecko::match_type::DMATCH: $$.second = "!"; break;
		}
	}
	| CMPO{ 
		$$.first = "CMPO"; 
		switch ($1)
		{
		case cecko::gt_cmpo::LT: $$.second = "<"; break;
		case cecko::gt_cmpo::LE: $$.second = "<="; break;
		case cecko::gt_cmpo::GE: $$.second = ">="; break;
		case cecko::gt_cmpo::GT: $$.second = ">"; break;
		default: $$.second = "?"; break;
		}
	}
	| CMPE{ 
		$$.first = "CMPE"; 
		switch ($1)
		{
		case cecko::gt_cmpe::EQ: $$.second = "=="; break;
		case cecko::gt_cmpe::NE: $$.second = "!="; break;
		default: $$.second = "?"; break;
		}
	}
	| ADDOP{ 
		$$.first = "ADDOP"; 
		switch ($1)
		{
		case cecko::gt_addop::ADD: $$.second = "+"; break;
		case cecko::gt_addop::SUB: $$.second = "-"; break;
		default: $$.second = "?"; break;
		}
	}
	| DIVOP{ 
		$$.first = "DIVOP"; 
		switch ($1)
		{
		case cecko::gt_divop::MOD: $$.second = "%"; break;
		case cecko::gt_divop::DIV: $$.second = "/"; break;
		default: $$.second = "?"; break;
		}
	}
	| ETYPE{ 
		$$.first = "ETYPE"; 
		switch ($1)
		{
		case cecko::gt_etype::BOOL: $$.second = "_Bool"; break;
		case cecko::gt_etype::CHAR: $$.second = "char";  break;
		case cecko::gt_etype::INT: $$.second = "int";  break;
		default: $$.second = "?"; break;
		}
	}
	;

token_i:
	INTLIT{ $$.first = "integer literal"; $$.second = $1; }
	;

/////////////////////////////////

%%

namespace cecko {

	void parser::error(const location_type& l, const std::string& m)
	{
		ctx->message(cecko::errors::SYNTAX, l, m);
	}

}
