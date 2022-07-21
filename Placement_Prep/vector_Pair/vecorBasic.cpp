#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(6);
    cout << "Via direct for loop vector is ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    vector<int>::iterator it;
    cout << "Via iterator vector is ";
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Via automatic vector is ";
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;

    v.pop_back();

    vector<int> v2(4, 50);
    swap(v, v2);
    cout << "After swap v becomes now ";
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << " and After swap v2 becomes now ";
    for (auto element : v2)
    {
        cout << element << " ";
    }

    sort(v2.begin(), v2.end());
    cout << "After sort v2 becomes now ";
    for (auto element : v2)
    {
        cout << element << " ";
    }
    return 0;
}