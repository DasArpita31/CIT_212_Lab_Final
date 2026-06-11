#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    vector<int> dist(n + 1, 1e9);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest Distances from Node " << source << ":\n";

    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " = " << dist[i] << endl;
    }

    return 0;
}
/*
3 2
1 2 5
2 3 2
1
*/