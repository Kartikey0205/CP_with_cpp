// Chineese Remainder Theorem
/*
Suppose we have 2 array -
int arr1 = [ x1 , x2 , x3 , ....]
int arr2 = [ y1 , y2 , y3 , ....]
 Now CRT says that
 we have to find that number which is when divisble by x1 gives remainder y1 , when divisble by x2 gives remainder y2 ..

 .
. .   NUMBER % x1 == y1
      NUMBER % x2 == y2
      NUMBER % x3 == y3
      NUMBER % x4 == y4
      .
      .
      .


*/

#include <iostream>
using namespace std;

int crt(int div[], int rem[], int size)
{
    bool isNumberFound = false;
    int count = 0;
    int number = 0;
    while (!isNumberFound)
    {
        for (int i = 0; i < size; i++)
        {
            if (number % div[i] != rem[i])
            {
                isNumberFound = false;
                count++;
                number++;
                if (count == 500)
                {
                    cout << "\nNumber is not found till 500 so exiting program" << endl;
                    exit;
                }

                break;
            }
            else
            {
                isNumberFound = true;
            }
        }
    }
    return number;
}
int main()
{
    int size;
    cout << "Enter the size of array (Both array Size will be SAME)" << endl;
    cin >> size;
    int div[size];
    int rem[size];

    cout << "Enter the " << size << " values of Array 1 i.e. Divisor ARRAY" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> div[i];
    }
    cout << "Enter the " << size << " values of Array 2 i.e. Remainder ARRAY" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> rem[i];
    }

    // Printing Array
    cout << "Array 1" << endl;
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << div[i] << " ";
    }
    cout << "] ";
    cout << "\nArray 2" << endl;
    cout << "[ ";

    for (int i = 0; i < size; i++)
    {
        cout << rem[i] << " ";
    }
    cout << "] ";
    int result = crt(div, rem, size);
    cout << " \n The NUMBER is " << result;
    return 0;
}