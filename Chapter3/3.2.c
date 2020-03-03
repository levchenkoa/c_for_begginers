/* Упражнение 3.2.
 * Напишите функцию escape (s,t), которая при копировании текста из t в s
 * преобразует такие символы, как новая строка и табуляция
 * в "видимые последовательности символов" (вроде \n и \t).
 * Используйте инструкцию switch.
 * Напишите функцию, выполняющую обратное преобразование эскейп-
 * последовательностей в настоящие символы.*/
#include <stdio.h>


void symbols(char s[], char t[])
{
    int i,j;
    i = j = 0;
    while(s[i] != '\0'){
        switch (s[i]){
            case '\\':
                    switch(s[++i]){
                        case 't':
                                t[j++] = '\t';
                            break;
                        case 'n':
                                t[j++] = '\n';
                            break;
                    }
                    i++;
                break;
            default:
                t[j++] = s[i++];
                break;
        }
    }
}

void escape(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while(s[i] != '\0'){
        switch (s[i]){
            case '\t':  t[j++] = '\\';
                        t[j++] = 't';
                        break;

            case '\n':  t[j++] = '\\';
                        t[j++] = 'n';
                        break;
            default:
                        t[j++] = s[i];
                        break;
        }
        i++;
    }
}

int main()
{
    char s1[] = "Test\tline\nwith\t\ttabs.\n\n";
    char t1[1000];

    char s2[] = "Test\\tline\\nwith\\t\\ttabs.\\n\\n";
    char t2[1000];

    escape(s1,t1);
    printf(s1);
    printf(t1);


    printf("\n-------------\n");
    symbols(s2,t2);
    printf(s2);

    printf("\n");
    printf(t2);
return 0;
}
