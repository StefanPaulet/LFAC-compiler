#ifndef __ERROR_REPORTING_HPP__
#define __ERROR_REPORTING_HPP__

#include <string>

extern unsigned long long int errorCount;

namespace error {

    auto variableRedeclaration ( 
        char const *  pSymbolName,
        SymbolEntry * existentEntry 
    ) -> void {

        ++ errorCount;
        std :: string errorMsg = "Identifier " + std :: string ( pSymbolName );
        if ( dynamic_cast < FunctionEntry * > ( existentEntry ) != nullptr ) {
            errorMsg += " redifined as different kind of symbol";
        } else {
            errorMsg += " already defined";
        }
        yyerror ( errorMsg.c_str() );
    } 


    auto functionRedeclaration ( 
        char const *  pSymbolName,
        SymbolEntry * existentEntry 
    ) -> void {

        ++ errorCount;
        std :: string errorMsg = "Identifier " + std :: string ( pSymbolName );
        if ( dynamic_cast < VariableEntry * > ( existentEntry ) != nullptr ) {
            errorMsg += " redifined as different kind of symbol";
        } else {
            errorMsg += " already defined";
        }
        yyerror ( errorMsg.c_str() );
    } 


    auto undefinedType (
        char const * pTypeName
    ) -> void {

        ++ errorCount;
        std :: string errorMsg = "Type " + std :: string ( pTypeName ) + " has not been defined";
        yyerror ( errorMsg.c_str() );
    }


    auto redefinedType ( 
        char const * pTypeName
    ) -> void {

        ++ errorCount;
        std :: string errorMsg = "Type " + std :: string ( pTypeName ) + " has already been defined";
        yyerror ( errorMsg.c_str() );
    }


    auto nonStructureType (
        char const * pTypeName
    ) -> void {

        ++ errorCount;
        std :: string errorMsg = "Type " + std :: string ( pTypeName ) + " is not a union";
        yyerror ( errorMsg.c_str() );
    }


    auto undeclaredSymbol (
        char const * pSymbolName
    ) -> void {
        
        ++ errorCount;
        std :: string errorMsg = "Symbol " + std :: string ( pSymbolName ) + " has not been declared";
        yyerror ( errorMsg.c_str() );
    }


    auto nonExistentMember (
        char const * pClassName,
        char const * pMemberName
    ) -> void {

        ++ errorCount;
        std :: string errorMsg = "Class " + std :: string ( pClassName ) + " has no member " + std :: string ( pMemberName );
        yyerror ( errorMsg.c_str() );
    }


    auto nonFunctionCallError (
        char const * pSymbolName
    ) -> void {

        ++ errorCount;
        std :: string errorMsg = "Identifier " + std :: string ( pSymbolName ) + " does not name a function";
        yyerror ( errorMsg.c_str() );
    }


    auto nonArrayTypeArrayAccess (
        char const * pSymbolName
    ) -> void {

        ++ errorCount;
        std :: string errorMsg = "Identifier " + std :: string ( pSymbolName ) + " does not have array type";
        yyerror ( errorMsg.c_str() );
    }


    auto arrayPointerAccess () {

        ++ errorCount;
        std :: string errorMsg = "Operation not supported: Accessed pointer to array";
        yyerror ( errorMsg.c_str() );
    }


    auto invalidSubscriptAccess () {

        ++ errorCount;
        std :: string errorMsg = "Required subscript does not match identifier type";
        yyerror ( errorMsg.c_str() );
    }


    auto mismatchedParameterCount (
        std :: size_t providedParameters,
        std :: size_t targetParameters
    ) {

        ++ errorCount;
        std :: string errorMsg = "No matchin function to call: " + std :: to_string ( targetParameters ) +  " parameters required but only "
                                + std :: to_string ( providedParameters ) + " provided";
        yyerror ( errorMsg.c_str() );
    }


    auto mismatchetParameterType (
        unsigned short int parameterCount,
        char const * pParameterType,
        char const * pCallerType
    ) -> void {

        ++ errorCount;
        std :: string errorMsg = "No matching function to call: parameter number " + std :: to_string ( parameterCount ) +
                                " has type " + pParameterType + " while calling argument has type " + pCallerType;
        yyerror ( errorMsg.c_str() );
    }
}

#endif //__ERROR_REPORTING_HPP__