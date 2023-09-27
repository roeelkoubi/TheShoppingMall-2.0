#pragma once
#include <iostream>
#include "Store.h"
using namespace std;

class SpecialtyStore : public Store
{
private:
	string	merchandiseType;

public:
	SpecialtyStore(string name_a, string type);

	string					getMerchandiseType() const { return merchandiseType; }
	void					setMerchandiseType(string type);
	void					show(ostream& out) const;
	void					specialEvent() const;
};