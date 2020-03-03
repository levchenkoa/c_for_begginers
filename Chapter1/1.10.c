#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t' || c == '\\' || c == '\b')
            putchar('\\');

        if (c == '\t')
            c ='t';
        else if (c == '\b')
            c = 'b';

        putchar(c);
    }

    return 0;
}

