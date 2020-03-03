#include <stdio.h>
#include <unistd.h>

int bitscount(unsigned);
void printbits(unsigned);

int main()
{
    int val = 0x77F;
    printf("Value:\n");
    printbits(val);
    printf("Bits count:[%d]\n", bitscount(val));
    return 0;
}

int bitscount(unsigned x)
{
    int b = 0;

    while (x)
    {
        b++;
        x &= (x-1);
    }
    return b;
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

