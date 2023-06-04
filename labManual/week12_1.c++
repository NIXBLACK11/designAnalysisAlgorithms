#include <iostream>
#include <vector>
using namespace std;

string lcs(string s1, string s2, int n1, int n2)
{
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int i=0; i<=n1; i++)
    {
        for(int j=0; j<=n2; j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    // Building the LCS string
    string lcsString = "";
    int i = n1, j = n2;
    while (i > 0 && j > 0)
    {
        if (s1[i-1] == s2[j-1])
        {
            lcsString = s1[i-1] + lcsString;
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    
    return lcsString;
}

int main()
{
    cout << "Enter the strings: " << endl;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    string lcsString = lcs(s1, s2, s1.size(), s2.size());
    cout << "Longest Common Subsequence: " << lcsString << endl;
    return 0;
}
/*

AGGTAB
GXTXAYB
*/