#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void knapsack01(vector<vector<double>>& Bag, int N, double cap)
{
    double amt = 0.0;
    vector<pair<double, double>> ans;
    sort(Bag.begin(), Bag.end());
    reverse(Bag.begin(), Bag.end());
    for(auto item:Bag)
    {
        if(cap>item[2])
        {
            cap -= item[2];
            amt += item[3];
            ans.push_back({item[1]+1, item[2]});
        }
        else
        {
            amt += item[0] * cap;
            ans.push_back({item[1]+1, cap});
            cap = 0;
            break;
        }
    }
    cout<<"Maximum value : "<< fixed << setprecision(2) <<amt<<endl;
    cout<<"item-weight\n";
    for(auto it:ans)
    {
        cout<< fixed << setprecision(0) <<it.first<<"-"<<it.second<<endl;
    }
}

int main()
{
    int  N;
    cout<<"Enter the number of items:";
    cin>>N;
    vector<vector<double>> Bag(N, vector<double>(4, 0));
    cout<<"Enter the weights:"<<endl;
    for(int i=0;i<N;i++)
    {
        Bag[i][1] = i;
        cin>>Bag[i][2];
    }
    cout<<"Enter the values:"<<endl;
    for(int i=0;i<N;i++)
    {
        cin>>Bag[i][3];
        Bag[i][0] = Bag[i][3] / Bag[i][2];
    }
    cout<<"Enter the capacity:";
    double cap;
    cin>>cap;
    knapsack01(Bag, N, cap);
}

/*
Maximum value : 22.33 
6 10 3 5 1 3 item-weight 
6 2 1 8 3 5 5-1 
16 6-3 
 4-5 
 1-6 
 3-1
*/
// 6 10 3 5 1 3
// 6 2 1 8 3 5