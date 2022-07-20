#include <iostream>
using namespace std;
string moveX(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ros = s.substr(1);
    string ans = moveX(ros);
    if (ch == 'x')
    {
        return ans + ch;
    }
    else
    {
        return ch + ans;
    }
}
int main()
{
    string s = " aaaaxxxxxxxxaaaabbxxbbbbbbexxxxxddddddddxxcccccc";
    cout << moveX(s);
    return 0;
}