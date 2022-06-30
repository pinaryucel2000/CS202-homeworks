/**
* Title: Heaps
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 3
* Description: Header file for the Heap class
*/

#ifndef Heap_h
#define Heap_h

#include <iostream>
using namespace std;

class Heap
{
public:
    Heap();
    ~Heap();

    // Functions required by the assignment.
    void insert(const int a);
    int maximum();
    int popMaximum();

    void insertAndCountComparisons(const int a, int& countOfComparisons);
    int popMaximumAndCountComparisons(int& countOfComparisons);

    void printHeap();

private:
    int* items;
    int size;

    void expandHeap(); // Expands the heap by one.
    void shrinkHeap(); // Shrinks the heap by one.
    void heapRebuild(int root);
    void heapRebuildAndCountComparisons(int root, int& countOfComparisons);

};
#endif
