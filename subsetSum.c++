#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Recursive solution O(2^n)
    bool recursion(vector<int>& s, int n, int w)
    {
        if (w == 0)
            return true;
        if (n == 0)
            return false;
        if (s[n - 1] > w)
        {
            return recursion(s, n - 1, w);
        }
        else
        {
            return recursion(s, n - 1, w) || recursion(s, n - 1, w - s[n - 1]);
        }
    }

    // Dynamic programming bottom-up O(n*w)
    bool dynamic(vector<int>& s, int n, int w)
    {
        vector<vector<bool>> dp(n + 1, vector<bool>(w + 1, false));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                if (j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else if (s[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - s[i - 1]];
            }
        }
        return dp[n][w];
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    vector<int> s(n, 0);
    cout << "Enter the array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int w;
    cout << "Enter the weight: " << endl;
    cin >> w;
    Solution ob;
    cout << "Ans by recursion: " << ob.recursion(s, n, w) << endl;
    cout << "Ans by dynamic programming: " << ob.dynamic(s, n, w) << endl;
    return 0;
}
