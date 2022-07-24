#include <bits/stdc++.h>
using namespace std;
#define n 10
class Queue
{
    int *arr;
    int front;
    int rear;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if (rear == n - 1)
        {
            cout << "Queue is full\n";
            return;
        }
        rear++;
        arr[rear] = x;
        if (front == -1)
        {
            front++;
        }
    }
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty\n";
            return;
        }
        front++;
    }
    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Queue qt;
    qt.enqueue(10);
    qt.enqueue(160);
    qt.enqueue(20);
    qt.enqueue(103);
    qt.enqueue(101);
    cout << qt.empty() << endl;
    cout << qt.peek() << endl;
    qt.dequeue();
    cout << qt.peek() << endl;
    return 0;
}