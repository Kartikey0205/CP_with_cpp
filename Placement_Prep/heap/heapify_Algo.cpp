#include <iostream>
using namespace std;
void heapify(int arr[], int size, int i)
{
    int largestNode = i;
    int leftNode = 2 * i;
    int rightNode = 2 * i + 1;

    if (leftNode <= size && arr[largestNode] < arr[leftNode])
    {
        largestNode = leftNode;
    }
    if (rightNode <= size && arr[largestNode] < arr[rightNode])
    {
        largestNode = rightNode;
    }

    // check whether largest node got change or not
    if (largestNode != i)
    {
        swap(arr[largestNode], arr[i]);
        heapify(arr, size, largestNode);
    }
}
int main()
{
    int arr[7] = {-1, 10, 15, 21, 30, 18, 19};
    int n = 6;

    // No need to check leaf Node in a HEAPIFY ALGO AS it is always MAX leaf will be from n/2+1 to n
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Converted into MAX HEAP via HEAPIFY ALGORITHM " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}