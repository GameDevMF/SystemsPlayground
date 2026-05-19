#pragma once
#include <vector>

#include "utils.h"

class ActivityManager
{
public:
	ActivityManager();

	inline const std::vector<Activity>& GetActivities() const noexcept { return m_activities; }

	void AddActivity(const Activity& activity);

	void RemoveActivity(const int index);

	void PrintActivities();

	void PrintLongActivities();

	void PrintShortestActivity();

	void PrintLongestActivity();

	void PrintAverageActivityNameLength();

	void CompleteActivity(const int index);

private:
	std::vector<Activity> m_activities;
	
	bool IsActivitiesEmpty();

	bool IsValidActivityIndex(const int index);

	std::string GetActivityStatus(const Activity& activity);
};