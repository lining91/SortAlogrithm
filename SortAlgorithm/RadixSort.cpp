#include <stdlib.h>

const int nMaxPos = 6;		//	本程序中的元素的最大位数


class RadixSort{
public:
	int GetNumIndex(int nNum, int nPos)
	{
		int nTemp = 1;
		for (int nIdx = 1; nIdx < nPos; nIdx++)
			nTemp *= 10;
		
		return (nNum / nTemp) % 10;
	}

	void Sort(int* pArr, int length)
	{
		int* C[10];
		for (int i = 0; i < 10; i++)
		{
			C[i] = (int*)malloc(sizeof(int) * (length + 1));
			C[i][0] = 0;	//	0为记录这个数组的个数
		}


		for (int nPos = 1; nPos <= nMaxPos; nPos++)		//	从第一位到最高位依次处理
		{
			for (int i = 0; i < length; i++)			//	分配到0-9号桶中
			{
				int nNum = GetNumIndex(pArr[i], nPos);
				int nIndex = ++C[nNum][0];
				C[nNum][nIndex] = pArr[i];
			}

			for (int i = 0, j = 0; i < 10; i++)			//	从0-9号桶收集
			{
				for (int k = 1; k <= C[i][0]; k++)
					pArr[j++] = C[i][k];

				C[i][0] = 0;							//	个数复位
			}
		}
	}

};