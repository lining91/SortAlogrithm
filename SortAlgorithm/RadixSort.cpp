#include <stdlib.h>

const int nMaxPos = 6;		//	�������е�Ԫ�ص����λ��


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
			C[i][0] = 0;	//	0Ϊ��¼�������ĸ���
		}


		for (int nPos = 1; nPos <= nMaxPos; nPos++)		//	�ӵ�һλ�����λ���δ���
		{
			for (int i = 0; i < length; i++)			//	���䵽0-9��Ͱ��
			{
				int nNum = GetNumIndex(pArr[i], nPos);
				int nIndex = ++C[nNum][0];
				C[nNum][nIndex] = pArr[i];
			}

			for (int i = 0, j = 0; i < 10; i++)			//	��0-9��Ͱ�ռ�
			{
				for (int k = 1; k <= C[i][0]; k++)
					pArr[j++] = C[i][k];

				C[i][0] = 0;							//	������λ
			}
		}
	}

};