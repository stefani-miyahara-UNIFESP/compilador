#include "globals.h"
#include "binary.h"
#include "target.h" 

static char temp[100]; 

void geraCodigoBinario(Objeto codigoObjeto, CodeInfo codeInfo) {
    if (TraceBinary) fprintf(listing, "\nGerando binário... (Simulado)\n");
    if (binary_file) fprintf(binary_file, "00000000000000000000000000000000\n"); 
}

/* Stubs */
char* toBinaryOpcode(int op) { return "000000"; }
char* toBinaryRegister(int reg) { return "00000"; }
char* toBinaryFunction(int func) { return "000000"; }
void emitBinary(char * s) { if(binary_file) fprintf(binary_file, "%s\n", s); }
/* emitCode REMOVIDO DAQUI POIS FOI PARA CODE.C */