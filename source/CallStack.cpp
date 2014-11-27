#include "CallStack.h"


CallStack::CallStack()
{
}


CallStack::~CallStack()
{
}

CallStack& CallStack::instance()
{
    static CallStack singleton;

    return singleton;
}

Table& CallStack::getScope()
{
    return CallStack::instance().peek();
}

Table& CallStack::peek()
{
    return *scopes[scopes.size() - 1];
}

void CallStack::push()
{
    scopes.push_back(new Table);
}

void CallStack::pop()
{
    delete scopes[scopes.size() - 1];
    scopes.pop_back();
}