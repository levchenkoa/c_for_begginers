#include <stdio.h>

unsigned int htoi(char hex[]);

int main(int argc, char *argv[])
{
    char hex1[] = "0XABCDF";
    char hex2[] = "0x123ab";

    printf("Input: [%s] \n", hex1);
    printf("Output:[%X] \n", htoi(hex1));

    printf("Input: [%s] \n", hex2);
    printf("Output:[%x] \n", htoi(hex2));
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


unsigned int htoi(char hex[])
{
    unsigned int result, digit;
    result = digit = 0;
    lower(hex);
    if(hex[0] == '0' && hex[1] == 'x')
    {
        for (int i = 2; hex[i] != '\0'; i++)
        {
            if (hex[i] >= '0' && hex[i] <='9')
                digit = hex[i] - '0';
            else if(hex[i] >='a' && hex[i] <= 'f')
                digit = hex[i] -'a' + 10;

            result = result * 16 + digit;
        }
    } else return 0;

    return result;
}
