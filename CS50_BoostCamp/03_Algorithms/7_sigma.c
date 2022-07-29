#include <cs50.h>
#include <stdio.h>

int sigma(int n);

int main(void)
{
    int number = get_int("Number? ");
    
    sigma(number);
}

int sigma(int n)
{
    if (n < 1)
    {
        return 0;
    }
    
    
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    printf("%i\n", sum);    
    return sum;  
}