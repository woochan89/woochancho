#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone)
{
	NameCard *Card = new NameCard;
	int len = strlen(name);
	for (int i = 0; i < len; i++)
	{
		Card->name[i] = name[i];
	}

	len = strlen(phone);
	for (int i = 0; i < len; i++)
	{
		Card->phone[i] = phone[i];
	}
	return Card;
}


void ShowNameCardInfo(NameCard * pcard)
{
	cout << pcard->name << "  " << pcard->phone << endl;
}

bool NameCompare(NameCard * pcard, char * name)
{
	if (pcard == NULL)
		return 0;
	int len = strlen(name);
	bool flag = true; 
	for (int i = 0; i < len; i++)
	{
		if (pcard->name[i] != name[i])
			flag = false;
	}

	return  flag;
}

void ChangePhoneNum(NameCard * pcard, char *phone)
{
	int len = strlen(phone);
	for (int i = 0; i < len; i++)
	{
		pcard->phone[i] = phone[i];
	}
}

void DeleteData(NameCard* pcard)
{
	delete pcard;
}