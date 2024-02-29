#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int>>& Graph, int V, int s, int d, vector<int>& visited)
{
    visited[s] = 1;
    cout<<s<<"->";
    if(s == d)
        return true;
    
    for(int i = 0; i < V; i++)
    {
        if(Graph[s][i] && !visited[i])
        {
            return dfs(Graph, V, i, d, visited);
        }
    }
    
    return false;
}

int main()
{
    cout << "Enter the number of vertices: ";
    int V;
    cin >> V;
    vector<vector<int>> Graph(V, vector<int>(V, 0));
    vector<int> visited(V, 0);
    
    cout << "Enter the Graph:\n";
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> Graph[i][j];
        }
    }
    
    cout << "Enter the start and end point: ";
    int s, d;
    cin >> s >> d;
    
    if(dfs(Graph, V, s-1, d-1, visited))
        cout << "Yes, Path Exists";
    else
        cout << "No Such Path Exists";
        
    return 0;
}
