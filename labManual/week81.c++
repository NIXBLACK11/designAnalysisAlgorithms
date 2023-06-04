#include<iostream>
#include<vector>
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
                Graph[i].push_back(make_pair(j, GraphM[i][j]));
                Graph[j].push_back(make_pair(i, GraphM[i][j])); // Add this line for an undirected graph
            }
        }
    }
}

void prims(vector<vector<pair<int, int>>>& Graph, int V)
{
    vector<int> parent(V, -1);
    vector<bool> visited(V, 0);
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty())
    {
        int src = pq.top().second;
        pq.pop();
        if(visited[src]==0)
        {
            visited[src] = 1;
            for (auto it : Graph[src])
            {
                int dest = it.first;
                int weight = it.second;
                if (!visited[dest] && dist[dest] > weight)
                {
                    dist[dest] = weight;
                    parent[dest] = src;
                    pq.push({weight, dest});
                }
            }
        }
    }
    int totalDist = 0;
    for (auto it : dist)
    {
        totalDist += it;
    }
    cout << "Minimum Spanning Weight: " << totalDist << endl;
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

    prims(Graph, V);
    return 0;
}
