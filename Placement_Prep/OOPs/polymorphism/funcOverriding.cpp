#include <iostream>
using namespace std;
class data
{

public:
    void print()
    {
        cout << "I am base print \n";
    }
    void display()
    {
        cout << "I am base display \n";
    }
};
class derived : public data
{

public:
    void print()
    {
        cout << "I am derived print \n";
    }
    void display()
    {
        cout << "I am derived display \n";
    }
};
int main()
{
    cout << "VIA CREATING OBJECT OF BASE CLASS AND CALLING BASE CLASS METHOD \n";
    data I;
    I.print();
    I.display();
    cout << endl;
    cout << endl;

    cout << "VIA CREATING OBJECT OF DERIVED CLASS AND CALLING BASE CLASS METHOD \n";

    derived C_BASE;
    C_BASE.data::display();
    C_BASE.data::print();
    cout << endl;
    cout << endl;
    cout << "VIA CREATING OBJECT OF DERIVED CLASS AND CALLING DERIVED CLASS METHOD \n";

    derived C;
    C.print();
    C.display();
    cout << endl;
    cout << endl;

    cout << "VIA CREATING OBJECT OF BASE CLASS AND POINTER TOO CALLING METHOD AND IT CALLS BASE CLASS \n";

    data a;
    data *ptr = &a;
    ptr->print();
    ptr->display();
    cout << endl;
    cout << endl;

    cout << "VIA CREATING OBJECT OF DERIVED CLASS AND POINTER TOO CALLING METHOD AND IT CALLS DERIVED CLASS \n";
    derived d;
    derived *dptr = &d;
    dptr->print();
    dptr->display();
    cout << endl;
    cout << endl;

    cout << "VIA CREATING POINTER OF BASE CLASS AND STORIG DERIVED ADDRESS BUT  IT  CALLS BASE CLASS \n";
    data *A;
    derived B;
    A = &B;
    A->print();
    A->display();
    cout << endl;
    cout << endl;

    return 0;
}