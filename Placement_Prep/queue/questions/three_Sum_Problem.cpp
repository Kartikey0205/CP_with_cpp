#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cout << "Enter size ";
    cin >> size;
    cout << "Enter target ";
    int target;
    cin >> target;
    cout << "Enter array ";
    vector<int> a(size);
    for (auto &i : a)
        cin >> i;

    bool found = false;

    sort(a.begin(), a.end());
    for (int i = 0; i < size; i++)
    {
        int low = i + 1;
        int high = size - 1;
        while (low < high)
        {
            int current = a[i] + a[low] + a[high];
            if (current == target)
                found = true;
            if (current < target)
                low++;
            else
                high--;
        }
    }
    if (found)
        cout << "True";
    else
        cout << "False";
    return 0;
}