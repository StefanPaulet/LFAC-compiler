#ifndef __FUNCTION_ENTRY_HPP__
#define __FUNCTION_ENTRY_HPP__

#include "../SymbolEntry.hpp"
#include "../../../AbstractSyntaxTree/TreeNode/TreeNodeIdentifier.hpp"
#include <list>
#include <utility>
#include <stdio.h>

class Scope;

class FunctionEntry : public SymbolEntry {

public:
    using ParameterPair  = std :: pair < TypeEntry *, char const * >;
    using ParameterList  = std :: list < ParameterPair * >;
    
private:
    TypeEntry * _pReturnType;

    TreeNodeIdentifier * _pFunctionBody;

    ParameterList * _pParameterList;

    Scope * _pScope;

public:

    FunctionEntry ( 
        char const          * pname,
        TypeEntry           * pReturnType,
        TreeNodeIdentifier  * pFunctionBody,
        ParameterList       * pParameterList,
        Scope               * pScope
    );


    ~FunctionEntry ();


    auto getTypeName () const -> std :: string override;


    constexpr auto getType () const -> TypeEntry * override;
    

    auto matchParameterList (
        std :: list < SymbolEntry * > * pParameterList
    ) -> bool;


    constexpr auto getScope () const -> Scope *;
};

#endif //__FUNCTION_ENTRY_HPP__