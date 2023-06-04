#include<iostream>
#include<vector>
using namespace std;

void mcm(vector<int>& p, int n)
{
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
 
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
 
    cout<<m[1][n - 1];
}

int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> p(n+1, 0);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            cin>>p[0];
            cin>>p[1];
        }
        else
        {
            int temp;
            cin>>temp;
            cin>>p[i+1];
        }
    }
    for(auto it:p)
        cout<<it<<",";
    mcm(p, n+1);
}