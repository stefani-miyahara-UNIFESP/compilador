/****************************************************/
/* File: cgen.c                                     */
/* The code generator implementation                */
/* Versão Final: Dono do HEAD                       */
/****************************************************/

#include "globals.h"
#include "symtab.h"
#include "code.h"
#include "cgen.h"

/* Pilha para contagem de parâmetros */
typedef struct Param { int * count; struct Param * next; } * ParamStack;
ParamStack paramHead = NULL;

/* AQUI ESTÁ A DEFINIÇÃO GLOBAL DO HEAD */
Quadruple head = NULL; 

/* Pilha para backpatching */
typedef struct Location { Quadruple quad; struct Location * next; } * LocationStack;
LocationStack locationHead = NULL;

static int temporario = 1;
static int label = 1;
Operand operandoAtual;
Opcode instrucaoAtual; 
Quadruple ultimaQuadrupla;
static int linha = 0;

/* Protótipos */
static void cGen (TreeNode * tree);

/* --- Funções Auxiliares --- */
void pushParam(int * count) {
    ParamStack ps = (ParamStack) malloc(sizeof(struct Param));
    ps->count = count; ps->next = paramHead; paramHead = ps;
}
void popParam(void) {
    if(paramHead) { ParamStack ps = paramHead; paramHead = paramHead->next; free(ps); }
}
void pushLocation(Quadruple quad) {
    LocationStack ls = (LocationStack) malloc(sizeof(struct Location));
    ls->quad = quad; ls->next = locationHead; locationHead = ls;
}
void popLocation() {
    if(locationHead) { LocationStack ls = locationHead; locationHead = locationHead->next; free(ls); }
}
void updateLocation(Operand op) {
    if (locationHead) {
        Quadruple q = locationHead->quad;
        if(q->instruction != JPF) q->op1 = op; else q->op2 = op;
    }
}

/* --- Construtores --- */
static char * createLabelName() {
    char * temp = (char *) malloc(10); sprintf(temp, "L%d", label++); return temp;
}
static char * createTemporaryOperandName() {
    char * temp = (char *) malloc(10); sprintf(temp, "t%d", temporario++); return temp;
}
Operand createOperand(void) { return (Operand) malloc(sizeof(struct operand)); }
static Operand createTemporaryOperand() {
    Operand temp = createOperand(); temp->kind = String; temp->contents.variable.scope = NULL;
    temp->contents.variable.name = createTemporaryOperandName(); return temp;
}

Quadruple createQuad(Opcode instruction, Operand op1, Operand op2, Operand op3) {
    Quadruple q = (Quadruple) malloc(sizeof(struct quadruple));
    q->instruction = instruction; q->op1 = op1; q->op2 = op2; q->op3 = op3;
    q->lineno = ++linha; q->next = NULL; return q;
}
void insertQuad(Quadruple q) {
    if(head == NULL) head = q;
    else { Quadruple temp = head; while(temp->next) temp = temp->next; temp->next = q; }
}

/* --- Geração Recursiva --- */
static void genStmt(TreeNode * tree) {
    Quadruple q; Operand op1, op2, op3; TreeNode * p1, * p2, * p3;
    switch (tree->kind.stmt) {
        case INTEGERK: case VOIDK: p1 = tree->child[0]; cGen(p1); break;
        case IFK:
            p1 = tree->child[0]; p2 = tree->child[1]; p3 = tree->child[2];
            cGen(p1); op1 = operandoAtual;
            instrucaoAtual = JPF; q = createQuad(instrucaoAtual, op1, NULL, NULL);
            insertQuad(q); pushLocation(q);
            cGen(p2);
            op2 = createOperand(); op2->kind = String; op2->contents.variable.name = createLabelName();
            op2->contents.variable.scope = tree->kind.var.scope;
            updateLocation(op2); popLocation();
            if(p3) {
                q = createQuad(GOTO, NULL, NULL, NULL); insertQuad(q); pushLocation(q);
            }
            insertQuad(createQuad(LBL, op2, NULL, NULL));
            cGen(p3);
            if(p3) {
                op1 = createOperand(); op1->kind = String; op1->contents.variable.name = createLabelName();
                op1->contents.variable.scope = tree->kind.var.scope;
                updateLocation(op1); popLocation();
                insertQuad(createQuad(LBL, op1, NULL, NULL));
            }
            break;
        case WHILEK:
            p1 = tree->child[0]; p2 = tree->child[1];
            op1 = createOperand(); op1->kind = String; op1->contents.variable.name = createLabelName();
            op1->contents.variable.scope = tree->kind.var.scope;
            insertQuad(createQuad(LBL, op1, NULL, NULL));
            cGen(p1); op2 = operandoAtual;
            instrucaoAtual = JPF; q = createQuad(instrucaoAtual, op2, NULL, NULL);
            insertQuad(q); pushLocation(q);
            cGen(p2);
            instrucaoAtual = GOTO; insertQuad(createQuad(instrucaoAtual, op1, NULL, NULL));
            op3 = createOperand(); op3->kind = String; op3->contents.variable.name = createLabelName();
            op3->contents.variable.scope = tree->kind.var.scope;
            insertQuad(createQuad(LBL, op3, NULL, NULL));
            updateLocation(op3); popLocation();
            break;
        case RETURNK:
            p1 = tree->child[0]; cGen(p1);
            op1 = p1 ? operandoAtual : NULL;
            instrucaoAtual = RTN; insertQuad(createQuad(instrucaoAtual, op1, NULL, NULL));
            break;
        case COMPK:
            p1 = tree->child[0]; p2 = tree->child[1]; if(p2) cGen(p2); break;
    }
}

