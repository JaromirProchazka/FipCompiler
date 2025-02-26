%language "c++"
%require "3.4"
// NEVER SET THIS INTERNALLY - SHALL BE SET BY CMAKE: %defines "../private/caparser.hpp"
// NEVER SET THIS INTERNALLY - SHALL BE SET BY CMAKE: %output "../private/caparser.cpp"
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
}

%code
{
// this code is emitted to caparser.cpp

YY_DECL;

using namespace casem;
}

%param {yyscan_t yyscanner}		// the name yyscanner is enforced by Flex
%param {cecko::context * ctx}

%start translation_unit

%token EOF		0				"end of file"

%token						LBRA		"["
%token						RBRA		"]"
%token						LPAR		"("
%token						RPAR		")"

%token						ARROW		"->"
%token						COMMA		","
%token						AMP			"&"
%token						VERT		"|"
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
%token						LCUR		"{"
%token						RCUR		"}"

%token						TYPEDEF		"typedef"
%token						SIZEOF		"sizeof"
%token                      IN          "in"
%token                      LET         "let"
%token                      MATCH       "match"
%token                      DMATCH      "match!"
%token                      FIP         "fip"
%token                      FN          "fn"

%token<cecko::CIName>		IDF			"identifier"
%token<cecko::CIName>		TYPEIDF		"type identifier"
%token<int>					INTLIT		"integer literal"
%token<cecko::CIName>		STRLIT		"string literal"



/////////////////////////////////

%%

// %type<casem::CKTypeRefDefPack>          declaration_specifiers
// %type<casem::CKTypeRefDefPack>          declaration_specifier
// %type<cecko::CKTypeSafeObs>             type_specifier
// %type<casem::CKTypeRefDefPack>          type_specifier_qualifier
// %type<casem::CKTypeRefDefPack>          specifier_qualifier_list

// %type<casem::TypeRefPack_Action>        member_declarator_list
// %type<casem::TypeRefPack_Action>        init_declarator_list
// %type<casem::TypeRefPack_Action>        init_declarator
// %type<casem::TypeRefPack_Action>        member_declarator
// %type<casem::TypeRefPack_Action>        declarator
// %type<casem::TypeRefPack_Action>        direct_declarator
// %type<casem::TypeRefPack_Action>        array_declarator
// %type<casem::TypeRefPack_Action>        function_declarator
// %type<cecko::CIName>                    enumeration_constant

// %type<cecko::CKStructItemArray>         member_declaration
// %type<cecko::CKStructItemArray>         member_declaration_list

// %type<casem::TRDArray>                  parameter_type_list
// %type<casem::TRDArray>                  parameter_list
// %type<casem::CKTypeRefDefPack>          parameter_declaration
// %type<casem::TypeRefPack_Action>        abstract_declarator
// %type<casem::TypeRefPack_Action>        direct_abstract_declarator
// %type<casem::TypeRefPack_Action>        function_abstract_declarator
// %type<casem::TypeRefPack_Action>        array_abstract_declarator

// %type<cecko::CKTypeObs>                 type_name
// %type<cecko::CIName>                    typedef_name

// %type<cecko::gt_cass>                   assignment_operator
// %type<casem::InstructionArray>          argument_expression_list
// %type<casem::InstructionWrapper>        assignment_expression
// %type<casem::InstructionWrapper>        primary_expression
// %type<casem::InstructionWrapper>        postfix_expression
// %type<casem::InstructionWrapper>        unary_expression
// %type<casem::InstructionWrapper>        cast_expression
// %type<casem::InstructionWrapper>        multiplicative_expression
// %type<casem::InstructionWrapper>        additive_expression
// %type<casem::InstructionWrapper>        relational_expression
// %type<casem::InstructionWrapper>        equality_expression
// %type<casem::InstructionWrapper>        logical_and_expression
// %type<casem::InstructionWrapper>        logical_or_expression
// %type<casem::InstructionWrapper>        expression 
// %type<casem::InstructionWrapper>        expression_opt
// %type<casem::UnaryOperator>             unary_operator

// %type<cecko::CKIRBasicBlockObs>         expression_statement
// %type<cecko::CKIRBasicBlockObs>         compound_statement
// %type<cecko::CKIRBasicBlockObs>         compound_statement_body
// %type<cecko::CKIRBasicBlockObs>         block_item_list
// %type<cecko::CKIRBasicBlockObs>         block_item
// %type<cecko::CKIRBasicBlockObs>         statement
// %type<cecko::CKIRBasicBlockObs>         non_split_statement
// %type<cecko::CKIRBasicBlockObs>         split_statement
// %type<cecko::CKIRBasicBlockObs>         jump_statement
// %type<casem::IfControllFlowData>        if_statement_head
// %type<casem::IfControllFlowData>        if_non_split_statement
// %type<casem::IfControllFlowData>        if_non_split_statement_else

