#include <string.h>
#include <stdio.h>
const int nMax = 100;


class CCountingSort{
public:
	void Sort(int* pArr, int length)
	{
		int* C = new int[nMax];
		if (C == NULL)
			return;

		memset(C, 0, nMax * sizeof(int));

		for (int i = 0; i < length; i++)
			C[pArr[i]]++;

		for (int i = 1; i< nMax; i++)
			C[i] = C[i] + C[i - 1];


		int* B = new int[length];
		if (B == NULL)
			return;

		for (int i = length - 1; i >= 0; i--)
		{
			int nTemp = pArr[i];
			B[C[nTemp] - 1] = nTemp;
			C[nTemp]--;
		}

		for (int i = 0; i < length; i++)
			pArr[i] = B[i];

		delete C;
		C = NULL;
		delete B;
		B = NULL;
	}

};