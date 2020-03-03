#include <stdio.h>
#define MAXLEN 21

void print_gist_data(int data[]);

int main (int argc, char *argv[])
{
    int gist_data[MAXLEN] = {0};
    char c;
    while((c = getchar()) != EOF)
    {
        int nc;
        c = (c == ' ' || c == '\t') ? '\n' : c;
        nc++;
        if (c == '\n')
        {
            gist_data[(nc > 20) ? 20 : nc - 1]++;   //"nc - 1" remove last symbol '\n'
            nc = 0;
        }
    }
    print_gist_data(gist_data);
    return 0;
}



void print_gist_data(int data[])
{
    printf ("\nHistogram of lengths of words\n------------------------------\n");
    for (int i = 1; i < MAXLEN; i++)
    {
        printf((i < 20)?"%4d:":">%3d:", i);
        for (int j = 0; j < data[i]; ++j)
            putchar('#');
        putchar('\n');
    }
}
