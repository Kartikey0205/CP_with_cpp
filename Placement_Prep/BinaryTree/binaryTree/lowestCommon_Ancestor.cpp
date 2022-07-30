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

Node *LCA(Node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
        return NULL;

    // Node mil gya
    if (root->data == n1 || root->data == n2)
        return root;

    // Left side search
    Node *left_LCA = LCA(root->left, n1, n2);
    // Right side search
    Node *right_LCA = LCA(root->right, n1, n2);

    // If(both exist that means common ancestor we got)
    if (left_LCA && right_LCA)
        return root;
    // if only left present
    if (left_LCA != NULL)
        return left_LCA;
    // if only right present
    return right_LCA;
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

    Node *lca = LCA(root, 89, 10);
    if (lca == NULL)
        cout << "No common Ancestor ";
    else
        cout << " LCA is " << lca->data;
    return 0;
}