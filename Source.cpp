#include<iostream>
#include<string>
#include<algorithm>
#include<conio.h>
#include<Windows.h>


#include "airplane.h"

int main()
{

	Airplane airplane(0, 0);
	
	if (airplane.Start())
	{
		std::cout << "Everything is ready. PRepare for the flight\n";
	}
	else
	{
		std::cout << "Start was cancelled\n";
		exit(2);
	}

	bool call_to_operators = true;

	while (true)
	{
		system("CLS");

		airplane.SpeedHeightCheck();

		std::cout << airplane;
		
		if (airplane.GetSpeed() < 50)
		{
			call_to_operators = false;
		}
		else
		{
			call_to_operators = true;
		}

		std::cout <<airplane.GetOperator(0);
		std::cout << "\nRecommended height " << airplane.OperatorRcomendation(0)<<std::endl;

		std::cout << airplane.GetOperator(1);
		std::cout << "\nRecommended height " << airplane.OperatorRcomendation(1)<<std::endl;

		if(call_to_operators == true)
			std::cout << "Score -> " << airplane.Score() <<std::endl;

		airplane.Up_and_Down();
		
		Sleep(1000);
	}


	return EXIT_SUCCESS;
}