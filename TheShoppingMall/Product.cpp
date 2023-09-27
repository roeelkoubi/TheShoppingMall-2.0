#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"

Product::Product(string name_a, int id_a, int price_a):
		name(name_a), id(id_a), price(price_a)
{}

bool Product::operator==(const Product& other) const
{
	return id == other.getPID();
}

void Product::setName(string name_a)
{
	name = name_a;
}

void Product::setPrice(int price_a)
{
	if (price_a < 0)
		throw GeneralException("invalid price to product, cannot be negative");
	else
		price = price_a;
}

void Product::show(ostream& out) const
{
	out << "[Product " << name << ", ID " << id << ", costs " << price << "]" << endl;	
}