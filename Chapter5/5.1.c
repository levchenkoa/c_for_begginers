#include <ctype.h>
#include <stdio.h>

int getch (void);
void ungetch (int);

/* getint: читает следующее целое из ввода в *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ; /* пропуск символов-разделителей */

    if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
        return 0;
    }
    sign =(c =='-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    if (!isdigit(c) && c != EOF){
           ungetch(c);
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c -'0');
    *pn *= sign;

    return c;
}

#define BUFSIZE 100
char buf[BUFSIZE];    /* буфер для ungetch */
int bufp = 0;         /* след. свободная позиция в буфере */

int getch(void)       /* взять (возможно возвращенный) символ */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* вернуть символ на ввод */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}

int main(){
    int x = 0;
    char c;
    while (c != EOF){
        if((c = getint(&x)))
            printf("\t%d\n",x);

    }
}
