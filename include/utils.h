#pragma once
#include <iostream>

void PrintWelcome();

void PrintMenu();

void PrintGoodbye(const std::string& name = "user");

void AddActivity(const std::string& activity);

void RemoveActivity(const int index);

void PrintActivities();

void PrintLongActivities();

void PrintShortestActivity();

void PrintLongestActivity();

void PrintAverageActivityNameLength();

void PrintColoredMessage(const std::string& message, const unsigned short color);

void PrintWarning(const std::string& message);

void PrintError(const std::string& message);

bool IsActivitiesEmpty();

void ShowDeveloperMode();