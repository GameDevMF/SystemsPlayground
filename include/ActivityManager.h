#pragma once
#include <vector>
#include <unordered_map>

enum class ActivityStatus
{
	Todo,
	InProgress,
	Completed
};

enum class PriorityLevel
{
	Lowest = 1,
	Low = 2,
	Medium = 3,
	High = 4,
	Highest = 5
};

struct Activity
{
	std::string Name{ "" };
	PriorityLevel Priority{ PriorityLevel::Lowest };
	ActivityStatus Status{ ActivityStatus::Todo };

	Activity() = default;

	Activity(const std::string& name)
		: Name(name) {}

	Activity(const std::string& name, PriorityLevel priority, ActivityStatus status = ActivityStatus::Todo)
		: Name(name), Priority(priority), Status(status) {}
};

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

	void PrintStats() const;

	void ClearActivities();

	void ShowDeveloperMode() const;

	void IncrementCommandCount(const std::string& command);
private:
	std::string m_currentMilestone{ "Week 2 Complete" };

	std::vector<Activity> m_activities;

	std::unordered_map<std::string, int> m_commandCount;
	
	bool IsActivitiesEmpty() const;

	static std::string GetActivityStatusString(const Activity& activity);

	static std::string GetActivityPriorityString(const Activity& activity);

	static void PrintActivity(const Activity& activity, int number = -1);

	static bool CompareActivityNameCaseInsensitive(std::string a, std::string b);

	void SaveActivitiesToFile();

	void LoadActivitiesFromFile();

	static bool IsSaveFileVersionValid(const std::string& versionLine);

	static bool TryParseActivityLine(const std::string& line, Activity& outActivity);

	bool ContainsInvalidSaveCharacter(const std::string& name);
};