#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void createEdgeList(const vector<vector<int>>& GraphM, vector<pair<pair<int, int>, int>>& Edges, int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (GraphM[i][j] != 0)
            {
                Edges.push_back({{i, j}, GraphM[i][j]});
            }
        }
    }
}

int countPath(vector<int>& parent, int i)
{
    if (parent[i] == -1)
    {
        return 0;
    }
    return 1 + countPath(parent, parent[i]);
}

void bellmanFord(vector<pair<pair<int, int>, int>>& Edges, int V, int start, int dest, int k)
{
    int E = Edges.size();
    vector<int> parent(V, -1);
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;
    for (int i = 1; i <= k + 1; i++) // Include the source vertex in the loop
    {
        vector<int> nextDist(dist);
        for (int j = 0; j < E; j++)
        {
            int source = Edges[j].first.first;
            int desti = Edges[j].first.second;
            int weight = Edges[j].second;
            if (dist[source] != INT_MAX && dist[source] + weight < nextDist[desti])
            {
                nextDist[desti] = dist[source] + weight;
                parent[desti] = source;
            }
        }
        dist = nextDist;
    }
    int count = countPath(parent, dest);
    cout << "Weight of the shortest path from " << start + 1 << " to " << dest + 1
         << " with exactly " << k << " edges: " << dist[dest];
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>> GraphM(V, vector<int>(V, 0));

    cout << "Enter the Graph:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> GraphM[i][j];
        }
    }
    vector<pair<pair<int, int>, int>> Edges;
    createEdgeList(GraphM, Edges, V);

    cout << "Enter the source node and destination node (1-" << V << "): ";
    int start, dest, k;
    cin >> start;
    cin >> dest;
    start--; // Convert to 0-based indexing
    dest--;
    cout << "Enter the number of edges on the path: ";
    cin >> k;
    bellmanFord(Edges, V, start, dest, k);

    return 0;
}
/*
0 10 3 2  
0 0 0 7  
0 0 0 6  
0 0 0 0
*/