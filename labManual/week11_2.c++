#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for(int coin : coins)
    {
        for(int val=coin; val<=amount; val++)
        {
            dp[val] += dp[val-coin];
        }
    }
    return dp[amount];
}

int main()
{
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;
    cout << "Enter the values of the coins:" << endl;
    vector<int> coins(n);
    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << "Enter the value to make: ";
    int val;
    cin >> val;
    int ways = coinChange(coins, val);
    cout << "Number of ways to make " << val << ": " << ways << endl;
    return 0;
}
