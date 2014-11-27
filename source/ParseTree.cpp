#include "ParseTree.h"

int ParseTree::execute(TreeNode* node_ptr)
{
    if (!node_ptr) { return 0; }

    int left = execute(node_ptr->left_child);
    int right = execute(node_ptr->right_child);
    return node_ptr->node_token->eval(left, right);
}

void ParseTree::buildTree()
{
    root_node = _buildTree();
}

TreeNode* ParseTree::_buildTree()
{
    TreeNode* node_ptr;
    Token* new_token = TokenFactory::buildNextToken();

    node_ptr = new TreeNode(new_token);

    if (new_token->isOperand) { return node_ptr; }

    node_ptr->left_child = _buildTree();
    if (!Operator::isUnary((Operator *) new_token)) { node_ptr->right_child = _buildTree(); } // Hack for unary operators

    return node_ptr;
}

TreeNode::TreeNode(Token* node_token)
{
    left_child = right_child = nullptr;
    this->node_token = node_token;
}

TreeNode::~TreeNode()
{
    delete node_token;
    delete left_child;
    delete right_child;
}