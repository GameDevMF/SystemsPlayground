#include "utils.h"

#include <windows.h>
#include <string>

constexpr const char* SEPARATOR{ "--------------------" };

void PrintWelcome()
{
	PrintColoredMessage("Welcome to the Activity Manager!", 10);
}

std::string GetCommand()
{
	std::cout << SEPARATOR << std::endl;

	std::string command{ "" };
	std::cout << "Enter a command (help / h for options): ";
	std::getline(std::cin, command);
	return command;
}

bool ProcessCommand(const std::string& command, ActivityManager& activityManager)
{	
	int inputNumber{ 0 };

	std::cout << SEPARATOR << std::endl;

	if (command.empty())
	{
		PrintWarning("Please enter a command.");
	}
	else if (command == "help" || command == "h")
	{
		PrintCommands();
		activityManager.IncrementCommandCount("help");
	}
	else if (command == "add")
	{
		HandleAddCommand(activityManager);
	}
	else if (command == "start")
	{
		if (activityManager.GetActivities().empty())
		{
			PrintWarning("No activities found.");
			return true;
		}

		while (true)
		{
			if (TryToGetInputIndex("Enter the index of the activity you want to start: ", activityManager, inputNumber))
			{
				activityManager.StartActivity(inputNumber);
				activityManager.IncrementCommandCount("start");
				break;
			}
		}
	}
	else if (command == "complete" || command == "finish")
	{
		if (activityManager.GetActivities().empty())
		{
			PrintWarning("No activities found.");
			return true;
		}

		while (true)
		{
			if (TryToGetInputIndex("Enter the index of the activity you want to complete: ", activityManager, inputNumber))
			{
				activityManager.CompleteActivity(inputNumber);
				activityManager.IncrementCommandCount("complete");
				break;
			}
		}
	}
	else if (command == "remove" || command == "delete")
	{
		if (activityManager.GetActivities().empty())
		{
			PrintWarning("No activities found.");
			return true;
		}

		while (true)
		{
			if (TryToGetInputIndex("Enter the index of the activity you want to remove: ", activityManager, inputNumber))
			{
				activityManager.RemoveActivity(inputNumber);
				activityManager.IncrementCommandCount("remove");
				break;
			}
		}
	}
	else if (command == "sort" || command == "s")
	{
		HandleSortCommand(activityManager);
	}
	else if (command == "print" || command == "p")
	{
		HandlePrintCommand(activityManager);
	}
	else if (command == "clear" || command == "c")
	{
		std::string inputString{ "" };

		std::cout << "Are you sure you want to clear all activities? (y/n): ";
		std::getline(std::cin, inputString);
		if (inputString == "y" || inputString == "Y")
			activityManager.ClearActivities();

		activityManager.IncrementCommandCount("clear");
	}
	else if (command == "stats")
	{
		activityManager.PrintStats();
		activityManager.IncrementCommandCount("stats");
	}
	else if (command == "exit" || command == "quit")
	{
		return false;
	}
	else
	{
		PrintError("Invalid command. Please try again.");
		activityManager.IncrementCommandCount("invalid");
	}

	return true;
}

void HandleAddCommand(ActivityManager& activityManager)
{
	std::string inputString{ "" };
	std::string activityName{ "" };
	int inputNumber{ 0 };

	std::cout << "Enter an activity you want to do: ";
	std::getline(std::cin, activityName);
	while (true)
	{
		PrintPriorityMenu();

		std::cout << "Enter the priority of the activity: ";

		std::getline(std::cin, inputString);

		if (inputString.size() != 1)
		{
			PrintError("The Priority must be between 1 and 5");
		}
		else if (!TryToGetInputNumber(inputString, inputNumber))
		{
			PrintError("The Priority must be a valid number");
			continue;
		}

		if (inputNumber < 1 || inputNumber > 5)
			PrintError("The Priority must be between 1 and 5");
		else
			break;
	}
	activityManager.AddActivity({ activityName, static_cast<PriorityLevel>(inputNumber) });

	activityManager.IncrementCommandCount("add");
}

