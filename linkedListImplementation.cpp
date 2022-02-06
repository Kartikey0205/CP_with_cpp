#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

// Inserting element at very begining
void insertAtBegin(int value, Node **head_ref)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = *head_ref;
    *head_ref = new_node; // head pointing to first element always so that it can traverse whole linked list
}

//  Inserting Element at middle somewhere
void insertAtMiddleSomewhere(Node *prev_node, int value, int index)
{
    if (prev_node == NULL)
    {
        cout << "Previous node is NULL so that call append method for inserting value at END " << endl;
        return;
    }

    Node *new_node = new Node();
    new_node->data = value;
    for (int i = 0; i < index; i++)
    {
        prev_node = prev_node->next;
    }

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

//  Inserting element at very end
void appendInsertingAtEnd(Node **head_ref, int value)
{
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = NULL;

    Node *last = *head_ref; // we made last bcause we don't want head to disturb
    // it means that this is first value
    if (last == NULL)
    {
        *head_ref = new_node;
        return;
    }

    //  if there are values in Linked List and we are appending in last
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

//  Printing Linked list
void printLinkedList(Node *node)
{
    cout << "Linked List will be " << endl;
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
int main()
{
    Node *head = NULL;

    int number, value, index;

    while (true)
    {
        cout << "\nEnter the respective number what operation you want " << endl;
        cout << "\nPress 1 for Inserting at Begin " << endl
             << "Press 2 for Inserting at Mid " << endl
             << "Press 3 for Inserting at Last " << endl
             << "Press 0 for Exit " << endl;
        cin >> number;

        cout << endl;

        if (number == 0)
        {
            break;
        }
        else
        {

            switch (number)

            {
            case 1:
                cout << " Enter the value you want to insert " << endl;
                cin >> value;
                insertAtBegin(value, &head);
                printLinkedList(head);

                break;
            case 2:
                cout << " Enter the value you want to insert " << endl;
                cin >> value;
                cout << " Enter the index value after which you want to insert " << endl;
                cin >> index;

                insertAtMiddleSomewhere(head, value, index);
                printLinkedList(head);

                break;
            case 3:
                cout << " Enter the value you want to insert " << endl;
                cin >> value;
                appendInsertingAtEnd(&head, value);
                printLinkedList(head);

                break;
            case 0:
                exit;
                break;
            default:
                cout << "Please enter valid number " << endl;
                break;
            }
        }
    }
    // insertAtBegin(8, &head);
    //  switch case if 1 to ist method  2 toh insertMid 3rd then append and if 2 is press then for loop
    // cout << " Enter the index value after which you want to insert " << endl;
    // insertAtMiddleSomewhere(head, 6);
    // insertAtMiddleSomewhere(head, 90);

    // appendInsertingAtEnd(&head, 9);
    // printLinkedList(head);
    return 0;
}