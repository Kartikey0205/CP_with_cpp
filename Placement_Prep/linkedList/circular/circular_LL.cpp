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

    if (head == NULL) // first element
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    // other element but at h
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
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
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}
// display Linked List
void display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
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
    return 0;
}