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
#include <stdlib.h>

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

%token						NEWLINE		"NEW_LINE"
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
%token						COLON		":"
%token						LCUR		"{"
%token						RCUR		"}"

%token						TYPEDEF		"type"
%token<cecko::gt_etype>		ETYPE		"_Bool, char, or int"
%token						SIZEOF		"sizeof"
%token                      IN          "in"
%token                      LET         "let"
%token<cecko::match_type>   MATCH       "match"
%token                      FIP         "fip"
%token                      FN          "fn"
%token						IF			"if"
%token						ELSE		"else"

%token<cecko::CIName>		IDF			"identifier"
%token<cecko::CIName>		TYPEIDF		"type identifier"
%token<int>					INTLIT		"integer literal"
%token<cecko::CIName>		STRLIT		"string literal"




%type<casem::InstructionWrapper>        primary_expression
%type<casem::InstructionWrapper>        unary_expression
%type<casem::InstructionWrapper>        cast_expression
%type<casem::InstructionWrapper>        multiplicative_expression
%type<casem::InstructionWrapper>        additive_expression
%type<casem::InstructionWrapper>        relational_expression
%type<casem::InstructionWrapper>        equality_expression
%type<casem::InstructionWrapper>        logical_and_expression
%type<casem::InstructionWrapper>        logical_or_expression
%type<casem::InstructionWrapper>        expression 
%type<casem::InstructionWrapper>        expression_body
%type<casem::UnaryOperator>             unary_operator
%type<casem::InstructionWrapper>        postfix_expression
%type<cecko::gt_cass>                   assignment_operator
%type<casem::InstructionWrapper>        assignment_expression
%type<casem::InstructionWrapper>        match_expression
%type<cecko::CKTypeSafeObs>             type_specifier
%type                                   expression_end
%type<cecko::CIName>                    typedef_name
%type<cecko::CIName>                    declared_type_name
%type<casem::CKTypeRefDefPack>          declaration_specifiers
%type<casem::CKTypeRefDefPack>          declaration_specifier
%type<casem::CKTypeRefDefPack>          type_specifier_qualifier
%type<casem::TypeRefPack_Action>        declarator
%type<casem::TypeRefPack_Action>        direct_declarator
%type<casem::TypeRefPack_Action>        function_declarator
%type<casem::FunctionDeclarationData>   function_definition_info
%type<casem::FunctionDeclarationData>   function_definition_head
%type<casem::TRDArray>                  parameter_type_list
%type<casem::TRDArray>                  parameter_list
%type<casem::TypeRefPack_Convertor>     pointer
%type<casem::CKTypeRefDefPack>          parameter_declaration
%type<casem::MatchWrapper>              match_head
%type<casem::MatchWrapper>              match_binders_list

%type<casem::TaggedTypeDecl>            enumtype_decl_head
%type<cecko::CKStructTypeSafeObs>       enumtype_decl_specifier
%type<cecko::CKStructTypeSafeObs>       member_types_declaration
%type<casem::StructObservers>           member_types_declaration_list
%type<cecko::CKStructItemArray>         member_declaration_list
%type<cecko::CKStructItemArray>         member_declaration
%type<casem::CKTypeRefDefPack>          specifier_qualifier_list
%type<casem::TypeRefPack_Action>        member_declarator
%type<casem::InstructionArray>          argument_expression_list
%type<std::vector<cecko::CIName>>       match_binder_arguments_list
%type<casem::MatchBinderChackerData>    match_binder_definer
%type<casem::MatchBinderChackerData>    match_binder_head
%type<casem::MatchBinderListHeadData>   match_binders_list_head_start
%type<casem::MatchBinderListHeadData>   match_binders_list_head

%type<casem::IfExpressionData>          flow_expression
%type<casem::IfExpressionData>          non_split_expression
%type<casem::IfExpressionData>          split_expression
%type<casem::IfExpressionData>          if_expression_head
%type<casem::IfExpressionData>          if_non_split_expression
%type<casem::IfExpressionData>          if_non_split_expression_else
%type<casem::IfExpressionData>          expression_statement

/////////////////////////////////

%%

