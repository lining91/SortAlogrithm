#include <iostream>
#include <stdio.h>
//#include "BubbleSort.cpp"
//#include "BubbleSort2.cpp"
//#include "SelectSort.cpp"
//#include "InsertSort.cpp"
//#include "BinInsertSort.cpp"
//#include "ShellSort.cpp"
//#include "MergeSort.cpp"
//#include "HeapSort.cpp"
/*#include "QuickSort.cpp"*/
/*#include "CountingSort.cpp"*/
#include "RadixSort.cpp"
using namespace std;

void main()
{

	int test[]={99999, 65, 24, 47, 13, 878, 321, 5, 82222, 66, 33, 22445, 10001, 624159, 624158, 6251};
	int count = sizeof(test) / sizeof(int);
	RadixSort*  pSort = new RadixSort();
	if (pSort == NULL)
		return;
	pSort->Sort(&test[0], count);
	delete pSort;
	pSort = NULL;

	cout << "After sort :" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << test[i] << "  "; 
	}
	cout << endl;
	system("pause");
}