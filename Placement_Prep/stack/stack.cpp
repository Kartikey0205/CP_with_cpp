#include <iostream>
using namespace std;

#define N 100
// stack
class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[N];
        top = -1;
    }

    // Push Method
    void push(int ele)
    {
        if (top == N - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = ele;
    }
    // Pop Method
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    // Top Method
    int Top()
    {
        if (top == -1)
        {
            cout << "No element in the Stack" << endl;
            return -1;
        }
        return arr[top];
        top--;
    }
    // Empty Method
    bool empty()
    {
        return top == -1;
    }
    // display method
    void display(Stack st)
    {
        while (!st.empty())
        {
            cout << st.Top() << " ";
            st.pop();
            top--;
        }
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(12);
    st.push(41);
    st.pop();
    st.push(98);
    st.push(100);
    st.display(st);

    return 0;
}