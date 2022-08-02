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
bool isIdentical(Node *root1, Node *root2) // 3 steps
{
    // 1st
    if (root1 == NULL && root2 == NULL)
        return true;
    // 2nd
    else if (root1 == NULL || root2 == NULL)
        return false;
    else
    {
        bool check_A = (root1->data == root2->data);            // values same or not
        bool check_B = isIdentical(root1->left, root2->left);   // left value
        bool check_C = isIdentical(root1->right, root2->right); // right value

        if (check_A && check_B && check_C)
            return true;
        else
            return false;
    }
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

    Node *root1 = NULL;
    root = insertBST(root, 25);
    root = insertBST(root, 15);
    root = insertBST(root, 36);
    root = insertBST(root, 18);
    root = insertBST(root, 16);
    root = insertBST(root, 19);

    /*
                     25
          15                       36
                 18
            16         19
  */
    if (isIdentical(root, root1))
        cout << "BSTs are Identical";
    else
        cout << "BSTs are not identical";
    return 0;
}