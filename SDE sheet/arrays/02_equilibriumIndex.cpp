
/*
Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array.
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Note: Retun the index of Equilibrium point. (1-based index)

Example 1:

Input:
n = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation: For second test case
equilibrium point is at position 3
as elements before it (1+3) =
elements after it (2+2).


*/

//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n)
    {

        // Your code here
        int i = 1;
        int j = n - 2;
        int sumL = a[0];
        int sumR = a[n - 1];
        if (n == 1)
        {
            return 1;
        }
        int ans = 0;
        bool flag = false;
        while (i < j)
        {
            if (sumL > sumR)
            {
                // cout<<"Left Big"<<endl;
                // cout<<sumL <<" "<<sumR <<endl;
                sumR += a[j];
                j--;
                // cout<<"New Left and Right are "<< sumL <<" and "<<sumR<<endl;
            }
            else
            {
                // cout<<"Right Big"<<endl;
                // cout<<sumL <<" "<<sumR <<endl;
                sumL += a[i];
                i++;
                // cout<<"New Left and Right are "<< sumL <<" and "<<sumR<<endl;
            }

            if (sumL == sumR and (i - j == 0))
            {
                // cout<<j <<" " <<i<<endl;
                // cout<<"Equal"<<endl;
                // cout<<sumL <<" "<<sumR <<endl;
                ans = (i + 1);
                // cout<<"ans "<<ans<<endl;
                flag = true;
            }
        }
        if (flag)
            return ans;
        else
            return -1;
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;

    // taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        // taking input n
        cin >> n;
        long long a[n];

        // adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        // calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends