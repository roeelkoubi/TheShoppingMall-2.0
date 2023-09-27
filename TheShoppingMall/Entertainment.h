#pragma once
#include <iostream>
#include "Store.h"
#include <string.h>
using namespace std;

class Entertainment : public Store
{
private:
	string	entertainmentType;

public:
	Entertainment(string name_a, string entertainmentType_a);

	string					getEntertainmentType() const { return entertainmentType; }
	void					setEntertainmentType(string type);
	void					show(ostream& out) const;
	void					specialEvent() const;
};

