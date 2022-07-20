#include <iostream>
using namespace std;
void subStrString(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);
    subStrString(ros, ans);
    subStrString(ros, ans + ch);
}
int main()
{
    string s = "ABC";
    subStrString(s, "");
    return 0;
}