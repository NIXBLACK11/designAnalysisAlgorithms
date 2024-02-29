#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void createGraph(const vector<vector<int>>& GraphM, vector<vector<pair<int, int>>>& Graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (GraphM[i][j] != 0)
            {
                Graph[i].push_back({j, GraphM[i][j]});
            }
        }
    }
}

void printPath(vector<int>& parent, int i)
{
    cout<<i+1<<" ";
    if(parent[i]==-1)
        return;
    printPath(parent, parent[i]);
}

void dijkstra(vector<vector<pair<int, int>>>& Graph, int V, int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    vector<int> visited(V, 0);
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    queue.push({0, start});
    dist[start] = 0;
    
    while (!queue.empty())
    {
        int source = queue.top().second;
        queue.pop();
        if (!visited[source])
        {
            visited[source] = 1;
            for (auto it : Graph[source])
            {
                int dest = it.first;
                int weight = it.second;
                if (!visited[dest] && dist[dest] > weight + dist[source])
                {
                    dist[dest] = weight + dist[source];
                    parent[dest] = source;
                    queue.push({dist[dest], dest});
                }
            }
        }
    }

    // Print shortest path distances and parent nodes
    for (int i = 0; i < V; i++)
    {
        printPath(parent, i);
        cout<<": "<<dist[i]<<endl;
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
    vector<vector<pair<int, int>>> Graph(V, vector<pair<int, int>>());
    createGraph(GraphM, Graph, V);
    
    cout << "Enter the source node (1-" << V << "): ";
    int start;
    cin >> start;
    start--; // Convert to 0-based indexing
    
    dijkstra(Graph, V, start);
    
    return 0;
}
/*
0 4 1 0 0 
0 0 0 0 4 
0 2 0 4 0 
0 0 0 0 4 
0 0 0 0 0 
*/