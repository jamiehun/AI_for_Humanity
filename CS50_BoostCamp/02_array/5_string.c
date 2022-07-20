#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    // 혹은 for(int i = 0; s[i] != '\0'; i++) 여기에서 \0은 널문자로 1개로 침 => ' '에 위치
    {
        printf("%c", s[i]);
    }
    printf("\n");
}