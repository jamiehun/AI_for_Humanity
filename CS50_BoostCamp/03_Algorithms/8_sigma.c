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
    if (n <= 0)
    {
        return 0;
    }
    
    else
    {
        return (n + sigma(n-1));
    }
}