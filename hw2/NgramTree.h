/**
* Title: Trees
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 2
* Description: Header file for the NgramTree class
*/

#ifndef NgramTree_h
#define NgramTree_h

#include <fstream>
#include <stdlib.h>
#include <stdio.h>

#include "TreeNode.h"

class NgramTree
{
public:
    NgramTree();
    ~NgramTree();

    // Regular operations
    void addNgram(string ngram);
    void deleteNgram(string ngram);
    TreeNode* retrieveNgram(string ngram);

    int getTotalNgramCount();
    bool isComplete();
    bool isFull();
    void generateTree(string fileName, int n);

private:
    TreeNode* root;
    void addNgram(TreeNode*& node, string ngram);
    void getTotalNgramCountHelper(TreeNode* node, int& count);
    void retrieveNgram(TreeNode* root, TreeNode*& node, string ngram);
    void toLower(string& str);
    void destroyTree(TreeNode* root);
    void deleteNgram(TreeNode*& node, string ngram);
    void deleteNgram(TreeNode*& node);
    void processLeftMost(TreeNode*& node, string& leftMostItem, int& leftMostCount);
    void toArray(TreeNode* node, string*& arr, int index, const int count);
    ostream& print(ostream& out, TreeNode* node) const;
    ostream& print(ostream& out) const;

    friend ostream& operator<<( ostream& out, const NgramTree& tree );

};
#endif
