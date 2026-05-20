#include "ActivityManager.h"

constexpr int HIGH_PRIORITY_THRESHOLD{ 7 };
constexpr int LONG_ACTIVITY_NAME_THRESHOLD{ 7 };

ActivityManager::ActivityManager()
{
	std::cout << "Activity Manager created!" << std::endl;
}

void ActivityManager::AddActivity(const Activity& activity)
{
	if (activity.Name.size() == 0)
	{
		PrintError("Name must have at least 1 character");
		return;
	}

	for (const Activity& existingActivity : m_activities)
	{
		if (existingActivity.Name == activity.Name)
		{
			PrintWarning("This activity already exists. Please try again.");
			return;
		}
	}

	m_activities.push_back(activity);
}

void ActivityManager::RemoveActivity(const int index)
{
	if (!IsValidActivityIndex(index))
		return;

	m_activities.erase(m_activities.begin() + index);
}

void ActivityManager::CompleteActivity(const int index)
{
	if (!IsValidActivityIndex(index))
		return;

	m_activities[index].IsCompleted = true;
	std::cout << "Activity " << m_activities[index].Name << " completed!" << std::endl;
}

void ActivityManager::PrintActivities() const
{
	if (IsActivitiesEmpty())
		return;

	std::cout << "Here are your activities:" << std::endl;

	for (size_t i = 0; i < m_activities.size(); i++)
		PrintActivity(m_activities[i], i + 1);

	std::cout << "Activities tracked: " << m_activities.size() << std::endl;
}

void ActivityManager::PrintLongActivities() const
{
	if (IsActivitiesEmpty())
		return;

	std::cout << "Here are your long activities:" << std::endl;

	for (const Activity& activity : m_activities)
		if (activity.Name.length() > LONG_ACTIVITY_NAME_THRESHOLD)
			std::cout << activity.Name << std::endl;
}

void ActivityManager::PrintShortestActivity() const
{
	if (IsActivitiesEmpty())
		return;

	int index{ -1 };
	int size{ 0 };

	for (size_t i = 0; i < m_activities.size(); i++)
	{
		if (index == -1 || m_activities[i].Name.size() < size)
		{
			index = i;
			size = m_activities[i].Name.size();
		}
	}

	std::cout << "Your shortest activity is " << m_activities[index].Name << std::endl;
}

void ActivityManager::PrintLongestActivity() const
{
	if (IsActivitiesEmpty())
		return;

	int index{ -1 };
	int size{ 0 };

	for (size_t i = 0; i < m_activities.size(); i++)
	{
		if (index == -1 || m_activities[i].Name.size() > size)
		{
			index = i;
			size = m_activities[i].Name.size();
		}
	}

	std::cout << "Your longest activity is " << m_activities[index].Name << std::endl;
}

void ActivityManager::PrintAverageActivityNameLength() const
{
	if (IsActivitiesEmpty())
		return;

	float count{ 0.0f };

	for (const Activity& activity : m_activities)
		count += activity.Name.size();

	std::cout << "Your average activity name length is " << count / m_activities.size() << std::endl;
}

void ActivityManager::PrintHighPriorityActivities() const
{
	for (const Activity& activity : m_activities)
		if (activity.Priority >= HIGH_PRIORITY_THRESHOLD)
			PrintActivity(activity);
}

void ActivityManager::ShowDeveloperMode() const
{
	int completed{ 0 };

	for (const Activity& activity : m_activities)
		if (activity.IsCompleted)
			completed++;

	int completedPercentage{ 0 };

	if (m_activities.size())
		completedPercentage = static_cast<int>(static_cast<float>(completed) / m_activities.size() * 100.0f);

	std::cout << "---Developer mode---" << std::endl;
	std::cout << "App version 0.0.1" << std::endl;
	std::cout << "Number of activities: " << m_activities.size() << std::endl;
	std::cout << "Number of completed activities: " << completed << std::endl;
	std::cout << "Percentage of completed activities: " << completedPercentage << std::endl;
	std::cout << "Current build target: " << (sizeof(void*) == 8 ? "x64" : "x86") << std::endl;
	std::cout << "Current Milestone: " << m_currentMilestone << std::endl;
}

bool ActivityManager::IsActivitiesEmpty() const
{
	if (m_activities.empty())
	{
		PrintWarning("No activities found.");
		return true;
	}

	return false;
}

bool ActivityManager::IsValidActivityIndex(const int index) const
{
	if (IsActivitiesEmpty())
		return false;

	if (index < 0 || index > m_activities.size() - 1)
	{
		PrintError("Invalid index. Please try again.");
		return false;
	}

	return true;
}

std::string ActivityManager::GetActivityStatus(const Activity& activity) const
{
	return activity.IsCompleted ? " [Done]" : " [Todo]" ;
}

void ActivityManager::PrintActivity(const Activity& activity, const int number) const
{
	if (number != -1)
		std::cout << number << ". ";

	std::cout << activity.Name <<
		", Priority: " << activity.Priority <<
		" " << GetActivityStatus(activity) <<
		std::endl;
}