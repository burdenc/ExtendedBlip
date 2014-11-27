#include "Statement.h"

#include "CallStack.h"
#include "Parse.h"
#include "ParseTree.h"

#include <stdio.h>

const int num_statements = 4;

String lookup[] =
{
	"text",
	"set",
	"var",
	"output",
    "return"
};

Statement::Statement(StatementType type) : type(type)
{
	switch (type)
	{
    case TEXT:
        read_next_token();
        output = next_token();
        break;
	case SET:
	case VAR:
        read_next_token();
		var_name = next_token();
    case RETURN:
	case OUTPUT:
		expression = new ParseTree();
		expression->buildTree();
	}
}


Statement::~Statement()
{
	delete expression;
}

ReturnType Statement::execute()
{
    ReturnType result;
	Table& scope = CallStack::getScope();

	switch (type)
	{
	case TEXT:
		printf("%s", output.c_str());
		break;
	case SET:
		scope[var_name] = expression->execute();
		break;
	case VAR:
		scope.declare(var_name, expression->execute());
		break;
	case OUTPUT:
		printf("%d", expression->execute());
        break;
    case RETURN:
        result.returned = true;
        result.returned_value = expression->execute();
        break;
	}

    return result;
}