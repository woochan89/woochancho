#include "Bag.h"

using namespace std;



Bag::Bag(string name):Item(name)
{
}

int Bag::View()
{
	//cout << setiosflags(ios::right) << setw(GetSize());
	//cout << setfill(' ') << GetName().c_str() << " - Bag" << endl;
	cout << GetName() << endl;
	int item_max = 0;
	int add_item = 0;
	vector<Item*>::iterator begin = ItemList.begin();
	vector<Item*>::iterator end = ItemList.end();

	while (begin != end)
	{
		(*begin)->View();
		begin++;
		item_max++;
	}
	return item_max+add_item;
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
		return *iter;
}


Bag::~Bag()
{
}
