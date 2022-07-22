#include <iostream>
using namespace std;
class student
{
private:
    string name;

public:
    bool gender;
    int age;
    student()
    {
        cout << "Default Constructor" << endl;
    } // default constructor
    student(string name, int age, bool gender)
    {
        cout << "Parameterized Constructor" << endl;

        this->name = name;
        this->age = age;
        this->gender = gender;
    }
    ~student(); // destructor

    // COPY CONSTRUCTOR
    student(student &a)
    {

        cout << "Copy Constructor" << endl;
        this->name = a.name; // this is for c
        this->age = a.age;
        this->gender = a.gender;
    }

    // OPERATOR OVERLOADING
    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void printInfo()
    {
        cout << "Name = " << name << endl;
        cout << "Age = " << age << endl;
        cout << "Gender = " << gender << endl;
    }
};

student::~student()
{
    cout << " Destructor" << endl;
}

int main()
{

    student a("Kartikey", 20, 1); // parameterized constructor
    a.printInfo();
    student b;

    student c(a); // COPY CONSTRUCTOR or student c = a; // DEEP COPY
    if (c == a)
    {
        cout << "Same " << endl;
    }
    else
    {
        cout << "Not Same " << endl;
    }
    return 0;
}