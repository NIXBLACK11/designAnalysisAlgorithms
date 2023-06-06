#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void print(vector<int>& arr, int n)
{
    for(auto it:arr)
    {
        cout<<it<<",";
    }
}

void bubbleSort(vector<int>& arr, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void merge(vector<int>& arr, int l, int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    vector<int> L, R;
    for(int i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j]=arr[m+j+1];
    }
    int i=0, j=0, k=l;
    while(i < n1 && j < n2)
    {
        if(L[i]<R[j])
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    while(i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while(j < n2)
    {
        arr[k] = L[j];
        k++;
        j++;
    }
}

void mergeSort(vector<int>& arr, int l, int r)
{
    if(l<=r)
    {
        int m = (l+r)/2;//r-l/2+l
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n, 0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // bubbleSort(arr, n);
    mergeSort(arr, 0, n-1);
    print(arr, n);
}