// time complexity - O(n log n)    T(n) = 2T(n/2) + n
#include <iostream>
using namespace std;
void joinMergeSort(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    // when i finishes first and j remains add j element direct becaus ethey are sorted
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }

    // when j finishes first and i remains add i element direct becaus ethey are sorted
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
}
void merge_Sort(int arr[], int l, int r)
{
    if (l < r)
    {

        int mid = (l + r) / 2;
        merge_Sort(arr, l, mid);
        merge_Sort(arr, mid + 1, r);

        joinMergeSort(arr, l, mid, r);
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

    merge_Sort(arr, 0, size - 1);
    cout << "Array after sorting is " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}