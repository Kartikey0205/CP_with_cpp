/*
Find subarray which leads to sum S
S = 5
Array = [1,2,3,7,5]
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
    int sum;
    cout << "Enter the sum you want ";
    cin >> sum;
    int st = -1, en = -1, currSum = 0;
    int i = 0, j = 0;
    // first directly finding sum
    while (j < size && currSum + arr[j] <= sum)
    {

        currSum = currSum + arr[j];
        j++;
    }

    if (currSum == sum)
    {
        cout << i + 1 << " and " << j << endl;
        return 0;
    }

    while (j < size)
    {
        currSum = currSum + arr[j];
        while (currSum > sum)
        {
            currSum = currSum - arr[i];
            i++;
        }
        if (currSum == sum)
        {
            st = i + 1;
            en = j + 1;
            break;
        }
        j++;
    }
    cout << st << " and " << en << endl;

    return 0;
}