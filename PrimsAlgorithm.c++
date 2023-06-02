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


//O(Elog(v))
vector<int> Prims(vector<vector<pair<int, int>>>& Graph, int V)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(V, INT_MAX);
    vector<int> visited(V, 0);
    vector<int> parent(V, -1);
    q.push({0, 0});
    dist[0] = 0;
    while(!q.empty())
    {
        int s = q.top().second;
        int w = q.top().first;
        q.pop();
        if(!visited[s])
        {
            visited[s] = 1;
            for(auto it : Graph[s])
            {
                int wt = it.second;
                int dest = it.first;
                if(!visited[dest] && dist[dest] > wt);
                {
                    dist[dest] = wt;
                    parent[dest] = s;
                    q.push({wt, dest});
                }
            }
        }
    }
    return parent;
}

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
    vector<int> parent = Prims(Graph, V);
    for(int i=0;i<V;i++)
    {
        cout<<"Parent of:"<<i<<"is"<<parent[i];
    }
}