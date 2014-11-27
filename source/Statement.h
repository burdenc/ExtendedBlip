#pragma once

#include "IStatement.h"

#include "String.h"

class Call;
class ParseTree;

enum StatementType
{
    TEXT,
    SET,
    VAR,
    OUTPUT,
    RETURN,
    CALL
};

class Statement : public IStatement
{
public:
    Statement(StatementType type);
    virtual ~Statement();

    virtual ReturnType execute();

    StatementType type;
    String var_name;
    String output;
    ParseTree* expression = nullptr;
    Call* functionCall = nullptr;
};

