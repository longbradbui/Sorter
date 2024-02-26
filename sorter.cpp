#include <vector>
#include <string>
#include <sys/time.h>
#include <iostream>
#include "sorts.h"
using namespace std;
static const int kStart = 3;
static const int kEnd = 21;

// Global functions
void InitVector(vector<int> &item_vetor, int size);
void PrintVector(const vector<int> &item_vector, string name);
int Elapsed(const timeval &start, const timeval &end);

int main(int argc, char *argv[])
{
	int size = 0;
	string sort_name = "";
	bool print_out = false;
	if ((argc != 3) && (argc != 4))
	{
		cerr << "Usage: Sorter algorithm size [Print]" << endl;
		return -1;
	}
	sort_name = string(argv[1]);
	size = atoi(argv[2]);
	if (size <= 0)
	{
		cerr << "Vector size must be positive" << endl;
		return -1;
	}
	if (argc == 4)
	{
		string print_arr = string(argv[3]);
		if (print_arr == "Print")
		{
			print_out = true;
		}
		else
		{
			cerr << "Usage: Sorter algorithm size [Print]" << endl;
			return -1;
		}
	}
	srand(1);
	vector<int> items(size);
	InitVector(items, size);
	if (print_out)
	{
		cout << "Initial:" << endl;
		PrintVector(items, string("items"));
		cout << endl;
	}
	// get time to measure the time it takes to sort
	struct timeval start_time, end_time;
	gettimeofday(&start_time, 0);
	/* BUBBLE SORT */
	if (sort_name == "BubbleSort")
	{
		BubbleSort(items, 0, size - 1);
		gettimeofday(&end_time, 0);
		if (print_out)
		{
			cout << "Sorted:" << endl;
			PrintVector(items, string("item"));
		}
		cout << "Time (microsecs): " << Elapsed(start_time, end_time) << endl;
	}
	/* INSERTION SORT */
	else if (sort_name == "InsertionSort")
	{
		InsertionSort(items, 0, size - 1);
		gettimeofday(&end_time, 0);
		if (print_out)
		{
			cout << "Sorted:" << endl;
			PrintVector(items, string("item"));
		}
		cout << "Time (microsecs): " << Elapsed(start_time, end_time) << endl;
	}
	/* MERGE SORT */
	else if (sort_name == "MergeSort")
	{
		MergeSort(items, 0, size - 1);
		gettimeofday(&end_time, 0);
		if (print_out)
		{
			cout << "Sorted:" << endl;
			PrintVector(items, string("item"));
		}
		cout << "Time (microsecs): " << Elapsed(start_time, end_time) << endl;
	}
	/* ITERATIVE MERGE SORT */
	else if (sort_name == "IterativeMergeSort")
	{
		IterativeMergeSort(items, 0, size - 1);
		gettimeofday(&end_time, 0);
		if (print_out)
		{
			cout << "Sorted:" << endl;
			PrintVector(items, string("item"));
		}
		cout << "Time (microsecs): " << Elapsed(start_time, end_time) << endl;
	}
	/* SHELL SORT */
	else if (sort_name == "ShellSort")
	{
		ShellSort(items, 0, size - 1);
		gettimeofday(&end_time, 0);
		if (print_out)
		{
			cout << "Sorted:" << endl;
			PrintVector(items, string("item"));
		}
		cout << "Time (microsecs): " << Elapsed(start_time, end_time) << endl;
	}
	/* QUICK SORT */
	else if (sort_name == "QuickSort")
	{
		QuickSort(items, 0, size - 1);
		gettimeofday(&end_time, 0);
		if (print_out)
		{
			cout << "Sorted:" << endl;
			PrintVector(items, string("item"));
		}
		cout << "Time (microsecs): " << Elapsed(start_time, end_time) << endl;
	}
	return 0;
}

