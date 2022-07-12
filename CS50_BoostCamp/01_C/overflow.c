#include <stdio.h>
#include <unistd.h> //sleep을 구현하기 위해 필요한 라이브러리 ; uni standard .h

int main(void)
{
    for (int i = 1; ; i *= 2)
        {
            printf("%i\n", i);
            sleep(1);
        }

}