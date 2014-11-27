#pragma once

#include "IStatement.h"

#include "String.h"

class ParseTree;

enum StatementType
{
	TEXT,
	SET,
	VAR,
	OUTPUT,
    RETURN
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
};

