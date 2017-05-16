//	堆排序算法的实现，使用最大堆来做辅助
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
			Swap(pArr, 0, i);		//	将堆顶元素与最后一个元素互换，保证最大值在后面
			HeapAdjust(pArr, 0, i - 1);	//	从堆顶进行堆调整
		}
	}

	//	建堆函数，对每一个非叶子节点进行堆调整
	void BuildHeap(int* pArr, int nSize)
	{
		for (int i = nSize / 2; i >= 0; i--)
			HeapAdjust(pArr, i, nSize);
	}

	//	堆调整函数（使用最大堆）
	void HeapAdjust(int* pArr, int nIdx, int nSize)
	{
		int nLChild = 2 * nIdx;
		int nRChild = 2 * nIdx + 1;
		int nMax = nIdx;

		if (nIdx > nSize / 2)
			return;

		//	选出当前结点与左右子结点中的最大值
		if (nLChild <= nSize && pArr[nLChild] > pArr[nMax])
			nMax = nLChild;

		if (nRChild <= nSize && pArr[nRChild] > pArr[nMax])
			nMax = nRChild;

		if (nMax == nIdx)
			return;

		Swap(pArr, nIdx, nMax);	//	当前结点和最大子结点交换
		HeapAdjust(pArr, nMax, nSize);		//	从当前结点向下递归进行堆调整
	}
};
