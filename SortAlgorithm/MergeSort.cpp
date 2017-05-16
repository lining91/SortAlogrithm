// �鲢�����㷨��ʵ��
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

		MergeSort(pArr, nStart, nMiddle, pTemp);		//	�ݹ黮����ߵ�����
		MergeSort(pArr, nMiddle + 1, nEnd, pTemp);		//	�ݹ黮���ұߵ�����
		Merge(pArr, nStart, nMiddle, nEnd, pTemp);		//	��������������кϲ���һ��
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