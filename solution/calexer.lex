%{

// allow access to YY_DECL macro
#include "ckbisonflex.hpp"
#include "casem.hpp"
#include <stdlib.h>

#include INCLUDE_WRAP(BISON_HEADER)

%}

/* NEVER SET %option outfile INTERNALLY - SHALL BE SET BY CMAKE */

%option noyywrap nounput noinput
%option batch never-interactive reentrant
%option nounistd 

/* AVOID backup perf-report - DO NOT CREATE UNMANAGEABLE BYPRODUCT FILES */

%x		COMMENT
%x		STRUCT_DEF

%x		STR
%x		STR_SPECIALCHAR

%x		LETTER
%x		LETTER_SPECIALCHAR
%x		LETTER_FOUND


dig					[0-9]
nonzero				[1-9]
alpha				[A-Za-z]
alphanum			[A-Za-z0-9]
hexdec				[0-9A-Fa-f]
ESCAPE_FLAGS		[\\nt\"\']|x[0-9a-fA-F]*



%%

%{
#include <string>
#include <stdexcept>
#include <utility>
#include <iostream>

std::string strval = "";
int commentnest = 0;
std::string msg = "";

%}


"in"				return cecko::parser::make_IN(ctx->line());
"let"				return cecko::parser::make_LET(ctx->line());
"match"				return cecko::parser::make_MATCH(cecko::match_type::MATCH, ctx->line());
"match!"			return cecko::parser::make_MATCH(cecko::match_type::DMATCH, ctx->line());
"fip"				return cecko::parser::make_FIP(ctx->line());
"fn"				return cecko::parser::make_FN(ctx->line());
"|"					return cecko::parser::make_VERT(ctx->line());
"if"				return cecko::parser::make_IF(ctx->line());
"else"				return cecko::parser::make_ELSE(ctx->line());

"type"			return cecko::parser::make_TYPEDEF(ctx->line());
"sizeof"			return cecko::parser::make_SIZEOF(ctx->line());
"_Bool"				return cecko::parser::make_ETYPE(cecko::gt_etype::BOOL, ctx->line());
"char"				return cecko::parser::make_ETYPE(cecko::gt_etype::CHAR, ctx->line());
"int"				return cecko::parser::make_ETYPE(cecko::gt_etype::INT, ctx->line());

"["        			return cecko::parser::make_LBRA(ctx->line());
"]"        			return cecko::parser::make_RBRA(ctx->line());
"("        			return cecko::parser::make_LPAR(ctx->line());
")"        			return cecko::parser::make_RPAR(ctx->line());
"{"        			return cecko::parser::make_LCUR(ctx->line());
"}"        			return cecko::parser::make_RCUR(ctx->line());

"->"        		return cecko::parser::make_ARROW(ctx->line());
","         		return cecko::parser::make_COMMA(ctx->line());
"*"        			return cecko::parser::make_STAR(ctx->line());
"+"	    			return cecko::parser::make_ADDOP(cecko::gt_addop::ADD, ctx->line());
"-"					return cecko::parser::make_ADDOP(cecko::gt_addop::SUB, ctx->line());
"!"         		return cecko::parser::make_EMPH(ctx->line());
"/"       			return cecko::parser::make_DIVOP(cecko::gt_divop::DIV, ctx->line());
"%"					return cecko::parser::make_DIVOP(cecko::gt_divop::MOD, ctx->line());
"<"					return cecko::parser::make_CMPO(cecko::gt_cmpo::LT, ctx->line()); 
"<="				return cecko::parser::make_CMPO(cecko::gt_cmpo::LE, ctx->line()); 
">"					return cecko::parser::make_CMPO(cecko::gt_cmpo::GT, ctx->line()); 
">="				return cecko::parser::make_CMPO(cecko::gt_cmpo::GE, ctx->line()); 
"=="     			return cecko::parser::make_CMPE(cecko::gt_cmpe::EQ, ctx->line());  
"!="				return cecko::parser::make_CMPE(cecko::gt_cmpe::NE, ctx->line()); 
"&&"        		return cecko::parser::make_DAMP(ctx->line());
"||"      			return cecko::parser::make_DVERT(ctx->line());
"="         		return cecko::parser::make_ASGN(ctx->line());
";"         		return cecko::parser::make_SEMIC(ctx->line());
":"         		return cecko::parser::make_COLON(ctx->line());

\/\/.*\n			ctx->incline(); 
\/\*				{ 
	BEGIN(COMMENT); 
	commentnest = 1; 
}
\*\/				ctx->message(cecko::errors::UNEXPENDCMT, ctx->line());
<COMMENT>\/\*		{ commentnest++; }
<COMMENT>\*\/		{
	commentnest--;
	if (commentnest == 0) {
		BEGIN(INITIAL);
	}
}
<COMMENT>\n			ctx->incline();
<COMMENT><<EOF>>	{
	ctx->message(cecko::errors::EOFINCMT, ctx->line());
	BEGIN(INITIAL);
}
<COMMENT>[^\n]		;

\"										{ 
	BEGIN(STR); 
	strval = ""; 
}
<STR>\\									{
	BEGIN(STR_SPECIALCHAR);
}
<STR_SPECIALCHAR>{ESCAPE_FLAGS}			{ 
	bool stat = casem::escape_interp(yytext, strval);
	if (!stat) {
		msg = std::string("\\") + std::string(yytext);
		ctx->message(cecko::errors::BADESCAPE, ctx->line(), msg);
	}
	BEGIN(STR);
}
<STR_SPECIALCHAR>\n						{
	msg = std::string("\\");
	ctx->message(cecko::errors::BADESCAPE, ctx->line(), msg);
	ctx->message(cecko::errors::EOLINSTRCHR, ctx->line());
	int l = ctx->line();
	ctx->incline();
	BEGIN(INITIAL);
	return cecko::parser::make_STRLIT(strval, l);
}		
<STR_SPECIALCHAR>.						{
	msg = std::string("\\") + std::string(yytext);
	ctx->message(cecko::errors::BADESCAPE, ctx->line(), msg);
	strval += yytext[0];
	BEGIN(STR);
}
<STR>\"									{
	BEGIN(INITIAL);
	return cecko::parser::make_STRLIT(strval, ctx->line());
}
<STR>\n									{
	ctx->message(cecko::errors::EOLINSTRCHR, ctx->line());
	int l = ctx->line();
	ctx->incline();
	BEGIN(INITIAL);
	return cecko::parser::make_STRLIT(strval, l);
}
<STR><<EOF>>							{ 
	ctx->message(cecko::errors::EOFINSTRCHR, ctx->line());
	BEGIN(INITIAL);
	return cecko::parser::make_STRLIT(strval, ctx->line());
}
<STR>[^\n]								{
	strval.append(std::string(yytext));
}