// %type<casem::WhileControllFlowData>     while_statement_head
// %type<casem::WhileControllFlowData>     do_statement_head

/*
%type<T> a // nonterminal with type T

add_expr:
    mul_expr { $$ = $1; }
    | add_expr ADD mul_expr { $$ = $1 + $3; } 
        // the $n denotes attribute of nth element in the rule ($$ <=> $0 <=> add_expr<T>) 
    | add_expr SUB mul_expr { $$ = $1 - $3; }
        // if none rule given, default is { $$ = $1; } 
    ;

doxymentation: https://www.ksi.mff.cuni.cz/teaching/nswi098-web/doxy/html/structcecko_1_1CKContext.html
*/

/////////////////////////////////

/////////////////////////////////
// Create rules for external definitions
/////////////////////////////////

// FIXME: DEBUG translation_unit, delete me later
translation_unit:
	INTLIT ADDOP INTLIT
	| 
	;


// translation_unit:
//     external_declaration
//     | translation_unit external_declaration
// ;

// external_declaration:
//     function_definition
//     | declaration
// ;

// function_definition:
//     function_definition_head block_item_list RCUR   {
//         log("[function_definition:] with BODY, if not returned explicitely, we void return here\n");
//         if (! ctx->builder()->GetInsertBlock() || ctx->current_function_return_type()->is_void()) {
//             ctx->builder()-> CreateRetVoid();
//         }

//         ctx->exit_function();
//     }
//     | function_definition_head RCUR   {
//         log("[function_definition:] with EMPTY BODY, implicite void return\n");
//         ctx->builder()-> CreateRetVoid();
//         ctx->exit_function();
//     }
// ;

// function_definition_info: 
//     declaration_specifiers declarator   {
//         log("[function_definition_info:]\n");
//         auto cur_l = ctx->line();
//         casem::TypeRefPack_Action DEFINER_BODY = $2;
//         casem::CKTypeRefDefPack rfpack = $1;

//         casem::CKTypeRefDefPack res_tpack = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));

//         cur_l--;
//         if (res_tpack.name.value() == "main" && cur_l != 0) {
//             log("decrementing loc\n");
//         }
//         cecko::CKFunctionSafeObs f_observer = ctx->declare_function(res_tpack.name.value(), res_tpack.type, cur_l);

//         ctx->enter_function(f_observer, res_tpack.optinonal_param_names, ctx->line());
//     }
// ;

// function_definition_head:
//     function_definition_info LCUR {
//         log("[function_definition_head:]");
//     }
// ;
//////////////////////////////////////////////////////////////////////////////////
// Notes
//////////////////////////////////////////////////////////////////////////////////
// Types: Built-in, TYPEIDF, const
// Pointer, Function
// Declarations: Variable, Function
// Expressions: Integer literals
// Statements: Return
//////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////
// Create rules for expressions 
/////////////////////////////////

// primary_expression:
//     enumeration_constant    {
//         log("[primary_expression:] name\n");
//         $$ = init_instruction_from_name(ctx, $1);
//     }
//     | INTLIT    {
//         //CKIRConstantIntObs
//         log("[primary_expression:] Found int lit '%d'\n", (int)$1);
//         $$ = init_instruction_const(ctx, $1);
//     }
//     | STRLIT    {
//         log_name("[primary_expression:] Found string lit ", $1);
//         // (StringRef Str, const Twine &Name = "", unsigned AddressSpace = 0, Module *M = nullptr, bool AddNull = true)	
//         $$ = init_instruction_const(ctx, $1);
//     }
//     | LPAR expression RPAR  {
//         $$ = $2;
//     }
// ;

// postfix_expression:
//     primary_expression      {
//         $$ = $1;
//     }
//     | postfix_expression LBRA expression RBRA   {
//         log("[postfix_expression:] postfix_expression [ expression ]\n");
//         // $$ = $1;
//     }
//     | postfix_expression LPAR argument_expression_list RPAR     {
//         log("[postfix_expression:] FUNCTION CALL, postfix_expression ( expression )\n");
//         $$ = init_instruction_function_call(ctx, $1, $3);
//     }
//     | postfix_expression ARROW IDF              {
//         log_name("[postfix_expression:] postfix_expression -> IDF", $3);
//         // $$ = $1;
//     }
// ;

