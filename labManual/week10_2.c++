#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<pair<int, int>,int> p1, pair<pair<int, int>,int> p2)
{
    return p1.first.second < p2.first.second;
}


void task_selection(int N, vector<pair<pair<int, int>, int>>& tasks)
{
    sort(tasks.begin(), tasks.end(), cmp);
    vector<int> selected;
    int currentTime = 0;
    int count = 0;
    for(int i=0;i<N;i++)
    {
        int time = tasks[i].first.first; 
        int deadline = tasks[i].first.second;
        int number = tasks[i].second;

        if(currentTime+time <= deadline)
        {
            currentTime += time;
            count++;
            selected.push_back(number);
        }
    }
    cout << "No. of non-conflicting  tasks : " << count << endl;
    cout << "List of selected tasks : ";
    for(int i:selected)
        cout  << i+1 << " ";
    cout << "\n";
}

int main()
{
    int N;
    cin >> N;
    vector<pair<pair<int, int>, int>> tasks(N);
    for(int i=0;i<N;i++)
    {
        cin >> tasks[i].first.first;
        tasks[i].second = i;
    }
    for(int i=0;i<N;i++)
    {
        cin >> tasks[i].first.second;
    }
    
    task_selection(N, tasks);
}