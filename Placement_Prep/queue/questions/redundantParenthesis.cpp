#include <bits/stdc++.h>
using namespace std;
int main()
{

    string str;
    // ((a+b))
    getline(cin, str);
    stack<char> s;

    bool ans = false;
    for (int i = 0; i < str.length(); i++)
    {
        // we can skip opearnd part
        // operator
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            s.push(str[i]);
        }
        // when there is a open braces
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        // when there is close braces
        if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                ans = true;
            }
            while (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
            {
                s.pop();
            }
            s.pop();
        }
    }
    if (ans)
        cout << "Reduntant Parenthesis";
    else
        cout << "Not a Reduntant Parenthesis";

    return 0;
}