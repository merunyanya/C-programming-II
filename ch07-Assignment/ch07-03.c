/*
학번: 202511859
이름: 최정현
프로그램명:Assignment03
날짜: 25.09.24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void assignment03();

int main()
{
    assignment03();
    return 0;
}


void assignment03()
{
    int num[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int max = num[0];
    int min = num[0];
    int i = 0, j = 0;

    printf("배열: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");

    for (i = 1; i < 10; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
        }
        if (num[i] < min)
        {
            min = num[i];
        }
    }
    printf("최댓값: %d\n", max);
    printf("최솟값: %d\n", min);

    return;
}