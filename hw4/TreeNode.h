/**
* Title: AVL Trees
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 4
* Description: Header file for the TreeNode class
*/

#ifndef TreeNode_h
#define TreeNode_h

#include <iostream>
using namespace std;

class TreeNode
{
private:
    TreeNode(const string nodeItem);
    string item;
    int count;
    int height;
    TreeNode* left;
    TreeNode* right;
    friend class AVL;
};

#endif
