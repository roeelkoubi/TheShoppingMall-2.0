#pragma once
#include <iostream>
#include "MallExceptions.h"
#include <string.h>
using namespace std;

class Address
{

private:
	string	city;
	string	street;
	int		houseNum;

public:
	Address(string city_a, string street_a, int houseNumber);

	friend ostream&		operator<<(ostream& os, const Address& add);
	string				getCity() const { return city; }
	string				getStreet() const { return street; }
	int					getHouseNum() const { return houseNum; }
	void				setCity(string city);
	void				setStreet(string street);
	void				setHouseNum(int num);
};


