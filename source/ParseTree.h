#pragma once

#include "TokenFactory.h"
#include "Parse.h"
#include "Token.h"
#include "String.h"
#include "Table.h"

class TreeNode
{
public:
    TreeNode(Token* node_token);
    ~TreeNode();
    Token* node_token = nullptr;
    TreeNode* left_child = nullptr;
    TreeNode* right_child = nullptr;
};

class ParseTree
{
public:
    ParseTree() {}

    //ParseTree(const String& expression, Table& variable_scope);
    ~ParseTree() { delete root_node; }

    // Execute statement represented by the tree
    int execute() { return execute(root_node); }

    // Recursively build tree, assumes next_token is the start of a new expression
    void buildTree();

private:
    TreeNode* root_node = nullptr;

    int execute(TreeNode* node_ptr);
    TreeNode* _buildTree();
};