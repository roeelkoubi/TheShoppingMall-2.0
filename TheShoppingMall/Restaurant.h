#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Store.h"
using namespace std;

class Restaurant : public Store
{
private:
	string	foodType;

public:
	Restaurant(string name_a, string type);

	string			    getFoodType() const { return foodType; }
	void				setFoodType(string type);
	void				show(ostream& out) const;
	void				specialEvent() const;
};

