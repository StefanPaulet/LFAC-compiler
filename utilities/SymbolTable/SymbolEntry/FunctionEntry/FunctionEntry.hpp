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
    using ParameterList  = std :: list < SymbolEntry * >;
    
private:
    TypeEntry * _pReturnType;

    TreeNode * _pFunctionBody;

    ParameterList * _pParameterList;

    Scope * _pScope;

public:

    FunctionEntry ( 
        char const          * pname,
        TypeEntry           * pReturnType,
        TreeNode            * pFunctionBody,
        ParameterList       * pParameterList,
        Scope               * pScope
    );


    ~FunctionEntry ();


    auto getTypeName () const -> std :: string override;


    constexpr auto getType () const -> TypeEntry * override;
    

    auto matchParameterCallList (
        ParameterList * pParameterList
    ) -> bool;


    constexpr auto getScope () const -> Scope *;


    auto setFunctionBody ( 
        TreeNode * pFunctionBody
    ) -> void;


    auto getFunctionBody () -> TreeNode *;


    auto getParameterList () -> ParameterList *;
};

#include "../../../AbstractSyntaxTree/TreeNode/impl/TreeNodeIdentifier.hpp"

#endif //__FUNCTION_ENTRY_HPP__