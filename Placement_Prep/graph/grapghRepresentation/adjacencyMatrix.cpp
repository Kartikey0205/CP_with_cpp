#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define vvi vector<vi>

const int N = 1e5 + 2;

int main()
{

    int nodes, edges;
    cout << "Enter number of Nodes : ";
    cin >> nodes;
    cout << endl;
    cout << "Enter number of edges : ";
    cin >> edges;
    cout << endl;

    vvi adjacencyMatrix(nodes + 1, vi(nodes + 1)); // first one is for index second contains matrix at that index

    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        cout << "Enter the node between which edge is connected : ";
        cin >> node1 >> node2;

        adjacencyMatrix[node1][node2] = 1;
        adjacencyMatrix[node2][node1] = 1;
    }
    for (int i = 1; i < nodes + 1; i++)
    {
        for (int j = 1; j < nodes + 1; j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}