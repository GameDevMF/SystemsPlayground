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
	std::cout << "Enter a command (help for options): ";
	std::getline(std::cin, command);
	return command;
}

bool ProcessCommand(const std::string& command, ActivityManager& activityManager)
{
	std::string inputString{ "" };
	int inputNumber{ 0 };

	std::cout << SEPARATOR << std::endl;

	if (command.empty())
	{
		PrintWarning("Please enter a command.");
	}
	else if (command.starts_with("help"))
	{
		PrintCommands();
	}
	else if (command.starts_with("add"))
	{
		std::string activityName{ "" };

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
	}
	else if (command.starts_with("start"))
	{
		while (true)
		{
			activityManager.PrintActivities();

			std::cout << "Enter the index of the activity you want to start: ";

			std::getline(std::cin, inputString);

			if (activityManager.TryGetActivityIndex(inputString, inputNumber))
			{
				activityManager.StartActivity(inputNumber);
				break;
			}
		}
	}
	else if (command.starts_with("complete"))
	{
		while (true)
		{
			activityManager.PrintActivities();

			std::cout << "Enter the index of the activity you want to complete: ";

			std::getline(std::cin, inputString);

			if (activityManager.TryGetActivityIndex(inputString, inputNumber))
			{
				activityManager.CompleteActivity(inputNumber);
				break;
			}
		}
	}
	else if (command.starts_with("remove"))
	{
		while (true)
		{
			activityManager.PrintActivities();

			std::cout << "Enter the index of the activity you want to remove: ";

			std::getline(std::cin, inputString);

			if (activityManager.TryGetActivityIndex(inputString, inputNumber))
			{
				activityManager.RemoveActivity(inputNumber);
				break;
			}
		}
	}
	else if (command.starts_with("sort"))
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
	}
	else if (command.starts_with("print"))
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
	}
	else if (command.starts_with("clear"))
	{
		std::cout << "Are you sure you want to clear all activities? (y/n): ";
		std::getline(std::cin, inputString);
		if (inputString == "y" || inputString == "Y")
			activityManager.ClearActivities();
	}
	else if (command.starts_with("developer"))
	{
		activityManager.ShowDeveloperMode();
	}
	else if (command.starts_with("exit"))
	{
		return false;
	}
	else
	{
		PrintError("Invalid command. Please try again.");
	}

	return true;
}

void PrintCommands()
{
	std::cout << "Commands:" << std::endl;
	std::cout << "add = Add an activity" << std::endl;
	std::cout << "start = Start an activity" << std::endl;
	std::cout << "complete = Complete activity" << std::endl;
	std::cout << "remove = Remove an activity" << std::endl;
	std::cout << "sort = Sort activities" << std::endl;
	std::cout << "print = Print activities" << std::endl;
	std::cout << "clear = Clear all activities" << std::endl;
	std::cout << "developer = Show developer mode" << std::endl;
	std::cout << "exit = Exit" << std::endl;
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