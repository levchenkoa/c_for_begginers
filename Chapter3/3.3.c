/* Упражнение 3.3. Напишите функцию expand(s1,s2), заменяющую сокращенную запись
 * наподобие a-z в строке s1 эквивалентной полной записью аbс...хуz в s2.
 * В s1 допускаются буквы (прописные и строчные) и цифры.
 * Следует уметь справляться с такими случаями, как a-b-c, a-z0-9 и -a-b.
 * Считайте знак - в начале или в конце s1 обычным символом минус. */

#include <stdio.h>

#define MAX 1000

enum expand_states {
    SEARCH = 0,         //Поиск начала последовательности 'letter-'
    HANDLING_SEPARATOR, //Обработка символа после '-'
    MOVE_UP,            //Заполнение последовательности при увеличении номера символа ASCII
    MOVE_DOWN           //заполнение последовательности при уменьшении номера символа ASCII
};

/* isletter: проверяет входит ли символ c в нужный диапазон таблицы ASCII */
int isletter(char c)
{
    return (c >= 'A' && c <='Z') || (c >= 'a' && c <= 'z') || (c >='0' && c <='9');
}
/* expand(s1,s2) заменяtn сокращенную запись наподобие a-z
 * в строке s1 эквивалентной полной записью аbс...хуz в s2.*/
void expand(char s1[], char s2[])
{
    int i, j;
    i = j = 0;
    enum expand_states state;
    state = SEARCH;

    while (s1[i] != '\0'){
        switch(state){
            case SEARCH:
                    if (i > 0 && isletter(s1[i-1]) && s1[i] == '-')
                        state = HANDLING_SEPARATOR;
                    else
                        s2[j++] = s1[i++];
                    break;

            case HANDLING_SEPARATOR:
                    if (isletter(s1[++i]))
                        state = (s1[i] - s2[j-1] >= 0) ?  MOVE_UP : MOVE_DOWN;
                    else {
                        s2[j++] = s1[i-1];
                        state = SEARCH;
                    }
                    break;

            case MOVE_UP:
                    for (char c = s2[j-1] + 1 ; c < s1[i] ; c++)
                            if (isletter(c))
                                s2[j++] = c;
                    state = SEARCH;
                    break;

            case MOVE_DOWN:
                    for (char c = s2[j-1] - 1 ; c > s1[i] ; c--)
                            if (isletter(c))
                                s2[j++] = c;
                    state = SEARCH;
                    break;
        }
    }
    s2[j] = '\0';
}

/* readline читает строку символов с stdin */
int readline(char line[])
{
    int i = 0;
    char c;
    while((c = getchar()) != '\n' && i < MAX){
        if (c == EOF) return 0;
        line[i++] = c;
    }
    line[i] = '\0';
    return 1;
}

int main()
{
    char line[MAX];
    char result[MAX];

    while(readline(line)){
        expand(line, result);
        printf("%s\n",result);
    }
    printf("Bye!\n");
    return 0;
}
