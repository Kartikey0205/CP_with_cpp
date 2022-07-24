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

Node *mergeSorted_LL(Node *&head1, Node *&head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;

    Node *dummyNode = new Node(-1);
    Node *ptr3 = dummyNode;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummyNode->next;
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
    Node *head1 = NULL;
    Node *head2 = NULL;

    int arr1[] = {1, 2, 23, 25, 27, 57, 68, 89, 132};
    for (int i = 0; i < 9; i++)
    {
        insertAtTail(head1, arr1[i]);
    }
    display(head1);
    int arr2[] = {13, 20, 62, 92};
    for (int i = 0; i < 4; i++)
    {
        insertAtTail(head2, arr2[i]);
    }
    display(head2);
    Node *newHead = mergeSorted_LL(head1, head2);
    display(newHead);
    return 0;
}