#include <cs50.h>
#include <stdio.h>

const int N = 3;

int main(void)
{
    // 점수 배열 선언 및 값 저장
    int scores[N];
    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 33;

    // 평균 점수 출력
    printf("Average: %i\n", (scores[0] + scores[1] + scores[2])/ N);
}