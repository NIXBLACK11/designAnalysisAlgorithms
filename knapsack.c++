#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> values(n, vector<int> (3));
    for(int i=0;i<n;i++)
    {
        int a, b, c;
        cin>>a;
        cin>>b;
        values[i][1] = a;
        values[i][2] = b;
        values[i][0] = a/b;
    }
    sort(values.begin(), values.end());
    int capacity = 50, profit = 0;
    for(auto it:values)
    {
        if(it[1]<capacity)
        {
            profit += it[1];
            capacity += it[0];
        }
        else{
            profit += (capacity*it[0]);
            capacity = 0;
        }
    }
    cout<<profit;
}