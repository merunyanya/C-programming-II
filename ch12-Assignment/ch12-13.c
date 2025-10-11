/*
학번: 202511859
이름 : 최정현
프로그램명: assignment13
날짜: 25.11.10
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void assignment13();
int* createRandom(int n);
void saveTextFile(const char* filename, int* arr, int n);
void saveBFile(const char* filename, int* arr, int n);

int main()
{
    assignment13();
    return 0;
}

void assignment13()
{
    int n;
    char txtFile[100] = "a.txt";
    char binFile[100] = "a.dat";

    printf("정수의 개수? ");
    scanf("%d", &n);

    int* arr = createRandom(n);
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }

    saveTextFile(txtFile, arr, n);
    saveBFile(binFile, arr, n);

    printf("%s와 %s를 생성했습니다.\n", txtFile, binFile);
    free(arr);
}

int* createRandom(int n)
{
    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL) return NULL;

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }

    return arr;
}

void saveTextFile(const char* filename, int* arr, int n)
{
    FILE* fp;
    fopen_s(&fp, filename, "w");
    if (fp == NULL)
    {
        printf("텍스트 파일 저장 실패\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
}

void saveBFile(const char* filename, int* arr, int n)
{
    FILE* fp;
    fopen_s(&fp, filename, "wb");
    if (fp == NULL)
    {
        printf("2진 파일 저장 실패\n");
        return;
    }

    fwrite(&n, sizeof(int), 1, fp);
    fwrite(arr, sizeof(int), n, fp);

    fclose(fp);
}