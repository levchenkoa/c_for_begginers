//Компилировать: gcc -o 3.4 3.4.c -lm

/* Упражнение 3.6. Напишите версию itoa с дополнительным третьим аргументом,
 * задающим минимальную ширину поля. При необходимости преобразованное число
 * должно слева дополняться пробелами. */
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

/* itoa: преобразование n в строку s */
void itoa(int n, char s[], int w)
{
    int i, sign;
    char t[MAX];
    if ((sign = n) > 0) //изменим работу функции в отрицательном диапазоне, чтобы избежать переполнения
        n = -n;         //при работе в положительном дипазаоне в этот момент происходит переполнение
    i = 0;
    do { /* генерируем цифры в обратном порядке */
        t[i++] = -(n % 10) + '0';
    } while ((n /= 10) < 0); /* исключить ее */
    if (sign < 0)
        t[i++] = '-';
    t[i] = '\0';
    reverse(t);
    sprintf(s,"%*s",w,t);  //использовал существующую ф-ю форматирвоания
}

int main()
{
    char s[MAX];
    int value;

    for (int i = 1; i < sizeof(i)*8 ; i++){
        value = -pow(2, i);
        itoa(value, s,12);
        printf("%s %15d\n",s, value);

        value = pow(2, i);
        itoa(value, s, 15);
        printf("%s %15d\n",s, value);
    }
}
