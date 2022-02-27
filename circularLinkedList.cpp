#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
// Insertion Method
void push(int data, Node **head_ref)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = *head_ref;

    Node *temp = *head_ref;
    //  If node alrady exists
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else // first node is coming
    {
        new_node->next = new_node;
    }
    *head_ref = new_node;
}
//  Traverse Method
void printCircularList(Node *head)
{
    Node *temp = head;

    cout << "Circular Linked List will be " << endl;
    if (head != NULL)
    {

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    else
    {
        cout << " No value in Circular Linked List" << endl;
    }
}

// Deleting a Node from Circular Linked List
void deleteNode(int element, Node **head_ref)
{
    //  Case -1 : if list is Empty
    if (*head_ref == NULL)
    {
        return;
    }
    // Case-2 : if list contain single node and that is Head only
    if ((*head_ref)->data == element && (*head_ref)->next == *head_ref)
    {
        free(*head_ref);
        *head_ref = NULL;
    }

    // Case-3 :Head node to be deleted and many element is present there
    Node *last = *head_ref, *d;
    if ((*head_ref)->data == element)
    {
        while (last->next != (*head_ref))
        {
            last = last->next;
        }
        last->next = (*head_ref)->next;
        free(*head_ref);
        *head_ref = last->next;
    }

    // Case-4: Regular Node to be deleted

    while (last->next != (*head_ref) && last->next->data != element)
    {
        last = last->next;
    }
    if (last->next->data == element)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    //  Case 5 : Node not found
    else
    {
        cout << "Node not Found\n";
    }
}

//  Count All Nodes
void countNode(Node *head_ref)
{
    int count = 0;
    Node *current = head_ref;
    if (head_ref == NULL)
    {
        cout << "Total number of Nodes will be 0 " << endl;
    }
    do
    {
        count++;
        current = current->next;
    } while (current != head_ref);

    cout << "Total number of Nodes will be " << count << endl;
}

int main()
{
    Node *head = NULL;
    // Node *reverseList;
    int number,
        value, index;

    while (true)
    {
        cout << "\nEnter the respective number what operation you want " << endl;
        cout << "\nEnter 1 for Inserting an Element at begining in a Circular Linked List " << endl
             << "Enter 2 for Deleting a node " << endl
             << "Enter 3 for Counting a node " << endl
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
                push(value, &head);
                printCircularList(head);

                break;
            case 2:
                cout << " Enter the value you want to delete " << endl;
                cin >> value;
                deleteNode(value, &head);
                printCircularList(head);

                break;
            case 3:
                countNode(head);

                break;
            default:
                cout << "Please enter valid number " << endl;
                break;
            }
        }
    }

    return 0;
}