/*
Array = {1 , 4 , 5 , 6 , 7}
Extra = 5
false true true true true
*/
#include <iostream>
#include <climits>
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
    int extraCandies;
    cout << "Enter extra Candies ";
    cin >> extraCandies;
    int maxCan = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        maxCan = max(maxCan, arr[i]);
    }

    int bolArr[size];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] + extraCandies >= maxCan)
            bolArr[i] = 1;
        else
            bolArr[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        cout << bolArr[i] << " ";
    }
    return 0;
}