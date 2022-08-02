#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;
void reverseArr(int arr[], int size)
{
    stack<int> s;
    for (int i = 0; i < 5; i++)
        s.push(arr[i]);

    cout << "Reverses of Array is ";
    for (int i = 0; i < 5; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
}
int main()
{
    int arr[5] = {23, 5, 89, 13, 6};
    reverseArr(arr, 5);
    cout << endl;
    set<int> s;
    for (int i = 0; i < 5; i++)
    {
        s.insert(arr[i]);
    }
    for (auto i = s.rbegin(); i != s.rend(); i++)
        cout << *i << " ";
    cout << endl;
    // reverse(arr, arr + 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}