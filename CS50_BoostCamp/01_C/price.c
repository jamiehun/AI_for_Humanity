// 실수 출력하기

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float price = get_float("What is the price?\n");
    printf("Your total is %.2f", price*1.0625);

}


