#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(23);
    v.push_back(12);
    v.push_back(28);
    v.push_back(4);
    v.push_back(8);

    // Binary Search
    cout << "Finding 28 -> " << binary_search(v.begin(), v.end(), 28) << endl;
    // Lower Bound
    cout << "Lower Bound-> " << lower_bound(v.begin(), v.end(), 28) - v.begin() << endl;
    // Upper Bound
    cout << "Upper Bound-> " << upper_bound(v.begin(), v.end(), 99) - v.begin() << endl;
    // Max
    int a = 3, b = 7;
    cout << "Before swap value of a is " << a << endl;
    cout << "Before swap value of b is " << b << endl;
    cout << "Max value is " << max(a, b) << endl;
    // Min
    cout << "Min value is " << min(a, b) << endl;

    // Swap

    swap(a, b);
    cout << "After swap value of a is " << a << endl;
    cout << "After swap value of b is " << b << endl;

    // reverse
    string ab = "Abcdef";
    reverse(ab.begin(), ab.end());
    cout << "After reverse string ab is " << ab << endl;

    cout << " Initial Vector is " << endl;

    for (int i : v)
    {
        cout << i << " ";
    }
    // rotate
    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "\nAfter rotate vector is " << endl;

    for (int i : v)
    {
        cout << i << " ";
    }
    // sort
    cout << "\nAfter sorting vector is " << endl;
    sort(v.begin(), v.end());
    for (int i : v)
    {
        cout << i << " ";
    }
    return 0;
}