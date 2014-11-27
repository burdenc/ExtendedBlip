#pragma once

#include "Token.h"
#include "String.h"

// String to operation lookup table
static String operations_str[] = {
    "+",
    "-",
    "*",
    "/",
    "%",
    "==",
    "!=",
    "<",
    ">",
    "<=",
    ">=",
    "&&",
    "||",
    "!",
    "~"
};

const int number_operations = 15;

typedef int(*OperatorEval)(int a, int b);

class Operator : public Token
{
public:
    Operator(String val);
    virtual ~Operator();

    static bool isUnary(Operator* oper);

    virtual int eval(int left, int right);

private:
    OperatorEval oper_eval;
};