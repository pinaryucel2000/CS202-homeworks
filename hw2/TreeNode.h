/**
* Title: Trees
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 2
* Description: Header file for the TreeNode class
*/

#ifndef TreeNode_h
#define TreeNode_h

#include <iostream>
using namespace std;


class TreeNode
{
private:
    TreeNode();
    TreeNode(const string nodeItem, TreeNode* leftPtr = NULL, TreeNode* rightPtr = NULL);
    string item;
    int count;
    TreeNode* left;
    TreeNode* right;
    friend class NgramTree;
};

#endif

