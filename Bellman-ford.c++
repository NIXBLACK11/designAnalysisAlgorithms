#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void Bellman_ford( pair<int, int>>>& Edges, int v, int e, int src)
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

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        int e = flights.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> nextDist(dist);
            for (int j = 0; j < e; j++) {
                int s = flights[j][0];
                int d = flights[j][1];
                int w = flights[j][2];

                if (dist[s] != INT_MAX && dist[s] + w < nextDist[d]) {
                    nextDist[d] = dist[s] + w;
                }
            }
            dist = nextDist;
        }
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
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
