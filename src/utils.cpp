#include "utils.h"

#include <vector>

std::vector<std::string> activities;

void PrintWelcome()
{
	std::cout << "Welcome user" << std::endl;
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
			std::cout << "This activity already exists. Please try again." << std::endl;
			return;
		}
	}

	activities.push_back(activity);
}

void RemoveActivity(int index)
{
	if (index < 1 || index > activities.size())
	{
		std::cout << "Invalid index. Please try again." << std::endl;
		return;
	}

	activities.erase(activities.begin() + index - 1);
}

void PrintActivities()
{
	std::cout << "Here are all your activities:" << std::endl;

	for (size_t i = 0; i < activities.size(); i++)
		std::cout << i + 1 << ". " << activities[i] << std::endl;
}

void PrintLongActivities()
{
	std::cout << "Here are your long activities:" << std::endl;

	for (const std::string& activity : activities)
		if (activity.length() > 7)
			std::cout << activity << std::endl;
}

void ShowDeveloperMode()
{
	std::cout << "---Developer mode---" << std::endl;
	std::cout << "App version 0.0.1" << std::endl;
	std::cout << "Number of activities: " << activities.size() << std::endl;
	std::cout << "Current build target: " << (sizeof(void*) == 8 ? "x64" : "x86") << std::endl;
	std::cout << "Favorite engineering topic: C++" << std::endl;
}
