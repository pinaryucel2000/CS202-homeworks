/**
* Title: Heaps
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 3
* Description: Cpp file for the Heap class
*/

#include "heap.h"

Heap::Heap()
{
    items = NULL;
    size = 0;
}

Heap::~Heap()
{
    if(size > 0)
    {
        delete [] items;
        items = NULL; // safeguard
    }
}

void Heap::expandHeap() // Expands heap by one but does not increase size since no new item is added.
{
    int* tmp = items;
    items = new int[size + 1];

    for(int i = 0; i < size; i++)
    {
        items[i] = tmp[i];
    }

    items[size] = -1;
    delete [] tmp;
    tmp = NULL; // safeguard
}

void Heap::shrinkHeap() // Deletes the last item in the heap and decreases size by one.
{
    int* tmp = items;
    items = new int[size - 1];


    for(int i = 0; i < size - 1; i++)
    {
        items[i] = tmp[i];
    }

    delete tmp;
    tmp = NULL;

    size--;
}

void Heap::insert(const int a)
{
    expandHeap();

    items[size] = a;

    int place = size;
    int parent = (place - 1) / 2;

    while( (place > 0) && (items[place] > items[parent]) )
    {
        int tmp = items[parent];
        items[parent] = items[place];
        items[place] = tmp;

        place = parent;
        parent = (place - 1) / 2;
    }

    size++;
}

int Heap::maximum()
{
    if(size > 0)
    {
        return items[0];
    }
    else
    {
        throw -1;
    }
}

void Heap::heapRebuild(int root)
{
    int child = 2 * root + 1;

    if(child < size)
    {
        int rightChild = child + 1;

        if( (rightChild < size) && (items[rightChild] > items[child]) )
        {
            child = rightChild;
        }

        if(items[root] < items[child])
        {
            int tmp = items[root];
            items[root] = items[child];
            items[child] = tmp;

            heapRebuild(child);
        }
    }
}

int Heap::popMaximum()
{
    if(items != NULL && size != 0 )
    {
        int last = items[size - 1];
        int max = maximum();
        items[0] = last;
        shrinkHeap();
        heapRebuild(0);

        return max;
    }
    else
    {
        throw -1;
    }
}

void Heap::insertAndCountComparisons(const int a, int& countOfComparisons)
{
    expandHeap();

    items[size] = a;

    int place = size;
    int parent = (place - 1) / 2;

    while( (place > 0) && ( ++countOfComparisons ) && ( items[place] > items[parent] ) )
    {
        int tmp = items[parent];
        items[parent] = items[place];
        items[place] = tmp;

        place = parent;
        parent = (place - 1) / 2;
    }

    size++;
}

int Heap::popMaximumAndCountComparisons(int& countOfComparisons)
{
    if(items != NULL && size != 0 )
    {
        int last = items[size - 1];
        int max = maximum();
        items[0] = last;
        shrinkHeap();
        heapRebuildAndCountComparisons(0, countOfComparisons);

        return max;
    }
    else
    {
        throw -1;
    }
}

void Heap::heapRebuildAndCountComparisons(int root, int& countOfComparisons)
{
    int child = 2 * root + 1;

    if(child < size)
    {
        int rightChild = child + 1;

        if( (rightChild < size) && (++countOfComparisons) && (items[rightChild] > items[child]) )
        {
            child = rightChild;
        }

        if( (++countOfComparisons) && (items[root] < items[child]) )
        {
            int tmp = items[root];
            items[root] = items[child];
            items[child] = tmp;

            heapRebuildAndCountComparisons(child, countOfComparisons);
        }
    }
}

void Heap::printHeap()
{
    cout << "size: " << size << endl;

    for(int i = 0; i < size; i++)
    {
        cout << items[i] << " ";
    }

    cout << endl;
    cout << endl;
}
