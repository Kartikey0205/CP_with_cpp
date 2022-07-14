#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;

    for (int i = 0; i < size; i++)
    {

        for (int j = i; j < size; j++)
        {
            sum = sum + arr[j];
        }
    }
    cout << "Sum of total subarrays possible will be " << sum;

    return 0;
}