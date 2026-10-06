#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, int source, int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[source] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        visited[u] = true;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && dist[u] != INT_MAX &&
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    cout << "\nShortest distances from source " << source + 1 << ":\n";

    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i + 1 << " : ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        u--;
        v--;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    source--;

    dijkstra(graph, source, n);

    return 0;
}