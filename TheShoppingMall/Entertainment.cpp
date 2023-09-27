#define _CRT_SECURE_NO_WARNINGS
#include "Entertainment.h"


Entertainment::Entertainment(string name_a, string entertainmentType_a):
	Store(name_a),entertainmentType(entertainmentType_a)
{}


void Entertainment::setEntertainmentType(string type)
{
	entertainmentType = type;
}

void Entertainment::show(ostream& out) const
{
	out << "[" << name << ", doing " << entertainmentType << "]" << endl;
}

void Entertainment::specialEvent() const
{
	if (productList.size() == 0 || clientList.size() == 0) {
		cout << "Store must have products and clients to initiate special event." << endl;
		return;
	}

	cout << "Starting Lottery - Who will get 50% discount?" << endl;
	srand(static_cast<unsigned int>(time(0)));
	int randomProduct = rand() % (productList.size());
	int randomClient = rand() % (clientList.size());
	int price = productList[randomProduct]->getPrice();
	productList[randomProduct]->setPrice(price/2);
	productList[randomProduct]->show(cout);
	clientList[randomClient]->buyProduct(productList[randomProduct]);
	cout << "Suprise! " << clientList[randomClient]->getName() << " recieved 50% discount on " << productList[randomProduct]->getName() << endl;
	productList[randomProduct]->setPrice(price);
}