// argument_expression_list:
//     assignment_expression   {
//         casem::InstructionArray args = { $1 };
//         $$ = args;
//     }
//     | argument_expression_list COMMA assignment_expression  {
//         casem::InstructionArray args = $1;
//         args.push_back($3);
//         $$ = args;
//     }
//     | %empty    {
//         casem::InstructionArray args = {};
//         $$ = args;
//     }
// ;

// unary_expression:
//     postfix_expression  {
//         log("[unary_expression:]>");
//         $$ = $1;
//     }
//     | unary_operator cast_expression    {
//         log("[unary_expression:] unary_operator cast_expression\n");
//         switch ($1) {
//         case AMPERSANT:
//             $$ = &($2);
//             break;
//         case STAR:
//             $$ = *($2);
//             break;
//         case SUB_S:
//             $$ = -($2);
//             break;
//         case ADD_S:
//             $$ = $2; 
//             break;
//         case EXCALMATION_MARK:
//             $$ = !($2);
//             break;
//         }
//     }
//     | SIZEOF LPAR type_name RPAR        {
//         log("[unary_expression:] SIZEOF LPAR type_name RPAR\n");
//         $$ = InstructionWrapper(
//             ctx,
//             RValue,
//             ctx->get_type_size($3),
//             ctx->get_int_type(),
//             true,
//             "size_of");
//     }
// ;

// unary_operator:
//     AMP         { $$ = AMPERSANT; }
//     | STAR      { $$ = STAR; }
//     | ADDOP     { 
//         switch ($1) {
//         case cecko::gt_addop::ADD:
//             $$ = ADD_S;
//             break;
//         case cecko::gt_addop::SUB:
//             $$ = SUB_S;
//             break;
//         }
//     }
//     | EMPH      { $$ = EXCALMATION_MARK; }
// ;

// cast_expression:
//     unary_expression        {
//         // log("[cast_expression:]>");
//         $$ = $1;
//     }
// ;

// multiplicative_expression:
//     cast_expression     {
//         // log("[multiplicative_expression:]>");
//         $$ = $1;
//     }
//     | multiplicative_expression STAR cast_expression    {
//         log("[multiplicative_expression:] multiplicative_expression * cast_expression\n");
//         $$ = ($1) * ($3);
//     }
//     | multiplicative_expression DIVOP cast_expression    {
//         log("[multiplicative_expression:] multiplicative_expression / cast_expression\n");
//         switch ($2) {
//         case cecko::gt_divop::DIV: 
//             $$ = ($1) / ($3);
//             break;
//         case cecko::gt_divop::MOD:
//             $$ = ($1) % ($3);
//             break;
//         }
//     }
// ;

// additive_expression:
//     multiplicative_expression   {
//         // log("[multiplicative_expression:]>");
//         $$ = $1;
//     }
//     | additive_expression ADDOP multiplicative_expression   {
//         log("[additive_expression:] additive_expression + multiplicative_expression\n");
//         switch ($2) {
//         case cecko::gt_addop::ADD:
//             $$ = ($1) + ($3);
//             break;
//         case cecko::gt_addop::SUB:
//             $$ = ($1) - ($3);
//             break;
//         }
//     }
// ;

// relational_expression:
//     additive_expression     {
//         // log("[relational_expression:]>");
//         $$ = $1;
//     }
//     | relational_expression CMPO additive_expression     {
//         log("[relational_expression:] relational_expression <,>,<=,>= additive_expression\n");
//         // $$ = $1;
//     }
// ;

// equality_expression:
//     relational_expression   {
//         // log("[equality_expression:]>");
//         $$ = $1;
//     }
//     | equality_expression CMPE relational_expression    {
//         log("[equality_expression:] equality_expression ==,!= relational_expression\n");
//         // $$ = $1;
//     }
// ;


// logical_and_expression:
//     equality_expression     {
//         // log("[logical_and_expression:]>");
//         $$ = $1;
//     }
//     | logical_and_expression DAMP equality_expression     {
//         log("[logical_and_expression:] logical_and_expression && equality_expression\n");
//         // $$ = $1;
//     }
// ;

// logical_or_expression:
//     logical_and_expression     {
//         // log("[logical_or_expression:]>");
//         $$ = $1;
//     }
//     | logical_or_expression DVERT logical_and_expression         {
//         log("[logical_or_expression:] logical_or_expression || logical_and_expression\n");
//         // $$ = $1;
//     }
// ;

