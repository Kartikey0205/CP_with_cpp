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
    while (1)
    {
        if (ch[i] == ' ' || ch[i] == '\0')
        {
            if (currLen > maxLen)
                maxLen = currLen;
            currLen = 0;
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
    cout << "Maximum Length of word in a sentence is " << maxLen;
    return 0;
}