#ifndef SORT_H_
#define SORT_H_
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BubbleSort(vector<int>& array, int start, int end);
void InsertionSort(vector<int>& array, int start, int end);
void MergeSort(vector<int>& array, int start, int end);
void IterativeMergeSort(vector <int> array, int start, int end);
void QuickSort(vector<int>& array, int start, int end);
void ShellSort(vector<int>& array, int start, int end);
void Merge(vector<int>& array, int start, int mid, int end);
void Swap(int& lhs, int& rhs);

#endif

void BubbleSort(vector<int>& array, int start, int end)
{
    /* Precondition Checking */
    if (array.size() < 1)
    {
        cerr << "Invalid Array Input" << endl;
    }
    if (start > end)
    {
        cerr << "Starting Point cannont be greater than Ending Point" << endl;
    }
    /* Loop from[start] to[end] */
    for (int i = start; i < end; i++) 
    {
        /* Loop from[start] to[start + end - i] */
        for (int j = start; j < start + end - i; j ++)  
        {
            if (array[j] > array[j + 1])
            {
                Swap(array[j], array[j + 1]);
            }
        }
    }
}

void InsertionSort(vector<int>& array, int start, int end)
{
    /* Precondition Checking */
    if (array.size() < 1)
    {
        cerr << "Invalid Array Input" << endl;
    }
    if (start > end)
    {
        cerr << "Starting Point cannont be greater than Ending Point" << endl;
    }
    for (int i = start + 1; i <= end; i++)
    {
        int j = i - 1;
        int key = array[i];
        while ((j >= start) && (array[j] > key))
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void QuickSort(vector<int>& array, int start, int end)
{
    /* Precondition Checking */
    if (array.size() < 1)
    {
        cerr << "Invalid Array Input" << endl;
    }
    if (start > end)
    {
        cerr << "Starting Point cannont be greater than Ending Point" << endl;
    }
    /* Array contains less than 10 items is reasonable to use Insertion Sort */
    if (end - start + 1 < 10)
    {
        InsertionSort(array, start, end);
        return;
    }
    int mid = (start + end) / 2;
    /* Swapping three major references before partitioning */
    if (array[start] > array[end])
    {
        Swap(array[start], array[end]);
    }
    if (array[start] > array[mid])
    {
        Swap(array[start], array[mid]);
    }
    if (array[mid] > array[end])
    {
        Swap(array[mid], array[end]);
    }
    int pivot = array[mid];
    Swap(array[mid], array[end - 1]);
    int item_from_left = start + 1;
    int item_from_right = end - 2;
    bool sorted = false;
    while (!sorted)
    {
        while (array[item_from_left] < pivot)
        {
            item_from_left++;
        }
        while (array[item_from_right] > pivot)
        {
            item_from_right--;
        }
        if (item_from_right > item_from_left)
        {
            Swap(array[item_from_left], array[item_from_right]);
            item_from_left++;
            item_from_right--;
        }
        else
        {
            sorted = true;
        }
    }
    Swap(array[item_from_left], array[end - 1]);
    QuickSort(array, start, item_from_left - 1);
    QuickSort(array, item_from_left + 1, end);
}

void ShellSort(vector<int>& array, int start, int end)
{
    /* Precondition Checking */
    if (array.size() < 1)
    {
        cerr << "Invalid Array Input" << endl;
    }
    if (start > end)
    {
        cerr << "Starting Point cannont be greater than Ending Point" << endl;
    }
    int size = end - start + 1;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap + start; i <= end; i++) // Start from start + gap
        {
            int temp = array[i];
            int j;
            for (j = i; j >= gap + start && temp < array[j - gap]; j -= gap) // Update loop condition
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void MergeSort(vector<int>& array, int start, int end)
{
    /* Precondition Checking */
    if (array.size() < 1)
    {
        cerr << "Invalid Array Input" << endl;
    }
    if (start > end)
    {
        cerr << "Starting Point cannont be greater than Ending Point" << endl;
    }
    else
    {
        int mid = (start + end) / 2;
        MergeSort(array, start, mid);
        MergeSort(array, mid + 1, end);
        Merge(array, start, mid, end);
    }
}

void IterativeMergeSort(vector <int> array, int start, int end)
{
    /* Precondition Checking */
    if (array.size() < 1)
    {
        cerr << "Invalid Array Input" << endl;
    }
    if (start > end)
    {
        cerr << "Starting Point cannont be greater than Ending Point" << endl;
    }
    int size = (end - start) + 1;
    /* Initially, we merge two sub-arrays of size 1 to create a sorted sub-array of size 2.
    Then merge two sub-arrays of size 2 to create a sorted sub array of size 4, and so on. */
    for (int curr_size = 1; curr_size < size; curr_size *= 2)
    {
        /* Left start: the starting point of different sub-arrays of the associated size*/
        for (int left_start = 0; left_start < size - 1; left_start += curr_size * 2)
        {
            int mid = min(left_start + curr_size - 1, size - 1);
            int end = min(left_start + 2 * curr_size - 1, size - 1);
            // Merge Subarrays array[left_start...mid] & array[mid + 1...right_end]
            Merge(array, left_start, mid, end);
        }
    }
}

void Swap(int& lhs, int& rhs)
{
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void Merge(vector<int>& array, int start, int mid, int end)
{
    int lhs_start = start;
    int lhs_end = mid;
    int rhs_start = mid + 1;
    int rhs_end = end;
    int size = end - start + 1;
    int index = 0;
    int* temp_array = new int[size];
    /* While both sub-arrays are not empty, continuously copy the smaller item to the temporary array
    After this point, either lhs sub-array or rhs sub-array might contain extra item */
    while ((lhs_start <= lhs_end) && (rhs_start <= rhs_end))
    {
        if (array[lhs_start] < array[rhs_start])
        {
            temp_array[index] = array[lhs_start];
            lhs_start++;
        }
        else
        {
            temp_array[index] = array[rhs_start];
            rhs_start++;
        }
        index++;
    }
    /* Finish off the first sub-array */
    while (lhs_start <= lhs_end)
    {
        temp_array[index] = array[lhs_start];
        lhs_start++;
        index++;
    }
    /* Finish off the second sub-array */
    while (rhs_start <= rhs_end)
    {
        temp_array[index] = array[rhs_start];
        rhs_start++;
        index++;
    }
    /* Copy the sorted elements from the temporary array back to the original array */
    for (index = start; index < end; index++)
    {
        array[start] = temp_array[index];
        start++;
    }
    /* Free the temporary array */
    delete[] temp_array;
}