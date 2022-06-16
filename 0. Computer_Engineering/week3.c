/* 함수 호출 방법 */

#include<stdio.h>
int sum(int a, int b);
void swap(int *p, int *q);

int main(void)
{
    int a, b, total;

    printf("Input two integers :");
    scanf("%d%d", &a, &b);
    printf("a:%d, b:%d \n", a, b);
    total = sum(a, b);
    
    printf("** sum function call ** \n");
    printf("%d + %d = %d \n", a, b, total);

    swap(&a, &b);
    printf("** swap function call**\n");
    printf("a:%d, b:%d \n", a, b);
    return 0;
}

int sum(int a, int b)
{
    int total;
    total = a + b;
    return total;
}

void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}


//-----------------------------------
/* 사칙연산 예제 : 2개의 값을 입력받아 + - * / % 연산 후 출력 */

#include <stdio.h>
int main(void)
{
    int x, y, add, sub, mul, div, mod;
    printf("정수1 입력하세요 : ");
    scanf("%d", &x);

    printf("정수2 입력하세요 : ");
    scanf("%d", &y);

    add = x + y;
    sub = x - y;
    mul = x * y;
    div = x / y;
    mod = x % y;

    printf(" %d + %d = %d 입니다\n", x, y, add);
    printf(" %d - %d = %d 입니다\n", x, y, sub);
    printf(" %d * %d = %d 입니다\n", x, y, mul);
    printf(" %d / %d = %d 입니다\n", x, y, div);
    printf(" %d %% %d = %d 입니다\n", x, y, mod);
    return 0;
}


//-----------------------------------
/* 관계연산예제 : 문자와 정수를 입력받아 관계연산 결과 출력 */

#include <stdio.h>
int main(void)
{
    int x, y;
    char c;

    printf("문자1개 입력하세요 : ");
    scanf("%c", &c);

    printf("입력한 문자 %c의 아스키진수는 %d 입니다\n", c, c);
    printf("입력한 문자 %c의 다음 문자는 %c 입니다\n", c, c+1);
    printf("(%c < %c)는 %d 입니다\n", c, c+1, (c < c + 1));

    printf("정수 2개 입력하세요 : ");
    scanf("%d%d", &x, &y);
    printf(" (%d >= %d)는 %d입니다\n", x, y, (x>=y));
    printf(" (%d == %d)는 %d입니다\n", x, y, (x==y));
    printf(" (%d != %d)는 %d입니다\n", x, y, (x!=y));

    return 0;
}


//-----------------------------------
/* 관계연산예제 : 문자와 정수를 입력받아 관계연산 결과 출력 */
#include <stdio.h>
int main(void)
{
    printf(" (3>2) && (1==2)의 결과는 %d 입니다.\n", (3>2) && (1==2));
    printf(" (3>2) || (1==2)의 결과는 %d 입니다.\n", (3>2) || (1==2));
    printf(" 0.0 && 5의 결과는 %d 입니다.\n", 0.0 && 5);
    printf(" (5>2) != (1==2)의 결과는 %d 입니다.\n", (5>2) != (1==2));
    printf(" (3>5) || !(2==1)의 결과는 %d 입니다.\n", (3>5) || !(2==1));
    printf(" 0.1 || 0.0의 결과는 %d 입니다.\n", 0.1 || 0.0);
    printf(" ('A' < 'B') || 0.0의 결과는 %d 입니다.\n", ('A' < 'B') || 0.0);
    return 0;
}