#ifndef __ERROR_REPORTING_HPP__
#define __ERROR_REPORTING_HPP__

#include <string>

namespace error {

    auto variableAddingError ( 
        char const *  pSymbolName,
        SymbolEntry * existentEntry 
    ) -> void {

        std :: string errorMsg = "Identifier " + std :: string ( pSymbolName );
        if ( dynamic_cast < FunctionEntry * > ( existentEntry ) != nullptr ) {
            errorMsg += " redifined as different kind of symbol";
        } else {
            errorMsg += " already defined";
        }
        yyerror ( errorMsg.c_str() );
    } 


    auto functionAddingError ( 
        char const *  pSymbolName,
        SymbolEntry * existentEntry 
    ) -> void {

        std :: string errorMsg = "Identifier " + std :: string ( pSymbolName );
        if ( dynamic_cast < VariableEntry * > ( existentEntry ) != nullptr ) {
            errorMsg += " redifined as different kind of symbol";
        } else {
            errorMsg += " already defined";
        }
        yyerror ( errorMsg.c_str() );
    } 


    auto undefinedTypeError (
        char const * pTypeName
    ) -> void {

        std :: string errorMsg = "Type " + std :: string ( pTypeName ) + " has not been defined";
        yyerror ( errorMsg.c_str() );
    }


    auto redefinedTypeError ( 
        char const * pTypeName
    ) -> void {

        std :: string errorMsg = "Type " + std :: string ( pTypeName ) + " has already been defined";
        yyerror ( errorMsg.c_str() );
    }
}

#endif //__ERROR_REPORTING_HPP__