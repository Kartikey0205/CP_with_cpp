#include <bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int> a)
{
    int n = a.size(), ans = 0, i = 0;
    stack<int> st; // storing index
    a.push_back(0);

    while (i < n)
    {
        // stack not empty
        while (!st.empty() and a[st.top()] > a[i])
        {
            int t = st.top(); // top value as a index
            int height = a[t];

            st.pop();
            if (st.empty())
                ans = max(ans, height * i);
            else
            {
                int width = i - st.top() - 1;
                ans = max(ans, height * width);
            }
        }

        // stack empty
        st.push(i);
        i++;
    }
    return ans;
}
int main()
{
    vector<int> a = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle in given Histogram :  " << largestRectangle(a);
    return 0;
}