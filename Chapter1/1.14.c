#include <stdio.h>
#include <stdlib.h>
#define SYMNUM 127

void print_data(int data[], int max);

int main(int argc, char *argv[])
{
    int c;
    int *symbols = (int*)calloc(SYMNUM, sizeof(int)); //See Chapter 7. You can usally use: int symbols[SYMNUM];

    while ((c = getchar()) != EOF)
            symbols[c]++;

    print_data(symbols, SYMNUM);

    free(symbols);
    return 0;
}

void print_data(int *data, int max)
{
    printf ("\nHistogram of symbols\n------------------------------\n");
    for (int i = 33; i < SYMNUM; ++i)
    {
        printf("%c: ", i);
        for (int j = 0; j < data[i]; j++)
           putchar('#');
        putchar('\n');
    }
}
