#include <iostream>
#include <vector>
#include <map>
using namespace std;

void slide(vector<int>& arr, int n, int k) {
    int count = 1;
    int start = 0, end = 0;
    map<int, int> m;
    while (end < n) {
        if (end - start + 1 == k) {
            if (m[arr[end]] != 0) {
                cout << "Duplicate present in window " << count << endl;
                return;
            }
            m[arr[start]]--;
            start++;
            count++;
        }
        m[arr[end]]++;
        end++;
    }
    cout << "Duplicate not present in window " << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        slide(arr, n, k);
        t--;
    }
    return 0;
}
