#include <ctype.h>
#include <stdio.h>

int getch (void);
void ungetch (int);

/* getint: читает следующее целое из ввода в *pn */
int getfloat(double *pn)
{ //my opinion for solving this type of task better use FSM
    int c, sign;
    int pflag = 0;
    int d = 1;

    while (isspace(c = getch()))
        ; /* пропуск символов-разделителей */

    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c !='.') {
        return 0;
    }
    sign =(c =='-') ? -1 : 1;

    pflag = (c == '.') ? 1 : 0;  //if point before value

    if (c == '+' || c == '-' || c =='.')
        c = getch();

    if (!isdigit(c) && c != EOF){
           ungetch(c);
        return 0;
    }
    for (*pn = 0; isdigit(c) || c == '.'; c = getch())
    {
        if(c == '.' && !pflag) //if point in value
        {
            pflag = 1;
            continue;
        }else
            if (c == '.' && pflag) //if second point
                break;

        if (pflag) d *= 10;

        *pn = 10 * *pn + (c -'0');

    }
     *pn *= sign;
     *pn /= d;

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
    double x = 0.;
    char c;
    while (c != EOF){
        if((c = getfloat(&x)))
            printf("\t%f\n",x);

    }
}
