#pragma once
#include "IStatement.h"
#include "Vector.h"
#include "ParseTree.h"
#include "Table.h"

class String;

enum ConditionalType
{
    IF,
    DO
};

class ConditionalStatement : public IStatement
{
public:
    ConditionalStatement(ConditionalType type);
    virtual ~ConditionalStatement();

    virtual ReturnType execute();

    ConditionalType type;

private:
    ParseTree conditional;
    Vector<IStatement*> statement_block;
    Vector<IStatement*> else_block;
};