// int main()
// {	
// 	/* MANUAL TESTING */
// 	cout << "Testing Bubble Sort" << endl;
// 	std::vector<int> arr1 = {31, 2, 17, 87, 10, 9, 0, 1, 4, 6, 5, 10, 99, 27, 33, 21, 56, 7, 87, 99, 43, 3, 71, 99, 12, 83, 2, 33, 46, 99, 22, 19, 65, 11, 97};
// 	std::cout << "Original array: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr1[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	BubbleSort(arr1, kStart, kEnd);
// 	std::cout << "Sorted subrange: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr1[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	cout << endl;

// 	std::vector<int> arr2 = {31, 2, 17, 87, 10, 9, 0, 1, 4, 6, 5, 10, 99, 27, 33, 21, 56, 7, 87, 99, 43, 3, 71, 99, 12, 83, 2, 33, 46, 99, 22, 19, 65, 11, 97};
// 	cout << "Testing Insertion Sort" << endl;
// 	std::cout << "Original array: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr2[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	InsertionSort(arr2, kStart, kEnd);
// 	std::cout << "Sorted subrange: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr2[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	cout << endl;

// 	std::vector<int> arr3 = {31, 2, 17, 87, 10, 9, 0, 1, 4, 6, 5, 10, 99, 27, 33, 21, 56, 7, 87, 99, 43, 3, 71, 99, 12, 83, 2, 33, 46, 99, 22, 19, 65, 11, 97};
// 	cout << "Testing Recursive Merge Sort" << endl;
// 	std::cout << "Original array: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr3[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	MergeSort(arr3, kStart, kEnd);
// 	std::cout << "Sorted subrange: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr3[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	cout << endl;

// 	std::vector<int> arr4 = {31, 2, 17, 87, 10, 9, 0, 1, 4, 6, 5, 10, 99, 27, 33, 21, 56, 7, 87, 99, 43, 3, 71, 99, 12, 83, 2, 33, 46, 99, 22, 19, 65, 11, 97};
// 	cout << "Testing Quick Sort" << endl;
// 	std::cout << "Original array: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr4[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	QuickSort(arr4, kStart, kEnd);
// 	std::cout << "Sorted subrange: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr4[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	cout << endl;

// 	std::vector<int> arr6 = {31, 2, 17, 87, 10, 9, 0, 1, 4, 6, 5, 10, 99, 27, 33, 21, 56, 7, 87, 99, 43, 3, 71, 99, 12, 83, 2, 33, 46, 99, 22, 19, 65, 11, 97};
// 	cout << "Testing Iterative Merge Sort" << endl;
// 	std::cout << "Original array: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr6[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	IterativeMergeSort(arr6, kStart, kEnd);
// 	std::cout << "Sorted subrange: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr6[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	cout << endl;

// 	std::vector<int> arr5 = {31, 2, 17, 87, 10, 9, 0, 1, 4, 6, 5, 10, 99, 27, 33, 21, 56, 7, 87, 99, 43, 3, 71, 99, 12, 83, 2, 33, 46, 99, 22, 19, 65, 11, 97};
// 	cout << "Testing Shell Sort" << endl;
// 	std::cout << "Original array: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr5[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	ShellSort(arr5, kStart, kEnd);
// 	std::cout << "Sorted subrange: ";
// 	for (int i = kStart; i <= kEnd; i++)
// 	{
// 		std::cout << arr5[i] << " ";
// 	}
// 	std::cout << std::endl;
// 	cout << endl;

// 	return 0;
// }

void InitVector(vector<int> &item_vector, int rand_max)
{
	if (rand_max < 0)
	{
		return;
	}
	vector<int> pool(rand_max);
	for (int i = 0; i < rand_max; i++)
	{
		pool[i] = i;
	}
	int spot;
	for (int i = 0; i < rand_max; i++)
	{
		spot = rand() % (pool.size());
		item_vector[i] = pool[spot];
		pool.erase(pool.begin() + spot);
	}
}
void PrintVector(const vector<int> &item_vector, string name)
{
	int size = item_vector.size();
	for (int i = 0; i < size; i++)
	{
		cout << item_vector[i] << " ";
	}
	cout << endl;
}
int Elapsed(const timeval &start, const timeval &end)
{
	return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}
