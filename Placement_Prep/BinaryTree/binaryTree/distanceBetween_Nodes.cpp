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
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftLCA = LCA(root->left, n1, n2);
    Node *rightLCA = LCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
    {
        return root;
    }

    if (leftLCA != NULL)
    {
        return leftLCA;
    }
    return rightLCA;
}
int findDist(Node *ancestor, int node, int distance)
{
    if (ancestor == NULL)
        return -1;
    if (ancestor->data == node)
        return distance;
    int left = findDist(ancestor->left, node, distance + 1);
    if (left != -1)
        return left;
    return findDist(ancestor->right, node, distance + 1);
}

int distance_Between_Nodes(Node *root, int n1, int n2)
{
    Node *lowest_Ancestor = LCA(root, n1, n2);

    int d1 = findDist(lowest_Ancestor, n1, 0);
    int d2 = findDist(lowest_Ancestor, n2, 0);
    return d1 + d2;
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
    root->left->right->left = new Node(19);
    root->left->right->left->left = new Node(45);
    root->left->right->left->left->right = new Node(96);

    /*
                              3
                    6                   10
            89              9
                        19
                    45
                        96
    */

    cout << "Shortest distance between 2 nodes is " << distance_Between_Nodes(root, 96, 89) << " ";
    return 0;
}