#include <iostream>
#include <vector>

using namespace std;

int knapsack(int n, vector<int>& wt, vector<int>& val, int k) {
    vector<vector<int>> sol(n + 1, vector<int>(k + 1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i == 0 || j == 0) {
                sol[i][j] = 0;
            } else if (wt[i - 1] > j) {
                sol[i][j] = sol[i - 1][j];
            } else {
                sol[i][j] = max(sol[i - 1][j], val[i - 1] + sol[i - 1][j - wt[i - 1]]);
            }
        }
    }

    int maxVal = sol[n][k];
    vector<int> selectedItems;

    int i = n, j = k;
    while (i > 0 && j > 0) {
        if (sol[i][j] != sol[i - 1][j]) {
            selectedItems.push_back(i);
            j -= wt[i - 1];
        }
        i--;
    }

    cout << "Selected items: ";
    for (int i = selectedItems.size() - 1; i >= 0; i--) {
        cout << selectedItems[i] << " ";
    }
    cout << endl;

    return maxVal;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> wt(n);
    vector<int> val(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int maxVal = knapsack(n, wt, val, capacity);
    cout << "Maximum value: " << maxVal << endl;

    return 0;
}
