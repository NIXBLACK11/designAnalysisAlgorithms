#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    vector<int> a = {1,2,3,6,10,12,15};//n=5  1,5,84,209,341  1,2,3,6,10,12,15  24,28,48,71,86,,89,92,120,194,201
    int n = a.size();
    map<int, int> map;
    int val = 0;
    for(int i = 0;i<n;i++)
    {
        val = a[i];
        map[val] = i+1;
    }
    val = 0;
    for(int i = 0;i<n;i++)
    {
        for(int  j = 0;j<n-1;j++)
        {
            val = a[i] - a[j];
            if(map[val]!=0 && map[val]-1 != i && map[val]-1!=j)
            {
                cout<<a[j]<<"+"<<val<<"="<<a[i]<<endl;
                cout<<j<<" "<<map[val]-1<<" "<<i<<endl;
                break;
            }
        }
    }

}