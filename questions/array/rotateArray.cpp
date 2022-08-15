/*
Given an unsorted array arr[] of size N. Rotate the array to the left (counter-clockwise direction) by D steps, where D is a positive integer.



Example 1:

Input:
N = 5, D = 2
arr[] = {1,2,3,4,5}
Output: 3 4 5 1 2
Explanation: 1 2 3 4 5  when rotated
by 2 elements, it becomes 3 4 5 1 2.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(int arr[], int d, int n)
    {
        // code here
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(arr[i]);
        }
        while (d != 0)
        {
            res.push_back(res.front());
            res.erase(res.begin());
            d--;
        }
        vector<int>::iterator it;
        int i = 0;
        for (it = res.begin(); it != res.end(); it++)
        {
            arr[i] = *it;
            i++;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cout << "Testcases" << endl;
    // taking testcases
    cin >> t;

    while (t--)
    {
        int n, d;
        cout << "n and d" << endl;
        // input n and d
        cin >> n >> d;

        int arr[n];
        cout << "insery ele" << endl;

        // inserting elements in the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d, n);

        // printing the elements of the array
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends