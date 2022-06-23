/* 마일(mile)을 킬로미터(kilometer)로 변환 프로그램 */

#include <stdio.h> /* printf, scanf 함수원형 */

int main(void)
{
    double miles, kilometer;
    
    /* 1. 마일(miles) 데이터 입력 */
    printf("Enter the distance in miles> ");
    scanf("%lf", &miles);

    /* 2. 마일을 킬로미터로 변환 */
    kilometer = 1.609 * miles;

    /* 3. 킬로미터 데이터 출력 */
    printf("That equals %f kilometers.\n", kilometer);
    return 0;

}