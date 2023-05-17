#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool cmp(pair<int, int>& A, pair<int, int>& B)
{
    return A.second <= B.second;
}

void ASP(vector<pair<int, int>>& Tasks, int n)
{
    sort(Tasks.begin(), Tasks.end(), cmp);
    int endTime = -1;
    int count = 0;
    for(auto it:Tasks)
    {
        if(it.first>endTime)
        {
            count++;
            endTime = it.second;
            it.first = INT_MIN;
        }
    }
    cout<<"Count:"<<count<<endl;
}

int main()
{
    cout<<"Enter the number of tasks:"<<endl;
    int n;
    cin>>n;
    vector<pair<int, int>> Tasks;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the start time:"<<endl;
        int s, e;
        cin>>s;
        cout<<"Enter the end time:"<<endl;
        cin>>e;
        Tasks.push_back({s, e});
    }
    while()
    ASP(Tasks, n);
}