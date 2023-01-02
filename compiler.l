%{
    #include <stdio.h>
    #include <string.h>
    #include "compiler.hpp"
%}

%x comment

%option yylineno
%option noyywrap

whitespace      [\n\t ]
digit           [0-9]
letter          [a-zA-Z]

INT          int
FLOAT        float
CHAR         char
BOOL         bool
STRING       string


IntNumber    (0|[1-9]{digit}*)
FloatNumber  {IntNumber}\.{IntNumber}
CharValue    '{letter}'
BoolValue    (true|false)
StringValue  "({letter}|{digit})*"
Identifier   ({letter}|_)({letter}|{digit}|_)*

%%

{IntNumber} {
    return ( T_INT_NUMBER );
}

{FloatNumber} {
    return ( T_FLOAT_NUMBER );
}

{CharValue} { 
    return ( T_CHAR_VALUE );
}

{BoolValue} {
    return ( T_BOOL_VALUE );
}

"main" {
    return ( T_MAIN_IDENTIFIER );
}

{Identifier} {
    yylval.stringValue = strdup ( yytext );
    return ( T_IDENTIFIER );
}

"/*" { BEGIN ( comment ); }
<comment>"*/" { BEGIN ( 0 ); }
<comment>.|\n ;

{whitespace} { }

. {
    return * yytext;
}

%%