static void genExp(TreeNode * tree) {
    TreeNode * p1, * p2; Operand op1, op2, op3;
    switch (tree->kind.exp) {
        case ATRIBK:
            p1 = tree->child[0]; p2 = tree->child[1];
            cGen(p2); op2 = operandoAtual;
            cGen(p1); op1 = operandoAtual; op3 = NULL;
            if(p1->node == VARK && p1->kind.var.varKind == VECTORK) {
                ultimaQuadrupla->instruction = VEC_ADDR;
                if(ultimaQuadrupla->op2->kind == Int) {
                    op3 = createOperand(); op3->kind = Int;
                    op3->contents.val = ultimaQuadrupla->op2->contents.val; op1 = ultimaQuadrupla->op1;
                }
            }
            instrucaoAtual = ASN; insertQuad(createQuad(instrucaoAtual, op1, op2, op3));
            break;
        case RELK:
            p1 = tree->child[0]; p2 = tree->child[1]; cGen(p1); op1 = operandoAtual; cGen(p2); op2 = operandoAtual;
            switch (tree->op) {
                case IGUAL: instrucaoAtual = EQ; break; case DIFERENTE: instrucaoAtual = NE; break;
                case MENOR: instrucaoAtual = LT; break; case MENORIGUAL: instrucaoAtual = LET; break;
                case MAIOR: instrucaoAtual = GT; break; case MAIORIGUAL: instrucaoAtual = GET; break;
                default: instrucaoAtual = HALT; break;
            }
            operandoAtual = createTemporaryOperand(); insertQuad(createQuad(instrucaoAtual, op1, op2, operandoAtual));
            break;
        case ARITHK:
            p1 = tree->child[0]; p2 = tree->child[1]; cGen(p1); op1 = operandoAtual; cGen(p2); op2 = operandoAtual;
            switch (tree->op) {
                case MAIS: instrucaoAtual = ADD; break; case MENOS: instrucaoAtual = SUB; break;
                case VEZES: instrucaoAtual = MULT; break; case DIVISAO: instrucaoAtual = DIV; break;
                default: instrucaoAtual = HALT; break;
            }
            operandoAtual = createTemporaryOperand(); insertQuad(createQuad(instrucaoAtual, op1, op2, operandoAtual));
            break;
    }
}

