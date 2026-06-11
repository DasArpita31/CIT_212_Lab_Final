#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[100];

void prim(int n)
{
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int cost = 0;

    pq.push({0, 0});

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        cost += weight;

        for (int i = 0; i < adj[node].size(); i++)
        {
            int next = adj[node][i].first;
            int w = adj[node][i].second;

            if (!visited[next])
            {
                pq.push({w, next});
            }
        }
    }

    cout << "Minimum Cost: " << cost << endl;
}

int main()
{
    int n, e;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (u v w): ";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prim(n);

    return 0;
}/*Enter number of nodes: 4
Enter number of edges: 5
Enter edges (u v w):
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4*/