#define _CRT_SECURE_NO_WARNINGS
#include "SpecialtyStore.h"

SpecialtyStore::SpecialtyStore(string name_a, string type):
	Store(name_a)
{}

void SpecialtyStore::setMerchandiseType(string type)
{
	merchandiseType = type;
}

void SpecialtyStore::show(ostream& out) const
{
	out << "[" << name << ", Selling " << merchandiseType << "]" << endl;
}

void SpecialtyStore::specialEvent() const
{
	cout << "Starting Lottery - What will be the discount for today?" << endl;
	srand(static_cast<unsigned int>(time(0)));
	unsigned int  discount = (rand() % 10) * 10;
	for (int i = 0; i < productList.size(); i++)
		productList[i]->setPrice(productList[i]->getPrice() - (productList[i]->getPrice() * discount / 100));

	cout << "Surprise! today's discount is " << discount << "%" << endl;
}







