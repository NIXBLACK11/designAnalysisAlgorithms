#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int, pair<int, int>>> viii;

void createGraph(viii Edges, vector<vector<pair<int, int>>>& Graph)
{
    for(auto it:Edges)
    {
        Graph[it.second.first].push_back({it.second.second, it.first});
    }
}

void Djiktras(vector<vector<pair<int, int>>>& Graph, int V)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(V, INT_MAX);
    vector<int> visited(V, 0);
    vector<int> parent(V, -1);
    q.push({0, 0});
    while(!q.empty())
    {
        int s = q.top().second;
        int w = q.top().first;
        if(!visited[s])
        {
            visited[s] = 1;
            for(auto it : Graph[s])
            {
                int wt = (*it).second;
                int dest = (*it).firts;
                if(!visited[dest] && dist[dest] > wt+dist[s]);
                {
                    dist[dest] = wt+dist[s];
                    parent[dest] = s;
                    q.push_back({wt, dest});
                }
            }
        }
    }
}

// network 
class Solution {
public:
    int Djikstras(vector<vector<pair<int, int>>>& Graph, int V, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> dist(V, INT_MAX);
        vector<int> visited(V, 0);
        int ans = 0;
        q.push({0, k});
        dist[k] = 0;
        
        while (!q.empty()) {
            int s = q.top().second;
            int w = q.top().first;
            q.pop();
            
            if (!visited[s]) {
                visited[s] = 1;
                ans = max(ans, w);
                
                for (auto it : Graph[s]) {
                    int dest = it.first;
                    int wt = it.second;
                    
                    if (!visited[dest] && dist[dest] > wt + dist[s]) {
                        dist[dest] = wt + dist[s];
                        q.push({dist[dest], dest});
                    }
                }
            }
        }
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return -1; // Indicates that not all nodes are reachable
            }
        }
        
        return ans;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int V, int k) {
        vector<vector<pair<int, int>>> Graph(V, vector<pair<int, int>>());
        
        for (auto it : times) {
            Graph[it[0] - 1].push_back({it[1] - 1, it[2]}); // Adjusting node indices to 0-based
        }
        
        return Djikstras(Graph, V, k - 1); // Adjusting node index to 0-based
    }
};

int main()
{
    int V, E;
    cout<<"Enter the number of vertices and edges:"<<endl;
    cin>>V;
    cin>>E;
    viii Edges;
    for(int i=0;i<E;i++)
    {
        cout<<"Enter the vertices:";
        int s, d, w;
        cin>>s;
        cin>>d;
        cout<<"Enter the weight:";
        cin>>w;
        Edges.push_back({w, {s, d}});
    }
    vector<vector<pair<int, int>>> Graph(V, vector<pair<int, int>>(/* columns */));
    createGraph(Edges, Graph);
    Djiktras(Graph, V);
}