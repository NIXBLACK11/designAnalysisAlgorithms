#include <iostream>
#include <vector>
#include <deque>
using namespace std;

bool bfs(vector<vector<int>>& Graph, int V, vector<int>& visited, vector<int>& color, int s)
{
    deque<int> queue;
    queue.push_back(s);
    visited[s] = 1;
    color[s] = 0;

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop_front();

        for (int i = 0; i < V; i++)
        {
            if (Graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                if (color[i] == -1)
                    color[i] = 1 - color[current];
                else if (color[i] == color[current])
                    return false;
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
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
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
