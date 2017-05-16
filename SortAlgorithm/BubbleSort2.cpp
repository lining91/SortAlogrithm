//	改进的冒泡排序算法的实现
#include <stdio.h>

class CBubbleSort_new{
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

		int begin = 0;
		int end = length - 1;
		
		while(begin < end)
		{
			//	将最大的元素放到后面
			for (int i = begin; i < end; i++)
			{
				if (pArr[i] > pArr[i + 1])
					Swap(pArr, i, i + 1);
			}
			end--;

			//	将最小的元素放到前面
			for (int i = end; i > begin; i--)
			{
				if (pArr[i] < pArr[i - 1])
					Swap(pArr, i, i - 1);
			}
			begin++;
		}
	}
};