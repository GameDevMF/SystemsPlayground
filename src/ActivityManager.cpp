#include "ActivityManager.h"

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

void ActivityManager::RemoveActivity(int index)
{
	if (!IsValidActivityIndex(index))
		return;

	m_activities.erase(m_activities.begin() + index);
}

void ActivityManager::PrintActivities()
{
	if (IsActivitiesEmpty())
		return;

	std::cout << "Here are your activities:" << std::endl;

	for (size_t i = 0; i < m_activities.size(); i++)
		std::cout << i + 1 << ". " << m_activities[i].Name <<
		", Priority: " << m_activities[i].Priority <<
		" " << GetActivityStatus(m_activities[i]) <<
		std::endl;

	std::cout << "Activities tracked: " << m_activities.size() << std::endl;
}

void ActivityManager::PrintLongActivities()
{
	if (IsActivitiesEmpty())
		return;

	std::cout << "Here are your long activities:" << std::endl;

	for (const Activity& activity : m_activities)
		if (activity.Name.length() > 7)
			std::cout << activity.Name << std::endl;
}

void ActivityManager::PrintShortestActivity()
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

void ActivityManager::PrintLongestActivity()
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

void ActivityManager::PrintAverageActivityNameLength()
{
	if (IsActivitiesEmpty())
		return;

	float count{ 0.0f };

	for (const Activity& activity : m_activities)
		count += activity.Name.size();

	std::cout << "Your average activity name length is " << count / m_activities.size() << std::endl;
}

void ActivityManager::CompleteActivity(const int index)
{
	if (!IsValidActivityIndex(index))
		return;

	m_activities[index].IsCompleted = true;
	std::cout << "Activity " << m_activities[index].Name << " completed!" << std::endl;
}

bool ActivityManager::IsActivitiesEmpty()
{
	if (m_activities.empty())
	{
		PrintWarning("No activities found.");
		return true;
	}

	return false;
}

bool ActivityManager::IsValidActivityIndex(const int index)
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

std::string ActivityManager::GetActivityStatus(const Activity& activity)
{
	return activity.IsCompleted ? " [Done]" : " [Todo]";
}