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
    // BFS LOGIC

    queue<int>
        q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";
        vi ::iterator it;

        for (it = adjancyList[node].begin(); it != adjancyList[node].end(); it++)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }

    return 0;
}