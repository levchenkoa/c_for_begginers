#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 100

int get_filtered_line(char line[], int lim);
void copy(char [], char []);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int len = 0;
    while((len = get_filtered_line(line, MAXLINE)) > 0)
        if(line[0] != '\n')
            printf("->:%s\n",line);
    return 0;
}

int get_filtered_line(char line[], int lim)
{
    int c, i = 0;
    bool sep = false;
    printf("<-:");
    while(--lim && (c = getchar()) != EOF && c != '\n')
        if (c == ' ' || c == '\t')
        {
            if (!sep)
            {
                line[i++] = c;
                sep = true;
            }
        }
        else
        {
            line[i++] = c;
            sep = false;
        };

    if (c == '\n') line[i++] = c;
    line[i] = '\0';
    return i;
}
