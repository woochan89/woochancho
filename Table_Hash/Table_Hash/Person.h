#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN 50

typedef struct _person
{
	int		ssn;
	char	name[STR_LEN];
	char	addr[STR_LEN];
} Person;

inline int GetSSN(Person* p){return p->ssn;}
void ShowPerInfo(Person* p);
Person* MakePersonData(int ssn, const char* name, const char* addr);

#endif
