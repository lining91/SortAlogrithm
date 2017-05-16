//	二分插入排序算法的实现
#include <stdio.h>

class CBinInsertSort{
public:
	void Sort(int* pArr, int length)
	{
		if (pArr == NULL || length == 0)
			return;

		for (int i = 1; i < length; i++)
		{
			int nTemp = pArr[i];
			int nLeft = 0;
			int nRight = i - 1;
			
			while (nLeft <= nRight)
			{
				int nMiddle = (nLeft + nRight) / 2;
				if (pArr[nMiddle] > nTemp)
					nRight = nMiddle - 1;
				else
					nLeft = nMiddle + 1;
			}

			for (int j = i; j > nLeft; j--)
				pArr[j] = pArr[j - 1];

			if (nLeft != i)
				pArr[nLeft] = nTemp;
		}
	}

};