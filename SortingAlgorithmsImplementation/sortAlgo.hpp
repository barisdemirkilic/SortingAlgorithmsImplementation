#pragma once

// Integer vector printer function
void PrintVector(std::vector<int>& arr);

// Merge sort merge function
void barisMergeSortMerge(std::vector<int>& arr, int startIdx, int midIdx, int lastIdx);

// Recursive merge sort function
void barisMergeSortHelper(std::vector<int>& arr, int startIdx, int lastIdx);

// Main merge sort function
void barisMergeSort(std::vector<int>& arr);

// Recursive quick sort function
void barisQuickSortHelper(std::vector<int>& arr, int startIdx, int lastIdx);

// Main quick sort function
void barisQuickSort(std::vector<int>& arr);