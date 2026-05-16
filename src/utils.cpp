#include "utils.h"

#include <vector>
#include <windows.h>

std::vector<Activity> activities;

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
	std::cout << "8. Mark activity as completed" << std::endl;
	std::cout << "9. Show developer mode" << std::endl;
	std::cout << "0. Exit" << std::endl;
}

void PrintGoodbye(const std::string& name)
{
	std::cout << "Goodbye " << name << std::endl;
}

void AddActivity(const Activity& activity)
{
	if (activity.Name.size() == 0)
	{
		PrintError("Name must have at least 1 character");
		return;
	}

	for (const Activity& existingActivity : activities)
	{
		if (existingActivity.Name == activity.Name)
		{
			PrintWarning("This activity already exists. Please try again.");
			return;
		}
	}

	activities.push_back(activity);
}

void RemoveActivity(int index)
{
	if (!IsValidActivityIndex(index))
		return;

	activities.erase(activities.begin() + index);
}

void PrintActivities()
{
	if (IsActivitiesEmpty())
		return;

	std::cout << "Here are your activities:" << std::endl;

	for (size_t i = 0; i < activities.size(); i++)
		std::cout << i + 1 << ". " << activities[i].Name <<
		", Priority: " << activities[i].Priority <<
		(activities[i].IsCompleted ? " [Done]" : " [Todo]") <<
		std::endl;

	std::cout << "Activities tracked: " << activities.size() << std::endl;
}

void PrintLongActivities()
{
	if (IsActivitiesEmpty())
		return;

	std::cout << "Here are your long activities:" << std::endl;

	for (const Activity& activity : activities)
		if (activity.Name.length() > 7)
			std::cout << activity.Name << std::endl;
}

void PrintShortestActivity()
{
	if (IsActivitiesEmpty())
		return;

	int index{ -1 };
	int size{ 0 };

	for (size_t i = 0; i < activities.size(); i++)
	{
		if (index == -1 || activities[i].Name.size() < size)
		{
			index = i;
			size = activities[i].Name.size();
		}
	}

	std::cout << "Your shortest activity is " << activities[index].Name << std::endl;
}

void PrintLongestActivity()
{
	if (IsActivitiesEmpty())
		return;

	int index{ -1 };
	int size{ 0 };

	for (size_t i = 0; i < activities.size(); i++)
	{
		if (index == -1 || activities[i].Name.size() > size)
		{
			index = i;
			size = activities[i].Name.size();
		}
	}

	std::cout << "Your longest activity is " << activities[index].Name << std::endl;
}

void PrintAverageActivityNameLength()
{
	if (IsActivitiesEmpty())
		return;

	float count{ 0.0f };

	for (const Activity& activity : activities)
		count += activity.Name.size();

	std::cout << "Your average activity name length is " << count / activities.size() << std::endl;
}

void CompleteActivity(const int index)
{
	if (!IsValidActivityIndex(index))
		return;

	for (size_t i = 0; i < activities.size(); i++)
	{
		if (index == i)
		{
			activities[i].IsCompleted = true;
			std::cout << "Activity " << activities[i].Name << " completed!" << std::endl;
		}
	}
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

bool IsValidActivityIndex(const int index)
{
	if (IsActivitiesEmpty())
		return false;

	if (index < 0 || index > activities.size() - 1)
	{
		PrintError("Invalid index. Please try again.");
		return false;
	}

	return true;
}

void ShowDeveloperMode()
{
	int completed{ 0 };

	for (const Activity& activity : activities)
		if (activity.IsCompleted)
			completed++;

	const int completedPercentage{ static_cast<int>(static_cast<float>(completed) / activities.size() * 100.0f) };

	std::cout << "---Developer mode---" << std::endl;
	std::cout << "App version 0.0.1" << std::endl;
	std::cout << "Number of activities: " << activities.size() << std::endl;
	std::cout << "Number of completed activities: " << completed << std::endl;
	std::cout << "Percentage of completed activities: " << completedPercentage << std::endl;
	std::cout << "Current build target: " << (sizeof(void*) == 8 ? "x64" : "x86") << std::endl;
	std::cout << "Favorite engineering topic: C++" << std::endl;
}
