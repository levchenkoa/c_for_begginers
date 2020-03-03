#include <stdio.h>

int strend(char *s, char *t)
{

    char *pend_s = s;
    char *pend_t = t;

    while(*pend_s++)
        ;
    while(*pend_t++)
        ;
    pend_s -= pend_t-t;

    while(*t && *t++ == *pend_s++)
        ;

    if (!*t)
        return 1;

    return 0;
}


int main()
{
    char s[] = "Hello, world!";
    char t[] = "world!";

    if (strend(s,t))
        printf("String \"%s\" found at the end of \"%s\".\n", t, s);
    else
        printf("Not found\n");

    return 0;
}

