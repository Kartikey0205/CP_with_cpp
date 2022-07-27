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
Node *buildTree(int postOrder[], int inOrder[], int start, int end)
{
    static int idx = end;
    if (start > end)
    {
        return NULL;
    }
    int current = postOrder[idx];
    idx--;
    Node *n = new Node(current);
    if (start == end)
    {
        return n;
    }
    int posIn_InOrder = searchNode(inOrder, start, end, current);
    n->right = buildTree(postOrder, inOrder, posIn_InOrder + 1, end);
    n->left = buildTree(postOrder, inOrder, start, posIn_InOrder - 1);
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
    int postOrder[] = {1, 2, 4, 3, 5};
    int inOrder[] = {4, 2, 1, 5, 3};
    Node *root = buildTree(postOrder, inOrder, 0, 4);
    inOrder_Tree(root);

    return 0;
}