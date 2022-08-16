/*
Given an array Arr (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output i.e you have to iterate on the original array only.

Example 1:

Input:
N = 7
Arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: 3 7 4 8 2 6 1
Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1

*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Program for zig-zag conversion of array
    void zigZag(int arr[], int n)
    {
        // code here
        string option = "big";
        int i = 0;
        int j = 1;
        if (n == 1)
        {
            return;
        }
        if (n == 2)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
            return;
        }
        // n > 3
        while (j < n)
        {
            if (option == "big")
            {
                if (arr[i] > arr[j])
                {
                    swap(arr[i], arr[j]);
                }
                option = "small";
            }
            else if (option == "small")
            {
                if (arr[i] < arr[j])
                {
                    swap(arr[i], arr[j]);
                }
                option = "big";
            }
            i++;
            j++;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
