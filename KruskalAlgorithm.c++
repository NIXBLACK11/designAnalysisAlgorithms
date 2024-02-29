#include<iostream>
#include<vector>
#include<deque>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int, pair<int, int>>> viii;

int find(int s, vector<int>& parent)
{
    if(parent[s]<0)
    {
        return s;
    }
    return find(parent[s], parent);
}

void unionByWeight(int u, int v, vector<int>& parent)
{
    int pu = find(u, parent);
    int pv = find(v, parent);
    if(pu!=pv)
    {
        if(parent[pu]<parent[pv])
        {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else
        {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}
//TC E*log(E) 
viii Kruskal(viii Edges, int V, int E)
{
    sort(Edges.begin(), Edges.end());
    viii res;
    vector<int> parent(V, -1);
    for(int i=0;i<E;i++)
    {
        int s = Edges[i].second.first;
        int d = Edges[i].second.second;
        int w = Edges[i].first;
        if(find(s, parent) != find(d, parent))
        {
            unionByWeight(s, d, parent);
            res.push_back({w, {s, d}});
        }
    }
    return res;
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
    cout<<"Kruskal-----------------"<<endl;
    viii MST = Kruskal(Edges, V, E);
    int sum = 0;
    for(int i=0;i<MST.size();i++)
    {
        int w = MST[i].first;
        cout<<MST[i].second.first<<"-"<<MST[i].second.second<<endl;
        sum += w;
    }
    cout<<"Weight :"<<sum;
}