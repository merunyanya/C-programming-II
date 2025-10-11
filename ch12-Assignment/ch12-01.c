/*
학번: 202511859
이름 : 최정현
프로그램명: assignment01
날짜: 25. 11. 09
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void assignment1201();

int main()
{
    assignment1201();
    return 0;
}

void assignment1201()
{
    char filename[100];
    FILE* fp;
    char line[256];
    int lineNumber = 1;

    printf("파일명? ");
    scanf_s("%s", filename, 100);

    if (fopen_s(&fp, filename, "r") != 0)
    {
        printf("파일을 열 수 없습니다: %s\n", filename);
        return;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%d: %s", lineNumber, line);
        lineNumber++;
    }

    fclose(fp);
}