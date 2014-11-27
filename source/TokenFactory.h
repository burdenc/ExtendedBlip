#pragma once

#include "Parse.h"

#include "Call.h"
#include "Token.h"
#include "Variable.h"
#include "Operator.h"

#include "Table.h"
#include "String.h"

static String call_str = "call";

class TokenFactory
{
public:
    static Token* buildNextToken()
    {
        read_next_token();

        if (call_str == next_token())
        {
            return new Call();
        }

        if (String("true") == next_token()) { return new Token(1); }
        if (String("false") == next_token()) { return new Token(0); }

        switch (next_token_type)
        {
        case NUMBER:
            return new Token(token_number_value);
        case SYMBOL:
            return new Operator(next_token());
        case NAME:
            return new Variable(next_token());
        }
    }

private:
    TokenFactory();
    ~TokenFactory();
};

