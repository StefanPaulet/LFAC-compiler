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

Type int|float|char|bool|string
Class class
If if
For for
While while
Main main
Const const
Return return

Band &&
Bor \|\|

IntNumber    (0|[1-9]{digit}*)
FloatNumber  {IntNumber}\.{IntNumber}
CharValue    '{letter}'
BoolValue    (true|false)
StringValue  \"({letter}|{digit})*\"
Identifier   ({letter}|_)({letter}|{digit}|_)*

%%

{Band} {
    return ( T_BAND );
}

{Bor} {
    return ( T_BOR );
}

{IntNumber} {
    yylval.intValue = atoi ( yytext );
    return ( T_INT_NUMBER );
}

{FloatNumber} {
    yylval.floatValue = atof ( yytext );
    return ( T_FLOAT_NUMBER );
}

{CharValue} { 
    yylval.charValue = yytext[1];
    return ( T_CHAR_VALUE );
}

{BoolValue} {
    if ( ! strcmp ( yytext, "true" ) ) {
        yylval.boolValue = 1;
    } else {
        yylval.boolValue = 0;
    }
    return ( T_BOOL_VALUE );
}

{StringValue} {
    char * pText = strdup ( yytext + 1 );
    pText [ strlen ( pText ) - 1 ] = '\0';
    yylval.stringValue = strdup ( pText );
    free ( pText );
    return ( T_STRING_VALUE );
}

{Class} {
    return ( T_CLASS );
}

{Main} {
    return ( T_MAIN_IDENTIFIER );
}

{Const} {
    return ( T_CONST );
}

{If} {
    return ( T_IF );
}

{While} {
    return ( T_WHILE );
}

{For} {
    return ( T_FOR );
}

{Return} {
    return ( T_RETURN );
}

{Type} {
    yylval.stringValue = strdup ( yytext );
    return ( T_TYPE );
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