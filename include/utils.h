#pragma once
#include <iostream>
#include <vector>

constexpr char ADD_ACTIVITY_OPTION{ '1' };
constexpr char START_ACTIVITY_OPTION{ '2' };
constexpr char COMPLETE_ACTIVITY_OPTION{ '3' };
constexpr char REMOVE_ACTIVITY_OPTION{ '4' };
constexpr char PRINT_ALL_ACTIVITIES_OPTION{ '5' };
constexpr char PRINT_LONG_ACTIVITIES_OPTION{ '6' };
constexpr char PRINT_SHORTEST_ACTIVITY_OPTION{ '7' };
constexpr char PRINT_LONGEST_ACTIVITY_OPTION{ '8' };
constexpr char PRINT_AVERAGE_ACTIVITY_NAME_LENGTH_OPTION{ '9' };
constexpr char PRINT_TODO_ACTIVITIES_OPTION{ '0' };
constexpr char PRINT_IN_PROGRESS_ACTIVITIES_OPTION{ 'a' };
constexpr char PRINT_COMPLETED_ACTIVITIES_OPTION{ 'b' };
constexpr char SHOW_DEVELOPER_OPTION{ 'c' };
constexpr char EXIT_OPTION{ 'd' };

enum class ActivityStatus
{
	Todo,
	InProgress,
	Completed
};

enum class PriorityLevel
{
	Lowest = 1,
	Low = 2,
	Medium = 3,
	High = 4,
	Highest = 5
};

struct Activity
{
	std::string Name{ "" };
	PriorityLevel Priority{ PriorityLevel::Lowest };
	ActivityStatus Status{ ActivityStatus::Todo };

	Activity(const std::string& name, PriorityLevel priority = PriorityLevel::Lowest)
		: Name(name), Priority(priority) {}
};

void PrintWelcome();

void PrintMenu();

void PrintPriorityMenu();

void PrintGoodbye(const std::string& name = "user");

void PrintColoredMessage(const std::string& message, const unsigned short color);

void PrintWarning(const std::string& message);

void PrintError(const std::string& message);

bool TryToGetInputNumber(const std::string& inputString, int& outputNumber);