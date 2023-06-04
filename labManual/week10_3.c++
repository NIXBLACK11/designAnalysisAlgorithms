#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool hasMajorityElement(vector<int>& arr, int n) {
    unordered_map<int, int> counts;

    for (int i = 0; i < n; i++) {
        counts[arr[i]]++;
    }

    for (auto it = counts.begin(); it != counts.end(); it++) {
        if (it->second > n / 2) {
            return true;
        }
    }

    return false;
}

double findMedian(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    } else {
        return arr[n / 2];
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool hasMajority = hasMajorityElement(arr, n);
    double median = findMedian(arr);

    cout << (hasMajority ? "yes" : "no") << endl;
    cout << "Median of the array: " << median << endl;

    return 0;
}
