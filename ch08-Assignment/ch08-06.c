/*
학번: 202511859
이름: 최정현
프로그램명:Assignment06
날짜: 25.09.24
*/

#include <stdio.h>

void assignment06();

int main()
{
    assignment06();
    return 0;
}

void get_min_max(int arr[], int size, int* min, int* max)
{
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

void assignment06()
{
    int x[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int min_val, max_val;

    printf("배열: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");

    get_min_max(x, 10, &min_val, &max_val);

    printf("최댓값: %d\n", max_val);
    printf("최솟값: %d\n", min_val);
}