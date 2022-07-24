#include <bits/stdc++.h>

using namespace std;
bool isValid(string s)
{
    bool ans = true;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        // open braces
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        // closed barces
        else if (s[i] == ')')
        {
            if (!st.empty() and st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() and st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() and st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }

    // stack empty or not
    if (!st.empty())
    {
        ans = false;
    }
    return ans;
}
int main()
{
    string s = "({[])}";
    if (isValid(s))
        cout << "Valid string " << endl;
    else
        cout << "Invalid string " << endl;
    return 0;
}