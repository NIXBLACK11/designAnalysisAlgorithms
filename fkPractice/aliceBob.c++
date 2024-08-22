#include <iostream>
#include <vector>

using namespace std;

string find_winner(int N) {
    // Use a DP array to store winning or losing status for first few chocolates
    vector<bool> dp(10, false);

    // Calculate the result for first 10 chocolates
    for (int i = 1; i <= 9; ++i) {
        if (i - 1 >= 0 && !dp[i - 1]) dp[i] = true;
        if (i - 2 >= 0 && !dp[i - 2]) dp[i] = true;
        if (i - 5 >= 0 && !dp[i - 5]) dp[i] = true;
    }

    // Determine the winner for given N using the period pattern
    if (dp[N % 10]) {
        return "Bob";
    } else {
        return "Alice";
    }
}

int main() {
    int N;
    cin >> N;

    // Output the result
    cout << find_winner(N) << endl;

    return 0;
}