#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vvi vector<vi>

const int N = 1e5 + 2;
bool visited[N];
// list
vi adjancyList[N];

void dfs(int node)
{
    // preOrder
    visited[node] = true;
    // cout << node << " ";
    // inOrder
    vi ::iterator it;

    for (it = adjancyList[node].begin(); it != adjancyList[node].end(); it++)
    {
        if (!visited[*it])
        {
            dfs(*it);
        }
    }
    // postOrder
    cout << node << " ";
}

int main()
{

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }

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
    // DFS Function

    dfs(1);

    return 0;
}