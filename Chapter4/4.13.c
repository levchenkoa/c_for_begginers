#include <stdio.h>

void reverse(char[]);
int main (int argc, char *argv[])
{
    char s1[] = "12345";
    char s2[] = "1234";
    char s3[] = "123";
    char s4[] = "12";
    char s5[] = "1";
    char s6[] = "";
    reverse(s1);
    reverse(s2);
    reverse(s3);
    reverse(s4);
    reverse(s5);
    reverse(s6);
    printf("%s \n", s1);
    printf("%s \n", s2);
    printf("%s \n", s3);
    printf("%s \n", s4);
    printf("%s \n", s5);
    printf("%s \n", s6);
    return 0;
}

void reverse(char s[])
{

    static int left, right;
    int temp;

    right++;

    if (s[left] != '\0' && s[right] != '\0')
        reverse(s);

    if (left < right)
    {
        temp = s[left];
        s[left++] = s[--right];
        s[right] = temp;
    } else
        left = right = 0;

}
