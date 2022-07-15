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
    int currSum[size + 1];
    currSum[0] = 0;
    for (int i = 1; i <= size; i++)
    {
        currSum[i] = currSum[i - 1] + arr[i - 1];
    }
    int maxSum = INT_MIN;
    for (int i = 1; i <= size; i++)
    {
        int sum = 0;

        for (int j = 0; j < i; j++)
        {
            sum = currSum[i] - currSum[j];
            maxSum = max(maxSum, sum);
        }
    }
    cout << "Maximum sum of subarray is " << maxSum;
    return 0;
}