#include <iostream>
using namespace std;
string remDuplicate(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ros = s.substr(1);
    string ans = remDuplicate(ros);
    if (ch == ans[0])
    {
        return ans;
    }
    else
    {
        return ch + ans;
    }
}
int main()
{
    string s = " aaaaaaaabbbbbbbbeeeeeeeedddddddddcccccc";
    cout << remDuplicate(s);
    return 0;
}