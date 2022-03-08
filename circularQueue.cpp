/*
35  25  12  41  19  47  75  96  74
 0   1  2   3   4   5   6   7   8
 F                              R
        R   F
 queue is full in 2 cases -
    when
        REAR is just behind the FRONT
        FRONT is at first and REAR is at last

(rear+1) % size == front
(front == 0&&rear == size-1) || (rear == (front-1)%(size-1))
*/

#include <iostream>
using namespace std;

// STRUCTURE OF QUEUE
struct circularQueue
{
    int rear, front;
    int size;
    // int *arr;
    int *arr;
    circularQueue(int s)
    {
        size = s;
        front = -1;
        rear = -1;
        arr = new int[s];
    }
    void enQueue(int data);
    int deQueue();
    void printCircularQueue();
};

void circularQueue ::enQueue(int data)
{
    // FULL Queue
    if (((front == 0) && (rear == size - 1)) || (rear == (front - 1) % (size - 1)))
    {
        cout << "Queue is full" << endl;

        return;
    }
    else if (front == -1) // very first value
    {
        cout << "Adding data = " << data << " in a queue " << endl;
        front = 0;
        rear = 0;
        arr[rear] = data;
    }
    else if ((rear == size - 1) && (front != 0)) // moving back again to front
    {
        cout << "Adding data = " << data << " in a queue " << endl;
        rear = 0;
        arr[rear] = data;
    }
    else // all other cases
    {
        cout << "Adding data = " << data << " in a queue " << endl;
        rear++;
        arr[rear] = data;
    }
}

int circularQueue ::deQueue()
{
    // Queue is Empty
    if (front == -1)
    {
        cout << "Queue is empty " << endl;
        return -1;
    }
    int data = arr[front];
    arr[front] = -1;
    // only one element is there in Queue
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1) // last element is deleted
    {
        front = 0;
    }
    else // alll other cases
    {
        front++;
    }
    return data;
}

void circularQueue::printCircularQueue()
{
    cout << "\nCircular Queue is" << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 10000)
        {
            arr[i] = 0;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{

    int size, number, value;
    cout << "Enter the size of queue " << endl;
    cin >> size;
    circularQueue myQueue(size);
    while (true)
    {
        cout << "\nEnter the respective number what operation you want " << endl;
        cout << "\nEnter 1 for Inserting data in a queue " << endl
             << "Enter 2 for Deleting data in a queue" << endl
             << "Enter 3 for Printing queue " << endl
             << "Enter 0 for Exit " << endl;

        cin >> number;
        cout << endl;
        if (number == 0)
        {
            break;
        }
        else
        {

            switch (number)

            {
            case 0:
                exit;
                break;
            case 1:
                cout << " Enter the data you want to insert " << endl;
                cin >> value;
                myQueue.enQueue(value);

                break;
            case 2:
                cout << "\nData deleted is " << myQueue.deQueue() << endl;

                break;
            case 3:
                myQueue.printCircularQueue();

                break;
            default:
                cout << "Please enter valid number " << endl;
                break;
            }
        }
    }
    return 0;
}