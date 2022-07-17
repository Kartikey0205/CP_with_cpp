#include <iostream>
using namespace std;
void divisble(int n, int a, int b)
{
    int c1 = n / a;
    int c2 = n / b;
    int c3 = n / (a * b);
    cout << c1 + c2 - c3;
}
int main()
{
    int num, div1, div2;
    cin >> num >> div1 >> div2;
    divisble(num, div1, div2);
    return 0;
}