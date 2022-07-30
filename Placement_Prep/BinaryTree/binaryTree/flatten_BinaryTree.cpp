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

void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    // left subtree
    if (root->left != NULL)
    {
        flatten(root->left);
        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *tail = root->right;
        while (tail->right != NULL)
        {
            tail = tail->right;
        }
        tail->right = temp;
    }
    // right subtree
    flatten(root->right);
}
void preOrder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{

    Node *root = new Node(3);
    root->left = new Node(6);
    root->right = new Node(10);

    /*
                3
            6       10

    */
    root->left->left = new Node(89);
    root->left->right = new Node(9);

    /*
                3
            6       10
        89      9
    */
    flatten(root);
    cout << "Pre Order of Tree is ";
    preOrder(root);
    return 0;
}