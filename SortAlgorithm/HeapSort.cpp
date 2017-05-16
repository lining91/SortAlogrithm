//	�������㷨��ʵ�֣�ʹ��������������
#include <stdio.h>

class CHeapSort{
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

		BuildHeap(pArr, length);
		for (int i = length - 1; i >= 1; i--)
		{
			Swap(pArr, 0, i);		//	���Ѷ�Ԫ�������һ��Ԫ�ػ�������֤���ֵ�ں���
			HeapAdjust(pArr, 0, i - 1);	//	�ӶѶ����жѵ���
		}
	}

	//	���Ѻ�������ÿһ����Ҷ�ӽڵ���жѵ���
	void BuildHeap(int* pArr, int nSize)
	{
		for (int i = nSize / 2; i >= 0; i--)
			HeapAdjust(pArr, i, nSize);
	}

	//	�ѵ���������ʹ�����ѣ�
	void HeapAdjust(int* pArr, int nIdx, int nSize)
	{
		int nLChild = 2 * nIdx;
		int nRChild = 2 * nIdx + 1;
		int nMax = nIdx;

		if (nIdx > nSize / 2)
			return;

		//	ѡ����ǰ����������ӽ���е����ֵ
		if (nLChild <= nSize && pArr[nLChild] > pArr[nMax])
			nMax = nLChild;

		if (nRChild <= nSize && pArr[nRChild] > pArr[nMax])
			nMax = nRChild;

		if (nMax == nIdx)
			return;

		Swap(pArr, nIdx, nMax);	//	��ǰ��������ӽ�㽻��
		HeapAdjust(pArr, nMax, nSize);		//	�ӵ�ǰ������µݹ���жѵ���
	}
};
