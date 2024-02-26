#ifndef SORT_H_
#define SORT_H_
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BubbleSort(vector<int> &array, int start, int end);
void InsertionSort(vector<int> &array, int start, int end);
void MergeSort(vector<int> &array, int start, int end);
void IterativeMergeSort(vector<int> &array, int start, int end);
void QuickSort(vector<int> &array, int start, int end);
void ShellSort(vector<int> &array, int start, int end);
void Merge(vector<int> &array, int start, int mid, int end);
void Swap(int &lhs, int &rhs);

#endif

void BubbleSort(vector<int> &array, int start, int end)
{
    /* Loop from[start] to[end] */
    for (int i = start; i < end; i++)
    {
        /* Loop from[start] to[start + end - i] */
        for (int j = start; j < start + end - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                Swap(array[j], array[j + 1]);
            }
        }
    }
}

void InsertionSort(vector<int> &array, int start, int end)
{
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

void QuickSort(vector<int> &array, int start, int end)
{
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

void ShellSort(vector<int> &array, int start, int end)
{
    int size = end - start + 1;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap + start; i <= end; i++) 
        {
            int temp = array[i];
            int j;
            for (j = i; j >= gap + start && temp < array[j - gap]; j -= gap) 
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void MergeSort(vector<int> &array, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(array, start, mid);
        MergeSort(array, mid + 1, end);
        Merge(array, start, mid, end);
    }
}

void IterativeMergeSort(vector<int> &array, int start, int end)
{
    int size = (end - start) + 1;
    int gap = 1;
	int *temp_array = new int[size];
    /* Copy from orginal array to auxiliary array */
	for (int i = 0; i < start; i++)
	{
		temp_array[i] = array[i];
	}
	while (gap < size)
	{
		int current = start;
		int first1 = start;
		int index1;
		int	index2;
		while ((first1 + gap) < (end + 1))
		{
			int first2 = (first1 + gap);
			int last1 = (first2 - 1);
			int last2;
			if (!((first2 + gap - 1) < (end + 1)))
			{
				last2 = end;
			}
			else
			{
				last2 = (first2 + gap - 1);
			}
			index1 = first1;
			index2 = first2;
			while ((index1 <= last1) && (index2 <= last2))
			{
				if (array[index1] >= array[index2])
				{
					temp_array[current] = array[index2];
					index2++;
				}
				else
				{
					temp_array[current] = array[index1];
					index1++;
				}
				current++;
			}
			while (index1 <= last1)
			{
				temp_array[current] = array[index1];
				index1++;
				current++;
			}

			while (index2 <= last2)
			{
				temp_array[current] = array[index2];
				current++;
				index2++;
			}

			first1 = last2 + 1;
		}
		index1 = first1;
		while (current < (end + 1))
		{
			temp_array[current] = array[index1];
			current++;
			index1++;
		}
        /* Copy from auxiliary array to orginal array */
		for (int i = start; i < (end + 1); i++)
		{
			array[i] = temp_array[i];
		}
        /* Increment size of gap */
		gap *= 2;
	}
}

void Swap(int &lhs, int &rhs)
{
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void Merge(vector<int> &array, int start, int mid, int end)
{
    int *temp_array;
    int size = end - start + 1;
    temp_array = new int[size];
    int lhs_start = start;
    int lhs_end = mid;
    int rhs_start = mid + 1;
    int rhs_end = end;
    int index = 0;
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
    while (lhs_start <= lhs_end)
    {
        temp_array[index] = array[lhs_start];
        lhs_start++;
        index++;
    }
    while (rhs_start <= rhs_end)
    {
        temp_array[index] = array[rhs_start];
        rhs_start++;
        index++;
    }
    for (index = 0; index < size; index++)
    {
        array[start] = temp_array[index];
        start++;
    }
    delete[] temp_array;
}
