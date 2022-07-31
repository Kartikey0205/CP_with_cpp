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
Node *insertBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);

    else
        root->right = insertBST(root->right, val);

    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{

    Node *root = NULL;
    root = insertBST(root, 5);
    root = insertBST(root, 1);
    root = insertBST(root, 3);
    root = insertBST(root, 7);
    root = insertBST(root, 2);
    root = insertBST(root, 4);

    /*
                       5
            1                       7
                  3
             2         4
    */
    cout << "In Order of BST is ";
    inOrder(root);
    return 0;
}