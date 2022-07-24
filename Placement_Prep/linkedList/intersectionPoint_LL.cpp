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
    return count;
}

void *intersect_LL(Node *head1, Node *head2, int pos)
{
    Node *temp1 = head1;
    // pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}
int intersectionPoint(Node *&head1, Node *&head2)
{
    int l1 = lengthList(head1);
    int l2 = lengthList(head2);
    int dif = 0;
    Node *ptr1;
    Node *ptr2;
    if (l1 > l2)
    {
        dif = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        dif = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (dif)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        dif--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
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

    int arr1[] = {1, 23, 68, 2, 57, 25, 27, 132, 89};
    for (int i = 0; i < 9; i++)
    {
        insertAtTail(head1, arr1[i]);
    }
    display(head1);
    int arr2[] = {13, 223, 628, 20};
    for (int i = 0; i < 4; i++)
    {
        insertAtTail(head2, arr2[i]);
    }
    display(head2);
    intersect_LL(head1, head2, 6);
    if (intersectionPoint(head1, head2) != -1)
    {
        cout << "Intersecting node is " << intersectionPoint(head1, head2);
    }
    else
    {
        cout << "No intersecting node";
    }
    return 0;
}