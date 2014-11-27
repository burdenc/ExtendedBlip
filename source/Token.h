#pragma once

#include "Parse.h"

class Token
{
public:
    Token(int value) : value(value), isOperand(true) {};
	virtual ~Token() {};

	virtual int eval(int left, int right) { return value; };

	int value;
    bool isOperand;
    TokenType type;

protected:
    // For class inheritance
    Token(bool isOperand) : isOperand(isOperand) {};
};

