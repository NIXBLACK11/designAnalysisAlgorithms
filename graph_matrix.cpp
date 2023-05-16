#include<iostream>
#include<vector>
#include <deque>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &Graph, vector<pair<int, int>> &Edges)
{
    for(auto edge:Edges)
    {
        Graph[edge.first][edge.second] = 1; 
    }
}

void createGraph(vector<vector<int>> &Graph, vector<vector<int>> &Edges, int v)
{
    for(auto edge:Edges)
    {
        Graph[edge[1]][edge[2]] = edge[0];
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


// The time complexity of the DFS algorithm is O(V+E), where V is the number of vertices and E is the number of edges in the graph.

// The space complexity of the DFS algorithm is O(V).

void DFS(vector<vector<int>>& Graph, int s, int v, vector<int>& visited)
{
    visited[s] = 1;
    cout<<s<<",";
    for(int i=0;i<v;i++)
    {
        if(Graph[s][i] == 1 && !visited[i])
        {
            DFS(Graph, i, v, visited);
        }
    }
}

void TraverseDFS(vector<vector<int>>& Graph, int s, int v, vector<int>& visited, stack<int>& Stack)
{
    visited[s] = 1;
    for(int i=0;i<v;i++)
    {
        if(Graph[s][i]==1 && !visited[i])
        {
            TraverseDFS(Graph, i, v, visited, Stack);
        }
    }
    Stack.push(s);
}

// Time Complexity: O(V+E). The above algorithm is simply DFS with an extra stack. So time complexity is the same as DFS

// Auxiliary space: O(V). The extra space is needed for the stack

// Note: Here, we can also use a vector instead of the stack. If the vector is used then print the elements in reverse order to get the topological sorting.

void TopologicalSort(vector<vector<int>>& Graph, int v)
{
    vector<int> visited(v, 0);
    stack<int> Stack;

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            TraverseDFS(Graph, i, v, visited, Stack);
        }
    }
    while(!Stack.empty())
    {
        cout<<Stack.top()<<",";
        Stack.pop();
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
    // display(Graph,v);
    // cout<<"\nBFS-----------------------------------"<<endl;
    // cout<<"Enter the source :"<<endl;
    // int s;
    // cin>>s;
    // BFS(Graph, s, v);
    // cout<<"\nDFS-----------------------------------"<<endl;
    // vector<int> visited(v, 0);
    // DFS(Graph, s, v, visited);
    cout<<"\nTopological---------------------------"<<endl;
    TopologicalSort(Graph, v);

}

// DFS
//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 2);
//     g.addEdge(2, 0);
//     g.addEdge(2, 3);
//     g.addEdge(3, 3);

// TopologicalSort
// Graph g(6);
//     g.addEdge(5, 2);
//     g.addEdge(5, 0);
//     g.addEdge(4, 0);
//     g.addEdge(4, 1);
//     g.addEdge(2, 3);
//     g.addEdge(3, 1);

// 5 4 2 3 1 0 