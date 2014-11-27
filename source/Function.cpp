#include "Function.h"

#include "Parse.h"
#include "StatementFactory.h"

String func_terminator = "nufed";
String params_terminator = "smarap";

Function::Function()
{
    read_next_token();
    name = next_token();
    read_next_token(); // "params" token

    while (read_next_token(), params_terminator != next_token())
    {
        param_names.push_back(next_token()); // Define parameters
    }

    while (read_next_token(), func_terminator != next_token())
    {
        function_statements.push_back(StatementFactory::buildNextStatement());
    }
}


Function::~Function()
{
    for (unsigned int i = 0; i < function_statements.size(); i++)
    {
        delete function_statements[i];
    }
}

int Function::call(int* args)
{
    Table& scope = CallStack::getScope();

    for (unsigned int i = 0; i < param_names.size(); i++)
    {
        scope.declare(param_names[i], args[i]);
    }

    ReturnType result;
    for (unsigned int i = 0; i < function_statements.size(); i++)
    {
        result = function_statements[i]->execute();
        if (result.returned) { break; }
    }

    return result.returned_value;
}