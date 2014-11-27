#include "Operator.h"
#include "String.h"

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int divi(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }

int equal(int a, int b) { return a == b; }
int not_equal(int a, int b) { return a != b; }
int less(int a, int b) { return a < b; }
int greator(int a, int b) { return a > b; }
int less_eq(int a, int b) { return a <= b; }
int greator_eq(int a, int b) { return a >= b; }

int and_op(int a, int b) { return a && b; }
int or_op(int a, int b) { return a || b; }

int logic_not(int a, int b) { return !a; }
int not_op(int a, int b) { return -a; }

// Operation lookup table
OperatorEval operations[] = {
    add,
    sub,
    mult,
    divi,
    mod,
    equal,
    not_equal,
    less,
    greator,
    less_eq,
    greator_eq,
    and_op,
    or_op,
    logic_not,
    not_op
};

Operator::Operator(String val) : Token(false)
{
    for (int i = 0; i < number_operations; i++)
    {
        if (val == operations_str[i]) oper_eval = operations[i];
    }
}

Operator::~Operator() {}

int Operator::eval(int left, int right)
{
    return oper_eval(left, right);
}

bool Operator::isUnary(Operator* oper)
{
    return oper->oper_eval == logic_not || oper->oper_eval == not_op;
}