#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 2499. Minimum Total Cost to Make Arrays Unequal

int minimumCost(vector<int>& group1, vector<int>& group2) {
    int n = group1.size();
    int totalCost = 0;
    vector<bool> visited(n, false); // Track visited positions
    
    for (int i = 0; i < n; ++i) {
        if (group1[i] == group2[i]) {
            int minCost = INT_MAX;
            int swapIndex = -1;
            
            // Try to find a swap that makes group1[i] != group2[i]
            for (int j = 0; j < n; ++j) {
                if (i != j && !visited[j] && group1[j] != group2[i] && group1[i] != group2[j]) {
                    int cost = i + j;
                    if (cost < minCost) {
                        minCost = cost;
                        swapIndex = j;
                    }
                }
            }
            
            if (swapIndex == -1) {
                // If no valid swap is found
                return -1;
            } else {
                // Perform the swap and add to the total cost
                swap(group1[i], group1[swapIndex]);
                totalCost += minCost;
                visited[swapIndex] = true; // Mark swap position as visited
            }
        }
    }
    
    return totalCost;
}

int minimumCost(vector<int>& group1, vector<int>& group2) {
    int n = group1.size();
    unordered_map<int, vector<int>> posGroup1, posGroup2;
    vector<int> cost; // Store the cost of required swaps

    // Build mappings for positions in both groups
    for (int i = 0; i < n; ++i) {
        posGroup1[group1[i]].push_back(i);
        posGroup2[group2[i]].push_back(i);
    }

    // Check for the mismatches and compute the required cost
    int totalCost = 0;
    for (int i = 0; i < n; ++i) {
        if (group1[i] == group2[i]) {
            bool swapped = false;
            // Try to find a position to swap
            for (int pos : posGroup2[group1[i]]) {
                if (posGroup1[group2[pos]].size() > 0) {
                    int swapPos = posGroup1[group2[pos]].back();
                    posGroup1[group2[pos]].pop_back();
                    totalCost += i + swapPos;
                    swap(group1[i], group1[swapPos]);
                    swapped = true;
                    break;
                }
            }
            if (!swapped) {
                return -1; // Impossible to resolve the mismatch
            }
        }
    }
    
    return totalCost;
}

int main() {
    int numGroup1, numGroup2;
    cin >> numGroup1;
    vector<int> group1(numGroup1);
    for (int i = 0; i < numGroup1; ++i) {
        cin >> group1[i];
    }

    cin >> numGroup2;
    vector<int> group2(numGroup2);
    for (int i = 0; i < numGroup2; ++i) {
        cin >> group2[i];
    }

    if (numGroup1 != numGroup2) {
        cout << -1 << endl;
    } else {
        int result = minimumCost(group1, group2);
        cout << result << endl;
    }

    return 0;
}
