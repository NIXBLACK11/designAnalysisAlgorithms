#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(vector<int> arr)
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

int main()
{
    vector<int> arr={2,4,6,3,5,9};
    bubbleSort(arr, 6);
    print(arr, 6);
}