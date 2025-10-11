/*
학번: 202511859
이름 : 최정현
프로그램명: assignment14
날짜: 25.11.10
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void assignment14();
int* readBFile(const char* filename, int* size);
void sortArray(int* arr, int size);
void saveBFile(const char* filename, int* arr, int size);


int main()
{
    assignment14();
    return 0;
}


void assignment14()
{
    char file1[100], file2[100], outFile[100];
    int size1, size2;

    printf("첫 번째 파일명: ");
    scanf("%s", file1);
    int* arr1 = readBFile(file1, &size1);
    if (arr1 == NULL) return;
    printf("정수 %d개를 읽었습니다.\n", size1);

    printf("두 번째 파일명: ");
    scanf("%s", file2);
    int* arr2 = readBFile(file2, &size2);
    if (arr2 == NULL)
    {
        free(arr1);
        return;
    }
    printf("정수 %d개를 읽었습니다.\n", size2);

    int total = size1 + size2;
    int* merged = (int*)malloc(sizeof(int) * total);
    if (merged == NULL)
    {
        printf("메모리 할당 실패\n");
        free(arr1);
        free(arr2);
        return;
    }

    for (int i = 0; i < size1; i++) merged[i] = arr1[i];
    for (int i = 0; i < size2; i++) merged[size1 + i] = arr2[i];

    free(arr1);
    free(arr2);

    printf("정수 %d개를 읽었습니다.\n", total);

    sortArray(merged, total);

    printf("저장할 파일명: ");
    scanf("%s", outFile);
    saveBFile(outFile, merged, total);
    printf("%s에 정수 %d개를 저장했습니다.\n", outFile, total);

    free(merged);
}


int* readBFile(const char* filename, int* size)
{
    FILE* fp;
    fopen_s(&fp, filename, "rb");
    if (fp == NULL)
    {
        printf("파일 열기 실패: %s\n", filename);
        return NULL;
    }

    fread(size, sizeof(int), 1, fp);
    int* arr = (int*)malloc(sizeof(int) * (*size));
    if (arr == NULL)
    {
        fclose(fp);
        return NULL;
    }

    fread(arr, sizeof(int), *size, fp);
    fclose(fp);
    return arr;
}



void sortArray(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void saveBFile(const char* filename, int* arr, int size)
{
    FILE* fp;
    fopen_s(&fp, filename, "wb");
    if (fp == NULL)
    {
        printf("파일 저장 실패: %s\n", filename);
        return;
    }

    fwrite(&size, sizeof(int), 1, fp);
    fwrite(arr, sizeof(int), size, fp);
    fclose(fp);
}