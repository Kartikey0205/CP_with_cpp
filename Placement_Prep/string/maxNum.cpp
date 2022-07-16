#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    cout << "Enter your numeric String ";
    getline(cin, str);

    sort(str.begin(), str.end(), greater<int>());
    cout << str;
    return 0;
}