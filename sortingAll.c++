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

int partition(vector<int> &arr, int l, int r) {
    int x = rand() % (r-l+1) + l;
    swap(arr[x], arr[r]);
    int pivot = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[r]);
    return i;
}

void quickSort(vector<int> &arr, int l, int r) {
    if(l<r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

void heapify(vector<int> &arr, int i, int n) {
    int c1 = i*2 + 1;
    int c2 = i*2 + 2;
    int max = i;

    if(c1<n && arr[c1]>arr[max]) {
        max = c1;
    }
    if(c2<n && arr[c2]>arr[max]) {
        max = c2;
    }
    if(max!=i) {
        swap(arr[max], arr[i]);
        heapify(arr, max, n);
    }
}

void heapSort(vector<int> &arr, int n) {
    for(int i=n/2;i>=0;i--) {
        heapify(arr, i, n);
    }

    for(int i=n-1;i>=0;i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
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
    // quickSort(arr, 0, n-1);
    // heapSort(arr, n);

    print(arr);
    return 0;
}