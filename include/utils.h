#pragma once
#include <iostream>
#include <vector>

#include "ActivityManager.h"

struct AppConfig
{
	bool bShowWelcomeMessage{ true };
	bool bShowDeveloperModeEnabled{ false };
};

void PrintWelcome();

std::string GetCommand();

bool ProcessCommand(const std::string& command, ActivityManager& activityManager);

void HandleAddCommand(ActivityManager& activityManager);

void HandleSortCommand(ActivityManager& activityManager);

void HandlePrintCommand(ActivityManager& activityManager);

void PrintCommands();

void PrintPriorityMenu();

void PrintGoodbye(const std::string& name = "user");

void PrintColoredMessage(const std::string& message, const unsigned short color);

void PrintWarning(const std::string& message);

void PrintError(const std::string& message);

bool TryToGetInputNumber(const std::string& inputString, int& outputNumber);

bool TryToGetInputIndex(const std::string& message, const ActivityManager& activityManager, int& outIndex);