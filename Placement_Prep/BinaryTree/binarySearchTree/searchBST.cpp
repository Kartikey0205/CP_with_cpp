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
Node *searchBST(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;
    if (root->data > key)
        return searchBST(root->left, key);
    return searchBST(root->right, key);
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
    cout << "In Order of BST is ";
    inOrder(root);
    cout << endl;
    if (searchBST(root, 3) == NULL)
        cout << "Not Exists";
    else

        cout << "Exists";
    return 0;
}