/*
Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.



Example 1:

Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    void rev(vector<long long> &arr, int idx1, int idx2)
    {
        while (idx1 < idx2)
        {

            swap(arr[idx1], arr[idx2]);
            idx1++;
            idx2--;
        }
    }
    // Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long> &arr, int n, int k)
    {
        int grp = k;
        // code here
        int start = 0;

        while (start < n)
        {
            if (k >= n)
            {
                rev(arr, start, n - 1);
                start = n;
                k = n;
            }
            else
            {
                rev(arr, start, k - 1);

                start = start + grp;
                k = k + grp;
            }
        }

        // rev(arr , start , n-1);
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
        vector<long long> arr;
        int k;
        cin >> k;

        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);

        for (long long i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends