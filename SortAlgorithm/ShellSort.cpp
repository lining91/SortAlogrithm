//	希尔排序算法的实现
#include <stdio.h>

class CShellSort{
public:
	void Sort(int* pArr, int length)
	{
		if (pArr == NULL || length == 0)
			return;

		int nInterval = 0;
		while (nInterval < length)
		{
			nInterval = nInterval * 3 + 1;
		}

		while (nInterval >= 1)
		{
			for (int i = 0; i < length; i++)
			{
				int j = i - nInterval;
				int nTemp = pArr[i];
				while ( j >= 0 && pArr[j] > nTemp)
				{
					pArr[j + nInterval] = pArr[j];
					j = j - nInterval;
				}
				pArr[j + nInterval] = nTemp;
			}
			nInterval = (nInterval - 1) / 3;
		}

	}
};