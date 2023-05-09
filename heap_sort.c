#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i)
{
    int c1 = i*2+1;
    int c2 = i*2+2;
    int max = i;
    if(c1<n && arr[c1]>arr[max])
    {
        max = c1;
    }
    if(c2<n && arr[c2]>arr[max])
    {
        max = c2;
    }
    if(max!=i)
    {
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}

void heap_sort(int *arr, int n)
{
    for(int i = n/2; i>=0;i--)
    {
        heapify(arr, n, i);
    }

    for(int i = n-1;i>=0;i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
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
    heap_sort(arr, n);
    for(int i=0;i<n;i++)
    {
        printf("%d", arr[i]);
    }
}