/*
%type<T> a // nonterminal with type T

doxymentation: https://www.ksi.mff.cuni.cz/teaching/nswi098-web/doxy/html/structcecko_1_1CKContext.html
*/

/////////////////////////////////

/////////////////////////////////
// Create rules for external definitions
/////////////////////////////////


translation_unit:
    external_declaration
    | translation_unit external_declaration
;

external_declaration:
    function_definition
    | enumtype_decl_specifier    {
        log("[declaration:] found enumtype_decl_specifier (line: %i)\n", (int)ctx->line());
        // $$ = $1;
    }
;

new_lines:
    NEWLINE
    | new_lines NEWLINE
;

expression_end:
    new_lines
    | EOF
;

function_definition:
    function_definition_head expression  {
        log("[function_definition:] with BODY, if not returned explicitely, we void return here (line: %i)\n", (int)ctx->line());

        log("jump_statement: ");
        // auto ret_obs = static_cast<cecko::CKIRConstantIntObs>($2);
        auto ret_obs = $2;
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
    | function_definition_info SEMIC expression_end   {
        log("[function_definition:] function_definition_info SEMIC (line: %i)\n", (int)ctx->line());
    }
;

function_definition_info: 
    declaration_specifiers declarator   {
        log("[function_definition_info:] (line: %i)\n", (int)ctx->line());
        casem::declare_support_functions(ctx);
        auto cur_l = ctx->line();
        casem::TypeRefPack_Action DEFINER_BODY = $2;
        casem::CKTypeRefDefPack rfpack = $1;

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
        $$ = res;
    }
;

function_definition_head:
    function_definition_info ASGN {
        log("[function_definition_head:] function_definition_info ASGN (line: %i)\n", (int)ctx->line());
        casem::CKTypeRefDefPack res_tpack = ($1).fun_type;
        auto f_observer = ($1).fun_obs;
        auto rfpack = ($1).fun_rfpack;
        ctx->enter_function(f_observer, res_tpack.optinonal_param_names, ctx->line());
        auto fip_state = casem::FipState::GetFipState();
        if (rfpack.is_fip) {
            log("{FipState} function_definition_info - entering fip function '"+res_tpack.name.value()+"' declaration\n");
            fip_state->enter_fip_mode();
            fip_state->enter_fip_context();
        }
        log("[function_definition_head:] function body entered\n");

        $$ = $1;
    }
;

/////////////////////////////////
// Create rules for expressions 
/////////////////////////////////

primary_expression:
    INTLIT    {
        //CKIRConstantIntObs
        log("[primary_expression:] Found int lit '%d' (line: %i)\n", (int)$1, (int)ctx->line());
        $$ = init_instruction_const(ctx, $1);
    }
    | STRLIT    {
        log_name("[primary_expression:] Found string lit ", $1);
        // (StringRef Str, const Twine &Name = "", unsigned AddressSpace = 0, Module *M = nullptr, bool AddNull = true)	
        $$ = init_instruction_const(ctx, $1);
    }
    | LPAR expression_body RPAR  {
        $$ = $2;
    }
;

postfix_expression:
    primary_expression     {
        $$ = $1;
    }
    | IDF LPAR argument_expression_list RPAR     {
        log("[postfix_expression:] FUNCTION CALL, IDF:'"+$1+"' ( expression ) (line: "+std::to_string(ctx->line())+")\n");
        $$ = casem::handle_postfix_expression_fcall(ctx, $1, $3);
    }
    | IDF   {
        auto &&label = $1;    
        log("[postfix_expression:] FUNCTION CALL, IDF:'" + label + "'(line: "+std::to_string(ctx->line())+")\n");
        if (casem::is_struct_label(ctx, label))
        {
            $$ = casem::handle_postfix_expression_fcall(ctx, label, {});
        }
        else {
            $$ = casem::init_instruction_from_name(ctx, label);
        }
    }
;

// TODO: APPLICATION RULE
// application_rule:
//     postfix_expression argument_expression_list
// ;

// TODO: BOXING RULE
// unboxing_rule:
//     LPAR argument_expression_list RPAR {
//         $$ = $2;
//     }
// ;

argument_expression_list:
    assignment_expression   {
        casem::InstructionArray args = { $1 };
        $$ = args;
    }
    | argument_expression_list COMMA assignment_expression  {
        auto &args = $1;
        args.push_back($3);
        $$ = args;
    }
    | %empty                  {
        casem::InstructionArray args = {};
        $$ = args;
    }
;

unary_expression:
    postfix_expression  {
        // log("[unary_expression:]>");
        $$ = $1;
    } 
    | unary_operator cast_expression    { 
        log("[unary_expression:] unary_operator cast_expression (line: %i)\n", (int)ctx->line());
        switch ($1) {
        case AMPERSANT:
            $$ = &($2);
            break;
        case STAR:
            $$ = *($2);
            break;
        case SUB_S:
            $$ = -($2);
            break;
        case ADD_S:
            $$ = $2; 
            break;
        case EXCALMATION_MARK:
            $$ = !($2);
            break;
        }
    } 
;

unary_operator:
    AMP         { $$ = AMPERSANT; }
    | STAR      { $$ = STAR; }
    | ADDOP     { 
        switch ($1) {
        case cecko::gt_addop::ADD:
            $$ = ADD_S;
            break;
        case cecko::gt_addop::SUB:
            $$ = SUB_S;
            break;
        }
    }
    | EMPH      { $$ = EXCALMATION_MARK; }
;

cast_expression:
    unary_expression        {
        // log("[cast_expression:]>");
        $$ = $1;
    }
;

multiplicative_expression:
    cast_expression     {
        // log("[multiplicative_expression:]>");
        $$ = $1;
    }
    | multiplicative_expression STAR cast_expression    {
        log("[multiplicative_expression:] multiplicative_expression * cast_expression (line: %i)\n", (int)ctx->line());
        $$ = ($1) * ($3);
    }
    | multiplicative_expression DIVOP cast_expression    {
        log("[multiplicative_expression:] multiplicative_expression / cast_expression (line: %i)\n", (int)ctx->line());
        switch ($2) {
        case cecko::gt_divop::DIV: 
            $$ = ($1) / ($3);
            break;
        case cecko::gt_divop::MOD:
            $$ = ($1) % ($3);
            break;
        }
    }
;

additive_expression:
    multiplicative_expression   {
        // log("[multiplicative_expression:]>");
        $$ = $1;
    }
    | additive_expression ADDOP multiplicative_expression   {
        log("[additive_expression:] additive_expression + multiplicative_expression (line: %i)\n", (int)ctx->line());
        switch ($2) {
        case cecko::gt_addop::ADD:
            $$ = ($1) + ($3);
            break;
        case cecko::gt_addop::SUB:
            $$ = ($1) - ($3);
            break;
        }
    }
;

relational_expression:
    additive_expression     {
        // log("[relational_expression:]>");
        $$ = $1;
    }
    | relational_expression CMPO additive_expression     {
        log("[relational_expression:] relational_expression <,>,<=,>= additive_expression (line: %i)\n", (int)ctx->line());
        switch ($2) {
        case cecko::gt_cmpo::LT:
            $$ = ($1) < ($3);
            break;
        case cecko::gt_cmpo::LE:
            $$ = ($1) <= ($3);
            break;
        case cecko::gt_cmpo::GT:
            log("[relational_expression:] GT -- found t0 > t1\n");
            $$ = ($1) > ($3);
            log("[relational_expression:] GT -- returnsed instruction\n");
            break;
        case cecko::gt_cmpo::GE:
            $$ = ($1) >= ($3);
            break;
        }
    }
;

equality_expression:
    relational_expression   {
        // log("[equality_expression:]>");
        $$ = $1;
    }
    | equality_expression CMPE relational_expression    {
        log("[equality_expression:] equality_expression ==,!= relational_expression (line: %i)\n", (int)ctx->line());
        switch ($2) {
        case cecko::gt_cmpe::EQ:
            $$ = ($1) == ($3);
            break;
        case cecko::gt_cmpe::NE:
            $$ = ($1) != ($3);
            break;
        }
    }
;


logical_and_expression:
    equality_expression     {
        // log("[logical_and_expression:]>");
        $$ = $1;
    }
    | logical_and_expression DAMP equality_expression     {
        log("[logical_and_expression:] logical_and_expression && equality_expression (line: %i)\n", (int)ctx->line());
        // $$ = $1;
    }
;

logical_or_expression:
    logical_and_expression     {
        // log("[logical_or_expression:]>");
        $$ = $1;
    }
    | logical_or_expression DVERT logical_and_expression         {
        log("[logical_or_expression:] logical_or_expression || logical_and_expression (line: %i)\n", (int)ctx->line());
        // $$ = $1;
    }
;

assignment_expression:
    logical_or_expression   {
        log(std::string("")+"[assignment_expression:]{"+($1).name+"}>");
        $$ = $1;
    }
    | unary_expression assignment_operator assignment_expression    {
        log("[assignment_expression:] unary_expression assignment_operator assignment_expression (line: %i)", (int)ctx->line());
        switch ($2) {
        case cecko::gt_cass::MULA:
            $$ = ($1).store($1 * $3);
            break; 
        case cecko::gt_cass::DIVA:
            $$ = ($1).store($1 / $3);
            break; 
        case cecko::gt_cass::MODA:
            $$ = ($1).store($1 % $3);
            break; 
        case cecko::gt_cass::ADDA:
            $$ = ($1).store($1 + $3);
            break;
        case cecko::gt_cass::SUBA:
            $$ = ($1).store($1 - $3);
            break;
        default:
            // normal assignment =
            $$ = ($1).store($3);
        }
        log(std::string("")+" = "+($1).name+"\n");
        $$ = $1;
    }
;

assignment_operator:
    ASGN  {
        $$ = (cecko::gt_cass)1000;
    }
;

match_head:
    MATCH assignment_expression ARROW declaration_specifiers  {
        log(std::string("")+"[match_head:] MATCH IDF{"+($2).name+"} ARROW declaration_specifiers "+std::to_string(ctx->line())+"\n");
        $$ = init_match_head(ctx, $1, $2, $4);
    }
;

match_expression:
    assignment_expression   {
        $$ = $1;
    }
    | match_binders_list block_end    {
        log("[match_expression:] MATCH IDF ARROW declaration_specifiers block_start match_binders_list block_end (line: %i)\n", (int)ctx->line());
        casem::MatchWrapper match_data = $1;
        log("[match_expression:] if (match_data.is_first_pattern_null_check)\n");
        if (match_data.is_first_pattern_null_check) {
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
        $$ = match_data.result;
    }
;

match_binders_list:
    match_binders_list_head_start expression_body  {
        log("[match_binders_list:] match_binders_list_head_start expression_body (line: %i)\n", (int)ctx->line());
        $$ = init_match_binders_list(ctx, $1, $2);
    }
    | match_binders_list_head expression_body  {
        log("[match_binders_list:] match_binders_list_head expression_body (line: %i)\n", (int)ctx->line());
        $$ = init_match_binders_list(ctx, $1, $2);
    }
;

match_binders_list_head_start:
    match_head block_start match_binder_head {
        log("[match_binders_list_head_start:] match_head block_start match_binder_head (line: %i)\n", (int)ctx->line());
        log(std::string("")+"[match_binders_list_head_start:] the checked label is "+($3).type_label+" which null ttype is "+std::to_string(casem::is_null_ttype(($3).type_label))+"\n");
        $$ = MatchBinderListHeadData::init_match_binders_list_head(ctx, $1, $3, casem::is_null_ttype(($3).type_label));
    }
;

match_binders_list_head:
    match_binders_list match_binder_head {
        log("[match_binders_list_head:] match_binders_list match_binder_head (line: %i)\n", (int)ctx->line());
        $$ = MatchBinderListHeadData::init_match_binders_list_head(ctx, $1, $2);
    }
;

match_binder_head:
    VERT match_binder_definer ARROW     {
        log(std::string("")+"[match_binder_head:] VERT match_binder_definer{"+($2).type_label+"} ARROW (line: "+std::to_string(ctx->line())+")\n");
        $$ = $2;
    }
;

match_binder_definer:
    IDF LPAR match_binder_arguments_list RPAR   {
        log("[match_binder_definer:] IDF LPAR match_binder_arguments_list RPAR (line: %i)\n", (int)ctx->line());
        $$ = casem::MatchBinderChackerData($1).set_args(ctx, $3);
    }
    | IDF   {
        log("[match_binder_definer:] IDF (line: %i)\n", (int)ctx->line());
        $$ = casem::MatchBinderChackerData($1);
    }
;

match_binder_arguments_list:
    IDF    { 
        log("[match_binder_arguments_list:] IDF (line: %i)\n", (int)ctx->line());
        $$ = { $1 };
    }
    | match_binder_arguments_list COMMA IDF {
        log("[match_binder_arguments_list:] match_binder_arguments_list COMMA IDF (line: %i)\n", (int)ctx->line());
        ($1).push_back($3);
        $$ = $1;
    }
;

expression_body:
    match_expression  {
        $$ = $1;
    }
    | flow_expression {
        $$ = ($1).result;
    }
;

expression:
    expression_body expression_end {
        $$ = $1;
    }
;

/////////////////////////////////
// Create rules for declarations
/////////////////////////////////

declaration_specifiers:
    declaration_specifier   { 
            log("[declaration_specifiers:] ^ simply give refpack from declaration_specifier to the list (line: %i)\n", (int)ctx->line());
            $$ = $1;
        }
    | declaration_specifier declaration_specifiers  {
            log("[declaration_specifiers:] take the list and update its info by the new element (line: %i)\n", (int)ctx->line());
            casem::CKTypeRefDefPack rfpack = $2;

            if (rfpack.type == NULL && ($1).type != NULL) {
                rfpack.type = ($1).type;
            }
            else if (rfpack.is_const == false && ($1).is_const == true) {
                rfpack.is_const = true;
            }
            else if (rfpack.has_typedef == false && ($1).has_typedef == true) {
                casem::CKTypeRefDefPack new_rfpack(rfpack.type, rfpack.is_const, true, rfpack.is_fip);
                rfpack = new_rfpack;
            }
            else if ( !rfpack.is_fip && ($1).is_fip) {
                rfpack.is_fip = ($1).is_fip;
            }
            else {
                ctx->message(errors::INVALID_SPECIFIERS, ctx->line());
            }

            $$ = rfpack;
        }
;

declaration_specifier:
    type_specifier_qualifier {
            log("[declaration_specifier:] ^ Found type_specifier_qualifier ");
            casem::CKTypeRefDefPack rpack;
            if (($1).type) {
                log("with set type, ");
                rpack.type = ($1).type;
            }
            else {
                log("with not set type, ");
            }
            if (($1).is_const) {
                log("with set const");
                rpack.is_const = true;
            }
            else {
                log("with not set const");
                rpack.is_const = false;
            }
            log("\n");
            $$ = rpack;
        }
    | FIP   {
        log("[declaration_specifier:] Found FIP (line: %i)\n", (int)ctx->line());
        casem::CKTypeRefDefPack rfpack;
        rfpack.is_fip = true;
        $$ = rfpack;
    }
;

type_specifier:
    ETYPE { 
        log("[type_specifier:] ^ Found ETYPE '"); 
        switch ($1) {
            case cecko::gt_etype::INT:
                log("INT' (line: %i)\n", (int)ctx->line());
                $$ = ctx->get_int_type();
                break;
            case cecko::gt_etype::CHAR:
                log("CHAR' (line: %i)\n", (int)ctx->line());
                $$ = ctx->get_char_type();
                break;
            case cecko::gt_etype::BOOL:
                log("BOOL' (line: %i)\n", (int)ctx->line());
                $$ = ctx->get_bool_type();
                break;
        }
     }
    | declared_type_name    {
        auto&& type = ctx->declare_struct_type($1, ctx->line());
        if (type && type->is_defined())  {
            $$ = ctx->get_pointer_type(cecko::CKTypeRefPack(type, false));
        }
        else {
            std::string e_msg = "Undefined type '" + $1 + "'!\n";
            ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
        }
    }
    | typedef_name  {
            log("[type_specifier:] ^ found typedef_name '%s' (line: %i)\n", ($1).c_str(), (int)ctx->line());
            auto type_def_data = ctx->find_typedef($1);
            if (type_def_data) {
                $$ = type_def_data->get_type_pack().type;
            }
            else {
                std::string e_msg = "Undefined type '" + $1 + "'!\n";
                ctx->message(cecko::errors::SYNTAX, ctx->line(), e_msg);
            }
        }
;

declared_type_name:
    TYPEDEF IDF     {
        log_name("[declared_type_name:] TYPEDEF IDF", $2);
        $$ = $2;
    }
;

enumtype_decl_head:
    TYPEDEF IDF     {
        casem::declare_support_functions(ctx);
        $$ = declare_parent_ttype(ctx, $2);
    }
;

block_start:
    LCUR
    | LCUR new_lines 
;

block_end:
    RCUR
    | new_lines RCUR
;

enumtype_decl_specifier:
    enumtype_decl_head block_start member_types_declaration_list block_end new_lines  {
        log("[enumtype_decl_specifier:] enumtype_decl_head block_start member_types_declaration_list block_end new_lines (line: %i)\n", (int)ctx->line());
        $$ = TaggedTypeDecl::finish_parent_ttype(ctx, $1);
    }
;

member_types_declaration_list:
    member_types_declaration     {
        log("[member_types_declaration_list:] member_types_declaration (line: %i)\n", (int)ctx->line());
        StructObservers vec = { $1 };
        $$ = vec;
    }
    | member_types_declaration_list member_types_declaration      {
        log("[member_types_declaration_list:] member_types_declaration_list member_types_declaration (line: %i)\n", (int)ctx->line());
        auto&& vec = $1; 
        vec.push_back($2);
        $$ = vec;
    }
;

member_types_declaration:
    IDF LPAR member_declaration_list RPAR SEMIC     {
        log_name("[member_types_declaration:] includes member_declaration_list", $1);
        $$ = casem::declare_child_ttype(ctx, $1, $3);
    }
    | IDF SEMIC    {
        log_name("[member_types_declaration:] found IDF SEMIC", $1);
        $$ = casem::declare_child_ttype(ctx, $1);
    }
;

member_declaration_list:
    member_declaration      {
        log("[member_declaration_list:] member_declaration (line: %i)\n", (int)ctx->line());
        $$ = $1;
    }
    | member_declaration_list COMMA member_declaration    {
        log("[member_declaration_list:] member_declaration_list COMMA member_declaration (line: %i)\n", (int)ctx->line());
        cecko::CKStructItemArray s_items = $1;
        s_items.push_back($3[0]);
        $$ = s_items;
    }
;

member_declaration:
    specifier_qualifier_list member_declarator   { 
        log("[member_declaration:] give refpack to member_declarator_list (line: %i)\n", (int)ctx->line());
        casem::TypeRefPack_Action DEFINER_BODY = $2;
        casem::CKTypeRefDefPack rfpack = $1;

        casem::CKTypeRefDefPack final_type = DEFINER_BODY(rfpack, std::function(FETCH_FINAL_TYPEPACK));
        cecko::CKStructItem s_item(final_type, final_type.name.value(), ctx->line());

        cecko::CKStructItemArray s_items = { s_item };
        $$ = s_items;
     }
;

specifier_qualifier_list:
    type_specifier_qualifier    { 
        log("[specifier_qualifier_list:] ^ type_specifier_qualifier (line: %i)\n", (int)ctx->line());
        $$ = $1;
     }
    | type_specifier_qualifier specifier_qualifier_list { 
        log("[specifier_qualifier_list:] ^ type_specifier_qualifier specifier_qualifier_list (line: %i)\n", (int)ctx->line());
        auto t = $2;
        auto nt = $1;
        if (!t.is_const && nt.is_const) {
            t.is_const = true;
        }
        else if (t.type == NULL && nt.type) {
            t.type = nt.type;
        }
        else {
            ctx->message(errors::INVALID_SPECIFIERS, ctx->line());
        }

        $$ = t;
     }
;

type_specifier_qualifier:
    type_specifier  { 
            log("[type_specifier_qualifier:] ^ Found type_specifier (line: %i)\n", (int)ctx->line()); 
            casem::CKTypeRefDefPack t($1, false, false, false);
            $$ = t;
        }
;

member_declarator:
    declarator      {
        $$ = $1;
    }
;

declarator:
    pointer direct_declarator {
        log("[declarator:] >v found pointer direct_declarator define LAMBDA (line: %i)\n", (int)ctx->line());
        auto DEFINER_F = $2;
        auto POINTER_F = $1;

        $$ = GET_POINTER_ADDER(POINTER_F, DEFINER_F);
    }
    | direct_declarator {
        log("[declarator:] v found direct_declarator, gave refpack to it (line: %i)\n", (int)ctx->line());
        $$ = $1;   
    }
;

pointer:
    STAR pointer  {
        auto LOWER_POINTER = $2;
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            POINTER_TO_DEFINER = [LOWER_POINTER, this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, false, rfpack.has_typedef, rfpack.is_fip);
                return LOWER_POINTER(pointer_pack);
            };

        $$ = POINTER_TO_DEFINER;
    }
    | STAR      {
        std::function<casem::CKTypeRefDefPack(casem::CKTypeRefDefPack&)> 
            POINTER_TO_DEFINER = [this](casem::CKTypeRefDefPack rfpack) {
                auto pt = ctx->get_pointer_type(rfpack);
                casem::CKTypeRefDefPack pointer_pack(pt, false, rfpack.has_typedef, rfpack.is_fip);
                return pointer_pack;
            };

        $$ = POINTER_TO_DEFINER;
    }
;

direct_declarator:
    IDF { 
        auto name = $1;
        log_name("[direct_declarator:] .() found IDF and define LAMBDA", name);

        $$ = GET_DEFINER(ctx, name);
    }
    | function_declarator   {
        log("[direct_declarator:] v found function_declarator (line: %i)\n", (int)ctx->line());
        $$ = $1;
    }
;

function_declarator: 
    direct_declarator LBRA parameter_type_list RBRA  {
        log("[function_declarator:] direct_declarator LBRA parameter_type_list RBRA -- v< wrap current lambdas rfpack in function (line: %i)\n", (int)ctx->line());
        bool is_variadic = (($3).empty()) ? false : ($3).back().is_variadic;
        if (is_variadic) log("FOUND VARIADIC ... on args len = %d\n", (int)($3).size());
        cecko::CKFunctionFormalPackArray param_names;
        for (auto& name_pack : ($3)) {
            if (name_pack.optinonal_param_names.size() > 0)
                param_names.push_back(name_pack.optinonal_param_names[0]);
        }
        cecko::CKTypeObsArray param_types;
        for (auto& pt : ($3)) {
            if (pt.is_variadic) break; 
            param_types.push_back(pt.type);
        }


        $$ = GET_FUNCTION_ADDER(ctx, $1, param_types, is_variadic, param_names);
    }
;

parameter_type_list:
    parameter_list {
        log("[parameter_type_list:] ^ parameter_list (line: %i)\n", (int)ctx->line());
        $$ = $1;
    }
    | %empty      {
        std::vector<casem::CKTypeRefDefPack> empty_param_array;
        $$ = empty_param_array;
    }
;

parameter_list:
    parameter_declaration   {
        log("[parameter_list:] ^ init parameter_list (line: %i)\n", (int)ctx->line());
        if (($1).type->is_void()) {
            std::vector<casem::CKTypeRefDefPack> empty_param_array;
            $$ = empty_param_array;
        }
        else {
            std::vector<casem::CKTypeRefDefPack> param_array = { $1 };
            $$ = param_array;
        }
    }
    | parameter_list COMMA parameter_declaration {
        log("[parameter_list:] ^ push_back to parameter_list (line: %i)\n", (int)ctx->line());
        if (($3).type->is_void()) {
            log("ERROR: non-first void argument!\n");
            ctx->message(cecko::errors::INVALID_FUNCTION_TYPE, ctx->line());
        }
        else {
            auto param_array = $1;
            if (param_array.back().is_variadic) {
                log("ERROR: non-last variadic argument!\n");
                ctx->message(cecko::errors::INVALID_FUNCTION_TYPE, ctx->line());
            }
            else {
                param_array.push_back($3);
                $$ = param_array;
            }
        }
    }
;

parameter_declaration:
    declaration_specifiers declarator   { 

        log("[parameter_declaration:] ^ found declaration_specifiers declarator, sent up the type observer (line: %i)\n", (int)ctx->line());
        casem::TypeRefPack_Action DEFINER_BODY = $2;
        casem::CKTypeRefDefPack rfpack = $1;
         
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

        $$ = param_typepack;
    }
    | declaration_specifiers                        {
        log("[parameter_declaration:] ^ found declaration_specifiers (line: %i)\n", (int)ctx->line());
        casem::CKTypeRefDefPack rfpack = $1;
        $$ = rfpack;
    }
;

typedef_name:
    TYPEIDF     { $$ = $1; }
;

/////////////////////////////////
// Create rules for statements
/////////////////////////////////


expression_statement:
    match_expression SEMIC    {
        log("[expression_statement:] expression_opt SEMIC (line: %i)\n", (int)ctx->line());
        IfExpressionData res;
        res.result = $1;
        res.block = ctx->builder()->GetInsertBlock();

        $$ = res;
    }
;


///////////////////////////////////////////////////////
if_expression_head:
    IF LPAR expression_body RPAR     {
        log(std::string("")+"[if_expression_head:] IF LPAR expression{"+($3).name+"} RPAR ("+std::to_string(ctx->line())+")\n");
        $$ = IfExpressionData::init_if_head(ctx, $3);
    }
;

if_non_split_expression:
    if_expression_head non_split_expression   {
        log("[if_non_split_expression:] if_expression_head non_split_statement (line: %i)\n", (int)ctx->line());
        auto &&expression_data = $1;
        auto &data = expression_data.if_data;
        data.if_block_back = ctx->builder()->GetInsertBlock();
        expression_data.store_to_result(ctx, $2);
        casem::exit_block(ctx);
        $$ = expression_data;
    }
;

if_non_split_expression_else:
    if_non_split_expression ELSE   {
        log("[if_non_split_expression_else:] if_non_split_expression ELSE: (line: %i)\n", (int)ctx->line());
        $$ = IfExpressionData::init_if_else_head(ctx, $1);
    }
;

flow_expression:
    non_split_expression
    | split_expression
;

non_split_expression:
    if_non_split_expression_else non_split_expression    {
        log("[non_split_expression:] if_non_split_expression_else non_split_expression:  (line: %i)\n", (int)ctx->line());
        auto &&expression_data = $1;
        auto &data = expression_data.if_data;
        expression_data.store_to_result(ctx, $2);
        data.else_block_back = ctx->builder()->GetInsertBlock();
        exit_block(ctx);
        log("SWITCHING to continue_block\n");
        ctx->builder()->SetInsertPoint(data.continue_block);
        expression_data.block = create_if_control_flow(ctx, data);

        $$ = expression_data;
    }
    | expression_statement    {
        log("[non_split_statement:] expression_statement (line: %i)\n", (int)ctx->line());
        $$ = $1;
    }
;

split_expression:
     if_expression_head expression_body    {
        log("[split_statement:] if_statement_head statement (line: %i)\n", (int)ctx->line());
        auto &&expression_data = $1;
        auto &data = expression_data.if_data;
        expression_data.store_to_result(ctx, $2);
        data.if_block_back = ctx->builder()->GetInsertBlock();
        exit_block(ctx);
        ctx->builder()->SetInsertPoint(data.continue_block);
        
        expression_data.block = create_if_control_flow(ctx, data);
        $$ = expression_data;
     }
     | if_non_split_expression_else split_expression    {
        log("[split_statement:] if_non_split_statement_else split_statement (line: %i)\n", (int)ctx->line());
        auto &&expression_data = $1;
        auto &data = expression_data.if_data;
        expression_data.store_to_result(ctx, $2);
        data.else_block_back = ctx->builder()->GetInsertBlock();
        exit_block(ctx);
        ctx->builder()->SetInsertPoint(data.continue_block);
         
        expression_data.block = create_if_control_flow(ctx, data);
        $$ = expression_data;
     }
;


/////////////////////////////////

%%

namespace cecko {

	void parser::error(const location_type& l, const std::string& m)
	{
		ctx->message(cecko::errors::SYNTAX, l, m);
	}
}
