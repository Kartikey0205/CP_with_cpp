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

            default:
                cout << "Please enter valid number " << endl;
                break;
            }
        }
    }
    return 0;
}