// assignment_expression:
//     logical_or_expression   {
//         // log("[assignment_expression:]>");
//         $$ = $1;
//     }
//     | unary_expression assignment_operator assignment_expression    {
//         log("[assignment_expression:] unary_expression assignment_operator assignment_expression\n");
//         switch ($2) {
//         case cecko::gt_cass::MULA:
//             $$ = ($1).store($1 * $3);
//             break; 
//         case cecko::gt_cass::DIVA:
//             $$ = ($1).store($1 / $3);
//             break; 
//         case cecko::gt_cass::MODA:
//             $$ = ($1).store($1 % $3);
//             break; 
//         case cecko::gt_cass::ADDA:
//             $$ = ($1).store($1 + $3);
//             break;
//         case cecko::gt_cass::SUBA:
//             $$ = ($1).store($1 - $3);
//             break;
//         default:
//             // normal assignment =
//             $$ = ($1).store($3);
//         }
//         $$ = $1;
//     }
// ;

// assignment_operator:
//     ASGN  {
//         $$ = (cecko::gt_cass)1000;
//     }
// ;

// expression:
//     assignment_expression   {
//         $$ = $1;
//     }
// ;

// constant_expression:
//     logical_or_expression
// ;

/////////////////////////////////
// Create rules for declarations
/////////////////////////////////

// declaration:
//     no_leading_attribute_declaration
// ;

// no_leading_attribute_declaration:
//     declaration_specifiers init_declarator_list SEMIC   {
//         log("[no_leading_attribute_declaration:] > call lambda\n");
//         casem::TypeRefPack_Action DEFINER_BODY = $2;
//         casem::CKTypeRefDefPack rfpack = $1;

//         DEFINER_BODY(rfpack, std::function(CHOOSE_AND_DEFINE)); // returns the final type of the defined
//         log("\n\n");
//     }
// ;

// declaration_specifiers:
//     declaration_specifier   { 
//             log("[declaration_specifiers:] ^ simply give refpack from declaration_specifier to the list\n");
//             $$ = $1;
//         }
//     | declaration_specifier declaration_specifiers  {
//             log("[declaration_specifiers:] take the list and update its info by the new element\n");
//             casem::CKTypeRefDefPack rfpack = $2;

//             if (rfpack.type == NULL && ($1).type != NULL) {
//                 rfpack.type = ($1).type;
//             }
//             else if (rfpack.is_const == false && ($1).is_const == true) {
//                 rfpack.is_const = true;
//             }
//             else if (rfpack.has_typedef == false && ($1).has_typedef == true) {
//                 casem::CKTypeRefDefPack new_rfpack(rfpack.type, rfpack.is_const, true);
//                 rfpack = new_rfpack;
//             }
//             else {
//                 ctx->message(errors::INVALID_SPECIFIERS, ctx->line());
//             }

//             $$ = rfpack;
//         }
// ;

// declaration_specifier:
//     storage_class_specifier { 
//             casem::CKTypeRefDefPack rfpack;
//             rfpack.has_typedef = true;
//             $$ = rfpack;
//         }
//     | type_specifier_qualifier {
//             log("[declaration_specifier:] ^ Found type_specifier_qualifier ");
//             casem::CKTypeRefDefPack rpack;
//             if (($1).type) {
//                 log("with set type, ");
//                 rpack.type = ($1).type;
//             }
//             else {
//                 log("with not set type, ");
//             }
//             if (($1).is_const) {
//                 log("with set const");
//                 rpack.is_const = true;
//             }
//             else {
//                 log("with not set const");
//                 rpack.is_const = false;
//             }
//             log("\n");
//             $$ = rpack;
//         }
// ;

// init_declarator_list:
//     init_declarator     { 
//         log("[init_declarator_list:] v \n");
//         $$ = $1;
//     }
//     | init_declarator_list COMMA init_declarator    {
//         log("[init_declarator_list:] v give refpack to init_declarator and the list\n");
//         $$ = GET_CALL_SEQUENCE_LINK($1, $3);
//     }
//     // | %empty    {}
// ;

// init_declarator:
//     declarator  {
//         log("[init_declarator:] v found declarator and gave it refpack\n");
//         $$ = $1;
//     }
// ;

// storage_class_specifier:
//     TYPEDEF
// ;

// type_specifier:
//     // | ETYPE { 
//     //     log("[type_specifier:] ^ Found ETYPE '"); 
//     //     switch ($1) {
//     //         case cecko::gt_etype::INT:
//     //             log("INT'\n");
//     //             $$ = ctx->get_int_type();
//     //             break;
//     //         case cecko::gt_etype::CHAR:
//     //             log("CHAR'\n");
//     //             $$ = ctx->get_char_type();
//     //             break;
//     //         case cecko::gt_etype::BOOL:
//     //             log("BOOL'\n");
//     //             $$ = ctx->get_bool_type();
//     //             break;
//     //     }
//     //  }
//     typedef_name  {
//             log("[type_specifier:] ^ found typedef_name '%s'\n", ($1).c_str());
//             auto type_def_data = ctx->find_typedef($1);
//             if (type_def_data) {
//                 $$ = type_def_data->get_type_pack().type;
//             }
//             else {
//                 std::string e_msg = "Undefined type '" + $1 + "'!\n";
//                 ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
//             }
//         }
// ;

