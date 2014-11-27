#include "Call.h"

#include "CallStack.h"
#include "Parse.h"
#include "ParseTree.h"

// TODO: This code sucks, nested ParseTrees make infants cry

Call::Call() : Token(true)
{
    read_next_token();
    function_name = next_token();

    read_next_token(); // "(" token

    String args_terminator = ")";
    while (args_terminator != peek_next_token())
    {
        ParseTree* tree = new ParseTree();
        tree->buildTree();
        args_list.push_back(tree);
    }

    read_next_token(); // args terminator
}


Call::~Call()
{
    for (unsigned int i = 0; i < args_list.size(); i++)
    {
        delete args_list[i];
    }
}

int Call::eval(int a, int b)
{
    int* arg_values = nullptr;

    if (args_list.size() != 0)
    {
        arg_values = new int[args_list.size()];

        for (unsigned int i = 0; i < args_list.size(); i++)
        {
            arg_values[i] = args_list[i]->execute();
        }
    }

    int result = CallStack::getScope().callFunc(function_name, arg_values);

    delete [] arg_values;

    return result;
}