#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    char c;
    bool is_space;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ')
            is_space = false;

        if (!is_space)
            putchar(c);

        if (c == ' ')
            is_space = true;
    }
    return 0;
}

