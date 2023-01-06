#ifndef __FUNCTION_ENTRY_IMPL_HPP__
#define __FUNCTION_ENTRY_IMPL_HPP__

FunctionEntry :: FunctionEntry ( 
        char const              * pname,
        TypeEntry               * pReturnType,
        TreeNodeIdentifier      * pFunctionBody,
        ParameterList           * pParameterList
) : 
    SymbolEntry    ( pname ),
    _pReturnType   ( pReturnType ),
    _pFunctionBody ( pFunctionBody ) {

    this->_pParameterList = new ParameterList;
    for ( auto e : * pParameterList ) {
        this->_pParameterList->push_back ( e );
    }
}


FunctionEntry :: ~FunctionEntry () {

    delete this->_pFunctionBody;
    while ( ! _pParameterList->empty() ) {
        delete _pParameterList->front();
        _pParameterList->pop_front();
    }
}


auto FunctionEntry :: getTypeName () const -> std :: string {

    std :: string s ( this->_pReturnType->getName() );
    s += '(';
    for ( auto e = this->_pParameterList->begin(); e != this->_pParameterList->end(); ++ e ) {
        s += (* e)->getName();
        s += ",";
    }
    if ( ! this->_pParameterList->empty() ) {
        s.pop_back();
    }
    s += ")";
    return s;
}

#endif //__FUNCTION_ENTRY_IMPL_HPP__