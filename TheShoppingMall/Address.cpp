#define _CRT_SECURE_NO_WARNINGS
#include "Address.h"

Address::Address(string city_a, string street_a, int houseNumber):
    city(city_a),street(street_a),houseNum(houseNumber)
{

}

void Address::setCity(string city_a)
{
    city = city_a;
}

void Address::setStreet(string street_a)
{
    street = street_a;
}

void Address::setHouseNum(int num)
{
    if (num < 0)
        throw GeneralException("House number can't be negative");

    houseNum = num;
}

ostream& operator<<(ostream& os, const Address& add)
{
    os << add.houseNum << " " << add.street << ", " << add.city;
    return os;
}