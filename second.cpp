#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include<time.h>
long getTimeInMicroseconds()
{
struct timeval start;
gettimeofday(&start, NULL);
return start.tv_sec * 1000000 + start.tv_usec;
}
void binarySearch(int arr[], int n, int key)
{
int high = n - 1, low = 0, mid;
mid = (low + high) / 2;
while (low <= high)
{
if (arr[mid] == key){
printf("Present\n");
return;
}
else if (arr[mid] < key){
low = mid + 1;
}
else if (arr[mid] > key){
high = mid - 1;
}
mid = (low + high) / 2;
}
printf("Not Present\n");
return;
}
int main()
{
srand(time(0));
for (int n = 500; n <= 5000; n += 500){
int arr[n];
for (int i = 0; i < n; i++){
arr[i] = i + 1;
}
int key = rand() % n + 1; // Generate a random key within the range of the array size
long start = getTimeInMicroseconds();
binarySearch(arr, n, key);
long end = getTimeInMicroseconds();
double time_taken = (double)(end - start) / 1000000;
printf("Array size: %d\n", n);
printf("Key: %d\n", key);
printf("Time taken: %.6f seconds\n", time_taken);
printf("---------------------------------\n");
}
return 0;
}

