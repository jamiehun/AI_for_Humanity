#include <stdio.h>

int main(int argc, char *argv[])
{
    // Ensure user ran program with two words at prompt
    if (argc != 2)
    {
        return 1;
    }

    // Open File
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 1;
    }

    // Read 3 bytes from file
    // fread를 활용해서 파일에서 첫 3바이트를 읽어옴
    // fread의 인자 = (배열, 읽을 바이트 수, 읽을 횟수, 읽을 파일)
    unsigned char bytes[3];
    fread(bytes, 3, 1, file);

    // Check if bytes are 0xff 0xd8 0xff
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("Maybe\n");
    }   
    else
    {
        printf("No\n");
    }
}