\'										{
	strval = "";
	BEGIN(LETTER);
}
<LETTER>\\								{
	BEGIN(LETTER_SPECIALCHAR);
}
<LETTER_SPECIALCHAR>{ESCAPE_FLAGS}		{
	bool stat = casem::escape_interp(yytext, strval);
	if (!stat) {
		msg = std::string("\\") + std::string(yytext);
		ctx->message(cecko::errors::BADESCAPE, ctx->line(), msg);
	}
	BEGIN(LETTER_FOUND);
}
<LETTER_SPECIALCHAR>\n					{
	msg = std::string("\\");
	ctx->message(cecko::errors::BADESCAPE, ctx->line(), msg);
	ctx->message(cecko::errors::EOLINSTRCHR, ctx->line()); 
	int l = ctx->line();
	ctx->incline();
	BEGIN(INITIAL);
	return cecko::parser::make_INTLIT(0, l);
}		
<LETTER_SPECIALCHAR>.					{
	msg = std::string("\\") + std::string(yytext);
	ctx->message(cecko::errors::BADESCAPE, ctx->line(), msg);
	strval += yytext[0];
	BEGIN(LETTER_FOUND);
}
<LETTER>\'								{
	ctx->message(cecko::errors::EMPTYCHAR, ctx->line());
	BEGIN(INITIAL);
	return cecko::parser::make_INTLIT(0, ctx->line());
}
<LETTER>\n								{ 
	ctx->message(cecko::errors::EOLINSTRCHR, ctx->line()); 
	ctx->incline(); 
	strval += (char)0;
	BEGIN(LETTER_FOUND); 
}
<LETTER><<EOF>>							{ 
	ctx->message(cecko::errors::EOFINSTRCHR, ctx->line()); 
	BEGIN(INITIAL);
}
<LETTER>[^\n]							{
	std::string schar = std::string(yytext);
	strval += schar;
	BEGIN(LETTER_FOUND);
}

