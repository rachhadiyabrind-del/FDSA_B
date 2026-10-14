#include <iostream>
#include <utility>
#include <vector>
using namespace std;

bool hasCycleFrom(int vertex, int parentEdge,
                  const vector<vector<pair<int, int>>> &adj, vector<bool> &visited)
{
    visited[vertex] = true;
    for (size_t i = 0; i < adj[vertex].size(); i++)
    {
        int next = adj[vertex][i].first;
        int edgeId = adj[vertex][i].second;
        if (edgeId == parentEdge)
            continue;
        if (visited[next])
            return true;
        if (hasCycleFrom(next, edgeId, adj, visited))
            return true;
    }
    return false;
}

int main()
{
    int vertices, edges;
    cout << "Enter number of tasks (vertices): ";
    cin >> vertices;
    cout << "Enter number of dependencies (edges): ";
    cin >> edges;

    vector<vector<pair<int, int>>> adj(vertices);
    cout << "Enter each dependency as two task numbers (0 to " << vertices - 1 << "):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u < 0 || v < 0 || u >= vertices || v >= vertices)
        {
            cout << "Invalid dependency skipped." << endl;
            continue;
        }
        adj[u].push_back(make_pair(v, i));
        if (u != v)
            adj[v].push_back(make_pair(u, i));
    }

    vector<bool> visited(vertices, false);
    bool cycle = false;
    for (int i = 0; i < vertices && !cycle; i++)
        if (!visited[i])
            cycle = hasCycleFrom(i, -1, adj, visited);

    cout << "Loop exists: " << (cycle ? "Yes" : "No") << endl;
    return 0;
}
