
/**
 * MyStack LIFO
 */
#include <iostream>
using namespace std;
class MyStack
{
public:
    int top;
    int capacity;
    int arr[];

    MyStack(int size)
    {
        int arr[size];
        top = -1;
        capacity = size;
    }

    void push(int element)
    {
        if (top + 1 < capacity)
        {
            cout << element << endl;
            // arr[++top] = element;

            // cout << endl;
            // cout << "Adding element " << element;
            // for (int i = 0; i <= top; i++)
            // {
            //     cout << arr[i] << " ";
            // }
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
            cout << "Popping element " << ele;

            if (top == -1)
            {
                cout << "Stack is empty now after popping";
            }
            else
            {

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
    // s1.pop();
    s1.push(2);
    s1.push(1);
    s1.push(11);
    // s1.pop();
    s1.push(12);
    s1.push(17);
    // s1.pop();
    s1.push(19);
}

/*

}


*/