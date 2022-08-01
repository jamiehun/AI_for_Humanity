#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("s: ");
    string t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s); // s는 메모리의 주소를 저장 (char *s)
    printf("t: %s\n", t); // t는 s의 주소를 저장
}