#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <ctype.h>
#include <string.h>
#define MAXOP 100  /* макс. размер операнда или оператора */
#define NUMBER '0' /* признак числа */
#define PRINT       -2
#define DOUBLE_TOP  -3
#define FLUSH       -4
#define SWAP_TOP    -5
#define UNKNOWN   -100
int getop (char []);
void push (double);
double pop (void);

void print_top(void);   //печать верхнего элемента в стеке
void double_top(void);  //дублировать верхний элемент
void swap_top(void);    //менять местами два верхних элемента стека
void flush(void);       //очистка стека

/* калькулятор с обратной польской записью */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    printf("Commands:\n print - printing top stack value\n dtop - dobule top stack values\n swtop - swap two top stack values\n flush - flush stack\n");
    while ((type = getop (s)) != EOF) {
        switch (type) {
        case PRINT:
            print_top();
            break;
        case DOUBLE_TOP:
            double_top();
            break;
        case FLUSH:
            flush();
            break;
        case SWAP_TOP:
            swap_top();
            break;
        case NUMBER:
            push (atof(s));
            break;
        case '+':
            push (pop() + pop());
            break;
        case '*':
            push (pop() * pop());
            break;
        case '-':
            op2 = pop();
            push (pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push (pop() / op2);
            else
                printf("ошибка: деление на нуль\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("ошибка: деление на нуль\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("ошибка: неизвестная операция %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100  /* максимальная глубина стека */

int sp = 0;         /* следующая свободная позиция в стеке */
double val[MAXVAL]; /* стек */

/* push: положить значение f в стек */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ошибка: стек полон, %g не помещается\n", f);
}

/* pop: взять с вершины стека и выдать в качестве результата */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf ("ошибка: стек пуст\n");
    return 0.0;
    }
}
void print_top()
{
    if (sp > 0)
        printf("верхний элемент стека: %g\n", val[sp-1]);
    else
        printf ("ошибка: стек пуст\n");
}
void double_top(void)
{
    if (sp > 0)
        push(val[sp-1]);
    else
        printf ("ошибка: стек пуст\n");
}
void swap_top(void)
{
    if (sp > 1){
        double temp1 = pop();
        double temp2 = pop();
        push(temp1);
        push(temp2);
    }
    else
        printf ("ошибка: стек пуст\n");
}
void flush(void)
{
    sp = 0;
}
int getch(void);
void ungetch(int);
int handle_command(char s[]);
char symbol_to_lower(char);
/* getop: получает следующий оператор или операнд */
int getop(char s[])
{
    int i,c,t;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (isalpha(c)){
        while (isalpha(s[++i] = (c = getch())))
            ;
        s[i] = '\0';
        return c = handle_command(s);
    }
    if(c == '-'){                   //Упражнение 4.3: обработка отрицательных чисел
        if(isdigit(t = getch()))
            s[++i] = c = t;
        else
            ungetch(t);
    }

    if (!isdigit(c) && c != '.')
            return c;

    if (isdigit(c)) /* накапливаем целую часть */
        while (isdigit(s[++i] = (c = getch())))
            ;

    if (c =='.') /* накапливаем дробную часть */
    while (isdigit(s[++i] = (c = getch())))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

#define NCOM 6
int handle_command(char s[])
{
    int i;
    char* commands[NCOM] = {"","","print","dtop","flush","swap"};
    for(i = 0; i < NCOM - 1 ; i++)
    {
        if(strcmp(s,commands[i]) == 0)
            return -1 * i;
    }
        return UNKNOWN;
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* буфер для ungetch */
int bufp = 0;         /* след. свободная позиция в буфере */

int getch(void)       /* взять (возможно возвращенный) символ */
{
    return (bufp > 0) ? buf[--bufp] : symbol_to_lower(getchar());
}

void ungetch(int c)   /* вернуть символ на ввод */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: слишком много символов\n");
    else
        buf[bufp++] = c;
}
char symbol_to_lower(char c)
{
            return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

void lower(char s[])
{
    int i = -1;
    while (s[++i] != '\0')
        s[i] = symbol_to_lower(s[i]);
    s[i] = '\0';
}
