/****************************************************/
/* File: cminus.y                                   */
/* The C- Yacc/Bison specification file             */
/* Adequado ao Projeto 2S2025 (Standard)            */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char * message);

%}

%token IF ELSE WHILE RETURN INT VOID
%token ID NUM
%token MAIS MENOS VEZES DIVISAO
%token MENOR MENORIGUAL MAIOR MAIORIGUAL IGUAL DIFERENTE
%token ATRIBUICAO
%token LPAREN RPAREN LBRACKET RBRACKET LKEY RKEY SEMI COMMA
%token ERROR 

/* Precedência para resolver Dangling Else */
%nonassoc RPAREN
%nonassoc ELSE

%% 

programa     : declaration_list
                 { savedTree = $1;} 
            ;

declaration_list : declaration_list declaration
                 { YYSTYPE t = $1;
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = $2;
                     $$ = $1; }
                     else $$ = $2;
                 }
            | declaration
                 { $$ = $1; }
            ;

declaration : var_declaration
                 { $$ = $1; }
            | fun_declaration
                 { $$ = $1; }
            ;

var_declaration : type_specifier id SEMI
                 { $$ = $1;
                   $$->child[0] = $2;
                   $$->child[0]->kind.var.mem = LOCALK; /* Default, analyze arruma */
                 }
            | type_specifier id LBRACKET num RBRACKET SEMI
                 { $$ = $1;
                   $$->child[0] = $2;
                   $$->child[0]->kind.var.varKind = VECTORK;
                   $$->child[0]->kind.var.mem = LOCALK;
                   $$->child[0]->child[0] = $4;
                 }
            ;

type_specifier : INT
                 { $$ = newStmtNode(INTEGERK);
                   $$->type = INTEGER_TYPE;
                 }
            | VOID
                 { $$ = newStmtNode(VOIDK);
                   $$->type = VOID_TYPE;
                 }
            ;

fun_declaration : type_specifier id LPAREN params RPAREN compound_stmt
                 { $$ = $1;
                   $$->child[0] = $2;
                   $$->child[0]->kind.var.varKind = FUNCTIONK;
                   $$->child[0]->kind.var.mem = FUNCTION_MEM;
                   $$->child[0]->child[0] = $4; /* Parametros */
                   $$->child[0]->child[1] = $6; /* Corpo */
                 }
            ;

params      : param_list
                 { $$ = $1; }
            | VOID
                 { $$ = NULL; }
            ;

param_list  : param_list COMMA param
                 { YYSTYPE t = $1;
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = $3;
                     $$ = $1; }
                     else $$ = $3;
                 }
            | param
                 { $$ = $1; }
            ;

param       : type_specifier id
                 { $$ = $1;
                   $$->child[0] = $2;
                   $$->child[0]->kind.var.mem = PARAMK;
                 }
            | type_specifier id LBRACKET RBRACKET
                 { $$ = $1;
                   $$->child[0] = $2;
                   $$->child[0]->kind.var.mem = PARAMK;
                   $$->child[0]->kind.var.varKind = VECTORK;
                 }
            ;

compound_stmt : LKEY local_declarations statement_list RKEY
                 { $$ = newStmtNode(COMPK);
                   $$->child[0] = $2;
                   $$->child[1] = $3;
                 }
            ;

local_declarations : local_declarations var_declaration
                 { YYSTYPE t = $1;
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = $2;
                     $$ = $1; }
                     else $$ = $2;
                 }
            | /* empty */
                 { $$ = NULL; }
            ;

statement_list : statement_list statement
                 { YYSTYPE t = $1;
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = $2;
                     $$ = $1; }
                     else $$ = $2;
                 }
            | /* empty */
                 { $$ = NULL; }
            ;

statement   : expression_stmt
                 { $$ = $1; }
            | compound_stmt
                 { $$ = $1; }
            | selection_stmt
                 { $$ = $1; }
            | iteration_stmt
                 { $$ = $1; }
            | return_stmt
                 { $$ = $1; }
            ;

