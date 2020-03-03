#include <ctype.h>
#include <stdio.h>
#define MAXLINE 100

double atof (char s[])
{
    double val, power, exp;
    int i, sign, exp_sign;
    exp = 1.0;
    for (i=0;isspace(s[i]);i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0 ; isdigit (s[i]); i++)
        val = 10.0 * val + (s[i]-'0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i]-'0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E'){
        i++;
    exp_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (int j = 1; j <= s[i]-'0' ; j++)
        if (exp_sign > 0)
            exp *= 10.0;
        else
            exp /= 10.0;
    }
    return sign * val / power * exp;
}
int _getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int main()
{
    double  atof(char[]);
    char line[MAXLINE];
    int _getline(char line[], int max);

    while (_getline(line, MAXLINE) > 0)
        printf("\t%g\n",  atof(line));
    return 0;

}
