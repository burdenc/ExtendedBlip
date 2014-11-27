#include "Table.h"

#include <stdio.h>

#include "CallStack.h"
#include "Function.h"
#include "Variable.h"

Table* Table::global = nullptr;

Table::Table()
{
	if (!Table::global) { Table::global = this; }
}

Table::~Table()
{
}

bool Table::exists(const String& name, bool use_global)
{
    for (unsigned int i = 0; i < name_list.size(); i++)
    {
        if (name == name_list[i]) { return true; }
    }

    if (!use_global) { return false; }

	if (Table::global != this)
	{
		return Table::global->exists(name);
	}

    return false;
}

int& Table::declare(const String& name, int value)
{
	if (exists(name, false))
	{
		printf("variable %s incorrectly re-initialized\n", name.c_str());
		(*this)[name] = value;
		return (*this)[name];
	}
    
    name_list.push_back(name);
    value_list.push_back(value);
    
    return value_list[value_list.size() - 1];
}

int& Table::operator[](const String& name)
{
    for (unsigned int i = 0; i < name_list.size(); i++)
    {
        if (name == name_list[i]) { return value_list[i]; }
    }

	if (Table::global != this && Table::global->exists(name))
	{
		return Table::global->operator[](name);
	}

    // Accessing undeclared variable, spit warning
    printf("variable %s not declared\n", name.c_str());

    return declare(name, 0);
}

int Table::callFunc(String name, int* args)
{
    for (unsigned int i = 0; i < function_list.size(); i++)
    {
        if (name == function_list[i]->name)
		{
			CallStack::instance().push();
			int ret = function_list[i]->call(args);
			CallStack::instance().pop();
			return ret;
		}
    }

    if (Table::global != this)
    {
        return Table::global->callFunc(name, args);
    }

	return 0;
}