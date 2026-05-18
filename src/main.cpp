#include <iostream>
#include <windows.h>
#include <string>

#include "utils.h"
#include "ActivityManager.h"

int main()
{
	PrintWelcome();

	std::string name{ "" };
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);

	std::string input{ "" };
	Activity activity;

	ActivityManager activityManager;

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
			activityManager.AddActivity(activity);
			break;
		case REMOVE_ACTIVITY_OPTION:
			activityManager.PrintActivities();
			std::cout << "Enter the index of the activity you want to remove: ";
			std::cin >> index;
			index--;
			activityManager.RemoveActivity(index);
			break;
		case PRINT_ALL_ACTIVITIES_OPTION:
			activityManager.PrintActivities();
			break;
		case PRINT_LONG_ACTIVITIES_OPTION:
			activityManager.PrintLongActivities();
			break;
		case PRINT_SHORTEST_ACTIVITY_OPTION:
			activityManager.PrintShortestActivity();
			break;
		case PRINT_LONGEST_ACTIVITY_OPTION:
			activityManager.PrintLongestActivity();
			break;
		case PRINT_AVERAGE_ACTIVITY_NAME_LENGTH_OPTION:
			activityManager.PrintAverageActivityNameLength();
			break;
		case MARK_ACTIVITY_COMPLETE_OPTION:
			activityManager.PrintActivities();
			std::cout << "Enter the index of the activity you want to complete: ";
			std::cin >> index;
			std::cin.ignore(256, '\n');
			index--;
			activityManager.CompleteActivity(index);
			break;
		case SHOW_DEVELOPER_OPTION:
			ShowDeveloperMode(activityManager.GetActivities());
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