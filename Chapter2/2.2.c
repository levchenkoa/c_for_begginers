#include <stdio.h>


int main(int argc, char *argv[])
{
    const int lim = 10;
    char s[lim];
    char c;
    int i;

    /*for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
            s[i] = c;

    s[i] = '\0';

    printf("%s \n", s);
    */
    i = 0;

    while(i < lim - 1)
    {
        c = getchar();
        if ( c == '\n')
            break;
        if ( c == EOF)
            break;

        s[i++] = c;
    }

    s[i] = '\0';

    printf("%s \n", s);

    return 0;
}
