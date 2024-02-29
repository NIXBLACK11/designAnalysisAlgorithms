#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<char> S(n);
    for(int i=0;i<n;i++)
        cin>>S[i];
    map<char, int> m;
    for(auto it:S)
        m[it]++;
    for(auto it:m)
        cout<<it.first<<" "<<it.second<<endl;
    return 0;
}