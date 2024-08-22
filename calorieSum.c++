#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t!=0) {
        int n, target;
        cin>>n;
        cin>>target;
        vector<int> cals(n);
        for(int i=0;i<n;i++) {
            cin>>cals[i];
        }

        vector<vector<bool>> dp(n+1, vector<bool> (target+1, false));

        for(int i=0;i<=n;i++) dp[i][0] = true;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=target;j++) {
                if(cals[i-1]<=j) dp[i][j] = dp[i-1][j] || dp[i-1][j-cals[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }

        //- - 
        //-  - - - - - - - -
        //    0 1 2 3 4 5 6 7
        //- - 1 0 0 0 0 0 0 0
        //1 - 1 1 0
        //2 - 1
        //3 - 1

        cout<<dp[n][target];

        t--;
    }
}