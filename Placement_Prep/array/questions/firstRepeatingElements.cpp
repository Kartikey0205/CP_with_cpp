/*
tell the minimum index of first repeating element
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of an array ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of an array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    const int N = 1e6 + 2; // 10^6
    int idx[N];
    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }
    int minIdx = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (idx[arr[i]] != -1)
        {
            minIdx = min(idx[arr[i]], minIdx);
        }

        idx[arr[i]] = i;
    }
    if (minIdx == INT_MAX)
    {
        cout << "-1";
    }
    else
    {
        cout << minIdx + 1;
    }

    return 0;
}