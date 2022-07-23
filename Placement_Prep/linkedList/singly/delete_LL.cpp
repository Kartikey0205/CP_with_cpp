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
// delete at Head
void deleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
}
// deleting a node
void deleteNode(Node *&head, int key)
{
    // Head is a NULL
    if (head == NULL)
    {
        cout << "No elements in a linked List \n";
        return;
    }

    // Head delete krne ki postion ho toh
    if (head->data == key)
    {
        deleteAtHead(head);
        return;
    }
    // other element means key is neither NULL nor head it is either other element or not available
    Node *temp = head;
    while (temp->next->data != key)
    {

        temp = temp->next;
        if (temp->next == NULL)
        {
            cout << "Element not found \n";
            return;
        }
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
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
    deleteNode(head, 25);
    display(head);

    deleteNode(head, 187);
    display(head);

    return 0;
}