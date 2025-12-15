#include "globals.h"
#include "util.h"

void printToken( TokenType token, const char* tokenString )
{ switch (token) {
    case IF: case ELSE: case WHILE: case RETURN: case INT: case VOID:
      fprintf(listing, "reserved word: %s\n",tokenString); break;
    case ATRIBUICAO: fprintf(listing,"=\n"); break;
    case MENOR: fprintf(listing,"<\n"); break;
    case MENORIGUAL: fprintf(listing,"<=\n"); break;
    case MAIOR: fprintf(listing,">\n"); break;
    case MAIORIGUAL: fprintf(listing,">=\n"); break;
    case IGUAL: fprintf(listing,"==\n"); break;
    case DIFERENTE: fprintf(listing,"!=\n"); break;
    case LPAREN: fprintf(listing,"(\n"); break;
    case RPAREN: fprintf(listing,")\n"); break;
    case LBRACKET: fprintf(listing,"[\n"); break;
    case RBRACKET: fprintf(listing,"]\n"); break;
    case LKEY: fprintf(listing,"{\n"); break;
    case RKEY: fprintf(listing,"}\n"); break;
    case SEMI: fprintf(listing,";\n"); break;
    case COMMA: fprintf(listing,",\n"); break;
    case MAIS: fprintf(listing,"+\n"); break;
    case MENOS: fprintf(listing,"-\n"); break;
    case VEZES: fprintf(listing,"*\n"); break;
    case DIVISAO: fprintf(listing,"/\n"); break;
    case ENDFILE: fprintf(listing,"EOF\n"); break;
    case NUM: fprintf(listing, "NUM, val= %s\n",tokenString); break;
    case ID: fprintf(listing, "ID, name= %s\n",tokenString); break;
    case ERROR: fprintf(listing, "ERROR: %s\n",tokenString); break;
    default: fprintf(listing,"Unknown token: %d\n",token);
  }
}

TreeNode * newStmtNode(StmtKind kind) {
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL) fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL; t->node = STMTK; t->kind.stmt = kind; t->lineno = lineno;
  }
  return t;
}

TreeNode * newExpNode(ExpKind kind) {
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL) fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL; t->node = EXPK; t->kind.exp = kind; t->lineno = lineno; t->type = VOID_TYPE;
  }
  return t;
}

TreeNode * newVarNode(VarKind kind) {
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL) fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL; t->node = VARK; t->kind.var.varKind = kind; 
    t->kind.var.acesso = DECLK; t->kind.var.scope = NULL; t->lineno = lineno;
  }
  return t;
}

TreeNode * newSysNode(SysCallKind kind) {
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL) fprintf(listing,"Out of memory error at line %d\n",lineno);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL; t->node = SYSK; t->kind.sys = kind; t->lineno = lineno;
  }
  return t;
}

char * copyString(char * s) {
  int n; char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1; t = malloc(n);
  if (t==NULL) fprintf(listing,"Out of memory error at line %d\n",lineno);
  else strcpy(t,s);
  return t;
}

static int indentno = 0;
#define INDENT indentno+=2
#define UNINDENT indentno-=2

static void printSpaces(void) { int i; for (i=0;i<indentno;i++) fprintf(listing," "); }

void printTree( TreeNode * tree ) {
  int i; INDENT;
  while (tree != NULL) {
    printSpaces();
    if (tree->node == STMTK) {
        switch (tree->kind.stmt) {
            case IFK: fprintf(listing,"If\n"); break;
            case WHILEK: fprintf(listing,"While\n"); break;
            case RETURNK: fprintf(listing,"Return\n"); break;
            case COMPK: fprintf(listing,"Compound Statement\n"); break;
            case INTEGERK: fprintf(listing,"Type: int\n"); break;
            case VOIDK: fprintf(listing,"Type: void\n"); break;
            default: fprintf(listing,"Unknown StmtNode kind\n"); break;
        }
    } else if (tree->node == EXPK) {
        switch (tree->kind.exp) {
            case ATRIBK: fprintf(listing,"Assign:\n"); break;
            case RELK: fprintf(listing,"Relational Op: "); printToken(tree->op,"\0"); break;
            case ARITHK: fprintf(listing,"Arith Op: "); printToken(tree->op,"\0"); break;
            default: fprintf(listing,"Unknown ExpNode kind\n"); break;
        }
    } else if (tree->node == VARK) {
        switch (tree->kind.var.varKind) {
            case IDK: fprintf(listing,"Id: %s\n",tree->kind.var.attr.name); break;
            case VECTORK: fprintf(listing,"Vector: %s\n",tree->kind.var.attr.name); break;
            case CONSTK: fprintf(listing,"Const: %d\n",tree->kind.var.attr.val); break;
            case FUNCTIONK: fprintf(listing,"Function: %s\n",tree->kind.var.attr.name); break;
            case CALLK: fprintf(listing,"Call: %s\n",tree->kind.var.attr.name); break;
            default: fprintf(listing,"Unknown VarNode kind\n"); break;
        }
    } else fprintf(listing,"Unknown node kind\n");
    for (i=0;i<MAXCHILDREN;i++) printTree(tree->child[i]);
    tree = tree->sibling;
  }
  UNINDENT;
}