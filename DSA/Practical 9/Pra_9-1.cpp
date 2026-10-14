#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

void dfsRecursive(int vertex, const vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[vertex] = true;
    cout << vertex << " ";
    for (size_t i = 0; i < adj[vertex].size(); i++)
    {
        int next = adj[vertex][i];
        if (!visited[next])
            dfsRecursive(next, adj, visited);
    }
}

void dfsIterative(int start, const vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    stack<int> pending;
    pending.push(start);
    while (!pending.empty())
    {
        int vertex = pending.top();
        pending.pop();
        if (visited[vertex])
            continue;
        visited[vertex] = true;
        cout << vertex << " ";
        for (int i = (int)adj[vertex].size() - 1; i >= 0; i--)
            if (!visited[adj[vertex][i]])
                pending.push(adj[vertex][i]);
    }
}

void bfs(int start, const vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    queue<int> line;
    visited[start] = true;
    line.push(start);
    while (!line.empty())
    {
        int vertex = line.front();
        line.pop();
        cout << vertex << " ";
        for (size_t i = 0; i < adj[vertex].size(); i++)
        {
            int next = adj[vertex][i];
            if (!visited[next])
            {
                visited[next] = true;
                line.push(next);
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter number of buildings (vertices): ";
    cin >> vertices;
    cout << "Enter number of roads (edges): ";
    cin >> edges;

    vector<vector<int>> adj(vertices);
    cout << "Enter each road as two building numbers (0 to " << vertices - 1 << "):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u < 0 || v < 0 || u >= vertices || v >= vertices)
        {
            cout << "Invalid road " << u << " " << v << " skipped." << endl;
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < vertices; i++)
        sort(adj[i].begin(), adj[i].end());

    int start;
    cout << "Enter starting building: ";
    cin >> start;
    if (start < 0 || start >= vertices)
    {
        cout << "Error: invalid starting building" << endl;
        return 0;
    }

    vector<bool> visited(vertices, false);
    cout << "DFS (recursive): ";
    dfsRecursive(start, adj, visited);
    cout << endl;

    cout << "DFS (iterative): ";
    dfsIterative(start, adj);
    cout << endl;

    cout << "BFS            : ";
    bfs(start, adj);
    cout << endl;

    int unreachable = 0;
    for (int i = 0; i < vertices; i++)
        if (!visited[i])
            unreachable++;
    if (unreachable > 0)
        cout << unreachable << " building(s) are not reachable from the start." << endl;

    return 0;
}
