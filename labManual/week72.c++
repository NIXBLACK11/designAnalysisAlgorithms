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

void printPath(vector<int>& parent, int i)
{
    cout << " " << i + 1;
    if (parent[i] == -1)
    {
        return;
    }
    printPath(parent, parent[i]);
}

void bellmanFord(vector<pair<pair<int, int>, int>>& Edges, int V, int start)
{
    int E = Edges.size();
    vector<int> parent(V, -1);
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int source = Edges[j].first.first;
            int dest = Edges[j].first.second;
            int weight = Edges[j].second;
            if (dist[source] != INT_MAX && dist[dest] > dist[source] + weight)
            {
                dist[dest] = dist[source] + weight;
                parent[dest] = source;
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "N/A" << endl;
        }
        else
        {
            printPath(parent, i);
            cout << " : " << dist[i] << endl;
        }
    }
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

    cout << "Enter the source node (1-" << V << "): ";
    int start;
    cin >> start;
    start--; // Convert to 0-based indexing

    bellmanFord(Edges, V, start);

    return 0;
}
/*
0 4 1 0 0 
0 0 0 0 4 
0 2 0 4 0 
0 0 0 0 4 
0 0 0 0 0 
*/