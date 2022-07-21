// time complexity - O(n log n) Best Case
//   T(n) = T(n-1) + n  O(n2)
#include <iostream>
using namespace std;
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int pivotIndex(int arr[], int l, int r)
{
    int pivot = arr[r];

    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}
void quick_Sort(int arr[], int l, int r)
{
    if (l < r)
    {

        int pivot = pivotIndex(arr, l, r);
        quick_Sort(arr, l, pivot - 1);
        quick_Sort(arr, pivot + 1, r);
    }
}
int main()
{
    int size;
    cout << "Enter array size" << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    quick_Sort(arr, 0, size - 1);
    cout << "Array after sorting is " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}