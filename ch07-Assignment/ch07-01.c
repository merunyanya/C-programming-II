/*
학번: 202511859
이름: 최정현
프로그램명:Assignment01
날짜: 25.09.24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void assignment01();
void CD(int a[], int d, int start);

int main()
{
    assignment01();
    return 0;
}

void assignment01()
{

    int a[10];
    int start = 0, d = 0;

    printf("첫 번째 항?");
    scanf("%d", &start);

    printf("공차?");
    scanf("%d", &d);

    CD(a, d, start);

    printf("등차수열: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    return;
}
void CD(int a[], int d, int start)
{
    a[0] = start;
    for (int i = 1; i < 10; i++)
    {
        a[i] = a[i - 1] + d;
    }
    return a;
}