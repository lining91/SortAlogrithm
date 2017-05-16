//	插入排序算法的实现
#include <stdio.h>

class CInsertSort{
public:
	void Sort(int* pArr, int length)
	{
		if (pArr == NULL || length == 0)
			return;

		for (int i = 1; i < length; i++)
		{
			int temp = pArr[i];
			int j = i;
			while(j >= 1 && pArr[j - 1] > temp)
			{
				pArr[j] = pArr[j - 1];
				j--;
			}
			pArr[j] = temp;
		}
	}
};