/**
* Title: AVL Trees
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 4
* Description: Main file for homework 4
*/

#include "AVL.h"

int main(int argc, char** argv)
{
    string inputFileName(argv[1]);
    AVL avl;
    avl.generateTree(inputFileName);
    avl.printWordFrequenciesToFile("wordfreqs");
    avl.printStatisticsToFile("statistics");

    return 0;
}
