#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

int parent[100];

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    parent[find(a)] = find(b);
}

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

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         {
             return a.w < b.w;
         });

    int cost = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v))
        {
            unite(u, v);
            cost += w;
        }
    }

    cout << "Minimum Cost: " << cost << endl;

    return 0;
}/*Enter number of nodes: 4
Enter number of edges: 5
Enter edges (u v w):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4*/