#pragma once
#include <vector>

#include "utils.h"

class ActivityManager
{
public:
	ActivityManager();

	inline const std::vector<Activity>& GetActivities() const noexcept { return m_activities; }

	void AddActivity(const Activity& activity);

	void StartActivity(int index);

	void RemoveActivity(int index);

	void CompleteActivity(int index);

	void PrintActivities() const;

	void PrintLongActivities() const;

	void PrintShortestActivity() const;

	void PrintLongestActivity() const;

	void PrintAverageActivityNameLength() const;

	void PrintHighPriorityActivities() const;

	void PrintActivitiesByStatus(ActivityStatus status) const;

	void ShowDeveloperMode() const;
private:
	std::vector<Activity> m_activities;

	std::string m_currentMilestone{ "Week 1 Complete" };
	
	bool IsActivitiesEmpty() const;

	bool IsValidActivityIndex(int index) const;

	std::string GetActivityStatusString(const Activity& activity) const;

	std::string GetActivityPriorityString(const Activity& activity) const;

	void PrintActivity(const Activity& activity, int number = -1) const;

	void SaveActivitiesToFile() const;

	void LoadActivitiesFromFile();
};