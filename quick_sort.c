#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int l, int r)
{
    // int x = rand()%(r-l+1) + l;
    // swap(&arr[x], &arr[r]);
    int pivot = arr[r];
    int start = l;
    int end = r;
    while(start < end)
    {
        while(arr[start] <= pivot)
        {
            start ++;
        }
        while(arr[end] > pivot)
        {
            end --;
        }
        if(start < end)
        {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[end], &arr[l]);
    return end;
}

void quick_sort(int *arr, int l, int r)
{
    if(l<r)
    {
        int part = partition(arr, l, r);
        quick_sort(arr, l, part-1);
        quick_sort(arr, part+1, r);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d", arr[i]);
    }
}