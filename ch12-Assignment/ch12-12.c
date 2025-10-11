/*
학번: 202511859
이름 : 최정현
프로그램명: assignment12
날짜: 25.11.10
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define LEN 50

typedef struct
{
    char name[LEN];
    char phone[LEN];

} CONTACT;


int loadContacts(const char* filename, CONTACT contacts[]);
void printContacts(CONTACT contacts[], int count);
int findContact(CONTACT contacts[], int count, const char* name);
int addContact(CONTACT contacts[], int count, const char* name);
void saveContacts(const char* filename, CONTACT contacts[], int count);
void assignment12();


int main()
{
    assignment12();
    return 0;
}


void assignment12()
{
    CONTACT contacts[MAX];
    int count = 0;
    char filename[100];
    char inputName[LEN];

    printf("연락처 파일명? ");
    scanf("%s", filename);

    count = loadContacts(filename, contacts);
    printf("%d개의 연락처를 로딩했습니다.\n", count);

    printf("이름(. 입력시 종료)? ");
    scanf("%s", inputName);

    int index = findContact(contacts, count, inputName);
    if (index != -1)
    {
        printf("전화번호: %s\n", contacts[index].phone);
    }
    else
    {
        printf("연락처가 없습니다. 새 연락처를 등록하시겠습니까? (y/n): ");
        char answer;
        scanf(" %c", &answer);
        if (answer == 'y' || answer == 'Y') {
            count = addContact(contacts, count, inputName);
        }
    }

    saveContacts(filename, contacts, count);
    printf("%s를 %d개의 연락처로 저장했습니다.\n", filename, count);
}


int loadContacts(const char* filename, CONTACT contacts[])
{
    FILE* fp;
    int count = 0;

    fopen_s(&fp, filename, "r");
    if (fp == NULL) return 0;

    while (fscanf(fp, "%s %s", contacts[count].name, contacts[count].phone) == 2)
    {
        count++;
        if (count >= MAX) break;
    }

    fclose(fp);
    return count;
}



int findContact(CONTACT contacts[], int count, const char* name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(contacts[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int addContact(CONTACT contacts[], int count, const char* name)
{
    if (count >= MAX) {
        printf("더 이상 추가할 수 없습니다.\n");
        return count;
    }

    strcpy(contacts[count].name, name);
    printf("전화번호 입력: ");
    scanf("%s", contacts[count].phone);
    return count + 1;
}

void saveContacts(const char* filename, CONTACT contacts[], int count)
{
    FILE* fp;
    fopen_s(&fp, filename, "w");
    if (fp == NULL)
    {
        printf("파일 저장 실패\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %s\n", contacts[i].name, contacts[i].phone);
    }

    fclose(fp);
}

void printContacts(CONTACT contacts[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("이름: %s\n", contacts[i].name);
        printf("전화번호: %s\n", contacts[i].phone);
    }
}