<LETTER_FOUND>\'						{
	int c = static_cast<unsigned char>(strval[0]);
	strval = "";
	BEGIN(INITIAL);
	return cecko::parser::make_INTLIT(c, ctx->line());
}
<LETTER_FOUND><<EOF>>					{
	ctx->message(cecko::errors::EOFINSTRCHR, ctx->line()); 
	BEGIN(INITIAL); 
	int c = static_cast<unsigned char>(strval[0]);
	strval = "";
	return cecko::parser::make_INTLIT(c, ctx->line());
}
<LETTER_FOUND>[^\']						{
	ctx->message(cecko::errors::UNTERMCHAR, ctx->line());
	BEGIN(INITIAL);
	return cecko::parser::make_INTLIT(strval[0], ctx->line());
}

0[xX][0-9A-Fa-f]*[g-zG-Z_][_A-Za-z0-9]+	{
	ctx->message(cecko::errors::BADINT, ctx->line(), yytext);

	int i = 0;
	if (!casem::safe_str_to_int(casem::num_prefix(yytext, false).c_str(), false, i)) {
		ctx->message(cecko::errors::INTOUTRANGE, ctx->line(), yytext);
	}
	return cecko::parser::make_INTLIT(i, ctx->line()); 
}
[0-9]+[_A-Za-z]+						{
	ctx->message(cecko::errors::BADINT, ctx->line(), yytext);

	int i = 0;
	if (!casem::safe_str_to_int(casem::num_prefix(yytext, true).c_str(), true, i)) {
		ctx->message(cecko::errors::INTOUTRANGE, ctx->line(), yytext);
	}
	return cecko::parser::make_INTLIT(i, ctx->line());
}

0[xX][0-9A-Fa-f]*						{
	int i = 0;
	if (!casem::safe_str_to_int(yytext, false, i)) {
		ctx->message(cecko::errors::INTOUTRANGE, ctx->line(), yytext);
	}
	return cecko::parser::make_INTLIT(i, ctx->line()); 
}
[1-9][0-9]*|0							{
	int i = 0;
	if (!casem::safe_str_to_int(yytext, true, i)) {
		ctx->message(cecko::errors::INTOUTRANGE, ctx->line(), yytext);
	}
	return cecko::parser::make_INTLIT(i, ctx->line());
}
[_A-Za-z][_A-Za-z0-9]*					{
	if (ctx->is_typedef(yytext)) {
		return cecko::parser::make_TYPEIDF(std::string(yytext), ctx->line());
	}
	return cecko::parser::make_IDF(std::string(yytext), ctx->line());
}

[\n][ \t\r]									ctx->incline(); 
[\n]+									{ 
	int n_count = std::string(yytext).size();
	for (int i = 0; i < n_count; i++) {
		ctx->incline(); 
	}
	return cecko::parser::make_NEWLINE(ctx->line());
}												
[ \t\r]            				;
.								ctx->message(cecko::errors::UNCHAR, ctx->line(), yytext);

<<EOF>>							return cecko::parser::make_EOF(ctx->line());

%%

namespace cecko {
	yyscan_t lexer_init(FILE * iff)
	{
		yyscan_t scanner;
		yylex_init(&scanner);
		yyset_in(iff, scanner);
		return scanner;
	}

	void lexer_shutdown(yyscan_t scanner)
	{
		yyset_in(nullptr, scanner);
		yylex_destroy(scanner);
	}
}