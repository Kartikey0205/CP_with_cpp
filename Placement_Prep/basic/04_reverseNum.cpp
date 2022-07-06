#include <iostream>
using namespace std;
int main()
{
    int num, reverse = 0;
    cout << "Enter the number" << endl;
    cin >> num;

    while (num > 0)
    {
        int lastDigit = num % 10;
        reverse = reverse * 10 + lastDigit;
        num = num / 10;
    }
    cout << "Reversed number is " << reverse;
    return 0;
}