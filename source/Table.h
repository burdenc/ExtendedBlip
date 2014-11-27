#pragma once

#include "Vector.h"

class String;
class Variable;
class Function;

class Table
{
public:
    Table();
    ~Table();

    int& operator[](const String& name);
    int& declare(const String& name, int value);

    bool exists(const String& name, bool use_global = true);

	unsigned int size() { return name_list.size(); }

    bool funcExists(String name);
    int callFunc(String name, int* args);
    void declareFunc(Function* func) { function_list.push_back(func); }

	static Table* global;

private:
    Vector<Function*> function_list;
    Vector<String> name_list;
    Vector<int> value_list;
    int num_params = 0;

    Table& operator=(const Table& table);
    Table(const Table& table);
};