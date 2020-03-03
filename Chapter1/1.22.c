#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 8
#define BORDER 5
int _getline(char line[], int lim);
void detab(char from[], char to[], int lim,  int tab_stop);
void right_alignment(char from[], char to[], int line_lim, int border);
int main(int argc, char *argv[])
{
    int len;
    char line[MAXLINE], detabed_line[MAXLINE], alignment_line[MAXLINE];
    printf("Detabing input with tabstop = %d\nMax line length = %d\n", TABSTOP, MAXLINE);
    while((len = _getline(line, MAXLINE)) > 0)
    {
        detab(line, detabed_line, MAXLINE, TABSTOP);
        right_alignment(detabed_line, alignment_line, MAXLINE, BORDER);
        printf("%s\n", alignment_line);
    }
    printf("\nBye!\n");
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

void detab (char from[], char to[], int lim,  int tab_stop)
{
    int i = 0;
    int j = 0;
    char c;
    while((c = from[i++]) != '\0' && i < lim - 1 && j < lim - 1)
    {
        if(c == '\t')
        {
            c = ' ';
            if (j % tab_stop == 0) //есле уже на стопе табуляции
                to[j++] = c;

            while(j % tab_stop != 0) //добираем до стопа табуляции
                to[j++] = c;

        } else
            to[j++] = c;
    }

    to[j] = '\0';
}
void right_alignment(char from[], char to[], int line_lim, int border)
{
    int sep_position = 0;
    int i = 0;
    int j = 0;
    int curp = 0;
    char c;
    while((c = from[i++]) != '\0' && i < line_lim - 1 && j < line_lim - 1)
    {
        curp = i - 1;
        if (c == ' ' || c == '\n')
            sep_position = curp;

        if (i % border == 0)
        {
            i = sep_position;
            to[j++] = '\n';
        }

        to[j++] = c;
    }
    to[j] = '\0';

}
