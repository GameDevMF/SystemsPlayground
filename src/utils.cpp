#include "utils.h"

void PrintWelcome()
{
	std::cout << "Welcome user" << std::endl;
}

void PrintGoodbye()
{
	std::cout << "Goodbye user" << std::endl;
}

void PrintUserInfo(const std::string& name, const std::string& trainingGoal, const std::string& favoriteInterest)
{
	std::cout << "Your name is: " << name << std::endl;
	std::cout << "Your training goal is: " << trainingGoal << std::endl;
	std::cout << "Your favorite interest is: " << favoriteInterest << std::endl;
}