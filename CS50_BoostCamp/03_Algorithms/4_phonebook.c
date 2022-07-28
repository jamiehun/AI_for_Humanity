#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct 
// typedef : 새로운 타입을 정의
// struct : C에 미리 정의된 키워드로 그릇처럼 여러가지 자료형을 담을 수 있음 
{
    string name;
    string number;
}
person; // clang에게 person이라는 자료형이 있다라고 알려줌

int main(void)
{
    person people[4];

    people[0].name = "EMMA";
    people[0].number = "617-555-0100";

    people[1].name = "RODRIGO";
    people[1].number = "617-555-0101";

    people[2].name  = "BRIAN";
    people[2].number = "617-555-0102";

    people[3].name = "DAVID";
    people[3].number = "617-555-0103";  

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(people[i].name, "EMMA") == 0)
        {
            printf("%s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
