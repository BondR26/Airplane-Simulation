#include<iostream>
#include<string>

#include"operator.h"

Operator::Operator(std::string name): name(name)
{
	adjustment = -250 + rand() % 500;
}

bool Operator::active()
{
	return this->name != "";
}

std::ostream& operator << (std::ostream& out, const Operator& other)
{
	out << "\nOperator : \n";
	out << "Name " << other.name<< std::endl;
	out << "Wheather adjustment " << other.adjustment << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, Operator& other)
{
	in >> other.name;
	return in;
}

int Operator::GetAdjustment()
{
	return adjustment;
}