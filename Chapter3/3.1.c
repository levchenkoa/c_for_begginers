#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

#define MAX 400000000

long int binsearch(long int x, long int v[], long int n)
{
    long int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <=high){
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

long int binsearch2(long int x, long int v[], long int n)
{
    long int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high){
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid -1;
        else
            low = mid + 1;
    }
    if (v[mid] == x)
        return mid;
    else
        return -1;
}
int main()
{
    long val = 1000000;
    time_t start, end;
    long v[val];
    long int count;
    for (long int i=0; i<val-1; i++){
        v[i] = i;
    }

    count = MAX;
    printf("Benchmarking binsearh with two conditions. Cycle iterations = %ld \n", count);
    start = time(NULL);
    while(count--)
        binsearch(9, v, val);
    end = time(NULL);
    printf("%f\n", difftime(end, start));

    count = MAX;
    printf("Benchmarking binsearh with one conditions. Cycle iterations = %ld \n", count);
    start = time(NULL);
    while(count--)
        binsearch2(9, v, val);
    end = time(NULL);
    printf("%f\n", difftime(end, start));

}

