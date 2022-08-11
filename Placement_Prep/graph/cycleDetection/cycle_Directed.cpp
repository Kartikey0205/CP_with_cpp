#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vvi vector<vi>

bool isCycle(int node, vvi &adjList, vector<bool> &visited, vi &stackNode)
{
    // put current node to stack
    stackNode[node] = 1;

    // if current node is not visted then make it visted now
    if (!visited[node])
        visited[node] = true;
    // iterating to all coonected node from current visted Node
    for (auto i : adjList[node])
    {
        // if not visited than then check that node is cycle or not
        if (!visited[i] and isCycle(i, adjList, visited, stackNode))
            return true;
        // check iterated node is visted then cycle is present
        if (stackNode[i])
            return true;
    }
    stackNode[node] = 0;
    return false;
}

int main()
{
    int nodes, edges;
    cout << "Enter number of Nodes : ";
    cin >> nodes;
    cout << endl;
    cout << "Enter number of edges : ";
    cin >> edges;
    cout << "directed graph";
    cout << endl;
    // first one is for index second contains matrix at that index
    vvi adjancyList(nodes);
    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        cout << "Enter the node between which edge is connected : ";
        cin >> node1 >> node2;

        adjancyList[node1].push_back(node2);
    }
    vi stack(nodes, 0);
    bool cycle = false;
    vector<bool> visited(nodes, 0);

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i] and isCycle(i, adjancyList, visited, stack))
        {
            cycle = true;
        }
    }

    if (cycle)
        cout << "Cycle is Present";
    else
        cout << "Cycle is not Present";

    return 0;
}

/*
Nodes = 4 edges = 3
0-----1
1-----2
2-----1


Nodes = 4 edges = 2
0-----1
2-----3
*/