#include <stdio.h>

int main(int argc, char *argv[])
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;
    printf("\t%9s\t%6s\n", "Фарингейт", "Цельсий");
    while(fahr >= lower){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("\t%9.0f\t%6.1f\n", fahr, celsius);
        fahr -= step;
    }


}
