#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr, int n) {
    bool sorted;
    for(int i=0;i<n;i++) {
        sorted = true;
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                sorted = false;
                swap(arr[j], arr[j+1]);
            }
        }
        if(sorted) break;
    }
}

void selectionSort(vector<int> &arr, int n) {
    for(int i=0;i<n-1;i++) {
        int min = i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void insertionSort(vector<int> &arr, int n) {
    for(int i=1;i<n;i++) {
        int key = arr[i];
        int j = i;
        while(arr[j-1]>key && j>=1) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }
}

void merge(vector<int> &arr, int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;

    vector<int> L(n1), R(n2);

    for(int i=0;i<n1;i++) {
        L[i] = arr[l+i];
    }

    for(int j=0;j<n2;j++) {
        R[j] = arr[m+j+1];
    }

    int i = 0, j = 0, k = l;
    while(i<n1 && j<n2) {
        if(L[i]<R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i<n1) {
        arr[k++] = L[i++];
    }

    while(j<n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if(l<r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void print(vector<int> &arr) {
    for(auto it: arr) cout<<it<<", ";
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n, 0);
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    // mergeSort(arr, 0, n-1);

    print(arr);
    return 0;
}