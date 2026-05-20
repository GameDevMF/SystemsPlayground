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

	void CompleteActivity(const int index);

	void PrintActivities() const;

	void PrintLongActivities() const;

	void PrintShortestActivity() const;

	void PrintLongestActivity() const;

	void PrintAverageActivityNameLength() const;

	void PrintHighPriorityActivities() const;

	void ShowDeveloperMode() const;
private:
	std::vector<Activity> m_activities;

	std::string m_currentMilestone{ "Week 1 Complete" };
	
	bool IsActivitiesEmpty() const;

	bool IsValidActivityIndex(const int index) const;

	std::string GetActivityStatus(const Activity& activity) const;

	void PrintActivity(const Activity& activity, const int number = -1) const;
};