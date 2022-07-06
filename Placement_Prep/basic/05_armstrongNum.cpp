#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int digit, num, sum = 0;
    cout << "Enter the how much digit number you want to check" << endl;
    cin >> digit;
    cout << "Enter the number" << endl;
    cin >> num;
    int original = num;
    while (num > 0)
    {
        int lastDigit = num % 10;
        sum = sum + pow(lastDigit, digit);
        num = num / 10;
    }
    if (original == sum)
        cout << "Number is Armstrong Number" << endl;
    else
        cout << "Not Armstrong Number" << endl;

    return 0;
}