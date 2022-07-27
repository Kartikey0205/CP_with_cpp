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
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
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

    cout << "Count of all Nodes in a binary tree :  " << countNodes(root);
    return 0;
}