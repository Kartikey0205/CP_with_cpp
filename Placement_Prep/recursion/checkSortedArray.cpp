#include <iostream>
using namespace std;
bool sorted(int arr[], int n)
{
    if (n == 1)
    {
        return true;
    }
    bool ros = sorted(arr + 1, n - 1);
    return (arr[0] < arr[1] && ros);
}
int main()
{

    int arr[] = {1, 2, 3, 5, 67, 9};
    cout << sorted(arr, 6);
    return 0;
}