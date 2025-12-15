#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include "analyze.h"
#include "cgen.h"
#include "target.h"
#include "binary.h"

int lineno = 0;
FILE * source;
FILE * listing;
FILE * code;
FILE * binary_file;

int TraceScan = FALSE;
int TraceParse = TRUE; /* Ativado para ver a árvore */
int TraceAnalyze = TRUE;
int TraceCode = TRUE;
int TraceBinary = FALSE;
int Error = FALSE;

int main( int argc, char * argv[] ) {
  TreeNode * syntaxTree;
  char pgm[120]; 
  char codefile[120];
  CodeInfo codeInfo; 
  codeInfo.codeType = PROGRAMA;

  if (argc != 2) { fprintf(stderr,"usage: %s <filename>\n",argv[0]); exit(1); }
  strcpy(pgm,argv[1]);
  if (strchr (pgm, '.') == NULL) strcat(pgm,".cm");
  source = fopen(pgm,"r");
  if (source==NULL) { fprintf(stderr,"File %s not found\n",pgm); exit(1); }
  
  listing = stdout; 
  fprintf(listing,"\nCompilação C Menos: %s\n",pgm);
  
  syntaxTree = parse();
  if (TraceParse) {
    fprintf(listing,"\nÁrvore sintática:\n");
    printTree(syntaxTree);
  }

  if (!Error) {
    fprintf(listing,"\nConstruindo tabela de símbolos...\n");
    buildSymtab(syntaxTree);
    fprintf(listing,"\nChecando tipos...\n");
    typeCheck(syntaxTree);
    fprintf(listing,"\nChecagem de tipos concluída!\n");
  }

  if (!Error) {
    strcpy(codefile,argv[1]);
    strcat(codefile,".txt");
    code = fopen(codefile,"w");
    if (code == NULL) { printf("Unable to open %s\n",codefile); exit(1); }
    
    /* CORREÇÃO: Chamada com 3 argumentos */
    codeGen(syntaxTree, codefile, codeInfo);
    fclose(code);
  }

  return 0;
}