#include "Namecard.h"

NameCard  *MakeNameCard(char name[], char phone[])
{
	NameCard *card = new NameCard;
	strcpy(card->name, name);
	strcpy(card->phone, phone);
	return card;
}

void ShowNameCardInfo(NameCard * pcard) {
	if (pcard== NULL)
		return;
	printf("%s %s\n", pcard->name, pcard->phone);
}

bool NameCompare(NameCard * pcard, char * name) {
	int num;
	(strcmp(pcard->name,name)==0) ? num = 1 : num = 0;
	return num;
}

void ChangePhoneNum(NameCard * pcard, char * phone) {
	strcpy(pcard->phone, phone);
}

void DeleteData(NameCard *pcard) {
	delete pcard;
}
