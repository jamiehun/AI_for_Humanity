#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; // '*' 연산자는 어떤 메모리 주소에 있는 값을 받아오게 함
    printf("%p\n", p);
    printf("%i\n", *p);
}