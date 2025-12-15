#ifndef _CODE_H_
#define _CODE_H_

#include "globals.h"
#include "cgen.h" 

#define  pc int

void emitComment(const char * c, int indent);
/* Adicionado protótipo */
void emitCode(const char * c, int indent);

const char * toStringInstruction(Opcode i);
Quadruple getCodigoIntermediario(void);
void freeCodigoIntermediario(void);

#endif