// member_declaration_list:
//     member_declaration      {
//         $$ = $1;
//     }
//     | member_declaration_list member_declaration    {
//         cecko::CKStructItemArray s_items = $1;
//         s_items.push_back($2[0]);
//         $$ = s_items;
//     }
// ;

// member_declaration:
//     specifier_qualifier_list member_declarator_list SEMIC   { 
//         log("[member_declaration:] give refpack to member_declarator_list\n");
//         casem::TypeRefPack_Action DEFINER_BODY = $2;
//         casem::CKTypeRefDefPack rfpack = $1;

//         casem::CKTypeRefDefPack final_type = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));
//         cecko::CKStructItem s_item(final_type, final_type.name.value(), ctx->line());

//         cecko::CKStructItemArray s_items = { s_item };
//         $$ = s_items;
//      }
// ;

// specifier_qualifier_list:
//     type_specifier_qualifier    { 
//         log("[specifier_qualifier_list:] ^ type_specifier_qualifier\n");
//         $$ = $1;
//      }
//     | type_specifier_qualifier specifier_qualifier_list { 
//         log("[specifier_qualifier_list:] ^ type_specifier_qualifier specifier_qualifier_list\n");
//         auto t = $2;
//         auto nt = $1;
//         if (!t.is_const && nt.is_const) {
//             t.is_const = true;
//         }
//         else if (t.type == NULL && nt.type) {
//             t.type = nt.type;
//         }
//         else {
//             ctx->message(errors::INVALID_SPECIFIERS, ctx->line());
//         }

//         $$ = t;
//      }
// ;

// type_specifier_qualifier:
//     type_specifier  { 
//             log("[type_specifier_qualifier:] ^ Found type_specifier\n"); 
//             casem::CKTypeRefDefPack t($1, false, false);
//             $$ = t;
//         }
// ;

// member_declarator_list:
//     member_declarator   {
//         $$ = $1;
//     }
//     | member_declarator_list COMMA member_declarator    {
//         $$ = GET_CALL_SEQUENCE_LINK($1, $3);
//     }
//     // | %empty    {
//     //     $$ = {};
//     // }
// ;

// member_declarator:
//     declarator      {
//         $$ = $1;
//     }
// ;

// enumerator_list:
//     enumerator
//     | enumerator_list COMMA enumerator
// ;

// // enumerator:
// //     enumeration_constant {
// //         log("[enumerator:] constant\n");
// //     }
// //     | enumeration_constant ASGN constant_expression {
// //         log("[enumerator:] ASGN\n");
// //     }
// // ;

// enumeration_constant:
//     IDF     {
//         log_name("[enumeration_constant:]", $1);
//         $$ = $1;
//     }
// ;

// declarator:
//     direct_declarator {
//             log("[declarator:] v found direct_declarator, gave refpack to it\n");
//             $$ = $1;    // giving the casem::CKTypeRefDefPack(type, is_const, has_typedef)
//         }
// ;

// direct_declarator:
//     IDF { 
//         auto name = $1;
//         log_name("[direct_declarator:] .() found IDF and define LAMBDA", name);

//         $$ = GET_DEFINER(ctx, name);
//     }
//     | LPAR declarator RPAR  {
//         log("[direct_declarator:] ^ found (declarator) and gave it refpack\n");
//         $$ = $2;
//     }
//     | array_declarator      {
//         log("[direct_declarator:] v found array_declarator\n");
//         $$ = $1;
//     }
//     | function_declarator   {
//         log("[direct_declarator:] v found function_declarator\n");
//         $$ = $1;
//     }
// ;

// array_declarator:
//     direct_declarator LBRA assignment_expression RBRA   {
//         log("[array_declarator:] direct_declarator [ assignment_expression ]\n");
//         if (($3).mode != casem::VarMode::LValue) {
//             auto value = static_cast<cecko::CKIRConstantIntObs>(($3).value);
//             $$ = GET_ARRAY_ADDER(ctx, $1, value);
//         }
//         else {
//             // FIXME: Handle LVal
//         }
//     }
// ;

