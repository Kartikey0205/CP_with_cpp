
/*
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

In case of multiple subarrays, return the subarray which comes first on moving from left to right.



Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements
from 2nd position to 4th position
is 12.


Example 2:

Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements
from 1st position to 5th position
is 15.


Your Task:
You don't need to read input or print anything. The task is to complete the function subarraySum() which takes arr, N and S as input parameters and returns an arraylist containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. The two indexes in the array should be according to 1-based indexing. If no such subarray is found, return an array consisting only one element that is -1.



Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)



Constraints:
1 <= N <= 105
1 <= Ai <= 109
135 101 170 125 79 159 163 65 106 146 82 28 162 92 196 143 28 37 192 5 103 154 93 183 22 117 119 96 48 127 172 139 70 113 68 100 36 95 104 12 123 134
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int> res;
        long long currSum = 0;
        for (int i = 0; i < n; i++)
        {
            // cout << "i = " << i;
            if (currSum == s)
            {
                break;
            }
            // cout << "sum =" << currSum << endl;

            if (currSum < s)
            {
                res.push_back(i);
                currSum += arr[i];
                // cout << "Less than equal to i = " << i << endl;
            }
            else
            {
                currSum -= arr[res.front()];
                // cout << res.front() << "begin" << endl;
                res.erase(res.begin());
                if (currSum == s)
                {
                    res.push_back(i);
                    break;
                }
                // cout << "greater than equal to i = " << i << endl;
                res.push_back(i);
                currSum += arr[i];
                // cout << "Greater than curr SUm= " << currSum << endl;
            }
        }
        // cout << res.front() << "front" << endl;
        int st = res.front() + 1;
        int last = res.back() + 1;
        res.erase(res.begin(), res.end());
        res.push_back(st);
        res.push_back(last);
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int n;
    long long s;
    cin >> n >> s;
    int arr[n];
    const int mx = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution ob;
    vector<int> res;
    res = ob.subarraySum(arr, n, s);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    // }
    return 0;
}
// } Driver Code Ends