#include <iostream>

#include "utils.h"

int main()
{
	PrintWelcome();

	std::string name{ "" };
	std::cout << "Enter your name: ";
	std::cin >> name;

	std::string trainingGoal{ "" };
	std::cout << "Enter your training goal: ";
	std::cin >> trainingGoal;

	std::string favoriteInterest{ "" };
	std::cout << "Enter your favorite interest: ";
	std::cin >> favoriteInterest;

	PrintUserInfo(name, trainingGoal, favoriteInterest);

	PrintGoodbye();

	std::cin;

	return 0;
}