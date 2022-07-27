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
int searchNode(int inOrder[], int start, int end, int current)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == current)
        {
            return i;
        }
    }
    return -1;
}
Node *buildTree(int preOrder[], int inOrder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int current = preOrder[idx];
    idx++;
    Node *n = new Node(current);
    if (start == end)
    {
        return n;
    }
    int posIn_InOrder = searchNode(inOrder, start, end, current);
    n->left = buildTree(preOrder, inOrder, start, posIn_InOrder - 1);
    n->right = buildTree(preOrder, inOrder, posIn_InOrder + 1, end);
    return n;
}
void inOrder_Tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder_Tree(root->left);
    cout << root->data << " ";
    inOrder_Tree(root->right);
}
int main()
{
    int preOrder[] = {1, 2, 4, 3, 5};
    int inOrder[] = {4, 2, 1, 5, 3};
    Node *root = buildTree(preOrder, inOrder, 0, 4);
    inOrder_Tree(root);

    return 0;
}