#include<iostream>
using namespace std;

#ifndef __NAME_CARD_H__
#define __NAME_CARD_H__

#define NAME_LEN		30
#define PHONE_LEN	30

typedef struct __namecard
{
	char name[NAME_LEN] = {0};
	char phone[PHONE_LEN] = {0};
} NameCard;

// NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
NameCard * MakeNameCard(char * name, char * phone);


void ShowNameCardInfo(NameCard * pcard);
bool NameCompare(NameCard * pcard, char * name);
void ChangePhoneNum(NameCard * pcard, char *phone);
void DeleteData(NameCard* pcard);

#endif