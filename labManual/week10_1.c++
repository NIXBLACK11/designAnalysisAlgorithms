#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const pair<int, pair<int, int>>& A, const pair<int, pair<int, int>>& B)
{
    return (A.second.second < B.second.second);
}

void selectActivity(vector<pair<int, pair<int, int>>>& Act, int n)
{
    int count = 1;
    vector<int> ans;
    sort(Act.begin(), Act.end(), cmp);
    int endTime = Act[0].second.second;
    ans.push_back(Act[0].first + 1);
    for (int i = 1; i < n; i++)
    {
        if (endTime <= Act[i].second.first)
        {
            count++;
            endTime = Act[i].second.second;
            ans.push_back(Act[i].first + 1);
        }
    }
    cout << "No. of non-conflicting activities: " << count << endl;
    cout << "List of selected activities: ";
    for (auto it : ans)
        cout << it << ",";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;
    vector<pair<int, pair<int, int>>> Act(n);
    cout << "Enter the start time:" << endl;
    for (int i = 0; i < n; i++)
    {
        Act[i].first = i;
        cin >> Act[i].second.first;
    }
    cout << "Enter the end time:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> Act[i].second.second;
    }
    selectActivity(Act, n);
    return 0;
}