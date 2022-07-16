#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of an array ";
    cin >> size;

    char ch[size + 1];
    cout << "Enter the char elements of an array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> ch[i];
    }
    int j = size - 1;
    int i = 0;

    while (i != j)
    {
        if (ch[i] == ch[j])
        {
            i++;
            j--;
        }
        else
        {
            cout << "Our WORD  is not paloindrome";
            return 0;
        }
    }
    cout << "Our WORD is Palindrome";
    return 0;
}