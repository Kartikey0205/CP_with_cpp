#include <iostream>
using namespace std;
// class Node
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
// Inserting at very First
// Inserting at Middle
// Inserting at End
// Deleting
//  Printing

/*  Pushing element in very first--
        1- Head is Null
        2- Head has some list
*/
void pushElement(Node **head_ref, int data)
{
    Node *new_node = new Node();
    // if coming node is first node
    new_node->data = data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    //  If already have some node
    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

// Insert element at Last
void insertLast(Node **head_ref, int data)
{
    Node *last = *head_ref;
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;

    // If coming node is first node
    if ((*head_ref) == NULL)
    {
        new_node->prev = NULL;
        (*head_ref) = new_node;
        return;
    }

    // If head is not NULL taht means already have a list
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last; // THIS IS VERY IMPORTANT CONCEPT OF ADDING PREVIOUS VALUE FOR NEW NODE
    return;
}

// Insert element at middle somewhere
void middleInsert(Node **head_ref, int data, int index)
{
    Node *prev_node = (*head_ref);
    // previous node find kr liye
    for (int i = 0; i < index; i++)
    {
        prev_node = prev_node->next;
    }

    // Making new node
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    // Still new node k next k prev k arrow remaing so  VERY VERY VERY IMPORTANT PART
    /*
     2 CASES -
            - NEW NODE WHICH IS ENTERED ITS LAST MEANS IT'S NEXT HAS NULL AND
            - IT HAS NOT NULL
    */

    // if nULL then no woorry because we had return each thing acording to it

    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}

//  Printing Doubly Linked List
void printDoublyLinkedList(Node *head_ref)
{
    cout << "Doubly Linked List will be \n";
    while (head_ref != NULL)
    {
        cout << " " << head_ref->data << " ";
        head_ref = head_ref->next;
    }
}
int main()
{

    Node *head = NULL;
    int number,
        value, index;

    while (true)
    {
        cout << "\nEnter the respective number what operation you want " << endl;
        cout << "\nEnter 1 for Inserting at Begin " << endl
             << "Enter 2 for Inserting at Mid " << endl
             << "Enter 3 for Inserting at Last " << endl
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
                pushElement(&head, value);
                printDoublyLinkedList(head);

                break;
            case 2:
                cout << " Enter the value you want to insert " << endl;
                cin >> value;
                cout << " Enter the index value after which you want to insert " << endl;
                cin >> index;

                middleInsert(&head, value, index);
                printDoublyLinkedList(head);

                break;
            case 3:
                cout << " Enter the value you want to insert " << endl;
                cin >> value;
                insertLast(&head, value);
                printDoublyLinkedList(head);

                break;

            default:
                cout << "Please enter valid number " << endl;
                break;
            }
        }
    }
    return 0;
}