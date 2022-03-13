// Craeting Structure for BST
// INSERT
// DELETE
// INORDER SUCESSOR
// INORDER
// PREORDER
// POSTORDER
// LEFT VIEW
// LEFT CHILD
// MIRROR VIEW
// TOP VIEW

#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

// newNode
Node *newNode(int data)
{

    Node *temp = new Node();
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int data)
{
    // very first value
    if (root == NULL)
    {
        return newNode(data);
    }
    // other than first value
    if (data < root->key)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
Node *inOrder_Successor(Node *node)
{
    Node *newVal = node;
    while (newVal->left != NULL)
    {
        newVal = newVal->left;
    }
    return newVal;
}

Node *deleteNode(Node *root, int data)
{
    // root is empty
    if (root == NULL)
    {
        return root;
    }
    // checking at which side will data go
    if (data < root->key)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->key)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // we reach the data
        // left is empty
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        // right is empty
        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // 2 child
        Node *temp = inOrder_Successor(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int main()
{
    int number, value;
    Node *root = NULL;
    while (true)
    {
        cout << "\nEnter the respective number what operation you want " << endl;
        cout << "\nEnter 1 for Inserting data in a BST" << endl
             << "Enter 2 for Deleting data from BST" << endl
             << "Enter 3 for Printing In Order BST " << endl
             << "Enter 4 for Printing Pre Order BST " << endl
             << "Enter 5 for Printing Post Order BST " << endl
             << "Enter 6 for Printing Left View BST " << endl
             << "Enter 7 for Printing Only Left Child BST " << endl
             << "Enter 8 for Printing Mirror View BST " << endl
             << "Enter 9 for Printing Top View BST " << endl

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
                cout << " Enter the data you want to insert " << endl;
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << " Enter the data you want to data " << endl;
                cin >> value;
                root = deleteNode(root, value);
                break;

            default:
                cout << "Please enter valid number " << endl;
                break;
            }
        }
    }
    return 0;
}