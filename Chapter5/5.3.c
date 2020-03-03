#include <stdio.h>


void _strcat( char *s, char *t)
{
    while (*++s);
    while ((*s++ = *t++));

/*  'H','e','l','l','o',0
 *   |   |   |   |   |  |
 *   1   1   1   1   1  0   <- while(1) increment pointer */
}

int main()
{
    char s[20] = "Hello";
    char t[] = ", word!";
    _strcat(s, t);
    printf(s);
    return 0;

}
