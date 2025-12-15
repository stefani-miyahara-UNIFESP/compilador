#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef YYPARSER
#include "cminus.tab.h"
#define ENDFILE 0
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define MAXRESERVED 6

typedef int TokenType;

extern FILE* source;
extern FILE* listing;
extern FILE* code;
extern FILE* binary_file;

extern int lineno;

typedef enum {STMTK, EXPK, VARK, SYSK} NodeKind;
typedef enum {INTEGERK, VOIDK, IFK, WHILEK, RETURNK, COMPK} StmtKind;
typedef enum {ATRIBK, RELK, ARITHK} ExpKind;
typedef enum {IDK, VECTORK, CONSTK, FUNCTIONK, CALLK} VarKind;

typedef enum {INPUT, OUTPUT, LDK, SDK, LAM, SAM, SIM,
    MMULOWERIM, MMUUPPERIM,
    MMUSELECT, EXEC, LCD, LCD_PGMS, LCD_CURR,
    GIC, CIC, GIP, EXEC_AGAIN,
    SAVE_REGS, LOAD_REGS, LDM, SDM,
    GSP, GSPB, GGPB, SSPB, SGPB, RGNSP} SysCallKind;

typedef enum {DECLK, ACCESSK} VarAccessK;
typedef enum {LOCALK, PARAMK, GLOBALK, FUNCTION_MEM} VarMemK;
typedef enum {VOID_TYPE, INTEGER_TYPE} ExpType;
typedef enum {PROGRAMA, BIOS, KERNEL} CodeType;

#define MAXCHILDREN 3

typedef struct Identifier {
    VarKind varKind;
    VarMemK mem;
    VarAccessK acesso;
    struct ScopeRec * scope;
    union {
        int val;
        char * name;
    } attr;
} Identifier;

typedef struct treeNode {
    struct treeNode * child[MAXCHILDREN];
    struct treeNode * sibling;
    NodeKind node;
    int lineno;
    union {
        StmtKind stmt;
        ExpKind exp;
        struct Identifier var;
        SysCallKind sys;
    } kind;
    TokenType op;
    ExpType type;
    void * op3; /* Ponteiro genérico para uso do cgen */
} TreeNode;

typedef struct codeInfo {
    CodeType codeType;
    char pgm[120];
    int offset;
} CodeInfo;

extern int TraceScan, TraceParse, TraceAnalyze, TraceCode, TraceBinary, Error;
#endif