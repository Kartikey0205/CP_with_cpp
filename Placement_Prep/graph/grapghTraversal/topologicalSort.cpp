#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nodes, edges;
    cout << "Enter number of Nodes : ";
    cin >> nodes;
    cout << "Enter number of edges : ";
    cin >> edges;
    cout << endl;
    // in degeree
    vector<int> indeg(nodes, 0);
    // Directed Graph Entry

    vector<vector<int>> adjancyList(nodes);
    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        cout << "Enter the node between which edge is connected : ";
        cin >> node1 >> node2;

        // node 1 ---> node 2
        adjancyList[node1].push_back(node2);
        indeg[node2]++;
    }

    queue<int> q;
    for (int i = 0; i < nodes; i++)
    {
        if (indeg[i] == 0) // leaf node
            q.push(i);
    }
    cout << "Topological Sort : ";
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        cout << ele << " ";
        for (auto i : adjancyList[ele])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                q.push(i);
        }
    }

    return 0;
}