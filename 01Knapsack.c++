// Recursion

KnapSack(vector<int>& weights, vector<int>& values, int n, int k)
{
    if(k==0 || n==0)
    {
        return 0;
    }
    if(weight[n-1]>k)
    {
        return KnapSack(weights, values, n-1, k);
    }
    else
    {
        return max(KnapSack(weights, values, n-1, k), values[n-1]+KnapSack(weights, values, n-1, k-weight[n-1]));
    }
}

//Dynamic programming top down

KnapSack(vector<int>& weights, vector<int>& values, int n, int k)
{
    vector<vector<int>> sol(n+1, vector<int> (k+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(i==0 || j==0)
            {
                sol[i][j] = 0;
            }
            else if(wt[i-1]>j)
            {
                sol[i][j] = sol[i-1][j];
            }
            else
            {
                sol[i][j] = max(sol[i-1][j], val[i-1]+sol[i-1][j-wt[i-1]]);
            }
        }
    }
    return sol[n][k];
}