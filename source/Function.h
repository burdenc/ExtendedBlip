#pragma once
#include "IStatement.h"

#include "String.h"
#include "Vector.h"
#include "Table.h"

class Function : public IStatement
{
public:
    Function();
    virtual ~Function();

    virtual ReturnType execute() { return ReturnType(); } // Executing a function does nothing as they have to be called
    int call(int* params);

    String name;

private:
    Vector<IStatement*> function_statements;
    Vector<String> param_names;
};

