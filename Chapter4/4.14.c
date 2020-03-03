#include <stdio.h>
#define swap(t,x,y) {t tmp; tmp = x; x = y; y = tmp;}

int main(int argc, char *argv[])
{
    int x, y;
    x = 5, y = 3;
    printf("x = %d, y = %d \n", x,y);
    swap(int,x, y);

    printf("x = %d, y = %d \n", x, y);

    return 0;

}
