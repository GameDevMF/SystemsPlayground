#include <iostream>
#include <windows.h>

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
		PrintMenu();

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
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Invalid option. Please try again." << std::endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
	}

	return 0;
}