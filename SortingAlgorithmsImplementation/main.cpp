#include <iostream>
#include <vector>

#include "sortAlgo.hpp"

using namespace std;

// Some example unsorted arrays (vectors)
//vector<int> arr = { 3, 0, 1, 8, 7, 2, 5, 4, 9, 6 };
//vector<int> arr = { 1, 3, 6, 4, 1, 2 };
//vector<int> arr = { 4, 2, 8, 6, 0, 5, 1, 7, 3, 9};
vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 };

int main()
{
    // Print the vector before the sorting
    PrintVector(arr);

    // Uncomment the wanted sort algorithm
    barisQuickSort(arr);
    //barisMergeSort(arr);

    // Print the vector after the sorting
    PrintVector(arr);

    // Wait for a key to exit
    system("pause");
}
