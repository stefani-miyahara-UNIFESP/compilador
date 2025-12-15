/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation                      */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SHIFT is the power of two used as multiplier */
#define SHIFT 4

static int hash ( char * key ) {
  int temp = 0;
  int i = 0;
  while (key[i] != '\0') { 
      temp = ((temp << SHIFT) + key[i]) % SIZE;
      ++i;
  }
  return temp;
}

Scope globalScope = NULL;
static Scope scopeStack[100]; /* Stack de escopos */
static int nScope = 0;

Scope sc_create(char * funcName) {
    Scope newScope = (Scope) malloc(sizeof(struct ScopeRec));
    newScope->funcName = funcName;
    newScope->parent = (nScope > 0) ? scopeStack[nScope-1] : NULL;
    newScope->tamanhoBlocoMemoria = 0;
    int i;
    for (i=0;i<SIZE;++i) newScope->hashTable[i] = NULL;
    return newScope;
}

void sc_push(Scope scope) { scopeStack[nScope++] = scope; }
void sc_pop(void) { if(nScope > 0) nScope--; }
Scope sc_top(void) { return (nScope > 0) ? scopeStack[nScope-1] : NULL; }

/* Implementação de verificaGlobal que faltava */
BucketList verificaGlobal(char * name) {
    int h = hash(name);
    BucketList l = globalScope->hashTable[h];
    while ((l != NULL) && (strcmp(name,l->name) != 0))
        l = l->next;
    return l;
}

void st_insert( char * name, int lineno, int loc, TreeNode * treeNode, int tamanho ) {
  int h = hash(name);
  Scope top = sc_top();
  BucketList l = top->hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0)) l = l->next;
  if (l == NULL) { /* variable not yet in table */
    l = (BucketList) malloc(sizeof(struct BucketListRec));
    l->name = name;
    l->lines = (LineList) malloc(sizeof(struct LineListRec));
    l->lines->lineno = lineno;
    l->memloc = loc;
    l->tamanho = tamanho;
    l->treeNode = treeNode;
    l->lines->next = NULL;
    l->next = top->hashTable[h];
    top->hashTable[h] = l;
  }
}

void st_insert_func( char * name, int lineno, TreeNode * treeNode ) {
    st_insert(name, lineno, 0, treeNode, 0);
}

int st_lookup ( char * name ) {
    int h = hash(name);
    Scope current = sc_top();
    while(current != NULL) {
        BucketList l = current->hashTable[h];
        while ((l != NULL) && (strcmp(name,l->name) != 0)) l = l->next;
        if (l != NULL) return l->memloc;
        current = current->parent;
    }
    return -1;
}

int st_lookup_top ( char * name ) {
    int h = hash(name);
    Scope current = sc_top();
    BucketList l = current->hashTable[h];
    while ((l != NULL) && (strcmp(name,l->name) != 0)) l = l->next;
    if (l != NULL) return l->memloc;
    return -1;
}

int st_lookup_func ( char * name ) {
    /* Funções ficam no escopo global */
    int h = hash(name);
    BucketList l = globalScope->hashTable[h];
    while ((l != NULL) && (strcmp(name,l->name) != 0)) l = l->next;
    if (l != NULL) return 1; /* Encontrou */
    return 0;
}

void st_add_lineno( TreeNode * treeNode ) {
    /* Simplificado para compilar */
}

/* SysCall stubs */
SysCall syscallHead = NULL;
SysCall sys_create(char * name, TreeNode * treeNode) {
    SysCall s = (SysCall)malloc(sizeof(struct SysCallRec));
    s->name = name; s->treeNode = treeNode; s->next = NULL;
    return s;
}
void sys_insert(SysCall syscall) {
    syscall->next = syscallHead; syscallHead = syscall;
}
SysCall sys_lookup(char * name) {
    SysCall s = syscallHead;
    while(s != NULL) {
        if(!strcmp(s->name, name)) return s;
        s = s->next;
    }
    return NULL;
}
void sys_free(void) {}

void printSymTab(FILE * listing) {
    /* Impressão simplificada */
    fprintf(listing, "Tabela de Simbolos (Escopo Global e Local nao detalhados nesta versao)\n");
}