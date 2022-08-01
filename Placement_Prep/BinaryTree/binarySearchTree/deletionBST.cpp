#include <iostream>
using namespace std;

class Node
{
public:
    int data;

    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
Node *inOrderSuccessor(Node *n)
{
    Node *curr = n;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteBST(Node *root, int key)
{

    // firstly find which side key is present
    if (root->data < key)
    {
        root->right = deleteBST(root->right, key);
    }
    else if (root->data > key)
    {
        root->left = deleteBST(root->left, key);
    }

    else
    {
        // Case 1 - leaf Node
        // Case 2 - 1 children
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        // Case 3 - 2 children
        Node *inSuccessor = inOrderSuccessor(root->right);
        root->data = inSuccessor->data;
        root->right = deleteBST(root->right, inSuccessor->data);
    }
    return root;
}
int main()
{

    Node *root = new Node(5);
    root->right = new Node(7);
    root->left = new Node(1);
    root->left->right = new Node(3);
    root->left->right->left = new Node(2);
    root->left->right->right = new Node(4);

    /*
                       5
            1                       7
                  3
             2         4
    */
    cout << "In Order of BST before deletion";
    inOrder(root);
    cout << endl;
    Node *node = deleteBST(root, 3);
    cout << "In Order of BST after deletion";
    inOrder(root);
    return 0;
}