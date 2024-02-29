#include<iostream>
#include<vector>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int, pair<int, int>>> viii;

int findParent(int i, vector<int>& parent)
{
    if(parent[i]<0)
    {
        return i;
    }
    return findParent(parent[i], parent);
}

void unionEdges(int u, int v, vector<int>& parent)
{
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
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

void kruskal(viii Edges, int V)
{
    int totalWt = 0;
    sort(Edges.begin(), Edges.end());
    vector<int> parent(V, -1);
    for(auto edge:Edges)
    {
        int u = edge.second.first;
        int v = edge.second.second;
        int wt = edge.first;
        if(findParent(u, parent)!=findParent(v, parent))
        {
            unionEdges(u, v, parent);
            totalWt += wt;
        }
    }
    cout << "Minimum Spanning Weight: " << totalWt << endl;
}

int main()
{
    cout<<"Enter number of vertex: ";
    int V;
    cin>>V;
    viii Edges;
    cout<<"Enter the graph:"<<endl;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            int wt;
            cin>>wt;
            if(wt!=0)
                Edges.push_back({wt, {i, j}});
        }
    }
    kruskal(Edges, V);
    // for(auto edge:Edges)
    // {
    //     cout<<edge.first<<":"<<edge.second.first<<"->"<<edge.second.second<<",";
    // }
    return 0;
}