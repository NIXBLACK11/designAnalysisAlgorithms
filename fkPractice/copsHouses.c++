#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2
// 4 20 1
// 21 22 40 41
// 2 20 1
// 75 55

int main() {
    int t;
    cin>>t;
    while(t>0) {
        int m, x, y;
        cin>>m;
        cin>>x;
        cin>>y;
        vector<int> arr(m, 0);
        for(int i=0;i<m;i++) cin>>arr[i];

        vector<pair<int, int>> interval;
        for(auto it: arr) {
            interval.push_back({it, it});
        }

        int range = x*y;
        for(auto &it: interval) {
            it.first -= range;
            if(it.first<1) it.first = 1;
            it.second += range;
            if(it.second>100) it.second = 100;
        }

        for(auto it: interval) {
            cout<<it.first<<"-"<<it.second<<endl;
        }

        // merge intervals
        int n = interval.size();
        sort(interval.begin(), interval.end());
        vector<pair<int, int>> mergedInterval;

        mergedInterval.push_back(interval[0]);
        for(int i=1;i<n;i++) {
            if(mergedInterval.back().second<interval[i].first) {
                mergedInterval.push_back(interval[i]);
            } else {
                mergedInterval.back().second = max(mergedInterval.back().second, interval[i].second);
            }
        }

        for(auto it: mergedInterval) {
            cout<<it.first<<"-"<<it.second<<endl;
        }

        // find houses not covered
        int uncoveredHouses = 0;

        if (mergedInterval[0].first > 1) {
            uncoveredHouses += mergedInterval[0].first - 1;
        }

        for (int i = 1; i < mergedInterval.size(); i++) {
            uncoveredHouses += mergedInterval[i].first - mergedInterval[i - 1].second - 1;
        }

        if (mergedInterval.back().second < 100) {
            uncoveredHouses += 100 - mergedInterval.back().second;
        }

        cout << "Total uncovered houses: " << uncoveredHouses << endl;

        t--;
    }
}