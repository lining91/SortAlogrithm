// 归并排序算法的实现
#include <stdio.h>

class CMergerSort{
public:
	void Sort(int* pArr, int length)
	{
		if (pArr == NULL || length == 0)
			return;

		int* pTemp = new int[length];
		if (pTemp == NULL)
			return;
		MergeSort(pArr, 0, length - 1, pTemp);
		delete[] pTemp;
		pTemp = NULL;
	}

	void MergeSort(int* pArr, int nStart, int nEnd, int* pTemp)
	{		if (nStart >= nEnd)
			return;
		int nMiddle = (nStart + nEnd) / 2;

		MergeSort(pArr, nStart, nMiddle, pTemp);		//	递归划分左边的数组
		MergeSort(pArr, nMiddle + 1, nEnd, pTemp);		//	递归划分右边的数组
		Merge(pArr, nStart, nMiddle, nEnd, pTemp);		//	将有序的两个序列合并成一个
	}

	void Merge(int* pArr, int nStart, int nMiddle, int nEnd, int* pTemp)
	{
		int nFirst = nStart;
		int nSecond = nMiddle + 1;
		int nIndex = nStart;	

		if (nFirst <= nMiddle && nSecond <= nEnd)
		{
			if (pArr[nFirst] >= pArr[nSecond])
				pTemp[nIndex++] = pArr[nSecond++];
			else
				pTemp[nIndex++] = pArr[nFirst++];
		}

		while (nFirst <= nMiddle) pTemp[nIndex++] = pArr[nFirst++];
		while (nSecond <= nEnd) pTemp[nIndex++] = pArr[nSecond++];

		for (int i = nStart; i <= nEnd; i++)
			pArr[i] = pTemp[i];
	}
};