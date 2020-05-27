#include "Bag.h"

using namespace std;



Bag::Bag(string name):Item(name)
{
}

int Bag::View()
{
	cout << setw(Getlevel()) << setfill(' ') << '-';
	cout <<  GetName() <<  endl;
	int item_max = 1;
	vector<Item*>::iterator begin = ItemList.begin();
	vector<Item*>::iterator end = ItemList.end();

	while (begin != end)
	{
		item_max+=(*begin)->View();
		begin++;
	}
	return item_max;
}

void Bag::AddItem(Item* _item)
{
	_item->SetParent(this);
	ItemList.push_back(_item);
}

void Bag::RemoveItem(Item* _item)
{
	vector<Item*>::iterator remove = find(ItemList.begin(), ItemList.end(), _item);

	if (remove != ItemList.end())
	{
		ItemList.erase(remove);
	}
}

Item* Bag::finditem(int num)
{
	vector<Item*>::iterator iter = ItemList.begin();
	int n=1;
	while (iter!=ItemList.end() && n != num)
	{
		n++;
		iter++;
	}
	if (iter == ItemList.end())
		return 0;
	else 
		return *
		
		;
}


Bag::~Bag()
{
}
