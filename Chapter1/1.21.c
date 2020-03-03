#include <stdio.h>
#define MAXLINE 100
#define TABSTOP 8
int _getline(char line[], int lim);
void entab(char from[], char to[], int lim,  int tab_stop);
int main(int argc, char *argv[])
{
    int len;
    char line[MAXLINE], entabed_line[MAXLINE];
    printf("Entabing input with tabstop = %d\nMax line length = %d\n", TABSTOP, MAXLINE);
    while((len = _getline(line, MAXLINE)) > 0)
    {
        entab(line, entabed_line, MAXLINE, TABSTOP);
        printf("%s\n", entabed_line);
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

void entab (char from[], char to[], int lim,  int tab_stop)
{
    int i = 0;
    int j = 0;
    int ns = 0;
    int nt = 0;
    int ns_input = 0;
    int ns_output = 0;
    char c;
    while((c = from[i++]) != '\0' && i < lim - 1 && j < lim - 1)
    {
        if (c == ' ')
        {
            ns++;
            ns_input++;
            if (i % tab_stop == 0) //handle tab stop position
            {
                to[j++] = '\t';
                nt++;
                ns = 0;             //reset space counter
            }
        }
        else
        {
            while(ns)
            {
                to[j++] = ' ';
                ns--;
                ns_output++;
            }
            to[j++] = c;
        }
    }

    to[j] = '\0';
    printf("Input: %d spaces. Output %d tabs and %d spaces. \n",ns_input, nt ,ns_output);
}
