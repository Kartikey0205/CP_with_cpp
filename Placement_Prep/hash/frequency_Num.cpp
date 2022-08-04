#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    // map<int, int>::iterator it;
    for (auto i = freq.begin(); i != freq.end(); i++)
    {
        cout << i->first << " is " << i->second << " times in an array " << endl;
    }
    return 0;
}