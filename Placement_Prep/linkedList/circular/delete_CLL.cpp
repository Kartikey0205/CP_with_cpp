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

// delete at Head
void deleteAtHead(Node *&head)
{
    Node *temp = head;
    Node *toDelete = head;

    while (temp->next != head) // iterating because circular and last node is pointing to head so we have to change it too
    {
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
    delete toDelete;
}
// deleting a node
void deleteNode(Node *&head, int pos)
{
    // if position is a 1 then it means head is to delete
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    // other element means key is not 1 and it is either other element or not available
    Node *temp = head;
    int count = 1;
    while (count != pos - 1)
    {
        temp = temp->next;

        count++;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
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

    deleteNode(head, 2);
    display(head);

    deleteNode(head, 5);
    display(head);
    return 0;
}