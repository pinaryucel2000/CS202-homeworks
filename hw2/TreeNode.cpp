/**
* Title: Trees
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 2
* Description: Cpp file for the TreeNode class
*/

#include "TreeNode.h"

TreeNode::TreeNode() : item(""), count(1), left(NULL), right(NULL)
{
}

TreeNode::TreeNode(const string nodeItem, TreeNode* leftPtr, TreeNode* rightPtr) : item(nodeItem), count(1), left(NULL), right(NULL)
{
}

