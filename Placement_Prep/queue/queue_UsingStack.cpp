#include <bits/stdc++.h>
using namespace std;

class que
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s1.empty() and s2.empty())
        {
            cout << "queue is empty ";
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topVal = s2.top();
        s2.pop();
        return topVal;
    }
};
int main()
{
    que q;
    cout << q.pop();
    q.push(13);
    q.push(73);
    q.push(33);
    q.push(173);
    q.push(138);
    cout << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}