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
    int code = ch;
    string ros = s.substr(1);
    subStrString(ros, ans);
    subStrString(ros, ans + ch);
    subStrString(ros, ans + to_string(code));
}
int main()
{
    string s = "ABC";
    subStrString(s, "");
    return 0;
}