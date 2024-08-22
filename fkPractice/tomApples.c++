#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.geeksforgeeks.org/maximum-number-of-apples-that-can-be-eaten-by-a-person/
// Comparator function to sort apples by expiration date
bool compareByExpiration(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> apples(N);
    
    // Reading the input
    for (int i = 0; i < N; ++i) {
        int pd, d;
        cin >> pd >> d;
        apples[i] = make_pair(pd, d);
    }
    
    // Sort apples based on expiration date (ascending)
    sort(apples.begin(), apples.end(), compareByExpiration);
    
    // Output the production numbers in the sorted order
    for (const auto& apple : apples) {
        cout << apple.first << " ";
    }
    
    cout << endl;
    
    return 0;
}
