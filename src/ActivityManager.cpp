#include <fstream>
#include <iostream>
#include <string>

#include "ActivityManager.h"

constexpr PriorityLevel HIGH_PRIORITY_THRESHOLD{ PriorityLevel::High };
constexpr int LONG_ACTIVITY_NAME_THRESHOLD{ 7 };

ActivityManager::ActivityManager()
{
	LoadActivitiesFromFile();

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

	if (activity.Name.find('|') != std::string::npos)
	{
		PrintWarning("Activity name cannot contain the '|' character. Please try again.");
		return;
	}

	m_activities.push_back(activity);

	SaveActivitiesToFile();
}

void ActivityManager::StartActivity(int index)
{
	if (!IsValidActivityIndex(index))
		return;

	if (m_activities[index].Status == ActivityStatus::Completed)
	{
		PrintWarning("This activity is already completed. Please try again.");
		return;
	}

	m_activities[index].Status = ActivityStatus::InProgress;
	std::cout << "Activity " << m_activities[index].Name << " started!" << std::endl;

	SaveActivitiesToFile();
}

void ActivityManager::RemoveActivity(int index)
{
	if (!IsValidActivityIndex(index))
		return;

	m_activities.erase(m_activities.begin() + index);

	SaveActivitiesToFile();
}

void ActivityManager::CompleteActivity(int index)
{
	if (!IsValidActivityIndex(index))
		return;

	m_activities[index].Status = ActivityStatus::Completed;
	std::cout << "Activity " << m_activities[index].Name << " completed!" << std::endl;

	SaveActivitiesToFile();
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

void ActivityManager::PrintActivitiesByStatus(ActivityStatus status) const
{
	for (const Activity& activity : m_activities)
		if (activity.Status == status)
			PrintActivity(activity);
}

void ActivityManager::ShowDeveloperMode() const
{
	int completed{ 0 };

	for (const Activity& activity : m_activities)
		if (activity.Status == ActivityStatus::Completed)
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

bool ActivityManager::IsValidActivityIndex(int index) const
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

std::string ActivityManager::GetActivityStatusString(const Activity& activity) const
{
	switch (activity.Status)
	{
	case ActivityStatus::Todo:
		return "[Todo]";
	case ActivityStatus::InProgress:
		return "[In Progress]";
	case ActivityStatus::Completed:
		return "[Done]";
	default:
		return "";
	}
}

std::string ActivityManager::GetActivityPriorityString(const Activity& activity) const
{
	switch (activity.Priority)
	{
	case PriorityLevel::Lowest:
		return "Lowest";
	case PriorityLevel::Low:
		return "Low";
	case PriorityLevel::Medium:
		return "Medium";
	case PriorityLevel::High:
		return "High";
	case PriorityLevel::Highest:
		return "Highest";
	default:
		return "";
	}
}

void ActivityManager::PrintActivity(const Activity& activity, int number) const
{
	if (number != -1)
		std::cout << number << ". ";

	std::cout << activity.Name <<
		", Priority: " << GetActivityPriorityString(activity) <<
		" " << GetActivityStatusString(activity) <<
		std::endl;
}

void ActivityManager::SaveActivitiesToFile() const
{
	std::ofstream file("activities.txt");

	if (!file.is_open())
	{
		PrintError("Failed to save activities to file.");
		return;
	}

	for (const Activity& activity : m_activities)
		file << activity.Name << "|" << static_cast<int>(activity.Priority) << "|" << static_cast<int>(activity.Status) << std::endl;

	file.close();
}

void ActivityManager::LoadActivitiesFromFile()
{
	std::ifstream file("activities.txt");

	if (!file.is_open()) return;

	std::string line;

	while (std::getline(file, line))
	{
		size_t firstDelimiter = line.find('|');
		size_t secondDelimiter = line.find('|', firstDelimiter + 1);

		if (firstDelimiter == std::string::npos || secondDelimiter == std::string::npos)
			continue;

		std::string name = line.substr(0, firstDelimiter);

		int priorityValue = std::stoi(line.substr(firstDelimiter + 1, secondDelimiter - firstDelimiter - 1));
		int statusValue = std::stoi(line.substr(secondDelimiter + 1));

		if (priorityValue < static_cast<int>(PriorityLevel::Lowest) || priorityValue > static_cast<int>(PriorityLevel::Highest) ||
			statusValue < static_cast<int>(ActivityStatus::Todo) || statusValue > static_cast<int>(ActivityStatus::Completed))
		{
			continue;
		}

		PriorityLevel priority = static_cast<PriorityLevel>(priorityValue);
		ActivityStatus status = static_cast<ActivityStatus>(statusValue);

		m_activities.emplace_back(name, priority, status);
	}
	file.close();
}
