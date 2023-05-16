#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void Bellman_ford(vector<pair<int, pair<int, int>>>& Edges, int v, int e, int src)
{
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    for(int i = 1; i <= v - 1; i++)
    {
        for(int j = 0; j < e; j++)
        {
            int s = Edges[j].second.first;
            int d = Edges[j].second.second;
            int w = Edges[j].first;

            if(dist[s] != INT_MAX && dist[s] + w < dist[d])
            {
                dist[d] = dist[s] + w;
            }
        }
    }

    for(int j = 0; j < e; j++)
    {
        int s = Edges[j].second.first;
        int d = Edges[j].second.second;
        int w = Edges[j].first;

        if(dist[s] != INT_MAX && dist[s] + w < dist[d])
        {
            cout << "Negative cycle present!";
            return;
        }
    }

    for(int i = 0; i < v; i++)
    {
        cout << i << "--" << dist[i] << endl;
    }
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<pair<int, pair<int, int>>> Edges;
    for(int i = 0; i < e; i++)
    {
        cout << "Enter the vertices: ";
        int s, d, w;
        cin >> s >> d;
        cout << "Enter the weight: ";
        cin >> w;
        Edges.push_back({w, {s, d}});
    }

    cout << "Enter the source: ";
    int src;
    cin >> src;

    Bellman_ford(Edges, v, e, src);
    return 0;
}
