/**
* Title: Algorithm Efficiency and Sorting
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 1
* Description: Header file for the sorting algorithms
*/

#ifndef sorting_h
#define sorting_h

#include <iostream>
using namespace std;

void insertionSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount );
void mergeSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount );
void quickSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount );

void merge( int theArray[], int first, int mid, int last, unsigned long long& compCount, unsigned long long& moveCount );
void mergesort( int theArray[], int first, int last, unsigned long long& compCount, unsigned long long& moveCount );

void swap(int &x, int &y);
void partition( int theArray[], int first, int last, int &pivotIndex, unsigned long long& compCount, unsigned long long& moveCount );
void quicksort( int theArray[], int first, int last, unsigned long long& compCount, unsigned long long& moveCount );

#endif
