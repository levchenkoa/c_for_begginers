//Компилировать: gcc -o 3.4 3.4.c -lm
/* Упражнение 3.5. Напишите функцию itob(n,s,b), которая переводит целое n в строку s,
 * представляющую число по основанию b.
 * В частности, itob(n, s, 16) помещает в s текст числа n в шестнадцатеричном виде.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100
/* reverse: переворачивает строку s (результат в s) */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        }
}


void itob(int n, char s[], int b)
{
    int i, sign, c;
    if ((sign = n) > 0) //изменим работу функции в отрицательном диапазоне, чтобы избежать переполнения
        n = -n;         //при работе в положительном дипазаоне в этот момент происходит переполнение
    i = 0;
    do { /* генерируем цифры в обратном порядке */
        c = - (n % b);
        s[i++] = (c > 9) ? c + 'A' - 10 : c + '0';
    } while ((n /= b) < 0); /* исключить ее */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[MAX];
    printf("\nBase 2\n");
    for (int i = 1; i <= 32;i++){
        itob(i, s, 2);
        printf("%15s %15d\n",s, i);
    }

    printf("\nBase 8\n");
    for (int i = 1; i <= 32;i++){
        itob(i, s, 8);
        printf("%15s %15d\n",s, i);
    }

    printf("\nBase 10\n");
    for (int i = 1; i <= 32;i++){
        itob(i, s, 10);
        printf("%15s %15d\n",s, i);
    }

    printf("\nBase 16\n");
    for (int i = 1; i <= 32;i++){
        itob(i, s, 16);
        printf("%15s %15d\n",s, i);
    }
}
