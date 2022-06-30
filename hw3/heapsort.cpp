/**
* Title: Heaps
* Author: Pinar Yucel
* ID: 21802188
* Assignment: 3
* Description: Cpp file for the heapsort algorithm
*/

#include <fstream>
#include "heap.h"
#include <math.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

int heapsort(int* arr, int size)
{
    Heap heap;
    int countOfComparisons = 0;

    for(int i = 0; i < size; i++)
    {
        heap.insertAndCountComparisons(arr[i], countOfComparisons);
    }

    for(int i = size - 1; i >= 0; i--)
    {
        arr[i] = heap.popMaximumAndCountComparisons(countOfComparisons);
    }

    return countOfComparisons;
}

double stringToDouble(string str)
{
    int size = str.size();
    double result = 0;

    for(int i = 0; i < size; i++)
    {
        if(str[size - 1 - i] == '1')
        {
            result = result + 1 * pow(10, i);
        }
        else if(str[size - 1 - i] == '2')
        {
            result = result + 2 * pow(10, i);
        }
        else if(str[size - 1 - i] == '3')
        {
            result = result + 3 * pow(10, i);
        }
        else if(str[size - 1 - i] == '4')
        {
            result = result + 4 * pow(10, i);
        }
        else if(str[size - 1 - i] == '5')
        {
            result = result + 5 * pow(10, i);
        }
        else if(str[size - 1 - i] == '6')
        {
            result = result + 6 * pow(10, i);
        }
        else if(str[size - 1 - i] == '7')
        {
            result = result + 7 * pow(10, i);
        }
        else if(str[size - 1 - i] == '8')
        {
            result = result + 8 * pow(10, i);
        }
        else if(str[size - 1 - i] == '9')
        {
            result = result + 9 * pow(10, i);
        }
    }

    return result;
}

int* fileToArray(string fileName, int& size)
{
    string input = "";
    string word = "";
    size = 0;

    ifstream ifs;
    int fileNameSize = fileName.size();

    char* fileNamePtr = new char[fileNameSize];

    for(int i = 0; i < fileNameSize; i++)
    {
        fileNamePtr[i] = fileName[i];
    }

    ifs.open(fileNamePtr);

    while(ifs >> word)
    {
        size++;
    }

    ifs.close();

    int* arr = new int[size];
    int i = 0;

    ifs.open(fileNamePtr);

    while(ifs >> word)
    {
        arr[i] = stringToDouble(word);
        i++;
    }

    ifs.close();

    return arr;
}

void arrayToFile(string fileName, int* arr, int size)
{
    ofstream ofs;
    ofs.open(fileName.c_str());

    for(int i = 0; i < size; i++)
    {
        ofs << arr[i];
        ofs << "\n";
    }

    ofs.close();
}

int main(int argc, char** argv)
{
    string inputFileName(argv[1]);
    string outputFileName(argv[2]);

    int size = 0;
    int* arr = fileToArray(inputFileName, size);

    int countOfComparisons = heapsort(arr, size);

    arrayToFile(outputFileName, arr, size);

    if(size > 0)
    {
        delete [] arr;
        arr = NULL;
    }

    cout << size << " elements were sorted in ascending order." << endl;
    cout << countOfComparisons << " comparisons were made." << endl;
}
