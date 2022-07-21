#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output : \n");
    for (int i = 0, n = strlen(s); i < n; i++)
    // 혹은 for (int i = 0; s[i] != '\0'; i++)
    {
        printf("%c\n", s[i]);
    }
}



