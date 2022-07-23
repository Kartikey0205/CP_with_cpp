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
Node *reverse_LL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    cout << "After Reversing LL \n";
    Node *newHead = reverse_LL(head);
    display(newHead);
    return 0;
}