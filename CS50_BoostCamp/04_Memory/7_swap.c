#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y); // x와 y의 주소를 가르킴
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b) // 주소값만 값으로 가짐
{
    int tmp = *a; 
    *a = *b;
    *b = tmp;
}