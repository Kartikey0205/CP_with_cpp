#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int> a)
{
    int n = a.size(), ans = 0;
    stack<int> st; // storing index
    for (int i = 0; i < n; i++)
    {
        // stack not empty
        while (!st.empty() and a[st.top()] < a[i])
        {
            int curr = st.top(); // top value as a index

            st.pop();
            if (st.empty())
                break;
            else
            {
                int width = i - st.top() - 1;
                ans += (min(a[st.top()], a[i]) - a[curr]) * width; // a[st.top()] = left wall
                // a[i]= right wall
            }
        }

        // stack empty
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Water stored between the boundary is  :  " << largestRectangle(a) << " units";
    return 0;
}