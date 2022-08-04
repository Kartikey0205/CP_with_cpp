#include <bits/stdc++.h>

#define vi vector<int>
#define iterate(i, a, b) for (int i = a; i < b; i++)
using namespace std;
signed main()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    iterate(i, 0, n)
    {
        cin >> a[i];
    }

    // Max Heap
    priority_queue<int, vi> pq;
    iterate(i, 0, n)
    {
        pq.push(a[i]);
    }

    int sum = 0, count = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
        count++;

        if (sum >= k)
            break;
    }

    if (sum < k)
        cout << "-1" << endl;
    else
        cout << count << endl;
    return 0;
}