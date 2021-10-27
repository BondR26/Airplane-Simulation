#pragma once
#include<vector>
#include"operator.h"

class Airplane
{
private:

	int speed;
	int height;
	std::vector<Operator> operators;
	int score;

public:

	Airplane();
	Airplane(int speed, int height);

	bool Start();

	Operator& GetOperator(int i);

	int OperatorRcomendation(int index);

	void SpeedHeightCheck();
	
	friend std::ostream& operator << (std::ostream& out, const Airplane& other);

	int Score()
	{
		//
		int current_height_rec = (this->OperatorRcomendation(0) + this->OperatorRcomendation(1)) / 2 - height;

		if (current_height_rec > 300 and current_height_rec < 600)
		{
			score -= 25;
		}

		if (current_height_rec > 600 and current_height_rec < 900)
		{
			score -= 50;
		}

		if (speed > 1000)
		{
			score -= 100;
		}
		
		if (score < -1000)
		{
			std::cout << "THe plain has crashed becasue of oprators failure\n";
			system("pause");
			exit(3);
		}

		return score;
	}

	int Up_and_Down()
	{
		static bool flag = false;

		if (speed == 1000)
		{
			std::cout << "THe max point was reched. Now its time to land\n";
			flag = true;
		}

		if (flag == true and speed == 0)
		{
			std::cout << "The plane has reached its destination\n";
			system("pause");
			exit(6);
		}

	}

	int GetSpeed()
	{
		return speed;
	}
};