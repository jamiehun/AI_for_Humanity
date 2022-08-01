#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    char *s = get_string("S: ");
    char *t = get_string("T: ");

    if (strcmp(s, t) == 0)
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}