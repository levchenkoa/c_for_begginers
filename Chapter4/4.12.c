#include <stdio.h>

void ritoa(int, char[]);
int main (int argc, char *argv[])

{
    int a = -1234;
    int b = 1234;
    int c = -123;
    int d = -321426896;
    char s[100];

    printf("Int:    [%d]\n", a);
    ritoa(a, s);
    printf("Text:   [%s]\n", s);

    printf("Int:    [%d]\n", b);
    ritoa(b, s);
    printf("Text:   [%s]\n", s);

    printf("Int:    [%d]\n", c);
    ritoa(c, s);
    printf("Text:   [%s]\n", s);

    printf("Int:    [%d]\n", d);
    ritoa(d, s);
    printf("Text:   [%s]\n", s);


    return 0;

}

void ritoa(int n, char s[])
{

    static int i;       //index - char position
    static int sign;    //sign flag
    static int deep;    //recursion deep counter

    if(sign == 0 && (sign = n) < 0 )
        n = -n;

    deep++;             //forward recursion flow
    if ((n / 10) > 0)
        ritoa(n /10, s);
    deep--;             //backward recursion flow

    if(sign < 0)
    {
        s[i++] = '-';
        sign = 0;       //reset sign flag
    }

    s[i++] = n % 10 + '0';

    if(deep == 0)       //top level of recursion
    {
        s[i] = '\0';
        sign = 0;
        i = 0;
    }
}
