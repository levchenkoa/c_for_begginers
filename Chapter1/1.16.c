#include <stdio.h>
#define MAXLINE 100

int _getline(char line[], int lim);
void copy(char [], char []);
int main(int argc, char *argv[])
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];
    max = 0;
    while((len = _getline(line, MAXLINE)) > 0)
        if(len > max){
            max = len;
            copy(longest, line);
        }
    if (max > 0) printf("%s \n", longest);
    return 0;
}

int _getline(char line[], int lim)
{

    int c, i;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;

}
