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
	Activity activity;

	while (true)
	{
		PrintMenu();

		std::string menu{ "" };
		std::cin >> menu;
		int index{ -1 };

		switch (menu[0])
		{
		case '1':
			std::cout << "Enter an activity you want to do: ";
			std::cin >> input;
			activity.Name = input;
			AddActivity(activity);
			break;
		case '2':
			PrintActivities();
			std::cout << "Enter the index of the activity you want to remove: ";
			std::cin >> index;
			index--;
			RemoveActivity(index);
			break;
		case '3':
			PrintActivities();
			break;
		case '4':
			PrintLongActivities();
			break;
		case '5':
			PrintShortestActivity();
			break;
		case '6':
			PrintLongestActivity();
			break;
		case '7':
			PrintAverageActivityNameLength();
			break;
		case '8':
			PrintActivities();
			std::cout << "Enter the index of the activity you want to complete: ";
			std::cin >> index;
			index--;
			CompleteActivity(index);
			break;
		case '9':
			ShowDeveloperMode();
			break;
		case '0':
			PrintGoodbye(name);
			std::cin.get();
			return 0;
		default:
			PrintError("Invalid option. Please try again.");
		}
	}

	return 0;
}