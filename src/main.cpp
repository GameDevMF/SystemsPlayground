#include <iostream>

#include "utils.h"

int main()
{
	PrintWelcome();

	std::string name{ "" };
	std::cout << "Enter your name: ";
	std::cin >> name;

	std::string input{ "" };

	while (true)
	{
		std::cout << "Menu:" << std::endl;
		std::cout << "1. Add an activity" << std::endl;
		std::cout << "2. Remove an activity" << std::endl;
		std::cout << "3. Print all activities" << std::endl;
		std::cout << "4. Print long activities" << std::endl;
		std::cout << "5. Show developer mode" << std::endl;
		std::cout << "6. Exit" << std::endl;

		std::string menu{ "" };
		std::cin >> menu;

		switch (menu[0])
		{
		case '1':
			std::cout << "Enter an activity you want to do: ";
			std::cin >> input;
			AddActivity(input);
			break;
		case '2':
			PrintActivities();
			std::cout << "Enter the index of the activity you want to remove: ";
			int index;
			std::cin >> index;
			RemoveActivity(index);
			break;
		case '3':
			PrintActivities();
			break;
		case '4':
			PrintLongActivities();
			break;
		case '5':
			ShowDeveloperMode();
			break;
		case '6':
			PrintGoodbye(name);
			std::cin.get();
			return 0;
		default:
			std::cout << "Invalid option. Please try again." << std::endl;
		}
	}

	return 0;
}