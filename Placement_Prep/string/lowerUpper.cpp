#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    cout << "Enter your String ";
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32; // 'a' - 'A' = 32
        }
    }
    cout << "Capitalize String is " << str;
    cout << endl;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32; // 'a' - 'A' = 32
        }
    }
    cout << "Lowercase String is " << str;

    return 0;
}