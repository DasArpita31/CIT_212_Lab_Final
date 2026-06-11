#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int,int>> adj[100];

void dijkstra(int n, int start)
{
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (int i = 0; i < adj[node].size(); i++)
        {
            int next = adj[node][i].first;
            int weight = adj[node][i].second;

            if (dist[node] + weight < dist[next])
            {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "Shortest distances from source:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }
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

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    dijkstra(n, start);

    return 0;
}
/*Enter number of nodes: 3
Enter number of edges: 3
Enter edges (u v w):
0 1 5
1 2 2
0 2 9
Enter starting node: 0*/