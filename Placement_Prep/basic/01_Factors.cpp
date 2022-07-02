#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter the number" << endl;
    cin >> num;

    cout << "Factor of " << num << " is" << endl;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            cout << i << " ";
        else
            continue;
    }

    return 0;
}