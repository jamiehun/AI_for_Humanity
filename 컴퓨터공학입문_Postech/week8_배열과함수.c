#include <stdio.h>

int main(void)
{
    int score[5] = {10, 20, 30, 40, 50};
    int i, n, sum=0;

    n = sizeof(score) / sizeof(int); // 배열 원소의 수, sizeof는 전체 배열 byte 수

    printf("\n ** score 배열 ** \n");
    for( i=0; i<n; ++i)
    {
        printf(" score[%d] : %d\n", i, score[i]); // 배열원소 값
    }
    printf("\n ** score 배열주소 ** \n");
    for ( i=0; i<n; ++i)
    {
        printf(" &score[%d] : %d\n", i, &score[i]); // 배열원소 주소값
    }
    for (i=0; i<n; ++i)
    {
        sum += score[i]; // sum = sum + score[i] 배열 원소의 합
    }

    printf("\n 배열합: %4d\n", sum);
    return 0;
}

// ---------------------------------------------------------------------------
// 함수와 배열
#include <stdio.h>
void add_arrays(const int a[], const int b[], int absum[], int n);
int main(void)
{
    int x[5] = {10, 20, 30, 40, 50};
    int y[5] = {45, 55, 33, 28, 35};
    int xysum[5] = {0};
    int i = 0, n = 5;

    printf("\n x 배열원소 출력: ");
    for ( i=0; i<n; ++i)
    { printf("%3d", x[i]); }

    printf("\n\n y 배열원소 출력: ");
    for (i=0; i<n; ++i)
    { printf("%3d", y[i]); }

    add_arrays(x, y, xysum, n); // 함수 호출

    printf("\n\n x + y 결과 출력: ");
    for (i=0; i<n; ++i)
    { printf("%3d", xysum[i]); }
    return 0;
}

void add_arrays(const int a[], const int b[], int absum[], int n)
{
    int i;
    for (i=0; i<n; ++i)
    { //main의 xy[i]값을 직접 바꿈
        absum[i] = a[i] + b[i];
    }
}

// ---------------------------------------------------------------------------
#include <stdio.h>
#define MAX 3
// 구조체 정의 (사용자 정의 자료형 만들기)
struct stu
    {
        int ID;
        float kor, eng, math;
        float avg;
        char grade; };

int main(void)
{
    struct stu s[MAX]; // 구조체 변수(배열) 선언
    float korsum = 0, engsum = 0, mathsum = 0; // 변수 선언
    int i, j;

    printf("학번, 점수(국어, 영어, 수학)을 입력하세요.\n");

    for(i=0; i<MAX; i++)
    {
        scanf("%d %f %f %f", &s[i].ID, &s[i].kor, &s[i].eng, &s[i].math);
    }

    printf("\n입력된 점수\n"); // 입력된 점수 출력
    for(i=0; i<MAX; i++)
    {
        printf("%d %5.2f %5.2f %5.2f\n", s[i].ID, s[i].kor, s[i].eng, s[i].math);
    }

    for(i=0; i<MAX; i++)
    {
        s[i].avg = (s[i].kor + s[i].eng + s[i].math)/3.0; // 평균 계산
        korsum += s[i].kor;
        engsum += s[i].eng;
        mathsum += s[i].math;
    }

    for(i=0; i<MAX; i++) // 학점 계산
    {
        if(s[i].avg>=90)
            s[i].grade = 'A';
        else if(s[i].avg>=80)
            s[i].grade = 'B';
        else if(s[i].avg>=70)
            s[i].grade = 'C';
        else if(s[i].avg>=60)
            s[i].grade = 'D';
        else 
            s[i].grade = 'F';
    }

    printf("\n ** 성적 ** \n"); // 학번, 평균, 학점 출력
    
    for(i=0; i<MAX; i++)
        printf("학번 : %5d\t 평균: %5f\t 학점: %c\n", s[i].ID, s[i].avg, s[i].grade);

    printf("\n ** 과목별 평균 ** \n");
    printf("국어: %5.2f 영어: %5.2f 수학: %5.2f\n", korsum/MAX, engsum/MAX, mathsum/MAX);
    return 0;

}