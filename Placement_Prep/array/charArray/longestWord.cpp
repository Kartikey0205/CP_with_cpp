#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of an array ";
    cin >> size;
    cin.ignore();
    char ch[size + 1];
    cout << "Enter the char elements of an array" << endl;
    cin.getline(ch, size);
    cin.ignore();
    int currLen = 0, maxLen = 0;
    int i = 0;
    int st = 0, maxSt = 0;
    while (1)
    {
        if (ch[i] == ' ' || ch[i] == '\0')
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
                maxSt = st;
            }

            currLen = 0;
            st = i + 1;
        }
        else
        {
            currLen++;
        }

        if (ch[i] == '\0')
        {
            break;
        }
        i++;
    }

    for (int i = 0; i < maxLen; i++)
    {
        cout << ch[i + maxSt];
    }

    return 0;
}