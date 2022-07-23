#include <iostream>
using namespace std;
// Node Structure
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Insert at Head
void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL) // First Element
    {
        head = newNode;
        return;
    }
    // other than first Element
    newNode->next = head;
    head->prev = newNode;
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
    // Case - 2 - Head is not NULL and last mein insert krna ho toh
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
// display Linked List
void display(Node *head)
{
    Node *temp = head;
    cout << "NULL <-";
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

    insertAtHead(head, 1837);
    display(head);

    return 0;
}