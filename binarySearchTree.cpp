// Craeting Structure for BST
// INSERT
// DELETE
// INORDER SUCESSOR
// INORDER
// PREORDER
// POSTORDER
// LEFT VIEW
// LEFT CHILD
// MIRROR VIEW
// TOP VIEW

#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

// newNode
Node *newNode(int data)
{

    Node *temp = new Node();
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *root, int data)
{
    // very first value
    if (root == NULL)
    {
        return newNode(data);
    }
    // other than first value
    if (data < root->key)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
Node *inOrder_Successor(Node *node)
{
    Node *newVal = node;
    while (newVal->left != NULL)
    {
        newVal = newVal->left;
    }
    return newVal;
}

Node *deleteNode(Node *root, int data)
{
    // root is empty
    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
        return root;
    }
    // checking at which side will data go
    if (data < root->key)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->key)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // we reach the data
        // left is empty
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        // right is empty
        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // 2 child
        Node *temp = inOrder_Successor(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// inOrder
void inOrder(Node *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }
}
// preOrder
void preOrder(Node *node)
{
    if (node != NULL)
    {
        cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
// postOrder
void postOrder(Node *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->key << " ";
    }
}

// Left View
void leftView(Node *node)
{
    if (node != NULL)
    {
        cout << node->key << " ";
        leftView(node->left);
    }
}

// Left Child
void leftChild(Node *node)
{
    if (node != NULL)
    {
        if (node->left != NULL)
        {

            cout << node->left->key << " ";
        }
        leftChild(node->left);
        leftChild(node->right);
    }
}

// swap method
void swap(Node *n)
{
    Node *temp = n->left;
    n->left = n->right;
    n->right = temp;
}

// Printing mirror view only of tree
void mirrorViewTree(Node *node)
{
    Node *orginalNode = node;
    if (orginalNode != NULL)
    {
        swap(orginalNode);

        mirrorViewTree(orginalNode->left);
        cout << orginalNode->key << " ";
        mirrorViewTree(orginalNode->right);
    }
}
int main()
{
    int number, value;
    Node *root = NULL;
    while (true)
    {
        cout << "\nEnter the respective number what operation you want " << endl;
        cout << "\nEnter 1 for Inserting data in a BST" << endl
             << "Enter 2 for Deleting data from BST" << endl
             << "Enter 3 for Printing In Order BST " << endl
             << "Enter 4 for Printing Pre Order BST " << endl
             << "Enter 5 for Printing Post Order BST " << endl
             << "Enter 6 for Printing Left View BST " << endl
             << "Enter 7 for Printing Only Left Child BST " << endl
             << "Enter 8 for Printing Mirror View BST " << endl
             << "Enter 9 for Printing Top View BST " << endl

             << "Enter 0 for Exit " << endl;

        cin >> number;
        cout << endl;
        if (number == 0)
        {
            break;
        }
        else
        {

            switch (number)

            {
            case 0:
                exit;
                break;
            case 1:
                cout << " Enter the data you want to insert " << endl;
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                if (root == NULL)
                {
                    cout << " Tree is Empty " << endl;
                }
                else
                {

                    cout << " Enter the data you want to delete " << endl;
                    cin >> value;
                    root = deleteNode(root, value);
                }
                break;
            case 3:
                if (root == NULL)
                {
                    cout << " Tree is Empty " << endl;
                }
                else
                {

                    cout << " In order Traversal is " << endl;
                    inOrder(root);
                }
                break;
            case 4:
                if (root == NULL)
                {
                    cout << " Tree is Empty " << endl;
                }
                else
                {

                    cout << " Pre order Traversal is " << endl;
                    preOrder(root);
                }
                break;
            case 5:
                if (root == NULL)
                {
                    cout << " Tree is Empty " << endl;
                }
                else
                {

                    cout << " Post order Traversal is " << endl;
                    postOrder(root);
                }
                break;
            case 6:
                if (root == NULL)
                {
                    cout << " Tree is Empty " << endl;
                }
                else
                {

                    cout << " Left View of Tree is " << endl;
                    leftView(root);
                }
                break;
            case 7:
                if (root == NULL)
                {
                    cout << " Tree is Empty " << endl;
                }
                else
                {

                    cout << "Left Child is " << endl;
                    leftChild(root);
                }
                break;
            case 8:
                if (root == NULL)
                {
                    cout << " Tree is Empty " << endl;
                }
                else
                {

                    cout << "Mirror View is " << endl;
                    Node *mirrorTree = root;
                    mirrorViewTree(root);
                    root = mirrorTree;
                }

                break;

            default:
                cout << "Please enter valid number " << endl;
                break;
            }
        }
    }
    return 0;
}

// TREE IS

/*



                                                                100
                                              85                                     120
                                        70          90                      111              180
                                45              87                      108               130
                          32

*/