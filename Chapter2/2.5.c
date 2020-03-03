#include <stdio.h>

int any(char[], char[]);
void print_any_result(char[], int);

int main (int argc, char *argv[])
{
    char s1[] = "aaaaaaabbbbcccccb";
    char s2[] = "bcd";
    char s3[] = "xyz";
    printf("%s \n", s1);
    printf("%s \n", s2);
    print_any_result(s1, any(s1, s2));

    printf("%s \n", s1);
    printf("%s \n", s3);
    print_any_result(s1, any(s1, s3));
    return 0;
}
void print_any_result(char s[], int index)
{
    printf("Symbol:[%c] Index:[%d] \n\n",s[index], index);
}

int any(char s1[], char s2[])
{

    for(int i = 0; s1[i] != '\0'; i++)
        for (int j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j]) return i;
    return -1;

}
