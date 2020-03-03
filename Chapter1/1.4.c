#include <stdio.h>

int main(int argc, char *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("\t%9s\t\t%6s\n", "Цельсий", "Фарингейт");
    while(celsius <= upper){
        fahr = celsius/(5.0/9.0) + 32.0;
        printf("\t%9.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }


}
