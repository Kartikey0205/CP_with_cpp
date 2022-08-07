#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    Node *left, *right;

    Node(int data)
    {
        key = data;
        left = NULL;
        right = NULL;
    }
};

void getVerticalOrder(Node *root, int hdis, map<int, vector<int>> &m)
{
    if (root == NULL)
        return;

    m[hdis].push_back(root->key);
    getVerticalOrder(root->left, hdis - 1, m);
    getVerticalOrder(root->right, hdis + 1, m);
}
int main()
{

    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    // hash map
    map<int, vector<int>> m;
    int horzDist = 0;

    getVerticalOrder(root, horzDist, m);

    map<int, vector<int>>::iterator it;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        for (int j = 0; j < (it->second).size(); j++)
        {
            cout << (it->second)[j] << " ";
        }
        cout << endl;
    }

    return 0;
}