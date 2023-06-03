#include<iostream>
#include<vector>
#include<deque>
using namespace std;

bool bfs(vector<vector<int>>& Graph, int V, vector<int>& visited, vector<int>& color, int s)
{
    deque<int> queue;
    queue.push_back(s);
    visited[s] = 1;
    color[s] = 0;
    
    while (!queue.empty())
    {
        int s = queue.front();
        queue.pop_front();
        
        for (int i = 0; i < V; i++)
        {
            if (Graph[s][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                if (Graph[i][s] == 1 && color[i] == color[s])  // Check if there is an edge between s and i and if they have the same color
                    return false;
                if(color[i]==0)
                    color[s] = 1;
                else
                    color[s] = 0;
                queue.push_back(i);
            }
        }
    }
    
    return true;
}

int main()
{
    cout << "Enter the number of vertices: ";
    int V;
    cin >> V;
    vector<vector<int>> Graph(V, vector<int>(V, 0));
    vector<int> visited(V, 0);
    vector<int> color(V, -1);
    
    cout << "Enter the Graph:\n";
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> Graph[i][j];
        }
    }

    if (bfs(Graph, V, visited, color, 0))
        cout << "Graph is bipartite.";
    else
        cout << "Graph is not bipartite.";
    
    return 0;
}