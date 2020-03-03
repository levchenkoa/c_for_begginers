#include <stdio.h>

int main(int argc, char *argv[])
{
    char c;
    int nl, ns, nt;
    nl = 0;
    ns = 0;
    nt = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if (c == '\t')
            ++nt;
        else if (c == ' ')
            ++ns;
    printf("Spaces: %d\nTabs: %d\nLines: %d\n",ns, nt, nl);
    return 0;
}
