#include <stdio.h>

int main(int argc, char *argv[])
{
    char c;

    while((c = getchar()) != EOF)
        putchar((c == ' ' || c == '\t') ? '\n' : c);

    return 0;
}
