#pragma once

struct ReturnType
{
    bool returned = false;
    int returned_value = 0;
};

class IStatement
{
public:
    virtual ~IStatement() {};
    virtual ReturnType execute() = 0;
};

