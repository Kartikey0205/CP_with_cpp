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
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    cout << count << endl;
    return count;
}

Node *append_LL(Node *head, int k)
{
    Node *newHead;
    Node *newTail;
    Node *tail = head;
    int l = lengthList(head);
    cout << k << endl;

    k = k % l;
    cout << k << endl;
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == k)
        {
            newTail = tail;
        }
        if (count == k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;
    return newHead;
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
    int arr[] = {1, 23, 68, 2, 57, 25, 27, 132, 89};
    for (int i = 0; i < 8; i++)
    {
        insertAtTail(head, arr[i]);
    }
    insertAtHead(head, arr[8]);
    display(head);
    Node *newHead = append_LL(head, 3);
    display(newHead);
    return 0;
}