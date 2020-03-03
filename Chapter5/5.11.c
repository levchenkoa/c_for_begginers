#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100

int _getline(char line[], int lim);
void detab(char from[], char to[], int lim,  int tab_stop);
void entab(char from[], char to[], int lim,  int tab_stop);
void show_usage();
/*Keys:
 * -d - detabing;
 * -e - entabing;
 * -t n - number for tabstop;
 *  line - input line;
 *  app -d -t 8 "test line"*/

int main(int argc, char *argv[])
{
    int TABSTOP = 8;
    int mode = 0;
    int new_tab = 0;
    char c;
    char *pmessages[] = {"Detabing input with tabstop = %d\nMax line length = %d\n",
                        "Entabing input with tabstop = %d\nMax line length = %d\n"};

    char output_line[MAXLINE];

                char *pt ;
    while(--argc > 0 && (*++argv)[0] == '-')
    {
        new_tab = 0;
        while((c = *++argv[0]) && !new_tab)
            switch(c)
            {
                case 'd':
                    mode = 0;
                break;
                case 'e':
                    mode = 1;
                break;
                case 't':
                    TABSTOP = (int)strtol(*argv + 1,&pt , 10);
                    TABSTOP = (TABSTOP) ? TABSTOP : 8;
                    if(pt != NULL) *argv += (pt - *argv - 1);
                break;
            default:
                    printf("Unknown command:[%c]\n",c);
                    argc=0;
                break;
            }
    }
    if (argc != 1)
        show_usage();
    else
    {
        printf(pmessages[mode], TABSTOP, MAXLINE);
        switch(mode)
        {
            case 0:
                detab(*argv, output_line, MAXLINE, TABSTOP);
            break;
            case 1:
                entab(*argv, output_line, MAXLINE, TABSTOP);
            break;
        }
        printf(output_line);
    }

    printf("\nBye!\n");
    return 0;
}

void detab (char from[], char to[], int lim,  int tab_stop)
{
    int i = 0;
    int j = 0;
    int ns_input = 0;
    int nt_input = 0;
    int ns_output = 0;
    char c;
    while((c = from[i++]) != '\0' && i < lim - 1 && j < lim - 1)
    {
        if (c == ' ') ns_input++;

        if(c == '\t')
        {
            nt_input++;
            c = '_';
            if (j % tab_stop == 0) //есле уже на стопе табуляции
            {
                ns_output++;
                to[j++] = c;
            }
            while(j % tab_stop != 0) //добираем до стопа табуляции
            {
                ns_output++;
                to[j++] = c;
            }

        } else
            to[j++] = c;
    }

    to[j] = '\0';
    printf("Input: %d spaces and %d tabs. Output  %d spaces. \n",ns_input, nt_input ,ns_output+ns_input);
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

void show_usage()
{

    printf("Default mode: Detabing\n\
Keys:\n\
    -d - detabing (not required - default behaivor);\n\
    -e - entabing;\n\
    -tn - number for tabstop;\n\
    line - input line;\n\
    Example: -t8 \"test line\"\n");

}

