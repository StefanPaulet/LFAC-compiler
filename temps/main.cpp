#include <stdlib.h>
#include <stdio.h>

extern int yyparse(void);
extern FILE * yyin;
extern int yylineno;

int yyerror (char const * errorString) {
    fprintf( stderr, "Line : %d, error : %s\n", yylineno, errorString);
}

int main (int argc, char ** argv) {

    // buildSymbolTable();

    yyin = fopen ("test", "r");
    yyparse();

    return 0;
}
