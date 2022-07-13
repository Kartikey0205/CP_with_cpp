#include <iostream>
#include <climits>
using namespace std;
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

    int maxNo = INT_MIN;
    int minNo = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        maxNo = max(maxNo, arr[i]);
        minNo = min(minNo, arr[i]);
    }

    cout << "Max = " << maxNo << " & Min = " << minNo;
    return 0;
}