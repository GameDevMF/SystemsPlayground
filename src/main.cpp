#include <iostream>
#include <windows.h>
#include <string>

#include "utils.h"

int main()
{
	PrintWelcome();

	std::string name{ "" };
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);

	std::string input{ "" };
	Activity activity;

	while (true)
	{
		PrintMenu();

		std::string menu{ "" };
		std::getline(std::cin, menu);
		int index{ -1 };

		if (menu.empty())
		{
			PrintError("Please enter a menu option.");
			continue;
		}

		switch (menu[0])
		{
		case ADD_ACTIVITY_OPTION:
			std::cout << "Enter an activity you want to do: ";
			std::getline(std::cin, input);
			activity.Name = input;
			AddActivity(activity);
			break;
		case REMOVE_ACTIVITY_OPTION:
			PrintActivities();
			std::cout << "Enter the index of the activity you want to remove: ";
			std::cin >> index;
			index--;
			RemoveActivity(index);
			break;
		case PRINT_ALL_ACTIVITIES_OPTION:
			PrintActivities();
			break;
		case PRINT_LONG_ACTIVITIES_OPTION:
			PrintLongActivities();
			break;
		case PRINT_SHORTEST_ACTIVITY_OPTION:
			PrintShortestActivity();
			break;
		case PRINT_LONGEST_ACTIVITY_OPTION:
			PrintLongestActivity();
			break;
		case PRINT_AVERAGE_ACTIVITY_NAME_LENGTH_OPTION:
			PrintAverageActivityNameLength();
			break;
		case MARK_ACTIVITY_COMPLETE_OPTION:
			PrintActivities();
			std::cout << "Enter the index of the activity you want to complete: ";
			std::cin >> index;
			std::cin.ignore(256, '\n');
			index--;
			CompleteActivity(index);
			break;
		case SHOW_DEVELOPER_OPTION:
			ShowDeveloperMode();
			break;
		case EXIT_OPTION:
			PrintGoodbye(name);
			std::cin.get();
			return 0;
		default:
			PrintError("Invalid option. Please try again.");
		}
	}

	return 0;
}