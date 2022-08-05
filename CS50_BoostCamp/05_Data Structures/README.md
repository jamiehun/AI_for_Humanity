# 자료구조
- 데이터(자료) 구조를 정의하고 관리하는데 있어서 메모리와 포인터에 대한 개념을 정확히 이해하는 것이 중요
- 데이터(자료) 구조를 통해 컴퓨터 메모리를 더 효율적으로 관리할 수 있음 (메모리 레이아웃, 또는 지도라 할 수 있음)

## 문법 사항
### struct
- 구조체
- C에서 자신만의 구조를 만들 수 있는 키워드
- 예를 들어 person structure과 같이 두개의 값을 가진 우리만의 자료 종류를 만들 수 있음
- 추후 비트맵이나 비트맵 헤더 등과 관련된 문제에서도 구조체를 사용

### . 
- dot
- 구조체의 속성값에 접근할 때 사용 (변수 이름과 점 연산자 사용하여 자료구조에 들어감)
- 예를 들어 RGB 픽셀 조작시 사용

### *
- star operator
- 메모리 덩어리로 접근할 수 있는 역참조 연산자 (포인터를 이용해서)

## malloc과 포인터
- 아래의 y 값을 제대로 할당해놓지 않으면 오류가 뜸
```c
#include <stdlib.h>

int main(void)
{
    int *x; // x 포인터 설정
    int *y; // y 포인터 설정

    x = malloc(sizeof(int)); // 메모리 공간 확보 (포인티)
    y = x; // 메모리 공간 확보 (포인티)

    *x = 42; // 역참조 연산자 (포인티에 접근)
    *y = 13;
}
```

## 배열의 크기 조정
- Big O로 돌아가서,
    - O(n) : insert, O(log n) : search
- 배열의 크기는 포인터를 malloc에 지정하는 방법과, realloc으로 재조정하는 두가지 방안이 있음
- 포인터를 malloc에 지정하는 방법
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int 자료형 3개로 이루어진 list라는 포인터를 선언하고 메모리 할당
    int *list = malloc(3 * sizeof(int));
    
    // 메모리가 잘 선언되었는지 확인
    if (list == NULL)
    {
        return 1;
    }

    // list 배열의 각 인덱스에 값 저장
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    
    // tmp에 포인터 메모리 할당하고 list의 값 복사
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        return 1;
    }

    // Copy integers from old array into new array
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    // tmp 배열의 네번째 값도 저장
    tmp[3] = 4;

    // list 메모리를 초기화
    free(list);

    list = tmp;

    // 새로운 배열 list의 값 확인
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // list의 메모리 초기화
    free(list);
}
```

- realloc으로 재지정하는 방법
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // tmp 포인터에 메모리를 할당하고 list의 값을 복사
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        return 1;
    }

    // list가 tmp와 같은 곳을 가리키도록 지정
    list = tmp;

    // 새로운 list의 네번째 값 저장
    list[3] = 4;

    // list의 값 확인
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // list의 메모리 초기화
    free(list);
}
```


## 연결리스트 (linked list)
## 도입
### 배열의 단점 
- 배열은 고정된 메모리 덩어리로
- 배열의 크기를 조절해서 더 많은 값을 넣고 싶으면 많은 메모리를 할당, 값들을 복사, free 등의 일련의 과정 겪어야함  
### 배열의 장점
- 인덱싱 가능
- 랜덤 접근 등으로 빠름 

### 연결리스트의 단점
- 배열은 랜덤 접근이 가능하지만 연결리스트는 각 node들을 따라 이동해야함
- 랜덤 접근은 이진 검색으로 O(log n) 이지만 연결리스트는 실행시간이 O(n)이 됨
    - insert, search 모두 O(n)

### 연결리스트의 장점
- 새로운 값을 추가할 때 다시 메모리를 할당하지 않아도 됨

**그림1 _ 220804 추가**
- NULL
    - \0인 NUL과 다른 것임
    - NULL은 포인터임
    - NUL과 NULL은 둘다 값이 0임
- Node
    - 직사각형으로 나타낼 수 있는 메모리 덩어리

```c
typedef struct node
{
    int number;
    struct node *next;
}
node;
```
- number : 각 node가 가지는 값
- *next : 다음 node structure를 가리키는 포인터 
- typedef struct 대신 typedef struct node라고 'node'를 함께 명시해주는 이유는 구조체 안에서 node를 사용하기 위함임 (문법적 사항)

## 구현
### 1. 첫 연결 리스트 나타내기
**그림**
- list가 비어있으며 빈박스는 node를 가르키는 포인터라고 봤을 때
```c
node *list = NULL;
```

### 2. 리스트에 숫자 2 추가
**그림**
- 숫자 2와 포인터를 넣을 공간을 할당 (node)
```c
node *n = malloc(sizeof(node)); // 여기서 n은 임시 변수
if (n != NULL) // malloc 사용시 n이 NULL이 아닌지 확인 필수!
{
n->number = 2; //node의 number을 2로 설정
// (*n).number = 2;
n->next = NULL;
}
```

### 3. list와 node를 연결
**그림**
```c
list = n;
```
- list라는 변수가 있고 원래는 NULL로 초기화 되어 있었지만
- n은 새로운 node를 가지고 있는 임시변수임 --> list는 더이상 NULL이 아님

### 4. 리스트에 숫자 4 추가
**그림**
```c
node *n = malloc(sizeof(node));
if (n != NULL)
{
    n->number = 4;
    n->next = NULL;
}
```

### 5. 4에 화살표 추가
**그림**
```c
node *tmp = list; // list를 가리키는 포인터 만들기
while (tmp->next != NULL)
{
    tmp = tmp->next; // 가리키는 곳(next)이 null이 아니면 다음의 코드를 실행
}
tmp->next = n;
```

### 6. 리스트에 숫자 5 추가
**그림**
```c
node *n = malloc(sizeof(node));
if (n != NULL)
{
    n->number = 5;
    n->next = NULL;
}
```

### 7. 5에 화살표 추가
**그림**
```c
node *tmp = list;
while (tmp->next != NULL)
{
    tmp = tmp->next;
}
tmp->next = n;
```
### 8. 리스트에 숫자 1 추가
**그림**
```c
node *n = malloc(sizeof(node));
if (n != NULL)
{
    n->number = 1;
    n->next = NULL;
}
```

### 9. 1을 사이에 추가
**그림(잘못된)**
**그림(제대로)**
```c
n->next = list; // n->next를 list가 가르키고 있는 곳을 가르키도록 만듦
list = n; // list는 n 그 자체를 가르키도록 하면 됨
