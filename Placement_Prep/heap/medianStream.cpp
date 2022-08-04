#include <bits/stdc++.h>

using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define repeat(i, a, b) for (int i = a; i < b; i++)
priority_queue<int, vi> pqmax;
priority_queue<int, vi, greater<int>> pqmin;
double findMedian()
{
    // Both size equal
    if (pqmax.size() == pqmin.size())
    {
        return (pqmax.top() + pqmin.top()) / 2.0;
    }
    // Both size unequal
    else if (pqmax.size() > pqmin.size())
    {
        return pqmax.top();
    }
    else
    {
        return pqmin.top();
    }
}

void insert(int val)
{
    // Both size equal
    if (pqmax.size() == pqmin.size())
    {
        // size =  0 that means first element
        if (pqmax.size() == 0)
        {
            pqmax.push(val);
            return;
        }
        // val is less than max top value
        if (val < pqmax.top())
        {
            pqmax.push(val);
        }
        else
        {
            pqmin.push(val);
        }
    }
    // Both size unequal
    else
    {
        // pqmax is greater
        if (pqmax.size() > pqmin.size())
        {
            if (val >= pqmax.top())
            {
                pqmin.push(val);
            }
            else
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(val);
            }
        }
        // pqmin is greater
        if (pqmin.size() > pqmax.size())
        {
            if (val <= pqmax.top())
            {
                pqmax.push(val);
            }
            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(val);
            }
        }
    }
}
signed main()
{
    insert(10);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    insert(21);
    cout << findMedian() << endl;
    insert(30);
    cout << findMedian() << endl;
    insert(18);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;

    return 0;
}