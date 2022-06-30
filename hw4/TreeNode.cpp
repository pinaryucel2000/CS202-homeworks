/**
* Title: AVL Trees
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 4
* Description: Cpp file for the TreeNode class
*/

#include "TreeNode.h"

TreeNode::TreeNode(const string nodeItem)
{
    item = nodeItem;
    count = 1;
    height = 1;
    left = NULL;
    right = NULL;
}


