%{
#include "parser.tab.h"
#include <string.h>
#include <stdio.h>
%}

%x COMMENT
%option noyywrap
%option yylineno

%%

"SELECT"      return SELECT;
"FROM"        return FROM;
"WHERE"       return WHERE;
"INSERT"      return INSERT;
"INTO"        return INTO;
"VALUES"      return VALUES;
"CREATE"      return CREATE;
"TABLE"       return TABLE_;
"UPDATE"      return UPDATE;
"SET"         return SET;
"DELETE"      return DELETE;
"DROP"        return DROP;
"AND"         return AND;
"OR"          return OR;
"NOT"         return NOT;

"INT"         return INT_;
"FLOAT"       return FLOAT_;
"VARCHAR"     return VARCHAR;
"BOOL"        return BOOL_;

"TRUE"        return TRUE_;
"FALSE"       return FALSE_;

-?[0-9]+\.[0-9]+  { yylval.fval = atof(yytext); return FLOAT_CONST; }
-?[0-9]+          { yylval.ival = atoi(yytext); return INT_CONST; }

\'([^\'\n]|\\.)*\'   { yylval.sval = strdup(yytext); return STRING_CONST; }
\"([^\"\n]|\\.)*\"   { yylval.sval = strdup(yytext); return STRING_CONST; }

[a-zA-Z_][a-zA-Z0-9_]* { yylval.sval = strdup(yytext); return IDENTIFIER; }

">="  return GEQ;
"<="  return LEQ;
"!="  return NEQ;
"="   return EQ;
">"   return GT;
"<"   return LT;

","   return COMMA;
";"   return SEMICOLON;
"("   return LPAREN;
")"   return RPAREN;
"*"   return STAR;

"--".* ;
"/*"                  { BEGIN(COMMENT); }
<COMMENT>"*/"         { BEGIN(INITIAL); }
<COMMENT>\n           ;
<COMMENT>.            ;

[ \t\r\n]+            ;

. {
    fprintf(stderr, "Erreur lexicale ligne %d : '%s'\n", yylineno, yytext);
}

%%