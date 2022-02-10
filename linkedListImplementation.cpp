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

//  Deleting a node of linked list
void deleteElementInLinkedList(Node **head_ref, int element)
{
    Node *temp = (*head_ref); // temp store the actual where head is pointing
    Node *prev;               // just making a prev  of Node type so that it can hold previous Node

    // Case 1 ->>   if element which has to be deleted is very first Element
    if ((temp != NULL) && (temp->data == element))
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Case 2 ->>   Element has to be deleted is head itself means no linked list exists

    if (temp == NULL)
    {
        cout << "No value in Linked list" << endl;
        return;
    }

    // Case 3 ->>   Element is somewhere in between linked list and we want to delete that particular element
    while ((temp != NULL) && (temp->data != element))
    {
        prev = temp;
        temp = temp->next;
    }

    // // case 4 ->>  last node to be deleted (If this code gonna execute then its creating problem in deleteing element from middle)
    // while ((temp->next != NULL))
    // {
    //     prev = temp;
    //     temp = temp->next;
    //     if (temp == NULL)
    //     {
    //         free(temp);
    //         prev->next = NULL;
    //     }
    // }
    prev->next = temp->next;
    free(temp);
}

// DELETEING LINKED LIST COMPLETELY
void deleteLinkedListCompletely(Node **head_ref)
{
    Node *current = *head_ref;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
    cout << "All nodes are deleted succesfully" << endl;
}

// COUNTING ALL NODES
int getNodeCount(Node *head)
{
    Node *current = head;
    int count = 0;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

// Reversing the Linked List
Node *getReverseLinkedList(Node *head_ref)
{
    // STEP 1- Initialization
    Node *current = head_ref;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {

        // STEP 2 - Value Updating
        next = current->next;
        current->next = prev;

        // STEP 3 - Again assigning value back
        prev = current;
        current = next;
    }

    //  Head Update to prev
    head_ref = prev;
    return head_ref;
}
int main()
{
    Node *head = NULL;
    Node *reverseList;
    int number,
        value, index;

    while (true)
    {
        cout << "\nEnter the respective number what operation you want " << endl;
        cout << "\nEnter 1 for Inserting at Begin " << endl
             << "Enter 2 for Inserting at Mid " << endl
             << "Enter 3 for Inserting at Last " << endl
             << "Enter 4 for Deleting a particular node " << endl
             << "Enter 5 for Deleting whole linked list " << endl
             << "Enter 6 for Counting total NODE in a linked list " << endl
             << "Enter 7 for Reversing a linked list " << endl
             << "Enter 0 for Exit " << endl;
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
            case 0:
                exit;
                break;
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
            case 4:
                cout << " Enter the data you want to delete" << endl;
                cin >> value;

                deleteElementInLinkedList(&head, value);
                printLinkedList(head);

                break;

            case 5:
                deleteLinkedListCompletely(&head);
                printLinkedList(head);

                break;
            case 6:
                printLinkedList(head);
                cout << "\nTotal NODE in a Linked List will be " << getNodeCount(head);

                break;
            case 7:

                cout << "\nPreviously Linked List will be" << endl;
                printLinkedList(head);

                cout << "\n Linked List after Reverse will be " << endl;
                reverseList = getReverseLinkedList(head);
                printLinkedList(reverseList);

                break;
            default:
                cout << "Please enter valid number " << endl;
                break;
            }
        }
    }

    return 0;
}