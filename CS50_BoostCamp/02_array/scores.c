#include <stdio.h>

const int N = 3;

int main(void)
{
    int score[N];
    score[0] = 72;
    score[1] = 73;
    score[2] = 33;

    printf("Average: %i\n", ((score[0]+score[1]+score[2])/ N));
}