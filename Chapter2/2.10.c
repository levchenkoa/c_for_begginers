#include <stdio.h>

char symbol_to_lower(char c);
void lower(char s[]);

int main (int argc, char *argv[])
{
    char s[] = "HELLO, WORLD! Aa Bb Cc Dd";

    printf("%s \n", s);
    lower(s);
    printf("%s \n", s);
    return 0;
}

char symbol_to_lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;

}

void lower(char s[])
{
    int i = -1;
    while (s[++i] != '\0')
        s[i] = symbol_to_lower(s[i]);
    s[i] = '\0';

}