// function_declarator:
//     direct_declarator LPAR parameter_type_list RPAR {
//         log("[function_declarator:] v< wrap current lambdas rfpack in function\n");
//         //ctx->get_function_type(CKTypeObs ret_type, CKTypeObsArray arg_types, bool variadic=false)
//         // GET_FUNCTION_ADDER(cecko::context *ctx, TypeRefPack_Action old_action, CKTypeObsArray arg_types);
//         bool is_variadic = ($3).back().is_variadic;
//         if (is_variadic) log("FOUND VARIADIC ... on args len = %d\n", (int)($3).size());
//         cecko::CKFunctionFormalPackArray param_names;
//         for (auto& name_pack : ($3)) {
//             if (name_pack.optinonal_param_names.size() > 0)
//                 param_names.push_back(name_pack.optinonal_param_names[0]);
//         }
//         cecko::CKTypeObsArray param_types;
//         for (auto& pt : ($3)) {
//             if (pt.is_variadic) break; 
//             param_types.push_back(pt.type);
//         }

//         // TypeRefPack_Convertor UNPACK_PARAMETERS([](casem::CKTypeRefDefPack &rfpack) {
//         // }); 

//         $$ = GET_FUNCTION_ADDER(ctx, $1, param_types, is_variadic, param_names);
//     }
// ;

// parameter_type_list:
//     parameter_list {
//         log("[parameter_type_list:] ^ parameter_list\n");
//         $$ = $1;
//     }
// ;

// parameter_list:
//     parameter_declaration   {
//         log("[parameter_list:] ^ init parameter_list\n");
//         if (($1).type->is_void()) {
//             std::vector<casem::CKTypeRefDefPack> empty_param_array;
//             $$ = empty_param_array;
//         }
//         else {
//             std::vector<casem::CKTypeRefDefPack> param_array = { $1 };
//             $$ = param_array;
//         }
//     }
//     | parameter_list COMMA parameter_declaration {
//         log("[parameter_list:] ^ push_back to parameter_list\n");
//         if (($3).type->is_void()) {
//             log("ERROR: non-first void argument!\n");
//             ctx->message(cecko::errors::INVALID_FUNCTION_TYPE, ctx->line());
//         }
//         else {
//             auto param_array = $1;
//             if (param_array.back().is_variadic) {
//                 log("ERROR: non-last variadic argument!\n");
//                 ctx->message(cecko::errors::INVALID_FUNCTION_TYPE, ctx->line());
//             }
//             else {
//                 param_array.push_back($3);
//                 $$ = param_array;
//             }
//         }
//     }
// ;

// parameter_declaration:
//     declaration_specifiers declarator   { 
//         // FIXME: Send also the cecko::CKFunctionFormalPackArray to the function_definition 
//         // and from it to declarator and up

//         log("[parameter_declaration:] ^ found declaration_specifiers declarator, sent up the type observer\n");
//         casem::TypeRefPack_Action DEFINER_BODY = $2;
//         casem::CKTypeRefDefPack rfpack = $1;

//         // TODO: Add the param name to the rfpack.optinonal_param_names
//         // We give declarator a definer, that just adds to the 
//         // rfpack.optinonal_param_names the name and returs the rfpack back 
//         DefinerFunction PARAM_NAME_ADDER([](cecko::context *ctx, const cecko::CIName &name, CKTypeRefDefPack &rfpack) {
//             log("lambda from [parameter_declaration:] add named param to rfpack.optinonal_param_names and return it\n");
//             CKFunctionFormalPack param(std::make_optional(name), rfpack.is_const, ctx->line());
//             rfpack.optinonal_param_names.push_back(param);

//             return rfpack;
//         });

//         auto param_typepack = DEFINER_BODY(rfpack, PARAM_NAME_ADDER);
//         if (param_typepack.has_typedef) {
//             ctx->message(errors::INVALID_SPECIFIERS, ctx->line());
//         }

//         $$ = param_typepack;
//     }
//     | declaration_specifiers abstract_declarator    {
//         log("[parameter_declaration:] ^ found declaration_specifiers abstract_declarator\n");
//         casem::TypeRefPack_Action DEFINER_BODY = $2;
//         casem::CKTypeRefDefPack rfpack = $1;

//         auto param_typepack = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));

//         $$ = param_typepack;
//     }
//     | declaration_specifiers                        {
//         log("[parameter_declaration:] ^ found declaration_specifiers\n");
//         casem::CKTypeRefDefPack rfpack = $1;
//         $$ = rfpack;
//     }
// ;

// type_name:
//     specifier_qualifier_list abstract_declarator    {
//         log("[member_declaration:] give refpack to member_declarator_list\n");
//         casem::TypeRefPack_Action DEFINER_BODY = $2;
//         casem::CKTypeRefDefPack rfpack = $1;

