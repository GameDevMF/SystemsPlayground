#pragma once
#include <iostream>
#include <vector>

#include "ActivityManager.h"

void PrintWelcome();

std::string GetCommand();

bool ProcessCommand(const std::string& command, ActivityManager& activityManager);

void PrintCommands();

void PrintPriorityMenu();

void PrintGoodbye(const std::string& name = "user");

void PrintColoredMessage(const std::string& message, const unsigned short color);

void PrintWarning(const std::string& message);

void PrintError(const std::string& message);

bool TryToGetInputNumber(const std::string& inputString, int& outputNumber);