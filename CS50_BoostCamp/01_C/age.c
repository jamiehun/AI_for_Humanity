// 정수 출력하기

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int age = get_int("What is your age?\n");
    int days = age * 365;
    printf("Your age is at least %i days old.", days);
}


