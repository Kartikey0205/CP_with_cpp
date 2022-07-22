#include <iostream>
using namespace std;
class data
{

public:
    void func()
    {
        cout << "I am function without argument";
    }
    void func(int a)
    {
        cout << "I am function with int argument";
    }
    void func(double a)
    {
        cout << "I am function with double argument";
    }
};

int main()
{

    data a;
    a.func();
    a.func(2);
    a.func(9.2);
    return 0;
}