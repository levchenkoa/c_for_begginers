#include <stdio.h>

void squeeze(char[], char[]);

int main (int argc, char *argv[])
{
    char s1[] = "aaaabb cc ddd bb aa cc dd bb bb ccdde ee ee  cc faa";
    char s2[] = "abc";
    printf("%s \n", s1);
    printf("%s \n", s2);
    squeeze(s1, s2);
    printf("%s \n", s1);

    return 0;
}

void squeeze (char s1[], char s2[])
{
    char c;
    int i,k;
    i = 0;
    k = 0;
    while((c = s1[i++]) != '\0')
    {
        int j = 0;
        while(s2[j] != c && s2[j] != '\0')
        {
            j++;
        }

        if (s2[j] == '\0')
            s1[k++] = c;
    }
    s1[k] = '\0';

}
