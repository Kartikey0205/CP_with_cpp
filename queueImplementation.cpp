#include <iostream>
using namespace std;
class queueImplementation
{
private:
    /* data */
    int front;
    int rear;
    int capacity;
    int waitingInQueue;
    int arr[]; // flexible member should be last always and only one flexible member can be declared
    // int *arr;

public:
    queueImplementation(int size)
    {
        int arr[size];
        // arr = new int[size];
        this->front = 0;
        this->rear = -1;
        this->capacity = size;
        this->waitingInQueue = 0;
    }

    // Checking Queue is Full or not
    int isFullQueue()
    {
        if (waitingInQueue == capacity)
        {
            cout << "\nQueue is already full " << endl;
            return -1;
        }
        else
        {
            // Queue is not fulled
            return 1;
        }
    }

    // Checking Queue is Empty or not
    int isEmptyQueue()
    {
        if (waitingInQueue == 0)
        {
            cout << "\nQueue is already Empty " << endl;
            return -1;
        }
        else
        {
            // Queue is not empty
            return 1;
        }
    }
    // Pushing Element into Queue
    void enQueue(int element)
    {
        if (isFullQueue() == 1)
        {
            this->rear = (this->rear + 1) % capacity;
            arr[this->rear] = element;
            cout << "\nAdding element " << element << endl;
            displayQueue();

            waitingInQueue++;
        }
    }

    // Poping Element front Queue
    void deQueue()
    {
        if (isEmptyQueue() == 1)
        {
            int ElementPopped = arr[this->front];
            arr[front] = 0;
            cout << "\nPopped Element " << ElementPopped << " and in that popped palce , value is set to 0 " << endl;
            displayQueue();

            this->front = (this->front + 1) % capacity;
            waitingInQueue--;
        }
    }

    // Displaying Queue
    void displayQueue()
    {
        cout << "Queue is " << endl;

        // Condition valid if rear come back to first palce
        if (rear >= front)
        {
            cout << " For element pushing first timne and at time when Popping first element  " << endl;

            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            cout << " For element Popped and again pushing " << endl;
            for (int i = 0; i < this->capacity; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{
    queueImplementation Q1(5);
    Q1.enQueue(6);
    Q1.enQueue(9);
    Q1.enQueue(2);
    Q1.deQueue();

    Q1.enQueue(8);
    Q1.enQueue(1);
    Q1.deQueue();
    Q1.enQueue(100);
    Q1.deQueue();
    Q1.enQueue(99);
    Q1.enQueue(20);
    Q1.enQueue(82);
    Q1.deQueue();
    Q1.enQueue(39);
    Q1.enQueue(26);
    Q1.enQueue(80);

    return 0;
}