#pragma once

#include "CallStack.h"
#include "String.h"
#include "Token.h"
#include "Table.h"

class Variable : public Token
{
public:
    String name;

    Variable(String name) : Token(true), name(name) {}
    virtual ~Variable() {}

    Variable& operator=(int value) { CallStack::getScope()[name] = value; return *this; }

    int eval(int a, int b) { return CallStack::getScope()[name]; }
};

