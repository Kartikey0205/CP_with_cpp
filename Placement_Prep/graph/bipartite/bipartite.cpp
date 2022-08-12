#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vvi vector<vi>
int nodes, edges;
vector<vector<int>> adjancyList;

vector<bool> visited;
vi color;

// 0 -> red , 1 -> blue , -1 ->none
bool bipart;
void getColor(int node, int colorNumber)
{
    // if current Node is not none and its colorNumber also do not equals to same Color number that means Not bipartite
    if (color[node] != -1 and color[node] != colorNumber)
    {
        bipart = false;
        return;
    }
    color[node] = colorNumber;
    // if current node is visted return ;
    if (visited[node])
        return;
    visited[node] = 1;
    // iterating to all coonected node from current visted Node
    for (auto i : adjancyList[node])
    {
        getColor(i, colorNumber xor 1);
        // colNumber xor 1 if colnum is 0 the 0^1 = 1 and vice versa
    }
}

int main()
{
    bipart = true;
    cout << "Enter number of Nodes : ";
    cin >> nodes;
    cout << endl;
    cout << "Enter number of edges : ";
    cin >> edges;
    cout << "undirected graph";
    cout << endl;

    adjancyList = vector<vector<int>>(nodes);
    color = vector<int>(nodes, -1);
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
            getColor(i, 0);
        }
    }
    if (bipart)
        cout << "Bipartite Graph";
    else
        cout << "Not a Bipartite Graph";
    return 0;
}

/*
Nodes = 3 edges = 3
0-----1
1-----2
2-----0

Nodes = 4 edges = 4
0-----1
1-----2
2-----3
3-----0


*/