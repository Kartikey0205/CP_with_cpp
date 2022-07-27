#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size = 9;
    int window = 3;
    vector<int> a(size); // 1 , 3 ,-1 , -3, 5 ,3 ,4 , 6, 7   --->  Ans = 3 3 5 5 5 6 7
    for (auto &i : a)
    {
        cin >> i;
    }

    // O(1 * N);
    deque<int> dq;
    vector<int> ans;
    // O(1)
    for (int i = 0; i < window; i++)
    {
        while (!dq.empty() && dq.back() < a[i])
        {
            dq.pop_back();
        }

        dq.push_back(a[i]);
    }
    ans.push_back(dq.front());

    // O(N)
    for (int i = window; i < size; i++)
    {
        if (dq.front() == a[i - window])
        {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back() < a[i])
        {
            dq.pop_back();
        }

        dq.push_back(a[i]);

        ans.push_back(dq.front());
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}