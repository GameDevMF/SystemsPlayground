#pragma once
#include <iostream>

constexpr char ADD_ACTIVITY_OPTION{ '1' };
constexpr char REMOVE_ACTIVITY_OPTION{ '2' };
constexpr char PRINT_ALL_ACTIVITIES_OPTION{ '3' };
constexpr char PRINT_LONG_ACTIVITIES_OPTION{ '4' };
constexpr char PRINT_SHORTEST_ACTIVITY_OPTION{ '5' };
constexpr char PRINT_LONGEST_ACTIVITY_OPTION{ '6' };
constexpr char PRINT_AVERAGE_ACTIVITY_NAME_LENGTH_OPTION{ '7' };
constexpr char MARK_ACTIVITY_COMPLETE_OPTION{ '8' };
constexpr char SHOW_DEVELOPER_OPTION{ '9' };
constexpr char EXIT_OPTION{ '0' };

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

std::string GetActivityStatus(const Activity& activity);

void ShowDeveloperMode();