#include <iostream>
using namespace std;
void swap(int num1, int num2)
{
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
    cout << " A = " << num1 << " B = " << num2 << endl;
}
int main()
{
    int a, b;
    cout << "Enter the 2 numbers " << endl;
    cin >> a;
    cin >> b;
    cout << " A = " << a << " B = " << b << endl;

    swap(a, b);

    return 0;
}