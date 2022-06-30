/**
* Title: Algorithm Efficiency and Sorting
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 1
* Description: Cpp file for the sorting algorithms
*/

#include "sorting.h"

void insertionSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount )
{
    // Safeguard
    compCount = 0;
    moveCount = 0;

    for (int unsorted = 1; unsorted < size; ++unsorted)
    {
        int nextItem = arr[unsorted];
        moveCount++;

        int loc = unsorted;

        for (  ;(loc > 0) && (++compCount && arr[loc-1] > nextItem); --loc)
        {
            arr[loc] = arr[loc-1];
            moveCount++;
        }

        arr[loc] = nextItem;
        moveCount++;
    }
}

void merge( int theArray[], int first, int mid, int last, unsigned long long& compCount, unsigned long long& moveCount )
{
    int tempArray[last-first+1]; // temporary array
    int first1 = first; // beginning of first subarray
    int last1 = mid; // end of first subarray
    int first2 = mid + 1; // beginning of second subarray
    int last2 = last; // end of second subarray
    int index = 0; // next available location in tempArray

    for ( ; (first1 <= last1) && (first2 <= last2); ++index)
    {
        if (++compCount && theArray[first1] < theArray[first2])
        {
            tempArray[index] = theArray[first1];
            moveCount++;
            ++first1;
        }
        else
        {
            tempArray[index] = theArray[first2];
            moveCount++;
            ++first2;
        }
   }

    //finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = theArray[first1];
        moveCount++;
    }

    //finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = theArray[first2];
        moveCount++;
    }

    //copy the result back into the original array
    for (int i = 0; i < index; i++)
    {
        theArray[first + i] = tempArray[i];
        moveCount++;
    }
}

void mergesort( int theArray[], int first, int last, unsigned long long& compCount, unsigned long long& moveCount )
{
    if (first < last)
    {
        int mid = (first + last)/2; 	// index of midpoint

        mergesort(theArray, first, mid, compCount, moveCount);
        mergesort(theArray, mid+1, last, compCount, moveCount);

        // merge the two halves
        merge(theArray, first, mid, last, compCount, moveCount);
   }
}

void mergeSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount )
{
    mergesort(arr, 0, size - 1, compCount, moveCount);
}

void swap(int &x, int &y)
{
   int temp = x;
   x = y;
   y = temp;
}

void partition( int theArray[], int first, int last, int &pivotIndex, unsigned long long& compCount, unsigned long long& moveCount )
{
    int pivot = theArray[first];
    moveCount++;
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    // move one item at a time until unknown region is empty
    for (  ; firstUnknown <= last; ++firstUnknown)
    {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
        if ( ++compCount && theArray[firstUnknown] < pivot) // belongs to S1
        {
            ++lastS1;
            swap(theArray[firstUnknown], theArray[lastS1]);
            moveCount = moveCount + 3;
        }	// else belongs to S2
    }

   // place pivot in proper position and mark its location
    swap(theArray[first], theArray[lastS1]);
    moveCount = moveCount + 3;
    pivotIndex = lastS1;
}

void quicksort( int theArray[], int first, int last, unsigned long long& compCount, unsigned long long& moveCount )
{
    // Precondition: theArray[first..last] is an array.
    // Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

    if (first < last)
    {

        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        quicksort(theArray, first, pivotIndex-1, compCount, moveCount);
        quicksort(theArray, pivotIndex+1, last, compCount, moveCount);
    }
}

void quickSort( int* arr, const int size, unsigned long long& compCount, unsigned long long& moveCount )
{
    quicksort(arr, 0, size - 1, compCount, moveCount);
}

