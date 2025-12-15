/****************************************************/
/* File: code.c                                     */
/* Code emitting utilities implementation           */
/* Versão Final Sem Duplicatas                      */
/****************************************************/

#include "globals.h"
#include "code.h"
#include "cgen.h"

/* Converte o Opcode para string para impressão */
const char * toStringInstruction(Opcode i) {
    switch(i) {
        case ADD: return "add"; 
        case SUB: return "sub"; 
        case MULT: return "mult"; 
        case DIV: return "div"; 
        case MOD: return "mod"; /* Remova se o PDF proibir estritamente, mas não quebra compilação */
        case EQ: return "eq"; 
        case NE: return "ne"; 
        case LT: return "lt"; 
        case LET: return "let"; 
        case GT: return "gt"; 
        case GET: return "get";
        case ASN: return "asn"; 
        case VEC: return "vec"; 
        case VEC_ADDR: return "vec_addr";
        case FUNC: return "func"; 
        case RTN: return "rtn"; 
        case GET_PARAM: return "get_param"; 
        case SET_PARAM: return "set_param";
        case CALL: return "call"; 
        case PARAM_LIST: return "param_list";
        case GOTO: return "goto"; 
        case JPF: return "jpf"; 
        case LBL: return "lbl"; 
        case HALT: return "halt"; 
        case SYSCALL: return "syscall";
        default: return "unknown";
    }
}

/* Imprime comentários no arquivo de código */
void emitComment(const char * c, int indent) {
    if (TraceCode) { 
        int i; 
        for(i = 0; i < indent; ++i) fprintf(code, " "); 
        fprintf(code, "* %s\n", c); 
    }
}

/* A função que estava faltando para o cgen.c */
void emitCode(const char * c, int indent) {
    if (code != NULL) {
        int i; 
        for(i = 0; i < indent; ++i) fprintf(code, " "); 
        fprintf(code, "%s\n", c); 
    }
}

/* NOTA: getCodigoIntermediario e freeCodigoIntermediario 
   foram REMOVIDAS daqui pois pertencem ao cgen.c */