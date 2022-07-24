#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class que
{
    Node *front;
    Node *back;

public:
    que()
    {
        front = NULL;
        back = NULL;
    }
    void push(int x)
    {
        Node *n = new Node(x);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
    }
    void peek()
    {
        if (front == NULL)
        {
            cout << " EMPTY LL " << endl;
        }
        cout << front->data << endl;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << " EMPTY LL " << endl;
        }
        Node *toDelete = front;
        front = front->next;
        delete toDelete;
    }
    bool empty()
    {
        if (front == NULL)
            return true;
        return false;
    }
};
int main()
{
    que q;
    q.push(2);
    q.push(12);
    q.push(22);
    q.push(26);
    q.push(28);
    q.push(21);
    cout << q.empty();
    q.peek();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << q.empty();
    q.peek();
    return 0;
}