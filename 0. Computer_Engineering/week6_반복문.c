// for예제 : ********* 문자 5줄 찍기
#include <stdio.h>
int main(void)
{
    int i;

    printf("printf 5줄 실행예시\n");
    printf("*********\n");
    printf("*********\n");
    printf("*********\n");
    printf("*********\n");
    printf("*********\n\n");

    printf("for 5번 반복 실행예시\n");
    for (i = 0; i < 5; i++)
    {
        printf("*********\n");
    }

    return 0;

}

//-----------------------------------
// for예제 : 1부터 777까지의 합 구하기
#include <stdio.h>
int main(void)
{
    int i, sum;
    sum = 0; // 지역변수 초기화 (없을 시, garbage value 나옴)
    for (i = 1; i <= 777; i++)
    {
        sum += i; // sum = sum + i
    }

    printf("부터 777까지의 합: %d \n", sum);

    return 0;
}

//-----------------------------------
// 성적처리 반복문 설계
#include <stdio.h>
int main(void)
{   int i, stuNum, stuID, csed101;
    char grade;
    float total = 0;

    printf("*** 컴퓨터공학입문 성적 ***\n");
    printf("수강인원을 입력하세요: ");
    scanf("%d", &stuNum);

    for(i=0; i<stuNum; i++)
    {
        printf("학번과 점수를 순서대로 입력하세요: ");
        scanf("%d%d", &stuID, &csed101);
        total += csed101;
        if (csed101 >= 90)
            grade = 'A';
        else if (csed101 >= 80)
            grade = 'B';
        else if (csed101 >= 70)
            grade = 'C';
        else if (csed101 >= 60)
            grade = 'D';
        else
            grade = 'F';
        printf("학번: %d, 학점: %c\n", stuID, grade);
    }
printf("과목평균: %5.2f\n", total/stuNum);
return 0;
}

//-----------------------------------
// while 예제 : ********* 문자 5줄 찍기
#include <stdio.h>
int main(void)
{
    int i = 1;

    printf("printf 5줄 실행예시\n");
    printf("*********\n");
    printf("*********\n");
    printf("*********\n");
    printf("*********\n");
    printf("*********\n\n");

    printf("while 5번 반복 실행예시\n");
    while (i<=5)
    {
        printf("*********\n");
        i++;
    }

    return 0;

}

//-----------------------------------
// while 예제 : 1부터 888까지의 합 구하기
#include <stdio.h>
int main(void)
{
    int i=1, sum=0;

    while(i <= 888)
    {
        sum += i;
        i++;
    }

printf("1부터 888까지의 합: %d \n", sum);
return 0;
}

//-----------------------------------
// do-while 예제 : 1부터 999까지의 합 구하기
#include <stdio.h>
int main(void)
{
    int i, sum;

    sum = 0;
    i = 1;

    do
    {
        sum += i;
        i++;
    }
    while(i<=999);

    printf("1부터 999까지의 합: %d\n", sum);
    return 0;
}