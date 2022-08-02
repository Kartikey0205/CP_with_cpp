#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
void removeDuplicate(int arr[], int size)
{
    set<int> s;
    for (int i = 0; i < size; i++)
        s.insert(arr[i]);

    cout << "After removing  duplicates from Array is ";
    for (auto i : s)
        cout << i << " ";
}
int main()
{
    int arr[16] = {23, 5, 89, 89, 242, 5, 5, 55, 5, 13, 13, 14, 67, 13, 13, 6};
    removeDuplicate(arr, 16);

    return 0;
}