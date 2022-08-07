#include <bits/stdc++.h>
using namespace std;
int main()
{

    cout << "Enter Size ";

    int size;
    cin >> size;
    vector<int> arr(size);
    cout << "Enter Array Element ";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter Value ";
    int value;
    cin >> value;

    sort(arr.begin(), arr.end(), greater<int>());

    int coins = 0;
    for (int i = 0; i < size; i++)
    {
        coins += value / arr[i];
        value -= value / arr[i] * arr[i];
    }

    cout << coins << endl;

    return 0;
}