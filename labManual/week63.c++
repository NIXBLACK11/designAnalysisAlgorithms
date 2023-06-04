#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int>>& Graph, int V, int s, vector<int>& visited)
{
    visited[s] = 1;
    for(int i = 0; i < V; i++)
    {
        if(Graph[s][i] == 1 && !visited[i])
        {
            if(dfs(Graph, V, i, visited))
                return true;
        }
        else if(Graph[s][i] == 1 && visited[i])
            return true;
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

    bool hasCycle = false;
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(dfs(Graph, V, i, visited))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if(hasCycle)
        cout << "Cycle exists.";
    else
        cout << "No cycle exists.";

    return 0;
}
