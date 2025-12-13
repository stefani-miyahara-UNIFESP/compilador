#ifndef _CGEN_H_
#define _CGEN_H_

#include "globals.h"

typedef enum {String, Int} OperandKind;

typedef struct operand {
    OperandKind kind;
    union {
        int val;
        struct {
            char * name;
            struct ScopeRec * scope;
        } variable;
    } contents;
} * Operand;

/* Opcode: Instruções da Máquina Abstrata */
typedef enum {
    ADD, SUB, MULT, DIV, MOD,
    EQ, NE, LT, LET, GT, GET,
    ASN, 
    VEC, VEC_ADDR,
    FUNC, RTN, GET_PARAM, SET_PARAM, CALL, PARAM_LIST,
    GOTO, JPF, LBL, HALT, SYSCALL
} Opcode;

typedef struct quadruple {
    Opcode instruction;
    Operand op1;
    Operand op2;
    Operand op3;
    struct quadruple * next;
    int lineno;
    int display;
} * Quadruple;

void codeGen(TreeNode * syntaxTree, char * codefile, CodeInfo codeInfo);
Operand createOperand(void);
Quadruple createQuad(Opcode opcode, Operand op1, Operand op2, Operand op3);
void insertQuad(Quadruple q);
Quadruple getCodigoIntermediario(void);
void freeCodigoIntermediario(void);

#endif