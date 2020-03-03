#include <stdio.h>
#include <unistd.h>

unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned);
int bitsize(unsigned);
void printbits(unsigned);

unsigned getbits(unsigned x, int p, int n)
{
        if (bitsize(x) <= n)
            return x;
        else
            return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    int bits = bitsize(x);
    int cutp = p - n;
    int cutn = bits-(bits - cutp) + 1;
    unsigned tail = getbits(x, cutp, cutn);

    x = (x >> (p + 1)) << n;
    y = getbits(y, n-1, n);
    return ((x | y) << cutn | tail);
}
int bitsize(unsigned x)
{
    return sizeof(x) * 8;
}

void printbits(unsigned x)
{
    int bits = bitsize(x);
    int i;
    for (i = 0; i < bits; i++)
    {
        if ((i % 4) == 0 && i > 0)
            printf(" ");

        printf("%d", x >> (bits - i - 1) & 1);
    }
    printf("   | %d\n", bits);
}



int main()
{
    int val = 0x7;
    int mask = 02;
    printf("Value:\n");
    printbits(val);
    printf("Mask:\n");
    printbits(mask);

    printf("\nSetbits:\n");
    for(int i=0; i <=bitsize(val); i++)
        printbits(setbits(val,i,2,mask));


    return 0;
}
