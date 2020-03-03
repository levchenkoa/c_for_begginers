#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse, int case_sensitivity);

int main(int argc, char **argv)
{

    int((*get_cmpfunc(int numeric)))(void*, void*);
    int (*cmpfunc)(void*, void*); //pointer to compare function
    void parse_agruments(int argc, char **argv, int *numeric, int *reverse, int *case_sensitivity);

    int nlines;
    int numeric;
    int reverse;
    int case_sensitivity;

    parse_agruments(argc, argv, &numeric, &reverse, &case_sensitivity);
    cmpfunc = get_cmpfunc(numeric);

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        my_qsort((void **) lineptr, 0, nlines-1, cmpfunc, reverse, case_sensitivity);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Too many lines\n");
        return 1;
    }
}

void parse_agruments(int argc, char **argv, int *numeric, int *reverse, int *case_sensitivity)
{
    *numeric = 0;
    *reverse = 0;
    *case_sensitivity = 1;

    char param_key = 0;
    while (--argc > 0 && (*++argv)[0] == '-')
        while((param_key = *++argv[0]))
        switch(param_key)
        {
            case 'n':
                *numeric = 1;
                break;
            case 'r':
                *reverse = 1;
                break;
            case 'f':
                *case_sensitivity = 0;
                break;
            default:
                printf("Unknown param: [%c]\n", param_key);
                break;
        }
}

/* get_cmpfunc: takes flags and return pointer to compare functrion with casting it to int(*)(void*, void*) */
int((*get_cmpfunc(int numeric)))(void*, void*)
{
    int numcmp(char *, char *);

    if (numeric)
        return (int(*)(void*, void*))numcmp;
    else
        return (int(*)(void*, void*))strcmp;
}

char symbol_to_lower(char *c)
{
            return (*c >= 'A' && *c <= 'Z') ? *c + 'a' - 'A' : *c;
}

void my_qsort (void *v[], int left, int right, int (*comp)(void *, void *), int reverse, int case_sensitivity)
{
    int i, last;
    void swap(void *v[],int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1 ; i <= right; i++){
        char a = case_sensitivity ? *(char*)v[i] : symbol_to_lower(v[i]);
        char b = case_sensitivity ? *(char*)v[left] : symbol_to_lower(v[left]);
        if (reverse ? (*comp)(&a, &b) > 0 : (*comp)(&a, &b) < 0 )
            swap(v, ++last, i);
    }
    swap(v, left, last);
    my_qsort(v, left, last - 1, comp, reverse, case_sensitivity);
    my_qsort(v, last + 1, right, comp, reverse, case_sensitivity);
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    printf("%f\n", v1);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}


/* swap: swap elements in array */
void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* readlines: read lines from input and store into memory with dynamic allocation, return number of readed lines*/
int readlines(char *lineptr[], int maxlines)
{

    int my_getline(char *buffer, int lim);
    int len, nlines;
    char *p, buffer[MAXLINES];
    nlines = 0;

    while ((len = my_getline(buffer, MAXLINES)) > 0)
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            buffer[len - 1] = '\0';
            strcpy(p, buffer);
            lineptr[nlines++] = p;
        }

    return nlines;
}

/* writeline: take array of pointers to lines and print each line */
void writelines (char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* my_getline: read new line to buffer and return length */
int my_getline(char *buffer, int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c!= '\n')
        buffer[i++] = c;
    if (c == '\n')
        buffer[i++] = c;
    buffer[i] = '\0';
    return i;
}

