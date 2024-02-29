#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int totalCost = 0;
    for (int i = 1; i < n; i++) {
        int cost = arr[i-1] + arr[i];
        totalCost += cost;
        
        arr[i] = cost;
    }
    
    cout << "Minimum computation cost required to merge all the elements: " << totalCost << endl;
    
    return 0;
}