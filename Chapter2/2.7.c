#include <stdio.h>
#include <unistd.h>

unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned);
unsigned invert(unsigned, int, int);
unsigned invertbit(unsigned, int);
int bitsize(unsigned);
void printbits(unsigned);

/* getbigs: gets n bits by position p*/
unsigned getbits(unsigned x, int p, int n)
{
        if (bitsize(x) <= n)
            return x;
        else
            return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* setbtis: retrun value x with changing n bits by positon p to n right bits by y (other bits did't change) */
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
/* invert: return value x with inverted n bits by p position*/
unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = ~getbits(x,p,n);
    return setbits(x, p, n, mask);
}

unsigned invertbit(unsigned x, int p)
{
    return invert(x,p,1);
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

    printf("\nInvert:\n");
    for(int i=0; i <=bitsize(val); i++)
        printbits(invert(val,i,1));


    return 0;
}
