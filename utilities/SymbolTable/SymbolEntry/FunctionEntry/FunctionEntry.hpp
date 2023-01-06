#ifndef __FUNCTION_ENTRY_HPP__
#define __FUNCTION_ENTRY_HPP__

#include "../SymbolEntry.hpp"
#include "../../../AbstractSyntaxTree/TreeNodeIdentifier.hpp"
#include "../../../TypeTable/TypeEntry/TypeEntry.hpp"
#include <list>
#include <utility>
#include <stdio.h>

class FunctionEntry : public SymbolEntry {

public:
    using ParameterList  = std :: list < TypeEntry * >;
    
private:
    TypeEntry * _pReturnType;

    TreeNodeIdentifier * _pFunctionBody;

    ParameterList * _pParameterList;

public:

    FunctionEntry ( 
        char const              * pname,
        TypeEntry               * pReturnType,
        TreeNodeIdentifier      * pFunctionBody,
        ParameterList           * pParameterList
    );


    ~FunctionEntry ();


    auto getTypeName () const -> std :: string override;
    
};

#endif //__FUNCTION_ENTRY_HPP__