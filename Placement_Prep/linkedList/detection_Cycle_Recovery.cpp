#include <iostream>
using namespace std;
// Node Structure
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert at Head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
// Insert at Tail
void insertAtTail(Node *&head, int val)
{
    // Created new Node
    Node *newNode = new Node(val);
    // Case - 1 - Head is NULL
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    // Case - 2 - Head is not NULL
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
// Lnegth
int lengthList(Node *head)
{
    Node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// make cycle

void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;
    int l = lengthList(head);
    if (pos <= l)
    {

        int count = 1;
        while (temp->next != NULL)
        {
            if (count == pos)
            {
                startNode = temp;
            }
            temp = temp->next;
            count++;
        }
        temp->next = startNode;
    }
}

// DETECT CYCLE
bool detectCycle(Node *&head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
// display Linked List
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node *head = NULL;
    int arr[] = {1, 23, 68, 2, 57, 25};
    for (int i = 0; i < 5; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head);
    insertAtHead(head, arr[5]);
    display(head);
    cout << "Before making cycle " << detectCycle(head) << endl;

    makeCycle(head, 6);
    cout << "After making cycle " << detectCycle(head) << endl;
    removeCycle(head);
    cout << "After removing cycle " << detectCycle(head) << endl;

    return 0;
}