/****************************************************/
/* File: analyze.c                                  */
/* Semantic analyzer implementation                 */
/* Adequado ao Projeto 2S2025 (Standard)            */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include "util.h"

static int location = 0;
static int globalLocation = 0;
Scope scope = NULL;
int mainDeclarada = FALSE;

/* Procedure traverse */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
  { preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

/* nullProc is a do-nothing procedure */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* InsertNode: constrói a tabela de símbolos */
static void insertNode( TreeNode * t) {
    switch (t->node) { 
        case STMTK:
            switch (t->kind.stmt) {
                case COMPK:
                    if(scope != globalScope) {
                        scope = sc_create(scope->funcName);
                        sc_push(scope);
                    }
                    break;
                case INTEGERK: t->type = INTEGER_TYPE; break;
                case VOIDK: t->type = VOID_TYPE; break;
                default: break;
            }
            break;
        case EXPK: break;
        case VARK:
            switch (t->kind.var.varKind) {
                case FUNCTIONK:
                    if(st_lookup_func(t->kind.var.attr.name)) {
                         fprintf(listing, "Erro semântico: Função '%s' já declarada. LINHA: %d\n", t->kind.var.attr.name, t->lineno);
                         Error = TRUE;
                    } else {
                        if(!strcmp(t->kind.var.attr.name, "main")) mainDeclarada = TRUE;
                        st_insert_func(t->kind.var.attr.name, t->lineno, t);
                        scope = sc_create(t->kind.var.attr.name);
                        sc_push(scope);
                    }
                    break;
                
                case IDK:
                case VECTORK:
                    /* Parâmetros */
                    if (t->kind.var.mem == PARAMK) {
                        if(st_lookup_top(t->kind.var.attr.name) != -1) {
                             fprintf(listing, "Erro semântico: Parâmetro '%s' já declarado. LINHA: %d\n", t->kind.var.attr.name, t->lineno);
                             Error = TRUE;
                        } else {
                            st_insert(t->kind.var.attr.name, t->lineno, location++, t, 1);
                        }
                    } 
                    /* Declaração de Variável */
                    else if(t->kind.var.acesso == DECLK) {
                        if(st_lookup_top(t->kind.var.attr.name) != -1) {
                             fprintf(listing, "Erro semântico: Variável '%s' já declarada. LINHA: %d\n", t->kind.var.attr.name, t->lineno);
                             Error = TRUE;
                        } else {
                            int tamanho = (t->kind.var.varKind == VECTORK && t->child[0] != NULL) ? t->child[0]->kind.var.attr.val : 1;
                            if(scope == globalScope) {
                                st_insert(t->kind.var.attr.name, t->lineno, globalLocation++, t, tamanho);
                            } else {
                                st_insert(t->kind.var.attr.name, t->lineno, location++, t, tamanho);
                            }
                        }
                    } 
                    /* Uso de Variável */
                    else { 
                        BucketList l = verificaGlobal(t->kind.var.attr.name);
                        if(st_lookup(t->kind.var.attr.name) == -1 && l == NULL) {
                             fprintf(listing, "Erro semântico: Variável '%s' não declarada. LINHA: %d\n", t->kind.var.attr.name, t->lineno);
                             Error = TRUE;
                        } else {
                            st_add_lineno(t);
                        }
                    }
                    break;
                case CALLK:
                    /* Verifica se é função do sistema ou do usuário */
                    if(sys_lookup(t->kind.var.attr.name) == NULL && !st_lookup_func(t->kind.var.attr.name)) {
                         fprintf(listing, "Erro semântico: Função '%s' não declarada. LINHA: %d\n", t->kind.var.attr.name, t->lineno);
                         Error = TRUE;
                    }
                    break;
                default: break;
            }
            break;
        default: break;
    }
}

static void afterInsertNode( TreeNode * t ) {
    switch (t->node) { 
        case STMTK:
            if (t->kind.stmt == COMPK && scope != globalScope) {
                 scope->tamanhoBlocoMemoria = location;
                 location = 0;
                 sc_pop();
                 scope = sc_top();
            }
            break;
        default: break;
    }
}

/* Verificação de Tipos Simplificada */
static void checkNode(TreeNode * t) {
    switch (t->node) {
        case EXPK:
            if (t->kind.exp == ATRIBK || t->kind.exp == ARITHK || t->kind.exp == RELK) {
                if ((t->child[0]->type != INTEGER_TYPE) || (t->child[1]->type != INTEGER_TYPE)) {
                     /* Type mismatch */
                }
                t->type = INTEGER_TYPE;
            }
            break;
        case STMTK:
            if ((t->kind.stmt == IFK || t->kind.stmt == WHILEK) && t->child[0]->type == VOID_TYPE) {
                 fprintf(listing, "Erro semântico: Condição não pode ser VOID. LINHA: %d\n", t->lineno);
                 Error = TRUE;
            }
            break;
        default: break;
    }
}

void buildSymtab(TreeNode * syntaxTree) {
    /* REGISTRA FUNÇÕES BUILT-IN: INPUT e OUTPUT [cite: 224-228] */
    TreeNode * inputNode = newSysNode(INPUT);
    sys_insert(sys_create("input", inputNode));
    TreeNode * outputNode = newSysNode(OUTPUT);
    sys_insert(sys_create("output", outputNode));

    globalScope = sc_create((char *) "ESCOPO_GLOBAL");
    sc_push(globalScope);
    traverse(syntaxTree, insertNode, afterInsertNode);
    sc_pop();
    sys_free();
    
    if(mainDeclarada == FALSE) {
        fprintf(listing, "Erro de declaração: Função main não declarada\n");
        Error = TRUE;
    }
    
    if (TraceAnalyze) {
        fprintf(listing,"\nTabela de símbolos:\n");
        printSymTab(listing);
    }
}

void typeCheck(TreeNode * syntaxTree) {
    traverse(syntaxTree, nullProc, checkNode);
}