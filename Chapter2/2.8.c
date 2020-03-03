#include <stdio.h>
#include <unistd.h>

unsigned getbits(unsigned, int, int);
unsigned getbit(unsigned, int);
unsigned rightrot(unsigned, int);
int bitsize(unsigned);
void printbits(unsigned);

/* getbigs: get n bits starting by position p*/
unsigned getbits(unsigned x, int p, int n)
{
        if (bitsize(x) <= n)
            return x;
        else
            return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* getbit: return bit value in p position */
unsigned getbit(unsigned x, int p)
{
    return getbits(x, p, 1);
}

/* rightrot: rotation movement to rigth n bits */
unsigned rightrot(unsigned x, int n)
{
    unsigned rbit;
    while(n--)
    {
        rbit = getbit(x,0);
        rbit = rbit << (bitsize(x)-1);
        x = x >> 1 | rbit;
    }
    return x;

}

/* bitsize: returns count of bits */
int bitsize(unsigned x)
{
    return sizeof(x) * 8;
}

/* printbits: printig bits of value */
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

    printf("\nRightrot:\n");
    for(int i=0; i <=bitsize(val); i++)
        printbits(rightrot(val, i));


    return 0;
}
