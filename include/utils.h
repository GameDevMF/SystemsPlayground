#pragma once
#include <iostream>
#include <vector>

constexpr char ADD_ACTIVITY_OPTION{ '1' };
constexpr char START_ACTIVITY_OPTION{ '2' };
constexpr char COMPLETE_ACTIVITY_OPTION{ '3' };
constexpr char REMOVE_ACTIVITY_OPTION{ '4' };
constexpr char SORT_BY_NAME_OPTION{ '5' };
constexpr char SORT_BY_PRIORITY_OPTION{ '6' };
constexpr char SORT_BY_STATUS_OPTION{ '7' };
constexpr char SORT_BY_PRIORITY_THEN_NAME_OPTION{ '8' };
constexpr char PRINT_ALL_ACTIVITIES_OPTION{ '9' };
constexpr char PRINT_LONG_ACTIVITIES_OPTION{ '0' };
constexpr char PRINT_SHORTEST_ACTIVITY_OPTION{ 'a' };
constexpr char PRINT_LONGEST_ACTIVITY_OPTION{ 'b' };
constexpr char PRINT_AVERAGE_ACTIVITY_NAME_LENGTH_OPTION{ 'c' };
constexpr char PRINT_TODO_ACTIVITIES_OPTION{ 'd' };
constexpr char PRINT_IN_PROGRESS_ACTIVITIES_OPTION{ 'e' };
constexpr char PRINT_COMPLETED_ACTIVITIES_OPTION{ 'f' };
constexpr char CLEAR_ACTIVITIES_OPTION{ 'g' };
constexpr char SHOW_DEVELOPER_OPTION{ 'h' };
constexpr char EXIT_OPTION{ 'i' };

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

	Activity() = default;

	Activity(const std::string& name)
		: Name(name) {}

	Activity(const std::string& name, PriorityLevel priority, ActivityStatus status = ActivityStatus::Todo)
		: Name(name), Priority(priority), Status(status) {}
};

void PrintWelcome();

void PrintMenu();

void PrintPriorityMenu();

void PrintGoodbye(const std::string& name = "user");

void PrintColoredMessage(const std::string& message, const unsigned short color);

void PrintWarning(const std::string& message);

void PrintError(const std::string& message);

bool TryToGetInputNumber(const std::string& inputString, int& outputNumber);