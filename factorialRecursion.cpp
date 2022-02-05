#include <iostream>
using namespace std;
int fact(int num)
{
    if (num < 1)
    {
        return -1;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        return num * fact(num - 1);
    }
}
int main()
{
    int number;
    cout << "Enter the positive number" << endl;
    cin >> number;
    cout << "Fcatorial of " << number << " will be " << endl;

    if (fact(number) == -1)
    {
        cout << "Please enter positive number";
    }
    else
    {

        cout << fact(number);
    }

    return 0;
}