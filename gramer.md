translation_unit:
    external_declaration
    | translation_unit external_declaration

external_declaration:
    function_definition
    | enumtype_decl_specifier

new_lines:
    NEWLINE
    | new_lines NEWLINE

expression_end:
    new_lines
    | EOF

function_definition:
    function_definition_head expression
    | function_definition_info ; expression_end

function_definition_info: 
    declaration_specifiers declarator

function_definition_head:
    function_definition_info ASGN

primary_expression:
    INTLIT
    | STRLIT
    | ( expression_body )

postfix_expression:
    primary_expression
    | IDF ( argument_expression_list )
    | IDF

argument_expression_list:
    assignment_expression
    | argument_expression_list , assignment_expression
    | %empty

unary_expression:
    postfix_expression
    | unary_operator cast_expression

unary_operator:
    &
    | *  
    | ADDOP
    | !

cast_expression:
    unary_expression

multiplicative_expression:
    cast_expression 
    | multiplicative_expression * cast_expression 
    | multiplicative_expression DIVOP cast_expression 

additive_expression:
    multiplicative_expression  
    | additive_expression ADDOP multiplicative_expression

relational_expression:
    additive_expression 
    | relational_expression CMPO additive_expression

equality_expression:
    relational_expression 
    | equality_expression CMPE relational_expression

logical_and_expression:
    equality_expression  
    | logical_and_expression && equality_expression   

logical_or_expression:
    logical_and_expression  
    | logical_or_expression || logical_and_expression  

assignment_expression:
    logical_or_expression 
    | unary_expression assignment_operator assignment_expression

assignment_operator:
    =

match_head:
    MATCH assignment_expression -> declaration_specifiers

match_expression:
    assignment_expression
    | match_binders_list block_end

match_binders_list:
    match_binders_list_head_start expression_body
    | match_binders_list_head expression_body

match_binders_list_head_start:
    match_head block_start match_binder_head

match_binders_list_head:
    match_binders_list match_binder_head

match_binder_head:
    | match_binder_definer ->

match_binder_definer:
    IDF ( match_binder_arguments_list )
    | IDF

match_binder_arguments_list:
    IDF
    | match_binder_arguments_list , IDF

expression_body:
    match_expression
    | flow_expression

expression:
    expression_body expression_end

declaration_specifiers:
    declaration_specifier 
    | declaration_specifier declaration_specifiers

declaration_specifier:
    type_specifier_qualifier
    | FIP

type_specifier:
    ETYPE
    | declared_type_name  
    | typedef_name 

declared_type_name:
    TYPEDEF IDF 

enumtype_decl_head:
    TYPEDEF IDF 

block_start:
    {
    | { new_lines 

block_end:
    }
    | new_lines }

enumtype_decl_specifier:
    enumtype_decl_head block_start member_types_declaration_list block_end new_lines

member_types_declaration_list:
    member_types_declaration 
    | member_types_declaration_list member_types_declaration 

member_types_declaration:
    IDF ( member_declaration_list ) ; 
    | IDF ;  

member_declaration_list:
    member_declaration  
    | member_declaration_list , member_declaration 

member_declaration:
    specifier_qualifier_list member_declarator 

specifier_qualifier_list:
    type_specifier_qualifier  
    | type_specifier_qualifier specifier_qualifier_list 

type_specifier_qualifier:
    type_specifier  

member_declarator:
    declarator  

declarator:
    pointer direct_declarator 
    | direct_declarator 

pointer:
    * pointer  
    | *     

direct_declarator:
    IDF 
    | function_declarator 

function_declarator: 
    direct_declarator [ parameter_type_list ] 

parameter_type_list:
    parameter_list
    | %empty     

parameter_list:
    parameter_declaration  
    | parameter_list , parameter_declaration 

parameter_declaration:
    declaration_specifiers declarator   
    | declaration_specifiers                   

typedef_name:
    TYPEIDF    

expression_statement:
    match_expression ;   

if_expression_head:
    IF ( expression_body )   

if_non_split_expression:
    if_expression_head non_split_expression 

if_non_split_expression_else:
    if_non_split_expression ELSE 

flow_expression:
    non_split_expression
    | split_expression

non_split_expression:
    if_non_split_expression_else non_split_expression  
    | expression_statement 

split_expression:
     if_expression_head expression_body   
     | if_non_split_expression_else split_expression