static void genVar(TreeNode * tree) {
    TreeNode * p1, *tempNode; Operand op1, op2, op3; int qtdParams, offset, display = -1;
    switch (tree->kind.var.varKind) {
        case CONSTK:
            operandoAtual = createOperand(); operandoAtual->kind = Int; operandoAtual->contents.val = tree->kind.var.attr.val; break;
        case IDK:
            operandoAtual = createOperand(); operandoAtual->kind = String;
            operandoAtual->contents.variable.name = tree->kind.var.attr.name;
            operandoAtual->contents.variable.scope = tree->kind.var.scope; break;
        case VECTORK:
            p1 = tree->child[0];
            operandoAtual = createOperand(); operandoAtual->kind = String;
            operandoAtual->contents.variable.name = tree->kind.var.attr.name;
            operandoAtual->contents.variable.scope = tree->kind.var.scope;
            op1 = operandoAtual; cGen(p1); op2 = operandoAtual;
            instrucaoAtual = VEC; op3 = createTemporaryOperand(); operandoAtual = op3;
            if(tree->kind.var.acesso == ACCESSK) { ultimaQuadrupla = createQuad(instrucaoAtual, op1, op2, op3); insertQuad(ultimaQuadrupla); }
            break;
        case FUNCTIONK:
            if(head != NULL) { Quadruple temp = head; while(temp->next) temp = temp->next; if(temp->instruction != RTN) insertQuad(createQuad(RTN, NULL, NULL, NULL)); }
            op1 = createOperand(); op1->kind = String; op1->contents.variable.name = tree->kind.var.attr.name;
            op1->contents.variable.scope = tree->kind.var.scope; insertQuad(createQuad(FUNC, op1, NULL, NULL));
            p1 = tree->child[0];
            while(p1 != NULL) {
                op2 = createOperand(); op2->kind = String; op2->contents.variable.name = p1->child[0]->kind.var.attr.name;
                op2->contents.variable.scope = p1->child[0]->kind.var.scope; insertQuad(createQuad(GET_PARAM, op2, NULL, NULL)); p1 = p1->sibling;
            }
            cGen(tree->child[1]); break;
        case CALLK:
            p1 = tree->child[0]; op1 = createOperand(); op1->kind = String; op1->contents.variable.name = tree->kind.var.attr.name;
            op1->contents.variable.scope = tree->kind.var.scope;
            qtdParams = 0; tempNode = p1; while(tempNode) { qtdParams++; tempNode = tempNode->sibling; }
            pushParam(&qtdParams);
            op2 = createOperand(); op2->kind = Int; op2->contents.val = qtdParams;
            instrucaoAtual = PARAM_LIST; op3 = createOperand(); op3->kind = Int; op3->contents.val = qtdParams; insertQuad(createQuad(instrucaoAtual, op3, NULL, NULL));
            while(p1 != NULL) {
                cGen(p1); instrucaoAtual = SET_PARAM; insertQuad(createQuad(instrucaoAtual, operandoAtual, NULL, NULL));
                p1 = p1->sibling;
            }
            popParam();
            instrucaoAtual = CALL; if (op1->kind == Int) offset = operandoAtual->contents.val;
            operandoAtual = createTemporaryOperand(); insertQuad(createQuad(instrucaoAtual, op1, op2, operandoAtual));
            break;
    }
}

static void cGen(TreeNode * tree) {
    if (tree != NULL) {
        switch (tree->node) { case STMTK: genStmt(tree); break; case EXPK: genExp(tree); break; case VARK: genVar(tree); break; default: break; }
        if(paramHead == NULL || paramHead->count == 0) cGen(tree->sibling);
    }
}

/* Função Principal de Geração */
void codeGen(TreeNode * syntaxTree, char * codefile, CodeInfo codeInfo) {
    cGen(syntaxTree);
    if (codeInfo.codeType != PROGRAMA) insertQuad(createQuad(HALT, NULL, NULL, NULL));
    else insertQuad(createQuad(SYSCALL, NULL, NULL, NULL));
    
    emitCode("\n********** Código intermediário **********\n", 0);
    
    Quadruple q = head; char quad[200], tempBuf[50];
    while(q != NULL) {
        sprintf(quad, "%d: (", q->lineno); strcat(quad, toStringInstruction(q->instruction));
        if(!q->op1) strcat(quad, ", _"); else if(q->op1->kind == String) { strcat(quad, ", "); strcat(quad, q->op1->contents.variable.name); } else { sprintf(tempBuf, ", %d", q->op1->contents.val); strcat(quad, tempBuf); }
        if(!q->op2) strcat(quad, ", _"); else if(q->op2->kind == String) { strcat(quad, ", "); strcat(quad, q->op2->contents.variable.name); } else { sprintf(tempBuf, ", %d", q->op2->contents.val); strcat(quad, tempBuf); }
        if(!q->op3) strcat(quad, ", _)"); else if(q->op3->kind == String) { strcat(quad, ", "); strcat(quad, q->op3->contents.variable.name); strcat(quad, ")"); } else { sprintf(tempBuf, ", %d)", q->op3->contents.val); strcat(quad, tempBuf); }
        emitCode(quad, 0); q = q->next;
    }
}

/* Funções Públicas de Gerenciamento da Lista (AQUI É O LUGAR DELAS) */
Quadruple getCodigoIntermediario(void) { return head; }

void freeCodigoIntermediario(void) { 
    if (head) { 
        Quadruple temp; 
        while (head) { temp = head; head = head->next; free(temp); } 
    } 
}