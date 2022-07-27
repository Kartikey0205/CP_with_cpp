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
int sumNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
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

    cout << "Sum of all Nodes in a binary tree :  " << sumNodes(root);
    return 0;
}