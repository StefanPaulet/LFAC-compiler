#ifndef __SCOPE_HPP__
#define __SCOPE_HPP__

#include "../SymbolTable/SymbolTable.hpp"
#include "../TypeTable/TypeTable.hpp"

#include "../ErrorReporting/ErrorReporting.hpp"
#include <list>

class Scope {

public:
    using TypeLength    = TypeTable :: TypeLength;
    using ParameterList = FunctionEntry :: ParameterList;

private:
    Scope        * _pUpperScope       { nullptr };
    Scope        * _pGlobalScope      { nullptr };
    TypeTable    * _pTypes            = new TypeTable;
    SymbolTable  * _pSymbols          = new SymbolTable;

public:
    Scope ( 
        Scope     * pUpperScope  = nullptr,
        Scope     * pGlobalScope = nullptr,
        TypeTable * pTypes       = nullptr
    );


    ~Scope ();

    auto constexpr getUpperScope () -> Scope *;


    auto constexpr getSymbolTable () -> SymbolTable *;


    auto constexpr getTypeTable () -> TypeTable *;


private:
    auto _typeExistenceCheck (
        char const * pTypeName
    ) -> TypeEntry *;


public:

    auto addVariable (
        char const * pSymbolType,
        char const * pSymbolName
    ) -> void;


    auto addFunction (
        char const                   * pFunctionName,
        char const                   * pReturnTypeName,
        TreeNodeIdentifier           * pFunctionBody,
        std :: list < char const * > * pParameterListTypes
    ) -> void;


    auto addUserDefinedType (
        char const * pTypeName,
        Scope *      pTypeScope
    ) -> StructuredTypeEntry *;

    
    auto setUserDefinedTypeLength (
        StructuredTypeEntry * pTypeEntry
    ) -> void;
};

#include "../SymbolTable/impl/SymbolTable.hpp"
#include "../TypeTable/impl/TypeTable.hpp"

#endif //__SCOPE_HPP__