/*
학번: 202511859
이름 : 최정현
프로그램명: assignment03
날짜: 25.11.09
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> 

void assignment03();
void printArray(int alphabetCount[]);

int main()
{
    assignment03();
    return 0;
}

void assignment03()
{
    char filename[100];
    FILE* fp;
    char line[256];
    int alphabetCount[26] = { 0 };
    int lineNumber = 1;

    printf("파일명? ");
    scanf_s("%s", filename, (unsigned)_countof(filename));

    if (fopen_s(&fp, filename, "r") != 0)
    {
        printf("파일을 열 수 없습니다: %s\n", filename);
        return;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%d: %s", lineNumber, line);
        lineNumber++;

        for (int i = 0; line[i] != '\0'; i++)
        {
            if (isalpha(line[i]))
            {
                char lower = tolower(line[i]);
                alphabetCount[lower - 'a']++;
            }
        }
    }

    fclose(fp);
    printArray(alphabetCount);
}

void printArray(int alphabetCount[])
{
    for (int i = 0; i < 26; i++)
    {
        printf("%c: %d", 'a' + i, alphabetCount[i]);
    }
    printf("\n");
}