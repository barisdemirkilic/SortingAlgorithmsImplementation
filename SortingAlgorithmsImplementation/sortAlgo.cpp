#include <iostream>
#include <vector>

#include "sortAlgo.hpp"

using namespace std;

// Integer vector printer function
void PrintVector(vector<int>& arr)
{
	int arrLen = arr.size();
	for (int i = 0; i < arrLen; i++)
	{
		cout << arr[i];
		if (i < arrLen - 1)
			cout << " ";
	}
	cout << endl;
}

// Merge sort merge function
void barisMergeSortMerge(vector<int>& arr, int startIdx, int midIdx, int lastIdx)
{
	vector<int> lArr, rArr;
	int lArrLen = midIdx - startIdx + 1;
	int rArrLen = lastIdx - midIdx;
	for (int i = 0; i < lArrLen; i++)
		lArr.push_back(arr[startIdx + i]);
	for (int i = 0; i < rArrLen; i++)
		rArr.push_back(arr[midIdx + 1 + i]);
	int lArrIdx = 0, rArrIdx = 0, mainArrIdx = startIdx;
	while (true)
	{
		bool bRArrDone = rArrIdx >= rArrLen;
		bool bLArrDone = lArrIdx >= lArrLen;
		if (bRArrDone && bLArrDone)
			break;
		else if (bRArrDone)
			arr[mainArrIdx++] = lArr[lArrIdx++];
		else if (bLArrDone)
			arr[mainArrIdx++] = rArr[rArrIdx++];
		else
		{
			if (lArr[lArrIdx] > rArr[rArrIdx])
				arr[mainArrIdx++] = rArr[rArrIdx++];
			else
				arr[mainArrIdx++] = lArr[lArrIdx++];
		}
	}
}

// Recursive merge sort function
void barisMergeSortHelper(vector<int>& arr, int startIdx, int lastIdx)
{
	if (lastIdx <= startIdx)
		return;
	int midIdx = (startIdx + lastIdx) / 2;
	barisMergeSortHelper(arr, startIdx, midIdx);
	barisMergeSortHelper(arr, midIdx + 1, lastIdx);
	barisMergeSortMerge(arr, startIdx, midIdx, lastIdx);
}

// Main merge sort function
void barisMergeSort(vector<int>& arr)
{
	int arrLen = arr.size();
	barisMergeSortHelper(arr, 0, arrLen - 1);
}

// Recursive quick sort function
void barisQuickSortHelper(vector<int>& arr, int startIdx, int lastIdx)
{
	if (lastIdx <= startIdx)
		return;
	int pivotIdx = startIdx;
	int compIdx = lastIdx;
	bool pivotInLeft = true;
	int pivotVal = arr[pivotIdx];
	while (pivotIdx != compIdx)
	{
		int compVal = arr[compIdx];
		if ((pivotInLeft && (compVal < pivotVal)) || (!pivotInLeft && (compVal > pivotVal)))
		{
			swap(arr[pivotIdx], arr[compIdx]);
			int tmpCompIdx = compIdx;
			compIdx = pivotIdx;
			pivotIdx = tmpCompIdx;
			pivotInLeft = !pivotInLeft;
			pivotVal = arr[pivotIdx];
		}
		if (pivotInLeft)
			compIdx--;
		else
			compIdx++;
	}
	barisQuickSortHelper(arr, startIdx, pivotIdx - 1);
	barisQuickSortHelper(arr, pivotIdx + 1, lastIdx);
}

// Main quick sort function
void barisQuickSort(vector<int>& arr)
{
	int arrLen = arr.size();
	barisQuickSortHelper(arr, 0, arrLen - 1);
}

