#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

void printMat(vector<vector<int>>& Graph, int V)
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(Graph[i][j]==INT_MAX)
                cout<<"INF  ";
            else
                cout<<Graph[i][j]<<"    ";
        }
        cout<<endl;
    }
}

void floydWarshall(vector<vector<int>>& Graph, int V)
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            for(int k=0;k<V;k++)
            {
                if(Graph[i][k]!=INT_MAX && Graph[k][j]!=INT_MAX && Graph[i][j]>Graph[i][k]+Graph[k][j])
                {
                    Graph[i][j] = Graph[i][k]+Graph[k][j];
                }
            }
        }
    }
}

int main()
{
    int V;
    cout<<"Enter the number of vertices:";
    cin>>V;
    vector<vector<int>> Graph(V, vector<int> (V, 0));
    cout<<"Enter the matrix:"<<endl;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            string wt;
            int val;
            cin>>wt;
            if(wt=="INF")
                val = INT_MAX;
            else
                val = stoi(wt);
            Graph[i][j] = val;
        }
    }
    printMat(Graph, V);
    floydWarshall(Graph, V);
    printMat(Graph, V);
    return 0;
}

/*
0 10 5 5 INF 
INF 0 5 5 5 
INF INF 0 INF 10 
INF INF INF 0 20 
INF INF INF 5 0
*/
/*
0    10    5    5    15
INF  0    5    5    5
INF  INF  0    15    10
INF  INF  INF  0    20
INF  INF  INF  5    0  

*/

