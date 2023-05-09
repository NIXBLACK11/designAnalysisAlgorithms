#include<stdio.h>

void printArr(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d,", arr[i]);
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int leftSize = mid-left+1;
    int rightSize = right-mid;
    int leftArr[leftSize];
    int rightArr[rightSize];
    for(int i=0;i<leftSize;i++)
    {
        leftArr[i] = arr[i+leftSize];
    }
    for(int j=0;j<rightSize;j++)
    {
        rightArr[j] = arr[j+rightSize+1];
    }
    int i = 0, j = 0, k=left;
    while(i<leftSize && j<rightSize)
    {
        if(leftArr[i]<rightArr[j])
        {
            arr[k] = leftArr[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            k++;
            j++;
        }
    }
    while(i<leftSize)
    {
        arr[k] = leftArr[i];
        k++;
        i++;
    }
    while(j<rightSize)
    {
        arr[k] = rightArr[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int low, int high) //best O(nlog(n)), average O(nlog(n)), worst O(nlog(n))
{
    int mid;
    if(low < high)
    {
        mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
    mergeSort(arr, 0, n-1);
    printArr(arr, n);
}