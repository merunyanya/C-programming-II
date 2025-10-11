/*
학번: 202511859
이름 : 최정현
프로그램명: assignment11
날짜: 25.11.09
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct
{
    char name[MAX_LEN];
    char phone[MAX_LEN];

} CONTACT;


int getCount(const char* filename);
CONTACT* loadContacts(const char* filename, int count);
void printContacts(CONTACT* contacts, int count);
void assignment11();

int main()
{
    assignment11();
    return 0;
}

void assignment11()
{
    char filename[100];
    CONTACT* contacts = NULL;

    printf("연락처 파일명? ");
    scanf("%s", filename);

    int count = getCount(filename);
    if (count == 0) {
        printf("연락처를 불러올 수 없습니다.\n");
        return;
    }

    contacts = loadContacts(filename, count);
    if (contacts == NULL) {
        printf("메모리 할당 실패.\n");
        return;
    }

    printf("%d개의 연락처를 로딩했습니다.\n", count);
    printContacts(contacts, count);

    free(contacts);
}

int getCount(const char* filename)
{
    FILE* fp;
    char name[MAX_LEN], phone[MAX_LEN];
    int count = 0;

    if (fopen_s(&fp, filename, "r") != 0)
    {
        return 0;
    }

    while (fscanf(fp, "%s %s", name, phone) == 2)
    {
        count++;
    }

    fclose(fp);
    return count;
}

CONTACT* loadContacts(const char* filename, int count)
{
    FILE* fp;
    CONTACT* contacts = (CONTACT*)malloc(sizeof(CONTACT) * count);
    if (contacts == NULL) return NULL;

    if (fopen_s(&fp, filename, "r") != 0)
    {
        free(contacts);
        return NULL;
    }

    for (int i = 0; i < count; i++)
    {
        fscanf(fp, "%s %s", contacts[i].name, contacts[i].phone);
    }

    fclose(fp);
    return contacts;
}


void printContacts(CONTACT* contacts, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("이름: %s\n", contacts[i].name);
        printf("전화번호: %s\n", contacts[i].phone);
    }

    return;
}

