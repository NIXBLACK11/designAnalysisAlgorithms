#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void createGraph(vector<vector<int>>& Graph, int E, vector<pair<int, int>> Edges)
{
    for(auto it:Edges)
    {
        Graph[it.first].push_back(it.second);
    }
}

void bfs(vector<vector<int>>& Graph, int V)
{
    vector<int> visited(V, 0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        cout<<s<<"->";
        for(auto it:Graph[s])
        {
            if(!visited[it])
            {
                visited[it];
                q.push(it);
            }
        }
    }
}

void prims(vector<vector<int>>& Graph)
{
    priority_queue<pair<int, int>>, vector<int, int>, greater<int, int> q;
    vector<int> vis(V, 0);
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    q.push({0, 0});
    vis[0] = 1;
    while(!q.empty())
    {
        int s = q.front().second;
        q.pop();
        if(!vis[s])
        {
            vis[s] = 1;
            for(auto it:Graph[s])
            {
                int d = it;
                
            }
        }
    }
}

void dfs(vector<vector<int>>& Graph, vector<int>& visited, int i)
{
    visited[i] = 1;
    cout<<i<<"->";
    for(auto it:Graph[i])
    {
        if(!visited[it])
        {
            dfs(Graph, visited, it);
        }
    }
}

int main()
{
    int V, E;
    cout<<"Enter the vertices:";
    cin>>V;
    cout<<"Enter the edges:";
    cin>>E;
    vector<pair<int, int>> Edges;
    cout<<"Enter the edges:"<<endl;
    for(int i=0;i<E;i++)
    {
        int src, dest;
        cout<<"Enter the source:";
        cin>>src;
        cout<<"Enter the destination:";
        cin>>dest;
        Edges.push_back({src, dest});
    }
    vector<vector<int>> Graph;
    vector<int> visited(V, 0);
    createGraph(Graph, E, Edges);
    dfs(Graph, visited, 0);
    bfs(Graph, V);
}