#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vvi vector<vi>
int nodes, edges;
vector<vector<int>> adjancyList;

vector<bool> visited;
vi components;

int get_comp(int node)
{
    // if current node is visted return 0;
    if (visited[node])
        return 0;
    visited[node] = 1;
    int ans = 1;
    // iterating to all coonected node from current visted Node
    for (auto i : adjancyList[node])
    {
        // if not visited than then check that node is cycle or not
        if (!visited[i])
        {
            ans += get_comp(i);
            visited[i] = 1;
        }
    }
    return ans;
}

int main()
{
    cout << "Enter number of Nodes : ";
    cin >> nodes;
    cout << endl;
    cout << "Enter number of edges : ";
    cin >> edges;
    cout << "undirected graph";
    cout << endl;

    adjancyList = vector<vector<int>>(nodes);

    visited = vector<bool>(nodes, 0);
    // first one is for index second contains matrix at that index
    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        cout << "Enter the node between which edge is connected : ";
        cin >> node1 >> node2;

        adjancyList[node1].push_back(node2);
        adjancyList[node2].push_back(node1);
    }

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            components.push_back(get_comp(i));
        }
    }

    for (auto i : components)
    {
        cout << i << " ";
    }

    return 0;
}

/*
Nodes = 5 edges = 3
0-----1
2-----3
0-----4



*/