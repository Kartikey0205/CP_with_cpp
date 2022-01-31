#include <iostream>
#include <array>
using namespace std;
int main()
{
    // Basic Array
    int a[4] = {1, 2, 3, 4};

    // STL ARRAY ---> for this use #include<array>
    /*
    Syntax-
        array<data_Type , size> array_Name = {a,b,c,d};
    */

    array<int, 6>
        arraySTL = {100, 101, 102, 103, 104, 105};

    cout << "STL Array is :" << endl;
    for (int i = 0; i < arraySTL.size(); i++)
    {
        cout << arraySTL[i] << " ";
    }

    cout << "\nSTL Array Size is : " << arraySTL.size() << endl;
    cout << "\nElement at 2nd index of STL Array is : " << arraySTL.at(2) << endl;
    cout << "\nSTL Array is empty or not " << arraySTL.empty() << endl;
    cout << "\nFirst Element of STL Array Size is : " << arraySTL.front() << endl;
    cout << "\nLast Element of STL Array Size is : " << arraySTL.back() << endl;

    return 0;
}