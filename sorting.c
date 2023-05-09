#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp; 
}

void printArr(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d,", arr[i]);
    }
}

void bubbleSort(int *arr, int n)   //best O(n^2), average O(n^2), worst O(n^2)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int *arr, int n) //best O(n^2), average O(n^2), worst O(n^2)
{
    for(int i=0;i<n;i++)
    {
        int min = i;
        for(int j = i+1;j<n;j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

void insertionSort(int *arr, int n) //best O(n), average O(n^2), worst O(n^2)
{
    int key, j;
    for(int i=1;i<n;i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
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

void mergeSort(int *arr, int l, int r) //best O(nlog(n)), average O(nlog(n)), worst O(nlog(n))
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
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

void heapSort(int *arr, int n) //best O(nlog(n)), average O(nlog(n)), worst O(nlog(n))
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
    printf("Enter the number:");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements of the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf(" \n");
    //bubbleSort(arr, n);
    //selectionSort(arr, n);
    //insertionSort(arr, n);
    //mergeSort(arr, 0, n-1);
    //heapSort(arr, n);
    printArr(arr, n);
}