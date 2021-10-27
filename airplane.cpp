#include<iostream>
#include<conio.h>
#include<string>

#include "airplane.h"

Airplane::Airplane() : speed(0), height(0), score(0) {}

Airplane::Airplane(int speed, int height) : speed(speed), height(height), score(0)
{
	std::string first, second;
	std::cout << "Please enter name ";
	std::cin >> first;
	std::cout << "Please enter second ";
	std::cin >> second;
	operators.push_back(Operator(first));
	operators.push_back(Operator(second));
}

std::ostream& operator << (std::ostream& out, const Airplane& other)
{
	out << "Speed " << other.speed << std::endl;
	out << "Height " << other.height << std::endl;

	return out;

}


Operator& Airplane::GetOperator(int i)
{
	return operators[i];
}

int Airplane::OperatorRcomendation(int index)
{
	return 7 * this->speed - operators[index].GetAdjustment();
}

bool Airplane::Start()
{
	return this->operators[0].active() and this->operators[1].active();
}

void Airplane::SpeedHeightCheck()
{
	char velocity;

	if (_kbhit())
	{
		velocity = _getch();
		switch (velocity)
		{
		case 'a':
		{
			

			if ((this->speed -= 50) < 0)
			{
				std::cout << "The goddamn plane has crahed into a mountain\n";
				exit(1);
			}

		}break;
		case 'd':
		{
			this->speed += 50;

		}break;
		case 'w':
		{

			this->height += 250;

		}break;
		case 's':
		{
			if ((this->height -= 250) < 0)
			{
				std::cout << "The goddamn plane has crahed into a mountain\n";
				exit(2);
			}

		}break;
		}
	}
}

