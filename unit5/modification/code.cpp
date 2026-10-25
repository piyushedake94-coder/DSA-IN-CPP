
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int v, vector<vector<int>>& adj,
         vector<bool>& visited, vector<int>& order)
{
    visited[v] = true;
    order.push_back(v);

    for (int u : adj[v])
    {
        if (!visited[u])
            DFS(u, adj, visited, order);
    }
}

int main()
{
    int V, E, start;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= V)
    {
        cout << "Invalid starting vertex.\n";
        return 0;
    }

    // A. DFS traversal
    vector<bool> visited(V, false);
    vector<int> order;

    DFS(start, adj, visited, order);

    cout << "\nDFS Traversal Order: ";
    for (int v : order)
        cout << v << " ";
    cout << "\n";

    // B. Reachable and unreachable vertices
    cout << "\nReachable vertices: ";
    for (int v = 0; v < V; v++)
        if (visited[v])
            cout << v << " ";

    cout << "\nUnreachable vertices: ";
    bool found = false;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v])
        {
            cout << v << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << "\n";

    // Identify isolated vertices
    cout << "Isolated vertices: ";
    found = false;

    for (int v = 0; v < V; v++)
    {
        if (adj[v].empty())
        {
            cout << v << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << "\n";

    // C. Count reachable vertices
    cout << "Reachable vertices count: "
         << order.size() << "\n";

    // BFS levels
    vector<int> level(V, -1);
    queue<int> q;

    level[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int u : adj[v])
        {
            if (level[u] == -1)
            {
                level[u] = level[v] + 1;
                q.push(u);
            }
        }
    }

    cout << "\nBFS Levels:\n";
    for (int v = 0; v < V; v++)
    {
        if (level[v] != -1)
            cout << "Vertex " << v
                 << " -> Level " << level[v] << "\n";
    }

    return 0;
}