//         casem::CKTypeRefDefPack final_type = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));

//         $$ = final_type.type;
//     }
//     | specifier_qualifier_list  {
//         $$ = ($1).type;
//     }
// ;

// abstract_declarator:
//     direct_abstract_declarator     {
//         log("[abstract_declarator:] found direct_abstract_declarator\n");
//         $$ = $1;
//     }
// ;

// direct_abstract_declarator:
//     LPAR abstract_declarator RPAR   {
//         log("[direct_abstract_declarator:] ( abstract_declarator )\n");
//         $$ = $2;
//     }
//     | array_abstract_declarator     {
//         log("[direct_abstract_declarator:] array_abstract_declarator\n");
//         $$ = $1;
//     }
//     | function_abstract_declarator  {
//         log("[direct_abstract_declarator:] function_abstract_declarator\n");
//         $$ = $1;
//     }
// ;

// array_abstract_declarator:
//     direct_abstract_declarator LBRA assignment_expression RBRA  {
//         log("[array_abstract_declarator:] direct_abstract_declarator [ assignment_expression ]\n");
//         auto value = static_cast<cecko::CKIRConstantIntObs>(($3).value);
//         $$ = GET_ARRAY_ADDER(ctx, $1, value);
//     }
//     | LBRA assignment_expression RBRA   {
//         log("[array_abstract_declarator:] [ assignment_expression ]\n");
//         auto value = static_cast<cecko::CKIRConstantIntObs>(($2).value);
//         $$ = GET_ARRAY_ADDER(ctx, GET_DEFINER(ctx, ""), value);
//     }
// ;

// function_abstract_declarator:
//     direct_abstract_declarator LPAR parameter_type_list RPAR    {
//         log("[function_abstract_declarator:] direct_abstract_declarator LPAR parameter_type_list RPAR\n");
//         $$ = GET_FUNCTION_ADDER(ctx, $1, casem::get_types_from_tpacks($3), false);
//     }
//     | LPAR parameter_type_list RPAR {
//         log("[function_abstract_declarator:] LPAR parameter_type_list RPAR\n");
//         $$ = GET_FUNCTION_ADDER(ctx, GET_DEFINER(ctx, ""), casem::get_types_from_tpacks($2), false);
//     }
// ;

// typedef_name:
//     TYPEIDF     { $$ = $1; }
// ;

/////////////////////////////////
// Create rules for statements
/////////////////////////////////

// // statement:
// //     non_split_statement     {
// //         log("[statement:] non_split_statement\n");
// //         $$ = $1;
// //     }
// //     | split_statement       {
// //         log("[statement:] split_statement\n");
// //         $$ = $1;
// //     }
// // ;

// compound_statement_head:
//     LCUR        {
//         log("ENTER BLOCK\n");
//         ctx->enter_block();
//     }
// ;

// compound_statement:
//     compound_statement_head compound_statement_body   {
//         log("[compound_statement:] found { block_item_list }\n");
//         $$ = $2;
//     }
// ;

// compound_statement_body:
//     block_item_list RCUR        {
//         $$ = $1;

//         ctx->exit_block();
//         log("EXITING BLOCK\n");
//     }
//     | RCUR      {
//         ctx->exit_block();
//         log("EXITING BLOCK\n");

//         $$ = ctx->builder()->GetInsertBlock();
//     }
// ;

// block_item_list:
//     block_item      {
//         log("[block_item_list:] block_item\n");
//         $$ = $1;
//     }
//     | block_item_list block_item    {
//         log("[block_item_list:] block_item_list block_item\n");
//         $$ = $2;
//     }
// ;

// block_item:
//     declaration {
//         log("[block_item:] declaration\n");
//         $$ = ctx->builder()->GetInsertBlock();
//     }
//     // | statement {
//     //     log("[block_item:] statement\n");
//     //     $$ = $1;
//     // }
// ;

// expression_statement:
//     expression_opt SEMIC    {
//         log("[expression_statement:] expression_opt SEMIC\n");
//         $$ = ctx->builder()->GetInsertBlock();
//     }
// ;

// expression_opt:
//     expression  {
//         $$ = $1;
//     }
//     | %empty    {
        
//     }
// ;

///////////////////////////////////////////////////////
// if_statement_head:
//     IF LPAR expression RPAR     {
//         log("[if_statement_head:] IF LPAR expression RPAR\n");
//         $$ = init_if_data(ctx, $3);
//     }
// ;

