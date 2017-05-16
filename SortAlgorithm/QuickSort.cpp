//	快速排序算法的实现
#include <stdio.h>

class CQuickSort{
public:
	void Swap(int* pArr, int i, int j)
	{
		int temp = pArr[i];
		pArr[i] = pArr[j];
		pArr[j] = temp;

	}
	void Sort(int* pArr, int length)
	{
		if (pArr == NULL || length == 0)
			return;

		QuickSort(pArr, 0, length - 1);
	}

	void QuickSort(int* pArr, int left, int right)
	{
		int nIdx;
		if (left < right)
		{
			nIdx = Partition(pArr, left, right);
			QuickSort(pArr, left, nIdx - 1);
			QuickSort(pArr, nIdx + 1, right);
		}

	}

	int Partition(int* pArr, int left, int right)
	{
		int nIdx = left - 1;
		int nTemp = pArr[right];

		for (int i = left; i < right; i++)
		{
			if (pArr[i] <= nTemp)
			{
				nIdx++;
				Swap(pArr, nIdx, i);
			}
		}

		int nFindIdx = nIdx + 1;
		Swap(pArr, nFindIdx, right);
		return nFindIdx;
	}
};