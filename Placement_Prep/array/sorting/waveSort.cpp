// alternate elemnet are less than their neighbour

#include <iostream>
using namespace std;
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void wave_Sort(int arr[], int n)
{
    for (int i = 1; i < n; i = i + 2)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr, i, i - 1);
        }
        if (arr[i] > arr[i + 1] && i <= n - 2)
        {
            swap(arr, i, i + 1);
        }
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

    wave_Sort(arr, size);
    cout << "Array after sorting is " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}