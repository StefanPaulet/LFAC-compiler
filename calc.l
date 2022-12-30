%{
    #include <stdio.h>
    #include <string.h>
    #include "calc.hpp"
%}

%x comment

%option noyywrap

whitespace   [\n\t ]
digit        [0-9]
letter       [a-zA-Z]
INT          int
FLOAT        float
CHAR         char
BOOL         bool


IntNumber   (0|[1-9]{digit}*)
Id          ({letter}|_)({letter}|{digit}|_)*

%%

{IntNumber} {
    yylval.intValue = strtol ( yytext, NULL, 10 );
    return ( T_INT_NUMBER );
}

{Id} {
    yylval.stringValue = strdup ( yytext );
    return ( ID );
}

int { 

}

"/*" { BEGIN ( comment ); }
<comment>"*/" { BEGIN ( 0 ); }
<comment>.|\n ;

{whitespace} { }

. {
    return * yytext;
}

%%