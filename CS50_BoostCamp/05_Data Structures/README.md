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

<img width="400" alt="그림1_220804" src="https://user-images.githubusercontent.com/96214306/183237829-0405ae9a-70a1-4936-b0bc-c5428026a74c.png">  
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
<img width="400" alt="Screen Shot 2022-08-04 at 3 28 01 PM" src="https://user-images.githubusercontent.com/96214306/183237886-34a38cbd-5b9a-48ab-b8fe-7fc846161b3a.png">  

- list가 비어있으며 빈박스는 node를 가르키는 포인터라고 봤을 때
```c
node *list = NULL;
```

### 2. 리스트에 숫자 2 추가
<img width="400" alt="Screen Shot 2022-08-04 at 3 31 04 PM" src="https://user-images.githubusercontent.com/96214306/183237896-32605a32-b0f0-4cd4-b3fe-3d41b5d1a2f8.png">
  
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
<img width="400" alt="Screen Shot 2022-08-04 at 3 37 28 PM" src="https://user-images.githubusercontent.com/96214306/183237909-341f5a81-047b-4c51-817a-a4dace15f195.png">
  
```c
list = n;
```
- list라는 변수가 있고 원래는 NULL로 초기화 되어 있었지만
- n은 새로운 node를 가지고 있는 임시변수임 --> list는 더이상 NULL이 아님

### 4. 리스트에 숫자 4 추가
<img width="500" alt="Screen Shot 2022-08-04 at 3 39 21 PM" src="https://user-images.githubusercontent.com/96214306/183237926-5fdb75c7-42f9-4dc0-a860-d687dcc9ee34.png">
  
```c
node *n = malloc(sizeof(node));
if (n != NULL)
{
    n->number = 4;
    n->next = NULL;
}
```

### 5. 4에 화살표 추가
<img width="500" alt="Screen Shot 2022-08-04 at 3 45 14 PM" src="https://user-images.githubusercontent.com/96214306/183237939-7249c270-32c9-4025-b845-2179ec9ccd64.png">
  
```c
node *tmp = list; // list를 가리키는 포인터 만들기
while (tmp->next != NULL)
{
    tmp = tmp->next; // 가리키는 곳(next)이 null이 아니면 다음의 코드를 실행
}
tmp->next = n;
```

### 6. 리스트에 숫자 5 추가
<img width="500" alt="Screen Shot 2022-08-04 at 4 14 35 PM" src="https://user-images.githubusercontent.com/96214306/183237950-6060031e-478f-48e4-849e-fefedd54485c.png">
  
```c
node *n = malloc(sizeof(node));
if (n != NULL)
{
    n->number = 5;
    n->next = NULL;
}
```

### 7. 5에 화살표 추가
<img width="500" alt="Screen Shot 2022-08-04 at 4 14 45 PM" src="https://user-images.githubusercontent.com/96214306/183237967-72bba2cc-0a08-4515-85fd-b17d38bbf8f8.png">
  
```c
node *tmp = list;
while (tmp->next != NULL)
{
    tmp = tmp->next;
}
tmp->next = n;
```
### 8. 리스트에 숫자 1 추가
<img width="500" alt="Screen Shot 2022-08-04 at 4 15 19 PM" src="https://user-images.githubusercontent.com/96214306/183237975-354be664-b2a0-414f-abb2-094b1322673b.png">
  
```c
node *n = malloc(sizeof(node));
if (n != NULL)
{
    n->number = 1;
    n->next = NULL;
}
```

### 9. 1을 사이에 추가
<img width="550" alt="Screen Shot 2022-08-04 at 4 16 06 PM" src="https://user-images.githubusercontent.com/96214306/183237983-bdb28978-2db7-41fb-9929-4e1e4981920c.png">  
<img width="550" alt="Screen Shot 2022-08-04 at 4 17 12 PM" src="https://user-images.githubusercontent.com/96214306/183237986-f324506e-1469-4efb-9e72-14c81dd8a2a3.png">  

```c
n->next = list; // n->next를 list가 가르키고 있는 곳을 가르키도록 만듦
list = n; // list는 n 그 자체를 가르키도록 하면 됨
```

# 트리
<img width="450" alt="Screen Shot 2022-08-06 at 11 55 34 AM" src="https://user-images.githubusercontent.com/96214306/183238004-21eb8866-67b0-4c6d-888b-f19f09066f39.png">
  
- 연결 리스트를 기반으로 한 새로운 데이터 구조
- 트리에서의 노드들의 연결은 2차원 적으로 구성되어 있음
    - 가장 높은 층은 '루트', 다음 층은 '자식 노드'
    - 예를 들어 이진 검색 트리를 들 수 있음 
    - 검색시간과 삽입시간 모두 O(log n)

# 해시테이블
- 연결리스트의 배열 
- 여러 값들을 몇 개의 바구니에 나눠 담을 때 각 값들은 '해시함수'라는 맞춤형 함수를 통해 어떤 바구니에 담기는지가 결정됨
- 이상적인 검색 시간 : O(1) , 최악의 검색 시간 : O(n)
<img width="550" alt="Screen Shot 2022-08-06 at 2 49 55 PM" src="https://user-images.githubusercontent.com/96214306/183238016-43b74c0d-5c60-467b-a69f-ea9d381006ff.png">  
- 첫 알파벳으로 구분하는 경우 충돌이 일어나면 그 뒤에 연결리스트를 만듦
- 충돌이 없게 하려면 공간을 많이 사용해야하고 해시테이블은 공간과 속도 사이의 일종의 긴장이 있다고 보면 됨
- 

# 트라이 (Tries)
<img width="550" alt="Screen Shot 2022-08-06 at 2 50 11 PM" src="https://user-images.githubusercontent.com/96214306/183238024-97ac6111-7ce1-4ed1-9dd5-bee656d7c3be.png">
  
- 각 노드가 '배열'로 이루어져 있음
- 값을 검색하는데 걸리는 시간은 '문자열의 길이'
    - 예를 들어 영어 이름의 길이가 n이라고 했을 때 검색시간은 O(n)이지만 이름은 그리 크지 않은 상수값이므로 O(1)과 마찬가지임
- 속도가 빠르나 많은 메모리를 차지하는 것이 단점임

# 큐 (queue)
- First In First Out
- 예를 들어 패스트푸드 집, 프린터 사용할 때 (요청 순으로)
    - enqueue : In queue
    - dequeue : Out queue
- 배열이나 연결 리스트를 통해 구현이 가능

# 스택 (Stacks)
- Last In First Out
- 예를 들어 이메일, 식당의 트레이
    - push : adding
    - pop : removing
- 배열이나 연결 리스트를 통해 구현이 가능

# 딕셔너리 (Dictionary)
- '키'와 '값'이라는 요소로 이루어져 있음
- 일반적인 의미에서 '해시 테이블'과 동일한 개념
