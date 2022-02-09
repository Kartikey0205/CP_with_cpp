#include <iostream>
using namespace std;
bool isPrime(int num)
{
    for (int i = 2; i < num - 1; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int num;
    cout << "Enter the number" << endl;
    cin >> num;

    bool prime = isPrime(num);
    if (prime == false)
    {
        cout << "Not a PRIME NUMBER " << endl;
    }
    else
    {
        cout << "PRIME NUMBER" << endl;
    }

    return 0;
}