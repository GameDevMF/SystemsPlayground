#pragma once
#include <iostream>

void PrintWelcome();

void PrintMenu();

void PrintGoodbye(const std::string& name = "user");

void AddActivity(const std::string& activity);

void RemoveActivity(int index);

void PrintActivities();

void PrintLongActivities();

void ShowDeveloperMode();