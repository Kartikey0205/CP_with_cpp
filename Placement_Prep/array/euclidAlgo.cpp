#include <iostream>
using namespace std;
int euclid(int a, int b)
{
    while (b != 0)
    {
        int res = a % b;
        a = b;
        b = res;
    }
    return a;
}
int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    cout << "GCD Of numbers = " << euclid(num1, num2);
    return 0;
}