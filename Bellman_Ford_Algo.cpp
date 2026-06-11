#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge
{
    int u, v, w;
};

int main()
{
    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<Edge> edges;

    cout << "Enter edges (u v w): ";
    for (int i = 0; i < e; i++)
    {
        Edge edge;
        cin >> edge.u >> edge.v >> edge.w;
        edges.push_back(edge);
    }

    int source;

    cout << "Enter source node: ";
    cin >> source;

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "Shortest distances from source:\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }

    return 0;
}/*Enter number of nodes: 4
Enter number of edges: 5
Enter edges (u v w):
0 1 4
0 2 5
1 2 -2
2 3 3
1 3 4
Enter source node: 0*/