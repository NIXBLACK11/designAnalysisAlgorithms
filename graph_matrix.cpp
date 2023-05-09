#include<iostream>
#include<vector>
#include <deque>
using namespace std;

void addEdge(vector<vector<int>> &Graph, vector<pair<int, int>> &Edges)
{
    for(auto edge:Edges)
    {
        Graph[edge.first][edge.second] = 1; 
    }
}

void display(vector<vector<int>>& Graph, int v)
{
    cout<<"----------------------"<<endl;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<Graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Complexity of BFS algorithm

// Time complexity of BFS depends upon the data structure used to represent the graph. The time complexity of BFS algorithm is O(V+E), since in the worst case, BFS algorithm explores every node and edge. In a graph, the number of vertices is O(V), whereas the number of edges is O(E).

// The space complexity of BFS can be expressed as O(V), where V is the number of vertices.

void BFS(vector<vector<int>>& Graph, int s, int v)
{
    deque<int> queue;
    vector<int> visited(v, 0);
    visited[s] = 1;
    queue.push_back(s);
    while(!queue.empty())
    {
        int vertex = queue.front();
        cout<<vertex<<",";
        queue.pop_front();
        for(int i=0;i<v;i++)
        {
            if(Graph[vertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue.push_back(i);
            }
        }
    }
}

int main()
{
    int v, e;
    cout<<"Enter the number of vertices :";
    cin>>v;
    cout<<"Enter the number of edges :";
    cin>>e;
    vector<vector<int>> Graph(v, vector<int> (v, 0)) ;
    vector<pair<int, int>> Edges;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter the vertices:";
        int s, d;
        cin>>s;
        cin>>d;
        Edges.push_back({s,d});
    }
    addEdge(Graph, Edges);
    display(Graph,v);
    cout<<"BFS"<<endl;
    cout<<"Enter the source :"<<endl;
    int s;
    cin>>s;
    BFS(Graph, s, v);
}