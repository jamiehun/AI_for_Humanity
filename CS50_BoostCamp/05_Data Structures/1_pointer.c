#include <stdlib.h>

int main(void)
{
    int *x; // x 포인터 설정
    int *y; // y 포인터 설정

    x = malloc(sizeof(int)); // 메모리 공간 확보 (포인티)
    y = x; // 메모리 공간 확보 (포인티)

    *x = 42; // 역참조 연산자 (포인티에 접근)
    *y = 13;
}