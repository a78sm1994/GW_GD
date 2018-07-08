//	Factory Method
#include <iostream>
using namespace std;

class Item {
public:
	virtual void use() = 0;
};

class Creator {
public:
	Item* create()	//Factory method
	{
		Item* item;

		requeststep1();	//request
		item = Itemcreate();	//create item
		requeststep2(); //log write

		return item;

	}
protected:
	virtual void requeststep1() = 0;
	virtual Item* Itemcreate() = 0;
	virtual void requeststep2() = 0;
};

class HpItem :public Item {
public:
	virtual void use()
	{
		cout << "Hp Potion use" << endl;
	}
};

class MpItem :public Item {
public:
	virtual void use()
	{
		cout << "Mp Potion use" << endl;
	}
};

class HpCreator :public Creator {
private:
	virtual void requeststep1()
	{
		cout << "Hp requeset step1" << endl;
	}
	virtual Item* Itemcreate()
	{
		cout << "Hp create" << endl;
		return new HpItem();
	}
	virtual void requeststep2()
	{
		cout << "Hp requeset step2" << endl;
	}


};

class MpCreator :public Creator {
private:
	virtual void requeststep1()
	{
		cout << "Mp requeset step1" << endl;
	}
	virtual Item* Itemcreate()
	{
		cout << "Mp create" << endl;
		return new MpItem();
	}
	virtual void requeststep2()
	{
		cout << "Mp requeset step2" << endl;
	}

};
int main()
{
	Creator* creator;
	HpCreator Hp;
	MpCreator Mp;

	Item* item;

	creator = new HpCreator();
	item = creator->create();
	item->use();

	creator = new MpCreator();
	item = creator->create();
	item->use();

	delete item;
	delete creator;
}