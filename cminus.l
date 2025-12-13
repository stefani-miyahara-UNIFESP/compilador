/****************************************************/
/* File: cminus.l                                   */
/* Lex specification for C-                         */
/****************************************************/

%{
#include "globals.h"
#include "util.h"
#include "scan.h"

char tokenString[MAXTOKENLEN+1];
%}

%option noyywrap

digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
identifier  {letter}+
newline     \n
whitespace  [ \t\r]+

%%

"if"            {return IF;}
"else"          {return ELSE;}
"while"         {return WHILE;}
"return"        {return RETURN;}
"int"           {return INT;}
"void"          {return VOID;}

"+"             {return MAIS;}
"-"             {return MENOS;}
"*"             {return VEZES;}
"/"             {return DIVISAO;}
"<"             {return MENOR;}
"<="            {return MENORIGUAL;}
">"             {return MAIOR;}
">="            {return MAIORIGUAL;}
"=="            {return IGUAL;}
"!="            {return DIFERENTE;}
"="             {return ATRIBUICAO;}
";"             {return SEMI;}
","             {return COMMA;}
"("             {return LPAREN;}
")"             {return RPAREN;}
"["             {return LBRACKET;}
"]"             {return RBRACKET;}
"{"             {return LKEY;}
"}"             {return RKEY;}

{number}        {return NUM;}
{identifier}    {return ID;}
{newline}       {lineno++;}
{whitespace}    {/* skip whitespace */}

"/*"            { char c;
                  do { c = input();
                       if (c == EOF) break;
                       if (c == '\n') lineno++;
                       if (c == '*') {
                           if (input() == '/') break;
                       }
                  } while (1);
                }

.               {return ERROR;}

%%

TokenType getToken(void)
{ static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime)
  { firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  strncpy(tokenString,yytext,MAXTOKENLEN);
  if (TraceScan) {
    fprintf(listing,"\t%d: ",lineno);
    printToken(currentToken,tokenString);
  }
  return currentToken;
}