// Buble sort

#include <iostream>
using namespace std;
void swap(int *firstElement, int *secondElement)
{
    int temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

void buble_Sort(int myArray[], int sizeArray)
{
    int i, j;
    for (i = 0; i < sizeArray - 1; i++)
    {
        for (j = 0; j < sizeArray - i - 1; j++)
        {
            if (myArray[j] > myArray[j + 1])
            {
                swap(&myArray[j], &myArray[j + 1]);
            }
        }
    }
}
int main()
{
    int size, ele;
    cout << "Enter the total number of element of Array : " << endl;
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

    buble_Sort(arr, total_num_of_element);
    cout << "\n  Array after sort will be: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}