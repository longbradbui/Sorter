#include <vector>
#include <string>
//#include <sys/time.h>
#include <iostream>
#include "sorts.h"
using namespace std;

/*
//Global functions
void InitVector(vector<int>& item_vetor, int size);
void PrintVector(const vector<int>& item_vector, string name);
int Elapsed(const timeval& start, const timeval& end);
int main(int argc, char* argv[])
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
	//get time to measure the time it takes to sort
	struct timeval start_time, end_time;
	gettimeofday(&start_time, 0);
	//
	// PLACE YOUR CODE HERE
	// ...Determine which sort to call on the vector
	// ...The code below only looks for QuickSort
	// Other Signatures:
	// BubbleSort(items, 0, size - 1)
	// InsertionSort(items, 0, size � 1)
	// MergeSort(items, 0, size � 1)
	// IterativeMergeSort(items, 0, size � 1)
	// ShellSort(items, 0, size � 1)
	// PLACE YOUR CODE HERE; for instance:
	if (sort_name == "QuickSort")
	{
		QuickSort(items, 0, size - 1);
	}
	gettimeofday(&end_time, 0);
	if (print_out)
	{
		cout << "Sorted:" << endl;
		PrintVector(items, string("item"));
	}
	cout << "Time (microsecs): " << Elapsed(start_time, end_time) << endl;
	return 0;
}
void InitVector(vector<int>& item_vector, int rand_max)
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
void PrintVector(const vector<int>& item_vector, string name)
{
	int size = item_vector.size();
	for (int i = 0; i < size; i++)
	{
		cout << item_vector[i] << " ";
	}
	cout << endl;
}
// Function to calculate elapsed time
// Microseconds
int Elapsed(const timeval& start, const timeval& end)
{
	return (end.tv_sec - start.tv_sec) * 1000000
		+ (end.tv_usec - start.tv_usec);
}
*/

int main()
{
static const int kStart = 3;
static const int kEnd = 8;

	cout << "Testing Bubble Sort" << endl;
	std::vector<int> arr1 = { 3, 2, 7, 8, 10, 9, 0, 1, 4, 6, 5 };
	std::cout << "Original array: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	BubbleSort(arr1, kStart, kEnd);
	std::cout << "Sorted subrange: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	cout << endl;

	std::vector<int> arr2 = { 3, 2, 7, 8, 10, 9, 0, 1, 4, 6, 5 };
	cout << "Testing Insertion Sort" << endl;
	std::cout << "Original array: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;
	InsertionSort(arr2, kStart, kEnd);
	std::cout << "Sorted subrange: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;
	cout << endl;

	std::vector<int> arr3 = { 3, 2, 7, 8, 10, 9, 0, 1, 4, 6, 5 };
	cout << "Testing Recursive Merge Sort" << endl;
	std::cout << "Original array: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr3[i] << " ";
	}
	std::cout << std::endl;
	InsertionSort(arr3, kStart, kEnd);
	std::cout << "Sorted subrange: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr3[i] << " ";
	}
	std::cout << std::endl;
	cout << endl;

	std::vector<int> arr4 = { 3, 2, 7, 8, 10, 9, 0, 1, 4, 6, 5 };
	cout << "Testing Quick Sort" << endl;
	std::cout << "Original array: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr4[i] << " ";
	}
	std::cout << std::endl;
	QuickSort(arr4, kStart, kEnd);
	std::cout << "Sorted subrange: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr4[i] << " ";
	}
	std::cout << std::endl;
	cout << endl;

	std::vector<int> arr5 = { 3, 2, 7, 8, 10, 9, 0, 1, 4, 6, 5 };
	cout << "Testing Shell Sort" << endl;
	std::cout << "Original array: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr5[i] << " ";
	}
	std::cout << std::endl;
	ShellSort(arr5, kStart, kEnd);
	std::cout << "Sorted subrange: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr5[i] << " ";
	}
	std::cout << std::endl;
	cout << endl;

	std::vector<int> arr6 = { 3, 2, 7, 8, 10, 9, 0, 1, 4, 6, 5 };
	cout << "Testing Iterative Merge Sort" << endl;
	std::cout << "Original array: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr6[i] << " ";
	}
	std::cout << std::endl;
	ShellSort(arr6, kStart, kEnd);
	std::cout << "Sorted subrange: ";
	for (int i = kStart; i <= kEnd; i++) {
		std::cout << arr6[i] << " ";
	}
	std::cout << std::endl;
	cout << endl;
	return 0;
}