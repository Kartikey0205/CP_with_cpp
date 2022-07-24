#include <bits/stdc++.h>
using namespace std;
class Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }

    void push(int x)
    {
        q2.push(x);
        N++; // stack size increases
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        q1.pop();
        N--;
    }

    int top()
    {
        return q1.front();
    }

    int size()
    {
        return N;
    }
};
int main()
{
    Stack st;
    st.push(21);
    st.push(557);
    st.push(68);
    st.push(61);
    st.push(291);
    st.push(219);
    st.push(121);
    st.push(981);
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    return 0;
}