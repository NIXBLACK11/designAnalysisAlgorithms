#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <time.h>
long getTimeInMicroseconds()
{
struct timeval start;
gettimeofday(&start, NULL);
return start.tv_sec * 1000000 + start.tv_usec;
}
int jump_search(int arr[], int n, int key, int *comparisons)
{
int step = sqrt(n);
int prev = 0;
while (arr[step - 1] < key)
{
(*comparisons)++;
prev = step;
step += sqrt(n);
if (prev >= n)
{
return -1;
}
}
while (arr[prev] < key)
{
(*comparisons)++;
prev++;
if (prev == fmin(step, n))
{
return -1;
}
}
if (arr[prev] == key)
{
(*comparisons)++;
return prev;
}
return -1;
}
int main()
{
srand(time(0));
for (int n = 500; n <= 5000; n += 500)
{
int arr[n];
for (int i = 0; i < n; i++)
{
arr[i] = i + 1;
}
int key = rand() % n + 1; // Generate a random key within the range of the array size
int comparisons = 0;
long start = getTimeInMicroseconds();
jump_search(arr, n, key, &comparisons);
long end = getTimeInMicroseconds();
double time_taken = (double)(end - start) / 1000000;
printf("Array size: %d\n", n);
printf("Key: %d\n", key);
printf("Comparisons: %d\n", comparisons);
printf("Time taken: %.6f seconds\n", time_taken);
printf("---------------------------------\n");
}
return 0;
}

