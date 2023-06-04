#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, pair<int, int>>& A, const pair<int, pair<int, int>>& B)
{
    return (A.second.first > B.second.first);
}

void selectActivity(vector<pair<int, pair<int, int>>>& Act, int n, int MaxTime)
{
    int count = 1;
    vector<int> ans;
    vector<int> Time(maxTime, 0);
    sort(Act.begin(), Act.end(), cmp);
    for(auto it:Act)
    {
        int deadLine = it.second.second;
        int time = it.second.first;
        int task = it.first;
        if(Time[deadLine-1]==0)
        {
            
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;
    int maxTime = 0;
    vector<pair<int, pair<int, int>>> Act(n);
    cout << "Enter the time to complete:" << endl;
    for (int i = 0; i < n; i++)
    {
        Act[i].first = i;
        cin >> Act[i].second.first;
    }
    cout << "Enter the deadline:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> Act[i].second.second;
        maxTime = max(maxTime, Act[i].second.second);
    }
    selectActivity(Act, n, maxTime);
    return 0;
}