//	冒泡排序算法的实现
#include <stdio.h>

class CBubbleSort{
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

		int nIndex = 0;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length - i - 1; j ++)
			{
				if (pArr[j] > pArr[j + 1])
					Swap(pArr, j, j+1);
			}

		}
		return;
	}
};
