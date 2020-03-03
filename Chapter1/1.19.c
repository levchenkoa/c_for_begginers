#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 100

int get_filtered_line(char line[], int lim);
void reverse(char s[]);
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int len = 0;
    printf("Filter and Reverse input line\n");
    while((len = get_filtered_line(line, MAXLINE)) > 0)
        if(line[0] != '\n')
        {
            reverse(line);
            printf("->:%s\n",line);
        }
    printf("\nBye!\n");
    return 0;
}

void reverse(char s[])
{
    int line_end = 0;
    char tmp;
    while (s[++line_end] != '\n')
        ;
    for (int i = 0; i < line_end  / 2; ++i)
    {
        tmp = s[i];
        s[i] = s[line_end - i - 1];
        s[line_end - i - 1] = tmp;
    }
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