// if_non_split_statement:
//     if_statement_head non_split_statement   {
//         log("[if_non_split_statement:] if_statement_head non_split_statement\n");
//         auto data = $1;
//         if ($2 != NULL) data.if_block_back = $2;
//         $$ = data;
//     }
// ;

// if_non_split_statement_else:
//     if_non_split_statement ELSE   {
//         log("[if_non_split_statement_else:] if_non_split_statement ELSE: ");
//         auto data = $1;
//         data.else_block = ctx->create_basic_block("if.else");
//         data.else_block_back = data.else_block;
//         log("SWITCHING to else_block_back\n");
//         ctx->builder()->SetInsertPoint(data.else_block_back);

//         $$ = data;
//     }
// ;

///////////////////////////////////////////////////////
// while_statement_head:
//     WHILE LPAR expression RPAR  {
//         $$ = init_while_data(ctx, $3);
//     }
// ;
///////////////////////////////////////////////////////
// do_statement_head:
//     DO  {
//         $$ = init_do_data(ctx);
//     }
// ;
///////////////////////////////////////////////////////

// non_split_statement:
//     if_non_split_statement_else non_split_statement    {
//         log("non_split_statement: if_non_split_statement_else non_split_statement: ");
//         auto data = $1;
//         if ($2 != NULL) data.else_block_back = $2;
//         log("SWITCHING to continue_block\n");
//         ctx->builder()->SetInsertPoint(data.continue_block);
//         $$ = create_if_control_flow(ctx, data);
//     }
//     | while_statement_head non_split_statement    {
//         $$ = create_while_control_flow(ctx, $1);
//     }
//     | FOR LPAR expression_opt SEMIC expression_opt SEMIC expression_opt RPAR non_split_statement    {
//         // FIXME: Implement
//         $$ = ctx->builder()->GetInsertBlock();
//     }
//     | do_statement_head non_split_statement WHILE LPAR expression RPAR SEMIC    {
//         auto data = $1;
//         data.code_block_back = $2;
//         $$ = create_do_control_flow(ctx, $1, $5);
//     }
//     | jump_statement    {
//         log("[non_split_statement:] jump_statement\n");
//         $$ = $1;
//     }
//     | expression_statement    {
//         log("[non_split_statement:] jump_statement\n");
//         $$ = $1;
//     }
//     | compound_statement    {
//         log("[non_split_statement:] jump_statement\n");
//         $$ = $1;
//     }
// ;

// split_statement:
//     if_statement_head statement    {
//         log("[split_statement:] if_statement_head statement\n");
//         auto data = $1;
//         if ($2 != NULL) data.if_block_back = $2;
//         ctx->builder()->SetInsertPoint(data.continue_block);
//         $$ = create_if_control_flow(ctx, data);
//     }
//     | if_non_split_statement_else split_statement    {
//         log("[split_statement:] if_non_split_statement_else split_statement\n");
//         auto data = $1;
//         if ($2 != NULL) data.else_block_back = $2;
//         ctx->builder()->SetInsertPoint(data.continue_block);
//         $$ = create_if_control_flow(ctx, data);
//     }
//     | while_statement_head split_statement    {
//         $$ = create_while_control_flow(ctx, $1);
//     }
//     | FOR LPAR expression_opt SEMIC expression_opt SEMIC expression_opt RPAR split_statement    {
//         // FIXME: Implement
//         $$ = ctx->builder()->GetInsertBlock();
//     }
//     | do_statement_head split_statement WHILE LPAR expression RPAR SEMIC    {
//         auto data = $1;
//         data.code_block_back = $2;
//         $$ = create_do_control_flow(ctx, $1, $5);
//     }
// ;

// jump_statement:
//     RETURN expression_opt SEMIC {
//         log("[jump_statement:] ");
//         // auto ret_obs = static_cast<cecko::CKIRConstantIntObs>($2);
//         auto ret_obs = $2;
//         if (ret_obs.is_valid()) {
//             log("return val\n");
//             if (ret_obs.type != ctx->current_function_return_type())
//                 ctx->builder()->CreateRet(ret_obs.to_type(ctx->current_function_return_type()->get_ir()).read_ir());
//             else
//                 ctx->builder()->CreateRet(ret_obs.read_ir());
//         }
//         else {
//             log("return void\n");
//             ctx->builder()->CreateRetVoid();
//         }

//         ctx->builder()->ClearInsertionPoint();
//         $$ = ctx->builder()->GetInsertBlock();
//     }
// ;

/////////////////////////////////

%%

namespace cecko {

	void parser::error(const location_type& l, const std::string& m)
	{
		ctx->message(cecko::errors::SYNTAX, l, m);
	}
}
