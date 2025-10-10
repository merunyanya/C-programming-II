/*
학번: 202511859
이름: 최정현
프로그램명:Assignment04
날짜: 25.09.24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void assignment04();
int maximum(int a[], int size);
int minimum(int a[], int size);
void print_array(int a[], int size);

int a[10] = { 0 };

int main()
{

    assignment04();

    return 0;
}

void assignment04()
{
    int a[] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int size = sizeof(a) / sizeof(a[0]);

    printf("배열: ");
    print_array(a, size);

    int max_index = maximum(a, size);
    int min_index = minimum(a, size);

    printf("최댓값: 인덱스 = %d, 값 = %d\n", max_index, a[max_index]);
    printf("최솟값: 인덱스 = %d, 값 = %d\n", min_index, a[min_index]);



    return;

}
int maximum(int a[], int size)
{
    int max_index = 0;

    for (int i = 1; i < size; i++)
    {
        if (a[i] > a[max_index])
        {
            max_index = i;
        }
    }

    return max_index;
}

int minimum(int a[], int size)
{
    int min_index = 0;

    for (int i = 1; i < size; i++)
    {
        if (a[i] < a[min_index])
        {
            min_index = i;
        }
    }

    return min_index;
}

void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}