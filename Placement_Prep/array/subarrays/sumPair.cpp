#include <iostream>
using namespace std;
bool pairSum(int arr[], int size, int k)
{
    int low = 0;
    int high = size - 1;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[low] + arr[high] == k)
        {
            cout << low << " and " << high << endl;
            return true;
        }
        else if (arr[low] + arr[high] < k)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return false;
}
int main()
{
    int size = 8;
    int arr[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int k = 31;

    cout << pairSum(arr, size, k);

    return 0;
}