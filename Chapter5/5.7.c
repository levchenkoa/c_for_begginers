#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define BUFFSIZE 10000

char *lineptr[MAXLINES]; /* массив указателей на строки*/
int readlines(char *lineptr[], char *buffer, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines;
    char buffer[BUFFSIZE];
    if ((nlines = readlines(lineptr, buffer, MAXLINES)) >= 0) {
        qsort(lineptr,0 ,nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Ошибка: слишком много строк\n");
        return 1;
    }
}

#define MAXLEN 1000 /* максимальная длина строки */
int _getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], char buffer[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    p = buffer + strlen(buffer);

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (len+strlen(buffer) >= BUFFSIZE))
            return -1;
    else {
        line[len-1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
        p +=len;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);

}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
            return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v,++last,i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last+1, right);

}

int _getline(char s[], int lim)
{
    int c, i;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

