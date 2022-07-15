/*
Arithmatic Array acc. to que - minimum 2 integers in an array and consecutive difference is same
*/

#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of an array ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of an array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int dif = arr[1] - arr[0];
    int cur = 2;
    int maxLen = 2;
    for (int i = 2; i < size; i++)
    {
        if (arr[i] - arr[i - 1] == dif)
        {
            cur++;
        }
        else
        {
            dif = arr[i] - arr[i - 1];
            cur = 2;
        }
        maxLen = max(maxLen, cur);
    }
    cout << "Maximum length of Artithmatic subarray is " << maxLen;
    return 0;
}