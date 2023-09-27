#include "MallEmployee.h"

MallEmployee::MallEmployee(string name_a, int salary, double discount,int bonus_a):
	Employee(name_a,salary),discountFee(discount),bonus(bonus_a)
{}

void MallEmployee::setDiscountFee(double fee)
{
    if (fee > 0 && fee < 1)
        discountFee = fee;
    else
        throw GeneralException("Invalid discount fee. Please provide a value between 0 and 1");
}

void MallEmployee::setBonus(int bonus_a)
{
    if (bonus < 0)
        throw GeneralException("Bonus cannot be negative value\n");

    bonus = bonus_a;
}

int MallEmployee::calculateSalary() const 
{
    int newSalary = sSalary + bonus;
    return newSalary;

}

void MallEmployee::show(ostream& out) const
{
    out << "[" << name << ", eID " << id << " earn " << sSalary << ", and had discount of " << discountFee << " made bonus of " << bonus << "]" << endl;
}
