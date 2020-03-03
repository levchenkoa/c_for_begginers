#include <stdio.h>
float celsius_to_fahr(float);
float fahr_to_celsius(float);
int main(int argc, char *argv[])
{
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;
    printf("\t%9s\t%6s\n", "Фарингейт", "Цельсий");
    while(fahr >= lower){
        printf("\t%9.0f\t%6.1f\n", fahr, fahr_to_celsius(fahr));
        fahr -= step;
    }

}

float celsius_to_fahr(float celsius)
{
    return celsius/(5.0/9.0) + 32.0;
}

float fahr_to_celsius(float fahr)
{

    return (5.0/9.0) * (fahr - 32.0);
}
