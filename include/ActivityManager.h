#pragma once
#include <vector>

#include "utils.h"

class ActivityManager
{
public:
	ActivityManager();

	inline const std::vector<Activity>& GetActivities() const noexcept { return m_activities; }

	bool TryGetActivityIndex(const std::string& input, int& outIndex) const;

	void AddActivity(const Activity& activity);

	void StartActivity(int index);

	void RemoveActivity(int index);

	void CompleteActivity(int index);

	void SortByName();

	void SortByPriority();

	void SortByStatus();

	void SortByPriorityThenName();

	void PrintActivities() const;

	void PrintLongActivities() const;

	void PrintShortestActivity() const;

	void PrintLongestActivity() const;

	void PrintAverageActivityNameLength() const;

	void PrintHighPriorityActivities() const;

	void PrintActivitiesByStatus(ActivityStatus status) const;

	void ClearActivities();

	void ShowDeveloperMode() const;
private:
	std::vector<Activity> m_activities;

	std::string m_currentMilestone{ "Week 1 Complete" };
	
	bool IsActivitiesEmpty() const;

	static std::string GetActivityStatusString(const Activity& activity);

	static std::string GetActivityPriorityString(const Activity& activity);

	static void PrintActivity(const Activity& activity, int number = -1);

	static bool CompareActivityNameCaseInsensitive(std::string a, std::string b);

	void SaveActivitiesToFile();

	void LoadActivitiesFromFile();

	static bool IsSaveFileVersionValid(const std::string& versionLine);

	static bool TryParseActivityLine(const std::string& line, Activity& outActivity);
};