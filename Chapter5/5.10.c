#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <ctype.h>
#include <stdbool.h>
#include <iso646.h>
#define MAXOP 100  /* макс. размер операнда или оператора */
#define NUMBER '0' /* признак числа */

int getop (char []);
void push (double);
double pop (void);


/* калькулятор с обратной польской записью */
int main(int argc, char *argv[])
{
    int type;
    double op2;

    while (--argc > 0 and (type = getop (*++argv))) {
        switch (type) {
        case NUMBER:
            push (atof(*argv));
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
        default:
            printf("ошибка: неизвестная операция %s\n", *argv);
            break;
        }
    }

    printf("%.8g\n", pop());
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

/* getop: получает следующий оператор или операнд */
int getop(char line[])
{
    char c;
    char *p = line;
    while((c = *line++) != '\0' and (isdigit(c) or (c == '-' and isdigit(*line+1))))
        ;
    if (c == '\0')
        return NUMBER;

    return *p;
}

