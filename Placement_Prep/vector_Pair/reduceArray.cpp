// i/p - 10 , 16 , 7 ,14 ,5 ,3 ,12 , 9

// o/p -  4, 7,2 ,6,1, 0,5, 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
int main()
{
    int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};
    vector<pair<int, int>> v;

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        v.push_back(make_pair(arr[i], i));
    }

    // sort on based of their value
    sort(v.begin(), v.end(), myCompare);

    // Now updating array according to second paareter of vector
    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].second] = i;
    }

    cout << "Final " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}