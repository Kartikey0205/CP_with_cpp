#include <iostream>
using namespace std;
int fibo(int value);
int main()
{
    int number, i = 0;
    cout << "Enter the positive number" << endl;
    cin >> number;
    cout << "Fibonacci Series will be" << endl;
    while (i < number)
    {
        cout << fibo(i) << " ";
        i++;
    }
    return 0;
}

int fibo(int value)
{
    if (value == 1 || value == 0)
    {
        return value;
    }
    else
    {
        return fibo(value - 1) + fibo(value - 2);
    }
}