#include <bits/stdc++.h>
using namespace std;
int binary_Search(int arr[], int size, int ele)
{
    int lb = 0, ub = size, pos = 0;

    while (lb <= ub)
    {
        int mid = (lb + ub) / 2;

        if (arr[mid] > ele)
        {
            ub = mid - 1;
        }
        else if (arr[mid] < ele)
        {
            lb = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    int size;
    cout << "Enter sorted array size" << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the element you want to found" << endl;
    cin >> key;
    // sort(arr, arr + size);
    int res = binary_Search(arr, size, key);

    if (res != -1)
        cout << "Element found at index = " << res << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}