#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vvi vector<vi>

const int N = 1e5 + 2;
// list
vi adjancyList[N];

int main()
{

    int nodes, edges;
    cout << "Enter number of Nodes : ";
    cin >> nodes;
    cout << endl;
    cout << "Enter number of edges : ";
    cin >> edges;
    cout << endl;

    // first one is for index second contains matrix at that index

    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        cout << "Enter the node between which edge is connected : ";
        cin >> node1 >> node2;

        adjancyList[node1].push_back(node2);
        adjancyList[node2].push_back(node1);
    }

    vi ::iterator it;
    for (int i = 1; i < nodes + 1; i++)
    {
        cout << i << "-> ";
        for (it = adjancyList[i].begin(); it != adjancyList[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}