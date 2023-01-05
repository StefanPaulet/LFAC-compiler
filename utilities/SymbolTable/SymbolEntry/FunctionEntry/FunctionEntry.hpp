#ifndef __FUNCTION_ENTRY_HPP__
#define __FUNCTION_ENTRY_HPP__

#include "../SymbolEntry.hpp"
#include "../../../AbstractSyntaxTree/TreeNodeIdentifier.hpp"
#include <list>
#include <utility>
#include <stdio.h>

class FunctionEntry : public SymbolEntry {

public:
    using ParameterList  = std :: list < char const * >;
    
private:
    char const * _pReturnType;

    TreeNodeIdentifier * _pFunctionBody;

    ParameterList * _pParameterList;

public:

    FunctionEntry ( 
        char const              * pname,
        char const              * pReturnType,
        TreeNodeIdentifier      * pFunctionBody,
        ParameterList           * pParameterList
    );


    ~FunctionEntry ();


    auto getTypeName () const -> std :: string override;
    
};

#endif //__FUNCTION_ENTRY_HPP__