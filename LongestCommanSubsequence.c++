#include<iostream>
using namespace std;
int main()
{
    string s1
}

//Recursive solution TC-2^(min(n,m)) SC-2^(min(m,n))
class Solution {
public:
    int recur(string s1, string s2, int n, int m)
    {
        if(n<0 || m<0)
        {
            return 0;
        }
        if(s1[n]==s2[m])
        {
            return 1+recur(s1, s2, n-1, m-1);
        }
        else
        {
            return max(recur(s1, s2, n-1, m), recur(s1, s2, n, m-1));
        }
    }

    int longestCommonSubsequence(string s1, string s2) {
        return recur(s1, s2, s1.size()-1, s2.size()-1);
    }
};

//Dynamic programming bottom up approach
class solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        // return recur(s1, s2, s1.size()-1, s2.size()-1);
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] = 0;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
}