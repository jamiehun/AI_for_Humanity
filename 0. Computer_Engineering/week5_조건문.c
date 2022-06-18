// if-else 예제 : 2개의 값을 입력받아 짝수와 홀수를 판별
#include <stdio.h>
int main(void)
{
    int number;
    printf("정수 1개를 입력하세요 : ");
    scanf("%d", &number);

    if (number % 2 == 0)
        printf("입력한 %d는 짝수입니다. \n", number);
    
    else 
        printf("입력한 %d는 홀수입니다. \n", number);
    
    return 0;

}


// -------------------------------------------------
// if-else 예제 : 2개의 값을 입력받아 큰 값 (max)를 출력

#include <stdio.h>
int main(void)
{
    int x, y, max;
    printf("Input two integers: ");
    scanf("%d%d", &x, &y);

    if (x > y)
        max = x;
    else
        max = y;
    
    printf("The maximum value is %d\n", max);
    return 0;

}
*/

// -------------------------------------------------
// if-else 예제 : 3개의 값을 입력받아 가장 작은 값(min)을 출력

#include <stdio.h>
int main(void)
{
    int x, y, z, min;
    printf("Input three integers: ");
    scanf("%d%d%d", &x, &y, &z);
    if (x < y)
    {
        min = x;
    }
    else 
    {
        min = y;
    }
    if (z < min)
    {
        min = z;
    }

    printf("The minimum value is %d\n", min);
    return 0;
}

// -------------------------------------------------
// if-else 예제 : 점수를 입력받아 성적을 출력

#include <stdio.h>
int main(void)
{
    int com101 = 0;
    printf("컴퓨터공학입문 점수를 입력하세요: ");
    scanf("%d", &com101);
    
    if (com101 >= 90)
        printf("컴퓨터공학입문 학점은 A 입니다.\n");
    
    else if (com101 >= 80)
        printf("컴퓨터공학입문 학점은 B 입니다.\n");
    
    else if (com101 >= 70)
        printf("컴퓨터공학입문 학점은 C 입니다.\n");

    else if (com101 >= 60)
        printf("컴퓨터공학입문 학점은 D 입니다.\n");

    else
    {
        printf("컴퓨터공학입문 학점은 F 입니다.\n");
    }
    printf("수고 많으셨습니다!\n");
    return 0;
}

// -------------------------------------------------
// switch 예제 : 윤년 계산
#include <stdio.h>
int main(void){
int year = 0, month = 0, maxDay = 0;
printf("* 년과 월을 입력하세요 : ");
scanf("%d %d", &year, &month);
switch(month)
{
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        maxDay = 31;
        printf("%d년 %d월의 말일은 %d일 입니다. \n", year, month, maxDay);
        break;
    
    case 4:
    case 6:
    case 9:
    case 11:
        maxDay = 30;
        printf("%d년 %d월의 말일은 %d일 입니다. \n", year, month, maxDay);
    
    case 2:
        if((year%4 ==0) && (year%100 != 0) || (year%400 == 0))
        {
            maxDay = 29;
            printf("%d년 %d월의 말일은 %d일(윤년)입니다.\n", year, month, maxDay);
            break;
        }
        else
        {
            maxDay = 28;
            printf("%d년 %d월의 말일은 %d일 입니다.\n", year, month, maxDay);
            break;
        }
    default:
    printf("입력이 잘못 되었습니다!\n");
}
return 0;
}
