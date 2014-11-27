#pragma once

#include "Table.h"
#include "Vector.h"

class CallStack
{
public:
    ~CallStack();
    static CallStack& instance();
    static Table& getScope();

    void push();
    void pop();
    Table& peek();

private:
    CallStack();
    CallStack(const CallStack& ref);
    CallStack& operator=(const CallStack& ref);

    Vector<Table*> scopes;
};

