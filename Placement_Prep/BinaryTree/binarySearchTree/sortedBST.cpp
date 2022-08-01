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
Node *sortedArrayBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayBST(arr, start, mid - 1);
    root->right = sortedArrayBST(arr, mid + 1, end);

    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    Node *root = sortedArrayBST(arr, 0, 4);
    cout << "In Order of BST is ";
    inOrder(root);
    return 0;
}