#include <iostream>
using namespace std;
int first_occ(int arr[], int n, int i, int key)

{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return first_occ(arr, n, i + 1, key);
}
int last_occ(int arr[], int n, int i, int key)

{
    if (i == n)
    {
        return -1;
    }
    int ros = last_occ(arr, n, i + 1, key);
    if (ros != -1)
    {
        return ros;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}
int main()
{
    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    int key = 2;
    cout << first_occ(arr, 7, 0, key) << endl;
    cout << last_occ(arr, 7, 0, key) << endl;

    return 0;
}