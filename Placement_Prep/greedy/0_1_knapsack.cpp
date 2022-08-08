#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vii vector<pii>

int main()
{
    cout << "Enter total number of Items " << endl;
    int item;
    cin >> item;

    cout << "Enter total weight " << endl;
    int weight;
    cin >> weight;

    vii a(item);

    // first == value
    // secnd == weight
    for (int i = 0; i < item; i++)
    {
        cout << "Enter values and weight for " << i + 1 << " Item " << endl;

        cin >> a[i].first >> a[i].second;
    }

    // sorting acc value/weight;
    sort(a.begin(), a.end(), [&](pii p1, pii p2)
         {
        double v1 = (double)p1.first/p1.second;
        double v2 = (double)p2.first / p2.second;
        return v1>v2; });

    int ans = 0;

    for (int i = 0; i < item; i++)
    {
        if (weight >= a[i].second) // capacity whi lenge jb jada ho current value per weight se toh y toh equal ho
        {
            ans += a[i].first;
            weight -= a[i].second;
        }
    }

    cout << "Maximum value " << ans << endl;
    return 0;
}