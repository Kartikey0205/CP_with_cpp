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

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

vector<Node *> constructTrees(int start, int end)
{
    vector<Node *> trees;
    // base case
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    // root node
    for (int i = start; i <= end; i++)
    {
        // left subtTree
        vector<Node *> leftSubTree = constructTrees(start, i - 1);
        // right subtTree
        vector<Node *> rightSubTree = constructTrees(i + 1, end);

        // attaching each left side node to right side
        for (int j = 0; j < leftSubTree.size(); j++)
        {
            Node *left = leftSubTree[j];
            for (int k = 0; k < rightSubTree.size(); k++)
            {
                Node *right = rightSubTree[k];
                // attaching each left subtree and right subtree with main node
                Node *newNode = new Node(i);
                newNode->left = left;
                newNode->right = right;
                trees.push_back(newNode);
            }
        }
    }

    return trees;
}
int main()
{

    vector<Node *> totalTrees = constructTrees(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << i + 1 << " : ";
        preOrder(totalTrees[i]);
        cout << endl;
    }

    return 0;
}