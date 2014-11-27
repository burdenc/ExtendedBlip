#include "ConditionalStatement.h"

#include "Parse.h"

#include "StatementFactory.h"
#include "String.h"
#include "Table.h"
#include "ParseTree.h"

String else_str = "else"; // Hack, eh

ConditionalStatement::ConditionalStatement(ConditionalType type, String terminator) : conditional(), type(type)
{
    conditional.buildTree();

    while (read_next_token(), terminator != next_token() && else_str != next_token())
    {
        statement_block.push_back(StatementFactory::buildNextStatement());
    }

    if (else_str == next_token())
    {
        while (read_next_token(), terminator != next_token())
        {
            else_block.push_back(StatementFactory::buildNextStatement());
        }
    }
}


ConditionalStatement::~ConditionalStatement()
{
    for (unsigned int i = 0; i < statement_block.size(); i++)
    {
        delete statement_block[i];
    }

    for (unsigned int i = 0; i < else_block.size(); i++)
    {
        delete else_block[i];
    }
}

ReturnType ConditionalStatement::execute()
{
    ReturnType result;

    if (type == IF)
    {
        if (conditional.execute())
        {
            for (unsigned int i = 0; i < statement_block.size() && !result.returned; i++)
            {
                result = statement_block[i]->execute();
            }
        }

        else
        {
            for (unsigned int i = 0; i < else_block.size() && !result.returned; i++)
            {
                result = else_block[i]->execute();
            }
        }
    }
    else if (type == DO)
    {
        while (conditional.execute() && !result.returned)
        {
            for (unsigned int i = 0; i < statement_block.size() && !result.returned; i++)
            {
                result = statement_block[i]->execute();
            }
        }
    }

    return result;
}