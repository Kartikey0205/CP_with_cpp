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

// zig zag Traversal  --> 3 steps
void zigzagTraversal(Node *root)
{
    // base case
    if (root == NULL)
        return;

    // step 1 - var , 2 stack
    bool leftToRight = true;
    stack<Node *> currLevel;
    stack<Node *> nextLevel;
    currLevel.push(root);
    // step 2 - pop , check , left right traverse print
    while (!currLevel.empty())
    {
        Node *topMost_Node = currLevel.top();
        currLevel.pop();

        if (topMost_Node)
        {
            cout << topMost_Node->data << " ";

            if (leftToRight)
            {
                if (topMost_Node->left)
                {
                    nextLevel.push(topMost_Node->left);
                }
                if (topMost_Node->right)
                {
                    nextLevel.push(topMost_Node->right);
                }
            }
            else // not left to right
            {

                if (topMost_Node->right)
                {
                    nextLevel.push(topMost_Node->right);
                }
                if (topMost_Node->left)
                {
                    nextLevel.push(topMost_Node->left);
                }
            }
        }

        // step 3 - var change and swap stacks
        if (currLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
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
    zigzagTraversal(root);
    return 0;
}