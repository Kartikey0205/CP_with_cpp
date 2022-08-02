#include <iostream>
#include <set>
using namespace std;
int main()
{
    int arr[5] = {23, 5, 89, 13, 6};
    cout << endl;
    set<int> s;
    for (int i = 0; i < 5; i++)
    {
        s.insert(arr[i]);
    }
    cout << "SORT " << endl;
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;
    return 0;
}