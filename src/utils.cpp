#include "utils.h"

#include <vector>
#include <windows.h>

std::vector<std::string> activities;

void PrintWelcome()
{
	std::cout << "Welcome user" << std::endl;
}

void PrintMenu()
{
	std::cout << "Menu:" << std::endl;
	std::cout << "1. Add an activity" << std::endl;
	std::cout << "2. Remove an activity" << std::endl;
	std::cout << "3. Print all activities" << std::endl;
	std::cout << "4. Print long activities" << std::endl;
	std::cout << "5. Print shortest activity" << std::endl;
	std::cout << "6. Print longest activity" << std::endl;
	std::cout << "7. Print average activity name length" << std::endl;
	std::cout << "8. Show developer mode" << std::endl;
	std::cout << "9. Exit" << std::endl;
}

void PrintGoodbye(const std::string& name)
{
	std::cout << "Goodbye " << name << std::endl;
}

void AddActivity(const std::string& activity)
{
	for (const std::string& existingActivity : activities)
	{
		if (existingActivity == activity)
		{
			PrintWarning("This activity already exists. Please try again.");
			return;
		}
	}

	activities.push_back(activity);
}

void RemoveActivity(int index)
{
	if (IsActivitiesEmpty())
		return;

	if (index < 1 || index > activities.size())
	{
		std::cout << "Invalid index. Please try again." << std::endl;
		return;
	}

	activities.erase(activities.begin() + index - 1);
}

void PrintActivities()
{
	if (IsActivitiesEmpty())
		return;

	std::cout << "Here are your activities:" << std::endl;

	for (size_t i = 0; i < activities.size(); i++)
		std::cout << i + 1 << ". " << activities[i] << std::endl;

	std::cout << "Activities tracked: " << activities.size() << std::endl;
}

void PrintLongActivities()
{
	if (IsActivitiesEmpty())
		return;

	std::cout << "Here are your long activities:" << std::endl;

	for (const std::string& activity : activities)
		if (activity.length() > 7)
			std::cout << activity << std::endl;
}

void PrintShortestActivity()
{
	if (IsActivitiesEmpty())
		return;

	int index{ -1 };
	int size{ 0 };

	for (size_t i = 0; i < activities.size(); i++)
	{
		if (index == -1 || activities[i].size() < size)
		{
			index = i;
			size = activities[i].size();
		}
	}

	std::cout << "Your shortest activity is " << activities[index] << std::endl;
}

void PrintLongestActivity()
{
	if (IsActivitiesEmpty())
		return;

	int index{ -1 };
	int size{ 0 };

	for (size_t i = 0; i < activities.size(); i++)
	{
		if (index == -1 || activities[i].size() > size)
		{
			index = i;
			size = activities[i].size();
		}
	}

	std::cout << "Your longest activity is " << activities[index] << std::endl;
}

void PrintAverageActivityNameLength()
{
	if (IsActivitiesEmpty())
		return;

	float count{ 0.0f };

	for (const std::string& activity : activities)
		count += activity.size();

	std::cout << "Your average activity name length is " << count / activities.size() << std::endl;
}

void PrintColoredMessage(const std::string& message, const unsigned short color)
{
	HANDLE hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) };
	SetConsoleTextAttribute(hConsole, color);
	std::cout << message << std::endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void PrintWarning(const std::string& message)
{
	PrintColoredMessage(message, 14);
}

void PrintError(const std::string& message)
{
	PrintColoredMessage(message, 12);
}

bool IsActivitiesEmpty()
{
	if (activities.empty())
	{
		PrintWarning("No activities found.");
		return true;
	}

	return false;
}

void ShowDeveloperMode()
{
	std::cout << "---Developer mode---" << std::endl;
	std::cout << "App version 0.0.1" << std::endl;
	std::cout << "Number of activities: " << activities.size() << std::endl;
	std::cout << "Current build target: " << (sizeof(void*) == 8 ? "x64" : "x86") << std::endl;
	std::cout << "Favorite engineering topic: C++" << std::endl;
}
