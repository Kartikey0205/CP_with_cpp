#include <iostream>
using namespace std;
int main()
{
    string str;
    cout << "Enter your String ";
    getline(cin, str);

    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i] - 'a']++;
    }

    char ans = 'a';
    int maxLen = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxLen)
        {
            maxLen = freq[i]; // it is first occuring cahrater in a sequence
            ans = i + 'a';
        }
    }
    cout << "Maximum frequency is " << maxLen << " of character " << ans;
    return 0;
}