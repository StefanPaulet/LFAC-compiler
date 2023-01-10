#ifndef __SCOPE_HPP__
#define __SCOPE_HPP__

#include "../SymbolTable/SymbolTable.hpp"
#include "../TypeTable/TypeTable.hpp"
#include <list>


class Scope {

public:
    static Scope * pGlobalScope;

public:
    using TypeLength               = TypeTable :: TypeLength;
    using ParameterList            = FunctionEntry :: ParameterList;
    using ParameterDeclarationPair = std :: pair < char const *, char const * >;
    using ParameterDeclarationList = std :: list < ParameterDeclarationPair * >;

private:
    Scope        * _pUpperScope       { nullptr };
    TypeTable    * _pTypes            = new TypeTable;
    SymbolTable  * _pSymbols          = new SymbolTable;

public:
    Scope ( 
        Scope     * pUpperScope  = nullptr,
        TypeTable * pTypes       = nullptr
    );


    ~Scope ();

    auto constexpr getUpperScope () -> Scope *;


    auto constexpr getSymbolTable () -> SymbolTable *;


    auto constexpr getTypeTable () -> TypeTable *;


private:

    auto _copyScope (
        Scope * pOtherScope
    ) -> void;

    auto _typeExistenceCheck (
        char const * pTypeName
    ) -> TypeEntry *;


public:

    auto addVariable (
        char const * pSymbolType,
        char const * pSymbolName
    ) -> VariableEntry *;

    auto addVariable (
        TypeEntry  * pSymbolType,
        char const * pSymbolName
    ) -> VariableEntry *;

    
    auto addArrayVariable (
        char const * pBaseType,
        char const * pSymbolName,
        char const * pArrayType,
        TypeLength   arraySize
    ) -> void;

    auto addFunction (
        char const                   * pFunctionName,
        char const                   * pReturnTypeName,
        TreeNode                     * pFunctionBody,
        ParameterDeclarationList     * pParameterListTypes,
        Scope                        * pScope
    ) -> void;


    auto addUserDefinedType (
        char const * pTypeName,
        Scope *      pTypeScope
    ) -> StructuredTypeEntry *;

    
    auto setUserDefinedTypeLength (
        StructuredTypeEntry * pTypeEntry
    ) -> void;


    auto getSymbol ( 
        char const * pSymbolName
    ) -> SymbolEntry *;
};

#include "../SymbolTable/impl/SymbolTable.hpp"
#include "../TypeTable/impl/TypeTable.hpp"

#endif //__SCOPE_HPP__