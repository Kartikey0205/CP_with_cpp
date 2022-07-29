// O(N2)

#include <bits/stdc++.h>
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
int calculateHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced_Height(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced_Height(root->left) == false)
    {
        return false;
    }

    if (isBalanced_Height(root->right) == false)
    {
        return false;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    if (abs(leftHeight - rightHeight) <= 1)
        return true;

    else

        return false;
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

    if (isBalanced_Height(root))
        cout << "Balanced Tree";
    else
        cout << "Unbalanced Tree";
    return 0;
}