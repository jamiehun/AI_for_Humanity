#include <stdio.h>
#include <stdlib.h>

// 연결 리스트의 기본 단위가 되는 node 구조체를 정의
typedef struct node
{
    // node 안에서 정수형 값이 저장되는 변수를 name으로 지정
    int number;
    // 다음 node의 주소를 가르키는 포인터를 *next로 지정
    struct node *next;
}
node;

int main(void)
{
    // list라는 이름의 node 포인터 정의
    // 연결리스트의 가장 첫번째 node를 가르킬 것임
    // NULL로 초기화
    node *list = NULL;

    // 새로운 node를 위해 메모리 할당 및 포인터 *n을 가르킴
    node *n = malloc(sizeof(node));
    if (n==NULL)
    {
        return 1;
    }

    // n의 number 필드에 1을 저장
    // "n->number"은 "(*n).number"과 동일한 의미임
    // n이 가르키는 node의 number 필드를 의미
    n->number = 1;

    // n 다음에 정의된 node가 없음으로 NULL로 초기화
    n->next = NULL;

    // 첫번째 node를 정의했기 때문에 list 포인터를 n 포인터로 변경함
    list = n;

    // ------------------------------------------------------------
    // 다른 node 연결을 위해 새로운 메모리 다시 할당
    n = malloc(sizeof(node));
    if (n==NULL)
    {
        return 1;
    }

    // n의 number와 next 값을 각각 저장
    n->number = 2;
    n->next = NULL;

    // 현재 list가 가르키는 것은 첫번째 node임
    // 이 node의 다음 node를 n 포인터로 지정
    list->next = n;

    // ------------------------------------------------------------
    // 다른 node 연결을 위해 새로운 메모리 다시 할당
    n = malloc(sizeof(node));
    if (n==NULL)
    {
        return 1;
    }

    n->number = 3;
    n->next = NULL;

    // 현재 list는 첫번째 node 가르키고, 이는 두번째 node와 연결되어 있음
    // 따라서 세번째 node 연결을 위해서는 앞의 포인터를 n 포인터로 지정
    list->next->next = n;

    // ------------------------------------------------------------
    // 이제 list에 연결된 node를 처음부터 방문하면서 각 number 값을 출력
    // 마지막 node의 next에는 NULL이 저장되어 있을 것이기 때문에 이것이 for 루프의 종료조건이 됨
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // 메모리를 해제해주기 위해 list에 연결된 node들을 처음부터 방문하면서 free 해줌
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

}