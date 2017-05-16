//	�Ľ���ð�������㷨��ʵ��
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
			//	������Ԫ�طŵ�����
			for (int i = begin; i < end; i++)
			{
				if (pArr[i] > pArr[i + 1])
					Swap(pArr, i, i + 1);
			}
			end--;

			//	����С��Ԫ�طŵ�ǰ��
			for (int i = end; i > begin; i--)
			{
				if (pArr[i] < pArr[i - 1])
					Swap(pArr, i, i - 1);
			}
			begin++;
		}
	}
};