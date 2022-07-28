#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[4] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};

    for (int i = 0; i < 4; i++)
    {
        // C에서는 low level이라 string을 바로 비교 하지 못함 (names[i] == "Emma")
        if (strcmp(names[i], "EMMA") == 0)
        {
            printf("Found\n");
            return 0; // Success
        }
    }
    printf("Not Found\n");
    return 1; // Failure
}