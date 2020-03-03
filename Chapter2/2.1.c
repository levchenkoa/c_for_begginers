#include <stdio.h>
#include <limits.h>
#include <float.h>

#define MIN 0
#define MAX 1
#define USIGN 0
#define SIGN 1

void print_constants();
void print_calculates();

int main(int argc, char *argv[])
{
    print_constants();
    print_calculates();
    return 0;
}

void print_constants()
{
    printf("Constants value\n----------------\n");

    printf("Signed char from    %20d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char from  %20d to %d\n",MIN, UCHAR_MAX);

    printf("Signed short from   %20d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short from %20d to %d\n", MIN, USHRT_MAX);

    printf("Signed int from     %20d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int from   %20d to %u\n", MIN, UINT_MAX);

    printf("Signed long from    %20ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long from  %20d to %lu\n\n", MIN, ULONG_MAX);
}


long long int calc(size_t size, int sign, int value);
void print_calculates()
{

    printf("Calculates value\n----------------\n");

    printf("Signed char from    %20lld to %lld\n",   calc(sizeof(char),  SIGN,  MIN), calc(sizeof(char),  SIGN,  MAX));
    printf("Unsigned char from  %20llu to %llu\n",   calc(sizeof(char),  USIGN, MIN), calc(sizeof(char),  USIGN, MAX));

    printf("Signed short from   %20lld to %lld\n",   calc(sizeof(short), SIGN,  MIN), calc(sizeof(short), SIGN,  MAX));
    printf("Unsigned short from %20llu to %llu\n",   calc(sizeof(short), USIGN, MIN), calc(sizeof(short), USIGN, MAX));

    printf("Signed int from     %20lld to %lld\n",   calc(sizeof(int),   SIGN,  MIN), calc(sizeof(int),   SIGN,  MAX));
    printf("Unsigned int from   %20llu to %llu\n",   calc(sizeof(int),   USIGN, MIN), calc(sizeof(int),   USIGN, MAX));

    printf("Signed long from    %20lld to %lld\n",   calc(sizeof(long),  SIGN,  MIN), calc(sizeof(long),  SIGN,  MAX));
    printf("Unsigned long from  %20llu to %llu\n\n", calc(sizeof(long),  USIGN, MIN), calc(sizeof(long),  USIGN, MAX));


}

long long int pow2(int n);

long long int calc(size_t size, int sign, int value)
{
    int bits = size * 8;

    if(sign)
        return (value) ?  pow2(bits - 1) - 1 : -pow2(bits - 1);
    else
        return (value) ?  pow2(bits) - 1 : 0;
}

long long int pow2(int n)
{

    long long int p = 1;
    while (n--)
        p *= 2;
    return p;

}
