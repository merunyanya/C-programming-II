/*
학번: 202511859
이름 : 최정현
프로그램명: assignment04
날짜: 25.11.09
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct login
{
    char ID[MAX];
    char PASSWORD[MAX];

}LOGIN;


void assignment04();
int User(const char* fileanme, LOGIN login[]);
int login(LOGIN login[], int count, const char* inputId, const char* inputPw);


int main()
{
    assignment04();
    return 0;
}


void assignment04()
{

    LOGIN login[MAX];
    int user = User("password.txt", login);

    char inputId[MAX];
    char inputPw[MAX];

    printf("ID: ");
    scanf_s("%s", inputId, (unsigned)_countof(inputId));
    printf("Password: ");
    scanf_s("%s", inputPw, (unsigned)_countof(inputPw));

    if (checkLogin(login, user, inputId, inputPw))
    {
        printf("로그인 성공!\n");
    }
    else {
        printf("지정된 ID / Password를 찾을 수 없습니다.\n");
    }

}


int User(const char* filename, LOGIN login[])
{
    FILE* fp;
    int count = 0;

    if (fopen_s(&fp, filename, "r") != 0) {
        printf("파일을 열 수 없습니다: %s\n", filename);
        return 0;
    }

    while (fscanf(fp, "%s %s", login[count].ID, login[count].PASSWORD) == 2)
    {
        count++;
        if (count >= MAX) break;
    }

    fclose(fp);
    return count;

}

int checkLogin(LOGIN login[], int count, const char* inputId, const char* inputPw)
{
    for (int i = 0; i < count; i++) {
        if (strcmp(login[i].ID, inputId) == 0 && strcmp(login[i].PASSWORD, inputPw) == 0)
        {
            return 1;
        }
    }
    return 0;
}

