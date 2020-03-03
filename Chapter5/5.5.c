#include <stdio.h>

char *strncpy_(char *t, char *s, int n);
int strncat(char *t, char *s, int n);
int strncmp(char *t, char *s, int n);

char *strncpy_(char *t, char *s, int n)
{
    char *r = s;
    while(n-- && (*s++ = *t++));
    *s = '\0';
    return r;
}

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
    char s1[] = "world!";
    char t[] = "Bender!";
    int n = 15;
    if (strend(s,s1))
        printf("String \"%s\" found at the end of \"%s\".\n", s1, s);
    else
        printf("Not found\n");

    printf("char s[] = %s\n",s);
    printf("Copy %d chars from \"%s\" to char s[]:\nchar s[] = \"%s\"\n",n, t , strncpy_(t,s,n));

    return 0;
}

