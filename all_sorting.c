#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d,", arr[i]);
    }
}

void bubbleSort(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int *arr, int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

void insertionSort(int *arr, int n)
{
    for(int i = 1;i<n;i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int partition(int *arr, int l, int r)
{
    int x = rand()%(r-l+1) + l;
    swap(&arr[x], &arr[r]);
    int pivot = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}

void quickSort(int *arr, int l, int r)
{
    if(l<r)
    {
        int part = partition(arr, l, r);
        quickSort(arr, l, part-1);
        quickSort(arr, part+1, r);
    }
}

void merge(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i] = arr[l + i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j] = arr[m + j + 1];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(L[i]<=R[j])
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
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(int *arr, int l, int r)//best O(nlog(n)), average O(nlog(n)), worst O(nlog(n))
{
    if(l<r)
    {
        int m = (l+r)/2;//l+(r-l)/2
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void heapify(int *arr, int i, int n)
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
        swap(&arr[max], &arr[i]);
        heapify(arr, max, n);
    }
}

void heapSort(int *arr, int n)
{
    for(int i=n/2;i>=0;i--)
    {
        heapify(arr, i, n);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, 0, i);
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
    //bubbleSort(arr, n);
    //selectionSort(arr, n);
    //insertionSort(arr, n);
    //quickSort(arr, 0, n-1);
    //mergeSort(arr, 0, n-1);
    //heapSort(arr, n);
    printArr(arr, n);
}