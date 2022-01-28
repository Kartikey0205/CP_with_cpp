// Linear Search

#include <iostream>
using namespace std;

int lin_Search(int myArr[], int length, int Element)
{
    for (int i = 0; i < length; i++)
    {
        if (myArr[i] == Element)
        {
            return i;
            // cout << "Index number of " << Element << " will be " << i << endl;
        }
    }
    return -1;
}
int main()
{
    int size, ele;
    cout << "Enter the total number of Array : " << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the values of array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "\n  Values of Array will be: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    int total_num_of_element = sizeof(arr) / sizeof(arr[2]);
    cout << "\n Enter the element to search:  " << endl;
    cin >> ele;
    int indexNumber = lin_Search(arr, size, ele);

    if (indexNumber == -1)
    {
        cout << "Value is not present in Array " << endl;
    }
    else
    {
        cout << "Index number of " << ele << " will be " << indexNumber << endl;
    }
    return 0;
}