
/*
//                                                  RECORD BREAKER
/* Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is Vi.
A day is record breaking if it satisfies both of the following conditions:
● The number of visitors on the day is strictly larger than the number ofvisitors on each of the previous days.
● Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
Note:- that the very first day could be a record breaking day!
Please help Isyana find out the number of record breaking days.
O(N)
First ele is record day
2 cases
    ith ele is max amongst all preveious AND ALSO it is maximum of its next coming value

*/
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of an array ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of an array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int recordDay = arr[0];
    int maxV = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxV && (arr[i] > arr[i + 1] && (i + 1) < size))
        {
            recordDay = arr[i];
            cout << "Record Breaking Day " << recordDay << endl;
        }
        maxV = max(maxV, arr[i]);
    }
    return 0;
}