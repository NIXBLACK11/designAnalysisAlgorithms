#include <iostream>
#include <vector>
using namespace std;

string partitionSet(vector<int>& arr)
{
    int n = arr.size();
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }

    if (totalSum % 2 != 0)
    {
        return "no";
    }

    int targetSum = totalSum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

    for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= targetSum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i-1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][targetSum] ? "yes" : "no";
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements of the set: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    string result = partitionSet(arr);
    cout << result << endl;

    return 0;
}
