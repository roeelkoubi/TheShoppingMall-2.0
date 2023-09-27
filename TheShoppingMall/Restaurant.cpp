#define _CRT_SECURE_NO_WARNINGS
#include "Restaurant.h"


Restaurant::Restaurant(string name_a, string type):
	Store(name_a)
{}

void Restaurant::setFoodType(string type)
{
	foodType = type;
}

void Restaurant::show(ostream& out) const
{
	out << "[The Resturant " << name << ", Serves " << foodType<< " type of food]" << endl;
}


void Restaurant::specialEvent() const
{
	if (productList.size() == 0 || clientList.size() == 0) {
		cout << "Store must have products and clients to initiate special event." << endl;
		return;
	}

	cout << "Starting Lottery - Who will get a free product?" << endl;
	srand(static_cast<unsigned int>(time(0)));
	int randomProduct = rand() % (productList.size());
	int randomClient = rand() % (clientList.size());
	productList[randomProduct]->setPrice(0);
	productList[randomProduct]->show(cout);
	clientList[randomClient]->buyProduct(productList[randomProduct]);
	cout << "Suprise! " << clientList[randomClient]->getName() << " recieved " << productList[randomProduct]->getName() << " on the house" << endl;
}




