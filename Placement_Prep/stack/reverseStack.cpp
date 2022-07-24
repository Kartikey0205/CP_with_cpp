#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int topEle = st.top();
    // cout << "ele  = " << ele << endl;
    // cout << "Topele  = " << topEle << endl;

    st.pop();
    insertAtBottom(st, ele);
    st.push(topEle);
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    // cout << "ele  = " << ele << endl;
    st.pop();
    reverseStack(st);
    insertAtBottom(st, ele);
}
int main()
{
    stack<int> st;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        st.push(arr[i]);
    }

    reverseStack(st);
    cout << "After reversing " << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}