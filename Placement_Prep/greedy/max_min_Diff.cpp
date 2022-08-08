// Divide aaray in n/2 part and then find max min diif in both

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    long long minimum = 0, maximum = 0;

    for (int i = 0; i < n / 2; i++)
    {
        maximum += (a[i + n / 2] - a[i]);
        minimum += (a[(2 * i) + 1] - a[2 * i]);
    }

    cout << minimum << " " << maximum << endl;
    return 0;
}