//	选择排序算法的实现
#include <stdio.h>

class CSelectSort{
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
		
		for (int i = 0; i < length; i++)
		{
			int nMinIdx = i;
			for (int j = i + 1; j < length; j++)
			{
				if (pArr[j] < pArr[nMinIdx])
					nMinIdx = j;
			}
			if (nMinIdx != i)
				Swap(pArr, nMinIdx, i );

		}
		
	}

};