/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.


Example 1:

Input:
n = 4, arr1[] = [1 3 5 7]
m = 5, arr2[] = [0 2 6 8 9]
Output:
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two
non-decreasing arrays, we get,
0 1 2 3 5 6 7 8 9.
Example 2:

Input:
n = 2, arr1[] = [10, 12]
m = 3, arr2[] = [5 18 20]
Output:
arr1[] = [5 10]
arr2[] = [12 18 20]
Explanation:
After merging two sorted arrays
we get 5 10 12 18 20.

Your Task:
You don't need to read input or print anything. You only need to complete the function merge() that takes arr1, arr2, n and m as input parameters and modifies them in-place so that they look like the sorted merged array when concatenated.


Expected Time Complexity:  O((n+m) log(n+m))
Expected Auxilliary Space: O(1)


Constraints:
1 <= n, m <= 5*104
0 <= arr1i, arr2i <= 107

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        // code here
        int i = 0, j = 0, arr[n + m], k = 0;
        while (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
            {
                arr[k] = arr1[i];
                i++;
            }
            else
            {
                arr[k] = arr2[j];
                j++;
            }
            k++;
        }
        while (i < n)
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        while (j < m)
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
        // cout<<n+m<<endl;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            arr1[i] = arr[index];
            index++;
        }
        for (int j = 0; j < m; j++)
        {
            arr2[j] = arr[index];
            index++;
        }
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends