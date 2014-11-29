#pragma once

#include "Parse.h"

#include "CallStack.h"
#include "IStatement.h"
#include "Statement.h"
#include "ConditionalStatement.h"
#include "Function.h"

static String normal_lookup[] =
{
    "text",
    "set",
    "var",
    "output",
    "return",
    "call"
};
int const num_normal_lookup = sizeof(normal_lookup) / sizeof(String);

static String conditional_lookup[] =
{
    "if",
    "do"
};
int const num_conditional_lookup = sizeof(conditional_lookup) / sizeof(String);

static String function_keyword = "defun";

class StatementFactory
{
public:
    static IStatement* buildNextStatement()
    {
        for (int i = 0; i < num_normal_lookup; i++)
        {
            if (normal_lookup[i] == next_token())
            {
                return new Statement((StatementType) i);
            }
        }

        for (int i = 0; i < num_conditional_lookup; i++)
        {
            if (conditional_lookup[i] == next_token())
            {
                return new ConditionalStatement((ConditionalType) i);
            }
        }

        if (function_keyword == next_token())
        {
            return new Function();
        }

        return nullptr;
    }

private:
    StatementFactory();
    ~StatementFactory();
};