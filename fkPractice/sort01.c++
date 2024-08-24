#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Function to calculate the number of 1s and 0s in a string
pair<int, int> countOnesAndZeros(const string& s) {
    int ones = 0, zeros = 0;
    for (char c : s) {
        if (c == '1') ones++;
        else if (c == '0') zeros++;
    }
    return {ones, zeros};
}

// Function to find the maximum number of strings
int maxStrings(vector<string>& strings, int X, int Y) {
    // Vector to store the counts of ones and zeros for each string
    vector<pair<int, int>> counts;
    for (const string& s : strings) {
        counts.push_back(countOnesAndZeros(s));
    }

    // Sort strings based on the total count of 1s and 0s (ascending)
    sort(counts.begin(), counts.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first + a.second < b.first + b.second;
    });

    int totalOnes = 0, totalZeros = 0, numStrings = 0;

    // Greedily add strings until constraints are violated
    for (const auto& [ones, zeros] : counts) {
        if (totalOnes + ones < X && totalZeros + zeros < Y) {
            totalOnes += ones;
            totalZeros += zeros;
            numStrings++;
        } else {
            break;
        }
    }

    return numStrings;
}

int main() {
    int numStrings, X, Y;
    cin >> numStrings;
    
    vector<string> strings(numStrings);
    for (int i = 0; i < numStrings; ++i) {
        cin >> strings[i];
    }

    cin >> X >> Y;
    
    cout << maxStrings(strings, X, Y) << endl;

    return 0;
}
