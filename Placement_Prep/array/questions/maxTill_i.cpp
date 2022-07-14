#include <iostream>
using namespace std;
int main()
{

    int size;
    cout << "Enter the size of Array ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int maxNu = arr[0];
    for (int i = 0; i < size; i++)
    {
        maxNu = max(arr[i], maxNu);
        cout << "Till " << i + 1 << " position max value in array is " << maxNu << endl;
    }

    return 0;
}