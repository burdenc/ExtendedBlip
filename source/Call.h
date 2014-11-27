#pragma once
#include "Token.h"

#include "String.h"
#include "Vector.h"
#include "Table.h"

class ParseTree;

class Call : public Token
{
public:
    Call();
    virtual ~Call();

    virtual int eval(int a, int b);

    String function_name;
    Vector<ParseTree*> args_list;
};

