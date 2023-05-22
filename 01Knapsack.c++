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