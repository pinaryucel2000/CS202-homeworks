/**
* Title: Algorithm Efficiency and Sorting
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 1
* Description: Main file to test the sorting algorithms
*/

#include <iomanip>
#include "time.h"
#include <stdlib.h>
#include "sorting.h"

void display( int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void initializeArraysRandomly( int* arr1, int* arr2, int* arr3, int size )
{
    srand((int) time(NULL));
    int randomNumber;

    for(int i = 0; i < size; i++)
    {
        randomNumber = rand();
        arr1[i] = randomNumber;
        arr2[i] = randomNumber;
        arr3[i] = randomNumber;
    }
}

void initializeArraysDescending( int* arr1, int* arr2, int* arr3, int size )
{
    for(int i = 0; i < size; i++)
    {
        arr1[i] = size - i;
        arr2[i] = size - i;
        arr3[i] = size - i;
    }
}

void initializeArraysAscending( int* arr1, int* arr2, int* arr3, int size )
{
    for(int i = 0; i < size; i++)
    {
        arr1[i] = i + 1;
        arr2[i] = i + 1;
        arr3[i] = i + 1;
    }
}

// This function is used to measure the elapsed time more precisely by running the sorting algorithms more than once.
void copyArray( int* arr, int* c1, int* c2, int* c3, int* c4, int* c5, int* c6, int* c7, int* c8, int* c9, int size )
{
    for(int i = 0; i < size; i++)
    {
        c1[i] = arr[i];
        c2[i] = arr[i];
        c3[i] = arr[i];
        c4[i] = arr[i];
        c5[i] = arr[i];
        c6[i] = arr[i];
        c7[i] = arr[i];
        c8[i] = arr[i];
        c9[i] = arr[i];
    }
}

void analyzeInsertionSort( int* arr, int size )
{
    double duration;
    clock_t startTime;
    unsigned long long compCount = 0;
    unsigned long long moveCount = 0;

    int* c1 = new int[size];
    int* c2 = new int[size];
    int* c3 = new int[size];
    int* c4 = new int[size];
    int* c5 = new int[size];
    int* c6 = new int[size];
    int* c7 = new int[size];
    int* c8 = new int[size];
    int* c9 = new int[size];

    copyArray(arr, c1, c2, c3, c4, c5, c6, c7, c8, c9, size);

    startTime = clock();

    // compCount and moveCount variables can be reused because insertionSort function resets them everytime.
    insertionSort(arr, size, compCount, moveCount);
    insertionSort(c1, size, compCount, moveCount);
    insertionSort(c2, size, compCount, moveCount);
    insertionSort(c3, size, compCount, moveCount);
    insertionSort(c4, size, compCount, moveCount);
    insertionSort(c5, size, compCount, moveCount);
    insertionSort(c6, size, compCount, moveCount);
    insertionSort(c7, size, compCount, moveCount);
    insertionSort(c8, size, compCount, moveCount);
    insertionSort(c9, size, compCount, moveCount);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << left << setw(15) << "Insertion Sort" << "   " << left << setw(15) << compCount << "   " << left << setw(15) << moveCount << "   " << left << setw(15) << duration/10 << endl;

    delete [] c1;
    delete [] c2;
    delete [] c3;
    delete [] c4;
    delete [] c5;
    delete [] c6;
    delete [] c7;
    delete [] c8;
    delete [] c9;

    c1 = NULL;
    c2 = NULL;
    c3 = NULL;
    c4 = NULL;
    c5 = NULL;
    c6 = NULL;
    c7 = NULL;
    c8 = NULL;
    c9 = NULL;
}

void analyzeInsertionSortForAscendingOrderedArrays( int* arr, int size )
{
    double duration;
    clock_t startTime;
    unsigned long long compCount = 0;
    unsigned long long moveCount = 0;

    startTime = clock();

    // Since the array is already sorted, there will be no change on it so we can reuse it.
    for(int i = 0; i < 100000; i++)
    {
        insertionSort(arr, size, compCount, moveCount); // There is a safeguard which resets compCount and moveCount in insertionSort function.
    }

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << left << setw(15) << "Insertion Sort" << "   " << left << setw(15) << compCount << "   " << left << setw(15) << moveCount << "   " << left << setw(15) << duration/100000 << endl;
}

void analyzeMergeSort( int* arr, int size )
{
    double duration;
    clock_t startTime;
    unsigned long long compCount = 0;
    unsigned long long moveCount = 0;

    int* c1 = new int[size];
    int* c2 = new int[size];
    int* c3 = new int[size];
    int* c4 = new int[size];
    int* c5 = new int[size];
    int* c6 = new int[size];
    int* c7 = new int[size];
    int* c8 = new int[size];
    int* c9 = new int[size];

    copyArray(arr, c1, c2, c3, c4, c5, c6, c7, c8, c9, size);

    unsigned long long c1CompCount = 0;
    unsigned long long c1MoveCOunt = 0;

    unsigned long long c2CompCount = 0;
    unsigned long long c2MoveCOunt = 0;

    unsigned long long c3CompCount = 0;
    unsigned long long c3MoveCOunt = 0;

    unsigned long long c4CompCount = 0;
    unsigned long long c4MoveCOunt = 0;

    unsigned long long c5CompCount = 0;
    unsigned long long c5MoveCOunt = 0;

    unsigned long long c6CompCount = 0;
    unsigned long long c6MoveCOunt = 0;

    unsigned long long c7CompCount = 0;
    unsigned long long c7MoveCOunt = 0;

    unsigned long long c8CompCount = 0;
    unsigned long long c8MoveCOunt = 0;

    unsigned long long c9CompCount = 0;
    unsigned long long c9MoveCOunt = 0;

    startTime = clock();

    mergeSort(arr, size, compCount, moveCount);
    mergeSort(c1, size, c1CompCount, c1MoveCOunt);
    mergeSort(c2, size, c2CompCount, c2MoveCOunt);
    mergeSort(c3, size, c3CompCount, c3MoveCOunt);
    mergeSort(c4, size, c4CompCount, c4MoveCOunt);
    mergeSort(c5, size, c5CompCount, c5MoveCOunt);
    mergeSort(c6, size, c6CompCount, c6MoveCOunt);
    mergeSort(c7, size, c7CompCount, c7MoveCOunt);
    mergeSort(c8, size, c8CompCount, c8MoveCOunt);
    mergeSort(c9, size, c9CompCount, c9MoveCOunt);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << left << setw(15) << "Merge Sort" << "   " << left << setw(15) << compCount << "   " << left << setw(15) << moveCount << "   " << left << setw(15) << duration/10 << endl;

    delete [] c1;
    delete [] c2;
    delete [] c3;
    delete [] c4;
    delete [] c5;
    delete [] c6;
    delete [] c7;
    delete [] c8;
    delete [] c9;

    c1 = NULL;
    c2 = NULL;
    c3 = NULL;
    c4 = NULL;
    c5 = NULL;
    c6 = NULL;
    c7 = NULL;
    c8 = NULL;
    c9 = NULL;
}

void analyzeQuickSort( int* arr, int size )
{
    double duration;
    clock_t startTime;
    unsigned long long compCount = 0;
    unsigned long long moveCount = 0;

    int* c1 = new int[size];
    int* c2 = new int[size];
    int* c3 = new int[size];
    int* c4 = new int[size];
    int* c5 = new int[size];
    int* c6 = new int[size];
    int* c7 = new int[size];
    int* c8 = new int[size];
    int* c9 = new int[size];

    copyArray(arr, c1, c2, c3, c4, c5, c6, c7, c8, c9, size);

    unsigned long long c1CompCount = 0;
    unsigned long long c1MoveCOunt = 0;

    unsigned long long c2CompCount = 0;
    unsigned long long c2MoveCOunt = 0;

    unsigned long long c3CompCount = 0;
    unsigned long long c3MoveCOunt = 0;

    unsigned long long c4CompCount = 0;
    unsigned long long c4MoveCOunt = 0;

    unsigned long long c5CompCount = 0;
    unsigned long long c5MoveCOunt = 0;

    unsigned long long c6CompCount = 0;
    unsigned long long c6MoveCOunt = 0;

    unsigned long long c7CompCount = 0;
    unsigned long long c7MoveCOunt = 0;

    unsigned long long c8CompCount = 0;
    unsigned long long c8MoveCOunt = 0;

    unsigned long long c9CompCount = 0;
    unsigned long long c9MoveCOunt = 0;

    startTime = clock();

    quickSort(arr, size, compCount, moveCount);
    quickSort(c1, size, c1CompCount, c1MoveCOunt);
    quickSort(c2, size, c2CompCount, c2MoveCOunt);
    quickSort(c3, size, c3CompCount, c3MoveCOunt);
    quickSort(c4, size, c4CompCount, c4MoveCOunt);
    quickSort(c5, size, c5CompCount, c5MoveCOunt);
    quickSort(c6, size, c6CompCount, c6MoveCOunt);
    quickSort(c7, size, c7CompCount, c7MoveCOunt);
    quickSort(c8, size, c8CompCount, c8MoveCOunt);
    quickSort(c9, size, c9CompCount, c9MoveCOunt);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << left << setw(15) << "Quick Sort" << "   " << left << setw(15) << compCount << "   " << left << setw(15) << moveCount << "   " << left << setw(15) << duration/10 << endl;

    delete [] c1;
    delete [] c2;
    delete [] c3;
    delete [] c4;
    delete [] c5;
    delete [] c6;
    delete [] c7;
    delete [] c8;
    delete [] c9;

    c1 = NULL;
    c2 = NULL;
    c3 = NULL;
    c4 = NULL;
    c5 = NULL;
    c6 = NULL;
    c7 = NULL;
    c8 = NULL;
    c9 = NULL;
}

void analyzeRandomlyFilled()
{
    for(int size = 20000; size <= 100000; size = size + 20000)
    {
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Array Size: " << size << " (Randomly filled)\n" << endl;
        cout << left << setw(15) << "Algorithm" << "   " << left << setw(15) << "Key Comparisons" << "   " << left << setw(15) << "Data Moves" << "   " << left << setw(15) << "Time Elapsed (ms)" << endl;

        int* arr1 = new int[size];
        int* arr2 = new int[size];
        int* arr3 = new int[size];
        initializeArraysRandomly(arr1, arr2, arr3, size);

        analyzeInsertionSort(arr1, size);
        delete [] arr1;
        arr1 = NULL;

        analyzeMergeSort(arr2, size);
        delete [] arr2;
        arr2 = NULL;

        analyzeQuickSort(arr3, size);
        delete [] arr3;
        arr3 = NULL;
        cout << "----------------------------------------------------------------------------" << endl;
    }
}

void analyzeDescendingOrder()
{
    for(int size = 20000; size <= 28000; size = size + 2000)
    {
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Array Size: " << size << " (Descending order)\n" << endl;
        cout << left << setw(15) << "Algorithm" << "   " << left << setw(15) << "Key Comparisons" << "   " << left << setw(15) << "Data Moves" << "   " << left << setw(15) << "Time Elapsed (ms)" << endl;

        int* arr1 = new int[size];
        int* arr2 = new int[size];
        int* arr3 = new int[size];
        initializeArraysDescending(arr1, arr2, arr3, size);

        analyzeInsertionSort(arr1, size);
        delete [] arr1;
        arr1 = NULL;

        analyzeMergeSort(arr2, size);
        delete [] arr2;
        arr2 = NULL;

        analyzeQuickSort(arr3, size);
        delete [] arr3;
        arr3 = NULL;
        cout << "----------------------------------------------------------------------------" << endl;
    }
}

void analyzeAscendingOrder()
{
    for(int size = 20000; size <= 28000; size = size + 2000)
    {
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Array Size: " << size << " (Ascending order)\n" << endl;
        cout << left << setw(15) << "Algorithm" << "   " << left << setw(15) << "Key Comparisons" << "   " << left << setw(15) << "Data Moves" << "   " << left << setw(15) << "Time Elapsed (ms)" << endl;

        int* arr1 = new int[size];
        int* arr2 = new int[size];
        int* arr3 = new int[size];
        initializeArraysAscending(arr1, arr2, arr3, size);

        analyzeInsertionSortForAscendingOrderedArrays(arr1, size);
        delete [] arr1;
        arr1 = NULL;

        analyzeMergeSort(arr2, size);
        delete [] arr2;
        arr2 = NULL;

        analyzeQuickSort(arr3, size);
        delete [] arr3;
        arr3 = NULL;
        cout << "----------------------------------------------------------------------------" << endl;
    }
}

int main()
{
    cout << setprecision(1);
    cout << fixed;

    analyzeRandomlyFilled();
    analyzeDescendingOrder();
    analyzeAscendingOrder();

    return 0;
}
