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

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST_In_BT(Node *root)
{
    // base case
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    // leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    // Left Info
    Info leftInfo = largestBST_In_BT(root->left);
    // Right Info
    Info rightInfo = largestBST_In_BT(root->right);

    // current Node;
    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int main()
{

    Node *root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);

    /*
                15
            20       30
        5
    */
    root->left->left = new Node(5);

    cout << "Largest size of BST in a given BT is : " << largestBST_In_BT(root).ans;
    return 0;
}