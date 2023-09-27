#pragma once
#include <iostream>
using namespace std;
#include "MallExceptions.h"

class Product
{

private:
	string	name;
	int		id;
	int		price;


public:
	Product(string name_a, int id_a, int price_a);

	bool			operator==(const Product& other) const;

	string			getName() const { return name; }
	int				getPID() const { return id; } 
	int				getPrice() const { return price; }
	void			setName(string name_a);
	void			setPrice(int price_a);
	void			show(ostream& out) const;
};

