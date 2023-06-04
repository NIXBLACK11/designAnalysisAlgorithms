#include<vector>
using namespace std;

void slide(vector<int>&  arr, int n, int k)
{
    
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n, k;
        cin>>n;
        vector<int> arr(n, 0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        slide(arr, n, k);
        t--;
    }
}