expression_stmt : expression SEMI
                 { $$ = $1; }
            | SEMI
                 { $$ = NULL; }
            ;

selection_stmt : IF LPAREN expression RPAREN statement
                 { $$ = newStmtNode(IFK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
            | IF LPAREN expression RPAREN statement ELSE statement
                 { $$ = newStmtNode(IFK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                   $$->child[2] = $7;
                 }
            ;

iteration_stmt : WHILE LPAREN expression RPAREN statement
                 { $$ = newStmtNode(WHILEK);
                   $$->child[0] = $3;
                   $$->child[1] = $5;
                 }
            ;

return_stmt : RETURN SEMI
                 { $$ = newStmtNode(RETURNK); }
            | RETURN expression SEMI
                 { $$ = newStmtNode(RETURNK);
                   $$->child[0] = $2;
                 }
            ;

expression  : var ATRIBUICAO expression
                 { $$ = newExpNode(ATRIBK);
                   $$->op = ATRIBUICAO;
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                 }
            | simple_expression
                 { $$ = $1; }
            ;

var         : id
                 { $$ = $1; 
                   $$->kind.var.acesso = ACCESSK; 
                 }
            | id LBRACKET expression RBRACKET
                 { $$ = $1;
                   $$->kind.var.acesso = ACCESSK;
                   $$->kind.var.varKind = VECTORK;
                   $$->child[0] = $3;
                 }
            ;

simple_expression : additive_expression relop additive_expression
                 { $$ = $2;
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                 }
            | additive_expression
                 { $$ = $1; }
            ;

relop       : MENORIGUAL
                 { $$ = newExpNode(RELK); $$->op = MENORIGUAL; }
            | MENOR
                 { $$ = newExpNode(RELK); $$->op = MENOR; }
            | MAIOR
                 { $$ = newExpNode(RELK); $$->op = MAIOR; }
            | MAIORIGUAL
                 { $$ = newExpNode(RELK); $$->op = MAIORIGUAL; }
            | IGUAL
                 { $$ = newExpNode(RELK); $$->op = IGUAL; }
            | DIFERENTE
                 { $$ = newExpNode(RELK); $$->op = DIFERENTE; }
            ;

additive_expression : additive_expression addop term
                 { $$ = $2;
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                 }
            | term
                 { $$ = $1; }
            ;

addop       : MAIS
                 { $$ = newExpNode(ARITHK); $$->op = MAIS; }
            | MENOS
                 { $$ = newExpNode(ARITHK); $$->op = MENOS; }
            ;

term        : term mulop factor
                 { $$ = $2;
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                 }
            | factor
                 { $$ = $1; }
            ;

mulop       : VEZES
                 { $$ = newExpNode(ARITHK); $$->op = VEZES; }
            | DIVISAO
                 { $$ = newExpNode(ARITHK); $$->op = DIVISAO; }
            ;

factor      : LPAREN expression RPAREN
                 { $$ = $2; }
            | var
                 { $$ = $1; }
            | call
                 { $$ = $1; }
            | num
                 { $$ = $1; }
            ;

call        : id LPAREN args RPAREN
                 { $$ = $1;
                   $$->kind.var.varKind = CALLK;
                   $$->child[0] = $3;
                 }
            ;

args        : arg_list
                 { $$ = $1; }
            | /* empty */
                 { $$ = NULL; }
            ;

arg_list    : arg_list COMMA expression
                 { YYSTYPE t = $1;
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = $3;
                     $$ = $1; }
                     else $$ = $3;
                 }
            | expression
                 { $$ = $1; }
            ;

/* REGRAS AUXILIARES PARA TOKENS COM VALOR */
id          : ID
                 { $$ = newVarNode(IDK);
                   $$->kind.var.attr.name = copyString(tokenString);
                 }
            ;

num         : NUM
                 { $$ = newVarNode(CONSTK);
                   $$->kind.var.attr.val = atoi(tokenString);
                 }
            ;

%%

int yyerror(char * message)
{ fprintf(listing,"ERRO SINTÁTICO: %s LINHA: %d\n",tokenString,lineno);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with e.g. the TINY parser
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}