void HandleSortCommand(ActivityManager& activityManager)
{
	std::cout << "Sort options:" << std::endl;
	std::cout << "name = Sort by name" << std::endl;
	std::cout << "priority = Sort by priority" << std::endl;
	std::cout << "status = Sort by status" << std::endl;
	std::cout << "multiple = Sort by priority then name" << std::endl;

	std::string sortCommand{ "" };
	std::cout << "Enter a sort option: ";
	std::getline(std::cin, sortCommand);

	if (sortCommand.starts_with("name"))
		activityManager.SortByName();
	else if (sortCommand.starts_with("priority"))
		activityManager.SortByPriority();
	else if (sortCommand.starts_with("status"))
		activityManager.SortByStatus();
	else if (sortCommand.starts_with("multiple"))
		activityManager.SortByPriorityThenName();
	else
		PrintError("Invalid sort option. Please try again.");

	activityManager.IncrementCommandCount("sort");
}

void HandlePrintCommand(ActivityManager& activityManager)
{
	std::cout << "Print options:" << std::endl;
	std::cout << "all = Print all activities" << std::endl;
	std::cout << "long = Print long activities" << std::endl;
	std::cout << "shortest = Print shortest activity" << std::endl;
	std::cout << "longest = Print longest activity" << std::endl;
	std::cout << "average = Print average activity name length" << std::endl;
	std::cout << "high = Print high priority activities" << std::endl;
	std::cout << "todo = Print todo activities" << std::endl;
	std::cout << "progress = Print in progress activities" << std::endl;
	std::cout << "complete = Print completed activities" << std::endl;

	std::string printCommand{ "" };
	std::cout << "Enter a print option: ";
	std::getline(std::cin, printCommand);

	if (printCommand.starts_with("all"))
		activityManager.PrintActivities();
	else if (printCommand.starts_with("long"))
		activityManager.PrintLongActivities();
	else if (printCommand.starts_with("shortest"))
		activityManager.PrintShortestActivity();
	else if (printCommand.starts_with("longest"))
		activityManager.PrintLongestActivity();
	else if (printCommand.starts_with("average"))
		activityManager.PrintAverageActivityNameLength();
	else if (printCommand.starts_with("high"))
		activityManager.PrintHighPriorityActivities();
	else if (printCommand.starts_with("todo"))
		activityManager.PrintActivitiesByStatus(ActivityStatus::Todo);
	else if (printCommand.starts_with("progress"))
		activityManager.PrintActivitiesByStatus(ActivityStatus::InProgress);
	else if (printCommand.starts_with("complete"))
		activityManager.PrintActivitiesByStatus(ActivityStatus::Completed);

	activityManager.IncrementCommandCount("print");
}

void PrintCommands()
{
	std::cout << "Commands:" << std::endl;
	std::cout << "add = Add an activity" << std::endl;
	std::cout << "start = Start an activity" << std::endl;
	std::cout << "complete / finish = Complete activity" << std::endl;
	std::cout << "remove / delete = Remove an activity" << std::endl;
	std::cout << "sort / s = Sort activities" << std::endl;
	std::cout << "print / p = Print activities" << std::endl;
	std::cout << "clear / c = Clear all activities" << std::endl;
	std::cout << "stats = Show activity stats" << std::endl;
	std::cout << "exit / quit = Exit" << std::endl;
}

void PrintPriorityMenu()
{
	std::cout << "Priority levels:" << std::endl;
	std::cout << "1. Lowest" << std::endl;
	std::cout << "2. Low" << std::endl;
	std::cout << "3. Medium" << std::endl;
	std::cout << "4. High" << std::endl;
	std::cout << "5. Highest" << std::endl;
}

void PrintGoodbye(const std::string& name)
{
	std::cout << "Goodbye " << name << std::endl;
}

void PrintColoredMessage(const std::string& message, const unsigned short color)
{
	HANDLE hConsole{ GetStdHandle(STD_OUTPUT_HANDLE) };
	SetConsoleTextAttribute(hConsole, color);
	std::cout << message << std::endl;
	SetConsoleTextAttribute(hConsole, 7);
}

void PrintWarning(const std::string& message)
{
	PrintColoredMessage(message, 14);
}

void PrintError(const std::string& message)
{
	PrintColoredMessage(message, 12);
}

bool TryToGetInputNumber(const std::string& inputString, int& outputNumber)
{
	try
	{
		outputNumber = std::stoi(inputString);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

bool TryToGetInputIndex(const std::string& message, const ActivityManager& activityManager, int& outIndex)
{
	activityManager.PrintActivities();

	std::cout << message;

	std::string inputString{ "" };

	std::getline(std::cin, inputString);

	if (activityManager.TryGetActivityIndex(inputString, outIndex))
		return true;

	return false;
}
