#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "globals.h"

#define SIZE 211

typedef struct LineListRec { int lineno; struct LineListRec * next; } * LineList;

typedef struct BucketListRec {
    char * name;
    LineList lines;
    TreeNode * treeNode;
    int memloc;
    int tamanho;
    struct BucketListRec * next;
} * BucketList;

typedef struct ScopeRec {
    char * funcName;
    struct ScopeRec * parent;
    int tamanhoBlocoMemoria;
    BucketList hashTable[SIZE];
} * Scope;

extern Scope globalScope;

typedef struct SysCallRec { char * name; TreeNode * treeNode; struct SysCallRec * next; } * SysCall;

/* Protótipos */
SysCall sys_create(char * name, TreeNode * treeNode);
void sys_insert(SysCall syscall);
SysCall sys_lookup(char * name);
void sys_free(void);

void st_insert(char * name, int lineno, int loc, TreeNode * treeNode, int tamanho);
void st_insert_func(char * name, int lineno, TreeNode * treeNode);
void st_add_lineno(TreeNode * treeNode);
int st_lookup (char * name);
int st_lookup_top (char * name);
int st_lookup_func (char * name);

/* AQUI ESTÁ O QUE FALTAVA */
BucketList verificaGlobal(char * name);

Scope sc_create(char * funcName);
Scope sc_top(void);
void sc_pop(void);
void sc_push(Scope scope);

int getMemoryLocation(char * nome, Scope escopo);
void printSymTab(FILE * listing);

#endif