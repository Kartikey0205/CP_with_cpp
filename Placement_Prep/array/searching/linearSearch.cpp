#include <iostream>
using namespace std;
int linear_Search(int arr[], int size, int ele)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ele)
            return i;
    }
    return -1;
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
    int key;
    cout << "Enter the element you want to found" << endl;
    cin >> key;
    int res = linear_Search(arr, size, key);

    if (res != -1)
        cout << "Element found at index = " << res << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}