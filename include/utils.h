#pragma once
#include <iostream>

struct Activity
{
	std::string Name{ "" };
	int Priority{ 0 };
	bool IsCompleted{ false };
};

void PrintWelcome();

void PrintMenu();

void PrintGoodbye(const std::string& name = "user");

void AddActivity(const Activity& activity);

void RemoveActivity(const int index);

void PrintActivities();

void PrintLongActivities();

void PrintShortestActivity();

void PrintLongestActivity();

void PrintAverageActivityNameLength();

void CompleteActivity(const int index);

void PrintColoredMessage(const std::string& message, const unsigned short color);

void PrintWarning(const std::string& message);

void PrintError(const std::string& message);

bool IsActivitiesEmpty();

bool IsValidActivityIndex(const int index);

void ShowDeveloperMode();