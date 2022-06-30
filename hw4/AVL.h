/**
* Title: AVL Trees
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 4
* Description: Header file for the AVL class
*/

#ifndef AVL_h
#define AVL_h

#include <fstream>
#include <cmath>
#include "TreeNode.h"

class AVL
{
public:
    AVL();
    ~AVL();

    TreeNode* retrieve(const string str);

    // Functions required by the assignment
    void addWord(string str);
    void generateTree(string fileName);
    void printHeight();
    void printTotalWordCount();
    void printWordFrequencies();
    void printMostFrequent();
    void printLeastFrequent();
    void printStandartDeviation();

    void printWordFrequenciesToFile(string fileName);
    void printStatisticsToFile(string fileName);

private:
    TreeNode* root;

    void deleteAVL(TreeNode* node);
    TreeNode* retrieveHelper(TreeNode* node, const string str);
    int getHeight(TreeNode* node);
    int calculateHeight(TreeNode* node);
    int getBalanceFactor(TreeNode* node);
    bool isBalanced(TreeNode* node);
    void rotateRight(TreeNode* node, TreeNode*& topNode);
    void rotateLeft(TreeNode* node, TreeNode*& topNode);
    void rotate(TreeNode*& node, TreeNode*& unbalancedNode, string str);
    bool insert(TreeNode*& node, string str); // Same as binary seach tree insertion. Returns false if the specified word is a duplicate otherwise returns true.
    void setHeights(TreeNode* node, string str);
    void toLower(string& str);
    bool isNotValid(const char str); // Returns false if the char is a letter or a digit
    int getTotalWordCount(TreeNode* node);
    void printWordFrequenciesHelper(TreeNode* node);
    void findMostFrequent(TreeNode* node, TreeNode*& mostFrequent);
    void findLeastFrequent(TreeNode* node, TreeNode*& leastFrequent);
    void getFrequencies(TreeNode* node, int* arr, double& sum, int& index);
    void printWordFrequenciesToFileHelper(ofstream& ofs, TreeNode* node);

};
#endif
