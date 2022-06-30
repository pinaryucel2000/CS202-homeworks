/**
* Title: Trees
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 2
* Description: Cpp file for the NgramTree class
*/

#include "NgramTree.h"

NgramTree::NgramTree()
{
    root = NULL;
}

NgramTree::~NgramTree()
{
    destroyTree(root);
}

void NgramTree::destroyTree(TreeNode* root)
{
    if(root != NULL)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

void NgramTree::addNgram(string ngram)
{
    toLower(ngram);
    addNgram(root, ngram);
}

void NgramTree::addNgram(TreeNode*& node, string ngram)
{
    if(node == NULL)
    {
        node = new TreeNode(ngram);
    }
    else if(node->item > ngram)
    {
        addNgram(node->left, ngram);
    }
    else if(node->item < ngram)
    {
        addNgram(node->right, ngram);
    }
    else // equal
    {
        node->count++;
    }
}

void NgramTree::getTotalNgramCountHelper(TreeNode* node, int& count)
{
    if(node != NULL)
    {
        getTotalNgramCountHelper(node->left, count);
        getTotalNgramCountHelper(node->right,count);
        count++;
    }
}

int NgramTree::getTotalNgramCount()
{
    int count = 0;
    getTotalNgramCountHelper(root, count);
    return count;
}

void NgramTree::toArray(TreeNode* node, string*& arr, int index, const int count)
{
    if(node != NULL && index < getTotalNgramCount())
    {
        arr[index] = node->item;
        toArray(node->left, arr, 2 * index + 1, count);
        toArray(node->right, arr, 2 * index + 2, count);
    }
}

bool NgramTree::isComplete()
{
    int nodeCount = getTotalNgramCount();
    string* arr = new string[nodeCount];
    bool result = 1;

    for(int i = 0; i < nodeCount; i++)
    {
        arr[i] = "0";
    }

    toArray(root, arr, 0, getTotalNgramCount());

    for(int i = 0; i < nodeCount; i++)
    {
        if(arr[i] == "0")
        {
            result = 0;
        }
    }

    delete [] arr;
    arr = NULL;

    return result;
}

bool NgramTree::isFull()
{
    double dividend = getTotalNgramCount() + 1; // Full trees have t nodes where t = 2^k (for any integer k >= 0)

    while(dividend > 1)
    {
        dividend = dividend / 2.0;
    }

    return isComplete() && dividend == 1;
}

TreeNode* NgramTree::retrieveNgram(string ngram)
{
    TreeNode* node = NULL;
    toLower(ngram);
    retrieveNgram(root, node, ngram);
    return node;
}

void NgramTree::retrieveNgram(TreeNode* root, TreeNode*& node, string ngram)
{
    if(root != NULL)
    {
        if(root->item == ngram)
        {
            node = root;
        }
        else if(root->item > ngram)
        {
            retrieveNgram(root->left, node, ngram);
        }
        else
        {
            retrieveNgram(root->right, node, ngram);
        }
    }
}

void NgramTree::deleteNgram(string ngram)
{
    toLower(ngram);
    deleteNgram(root, ngram);
}

void NgramTree::deleteNgram(TreeNode*& node, string ngram)
{
    if(node == NULL)
    {
        return;
    }
    else if(node->item == ngram)
    {
        if(node->count > 1)
        {
            node->count--;
        }
        else
        {
            deleteNgram(node);
        }
    }
    else if(node->item < ngram)
    {
        deleteNgram(node->right, ngram);
    }
    else
    {
        deleteNgram(node->left, ngram);
    }
}

void NgramTree::deleteNgram(TreeNode*& node)
{
    if(node->left == NULL && node->right == NULL)
    {
        delete node;
        node = NULL;
    }
    else if(node->left == NULL)
    {
        TreeNode* tmp = node;
        node = node->right;
        delete tmp;
        tmp = NULL;
    }
    else if(node->left == NULL)
    {
        TreeNode* tmp = node;
        node = node->left;
        delete tmp;
        tmp = NULL;
    }
    else // two children
    {
        string leftMostItem;
        int leftMostCount;

        processLeftMost(node, leftMostItem, leftMostCount);

        node->item = leftMostItem;
        node->count = leftMostCount;

    }
}

void NgramTree::processLeftMost(TreeNode*& node, string& leftMostItem, int& leftMostCount)
{
    if(node->left == NULL)
    {
        leftMostItem = node->item;
        leftMostCount = node->count;

        if(node->right == NULL)
        {
            delete node;
            node = NULL;
        }
        else
        {
            TreeNode* tmp = node;
            node = node->right;
            delete tmp;
            tmp = NULL;
        }
    }
    else
    {
        processLeftMost(node->left, leftMostItem, leftMostCount);
    }
}

void NgramTree::generateTree(string fileName, int n)
{
    string input = ""; // txt file content
    string word_ = ""; // a word in the txt file

    ifstream ifs;
    int fileNameSize = fileName.size();

    char* fileNamePtr = new char[fileNameSize];

    for(int i = 0; i < fileNameSize; i++)
    {
        fileNamePtr[i] = fileName[i];
    }

    ifs.open(fileNamePtr);

    while(ifs >> word_)
    {
        input = input + " " + word_ + " ";
    }

    ifs.close();

    int size;
    int start;
    string word;
    int wordSize;

    size = input.size();
    start = 0;

    for(int i = 0; i <= size; i++)
    {
        if(input[i] == ' ' || i == size)
        {
            word = input.substr(start, i - start);
            wordSize = word.size();

            if(wordSize >= n)
            {
                for(int wordStart = 0; wordStart <= wordSize - n; wordStart++)
                {
                    addNgram(word.substr(wordStart,n));
                }
            }

            start = start + wordSize + 1;
        }
    }

    delete [] fileNamePtr;
    fileNamePtr = NULL;
}

ostream& NgramTree::print(ostream& out) const
{
    return print(out, root);
}

ostream& NgramTree::print(ostream& out, TreeNode* node) const
{
    if(node != NULL)
    {
        print(out, node->left);
        out << "\"" << node->item << "\"" << " appears " << node->count << " time(s)" << endl;
        print(out, node->right);
    }

    return out;
}

ostream& operator<<( ostream& out, const NgramTree& tree )
{
    return tree.print(out);
}

void NgramTree::toLower(string& str)
{
    int size = str.size();

    for(int i = 0; i < size; i++)
    {
        if(str[i] == 'A')
        {
            str[i] = 'a';
        }
        else if(str[i] == 'B')
        {
            str[i] = 'b';
        }
        else if(str[i] == 'C')
        {
            str[i] = 'c';
        }
        else if(str[i] == 'D')
        {
            str[i] = 'd';
        }
        else if(str[i] == 'E')
        {
            str[i] = 'e';
        }
        else if(str[i] == 'F')
        {
            str[i] = 'f';
        }
        else if(str[i] == 'G')
        {
            str[i] = 'g';
        }
        else if(str[i] == 'H')
        {
            str[i] = 'h';
        }
        else if(str[i] == 'I')
        {
            str[i] = 'i';
        }
        else if(str[i] == 'J')
        {
            str[i] = 'j';
        }
        else if(str[i] == 'K')
        {
            str[i] = 'k';
        }
        else if(str[i] == 'L')
        {
            str[i] = 'l';
        }
        else if(str[i] == 'M')
        {
            str[i] = 'm';
        }
        else if(str[i] == 'N')
        {
            str[i] = 'n';
        }
        else if(str[i] == 'O')
        {
            str[i] = 'o';
        }
        else if(str[i] == 'P')
        {
            str[i] = 'p';
        }
        else if(str[i] == 'Q')
        {
            str[i] = 'q';
        }
        else if(str[i] == 'R')
        {
            str[i] = 'r';
        }
        else if(str[i] == 'S')
        {
            str[i] = 's';
        }
        else if(str[i] == 'T')
        {
            str[i] = 't';
        }
        else if(str[i] == 'U')
        {
            str[i] = 'u';
        }
        else if(str[i] == 'V')
        {
            str[i] = 'v';
        }
        else if(str[i] == 'W')
        {
            str[i] = 'w';
        }
        else if(str[i] == 'X')
        {
            str[i] = 'x';
        }
        else if(str[i] == 'Y')
        {
            str[i] = 'y';
        }
        else if(str[i] == 'Z')
        {
            str[i] = 'z';
        }
    }
}
