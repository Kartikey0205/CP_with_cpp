
/**
 * MyStack LIFO
 */
#include <iostream>
using namespace std;
class MyStack
{
private:
    int i;
    int top;
    int capacity;
    int arr[]; // flexible member should be last always and only one flexible member can be declared
public:
    MyStack(int size)
    {
        int arr[size];
        top = -1;
        this->capacity = size;
    }

    void push(int element)
    {
        if (top + 1 < capacity)
        {
            arr[++top] = element;

            cout << endl;
            cout << "Adding element " << element << " into stack " << endl;

            cout << " Stack is : ";
            for (i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            cout << endl;

            cout << "Stack is full";
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
        }
        else
        {
            int ele = arr[top--];
            cout << endl;
            cout << "Popping out element = " << ele << " From stack ";

            if (top == -1)
            {
                cout << "Stack is empty now after popping";
            }
            else
            {

                cout << " \n Stack becomes after pop " << endl;
                for (int i = 0; i <= top; i++)
                {
                    cout << arr[i] << " ";
                }
            }
        }
    }
};

int main()
{
    MyStack s1(5);
    s1.push(0);
    s1.push(5);
    s1.push(7);
    s1.pop();
    s1.push(2);
    s1.push(1);
    s1.push(11);
    s1.pop();
    s1.push(12);
    s1.push(17);
    s1.pop();
    s1.push(19);
    return 0;
}
