#pragma once
#include<iostream>
#include<string>

class Operator
{
private:

	std::string name;

	int adjustment;

public:

	Operator(std::string name);

	bool active();

	int GetAdjustment();

	friend std::ostream& operator << (std::ostream& out, const Operator& other);

	friend std::istream& operator >> (std::istream& in, Operator& other);

	bool operator >(const Operator& other) const
	{
		return this->adjustment > other.adjustment;
	}

	bool operator < (const Operator& other) const
	{
		return this->adjustment < other.adjustment;
	}


};