#include <stdio.h>


int main (int argc, char *argv[])
{

    printf("Press Ctrl+D to generate EOF\n");
    int result  = getchar() != EOF;
    printf("%d \n", result);
}

