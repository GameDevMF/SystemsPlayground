#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

#include "ActivityManager.h"
#include "utils.h"

constexpr int LONG_ACTIVITY_NAME_THRESHOLD{ 7 };
constexpr int SAVE_FILE_VERSION{ 1 };
constexpr PriorityLevel HIGH_PRIORITY_THRESHOLD{ PriorityLevel::High };
const std::string SAVE_FILE_PATH{ "activities.txt" };

ActivityManager::ActivityManager()
{
	LoadActivitiesFromFile();

	std::cout << "Activity Manager created!" << std::endl;
}

bool ActivityManager::TryGetActivityIndex(const std::string& input, int& outIndex) const
{
	try
	{
		outIndex = std::stoi(input);
		outIndex--;

		if (IsActivitiesEmpty())
		{
			PrintWarning("No activities found.");
			return false;
		}

		if (outIndex < 0 || outIndex > m_activities.size() - 1)
		{
			PrintError("Invalid index.");
			return false;
		}

		return true;
	}
	catch (const std::exception&)
	{
		PrintError("Invalid index.");
		return false;
	}
}

void ActivityManager::AddActivity(const Activity& activity)
{
	if (activity.Name.empty())
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

	if (activity.Name.find('=') != std::string::npos)
	{
		PrintWarning("Activity name cannot contain the '=' character. Please try again.");
		return;
	}

	m_activities.push_back(activity);

	SaveActivitiesToFile();
}

void ActivityManager::StartActivity(int index)
{
	if (m_activities[index].Status == ActivityStatus::Completed)
	{
		PrintWarning("This activity is already completed. Please try again.");
		return;
	}

	if (m_activities[index].Status == ActivityStatus::InProgress)
	{
		PrintWarning("This activity is already in progress. Please try again.");
		return;
	}

	m_activities[index].Status = ActivityStatus::InProgress;
	std::cout << "Activity " << m_activities[index].Name << " started!" << std::endl;

	SaveActivitiesToFile();
}

void ActivityManager::RemoveActivity(int index)
{
	m_activities.erase(m_activities.begin() + index);

	SaveActivitiesToFile();
}

void ActivityManager::CompleteActivity(int index)
{
	m_activities[index].Status = ActivityStatus::Completed;
	std::cout << "Activity " << m_activities[index].Name << " completed!" << std::endl;

	SaveActivitiesToFile();
}

void ActivityManager::SortByName()
{
	std::sort(m_activities.begin(), m_activities.end(), [](const Activity& a, const Activity& b)
	{
		return CompareActivityNameCaseInsensitive(a.Name, b.Name);
	});

	PrintActivities();
}

void ActivityManager::SortByPriority()
{
	std::sort(m_activities.begin(), m_activities.end(), [](const Activity& a, const Activity& b)
	{
		return a.Priority > b.Priority;
	});

	PrintActivities();
}

void ActivityManager::SortByStatus()
{
	std::sort(m_activities.begin(), m_activities.end(), [](const Activity& a, const Activity& b)
	{
		return a.Status > b.Status;
	});

	PrintActivities();
}

void ActivityManager::SortByPriorityThenName()
{
	std::sort(m_activities.begin(), m_activities.end(), [](const Activity& a, const Activity& b)
	{
		if (a.Priority == b.Priority)
			return CompareActivityNameCaseInsensitive(a.Name, b.Name);
		return a.Priority > b.Priority;
	});

	PrintActivities();
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

void ActivityManager::ClearActivities()
{
	m_activities.clear();
	std::cout << "All activities cleared!" << std::endl;
	SaveActivitiesToFile();
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

std::string ActivityManager::GetActivityStatusString(const Activity& activity)
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

std::string ActivityManager::GetActivityPriorityString(const Activity& activity)
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

void ActivityManager::PrintActivity(const Activity& activity, int number)
{
	if (number != -1)
		std::cout << number << ". ";

	std::cout << activity.Name <<
		", Priority: " << GetActivityPriorityString(activity) <<
		" " << GetActivityStatusString(activity) <<
		std::endl;
}

bool ActivityManager::CompareActivityNameCaseInsensitive(std::string a, std::string b)
{
	std::transform(a.begin(), a.end(), a.begin(),
		[](unsigned char c) { return std::tolower(c); });

	std::transform(b.begin(), b.end(), b.begin(),
		[](unsigned char c) { return std::tolower(c); });

	return a < b;
}

void ActivityManager::SaveActivitiesToFile()
{
	std::ofstream file(SAVE_FILE_PATH);

	if (!file.is_open())
	{
		PrintError("Failed to save activities to file.");
		return;
	}

	file << "VERSION=" << SAVE_FILE_VERSION << std::endl;

	for (const Activity& activity : m_activities)
		file << activity.Name << "|" << static_cast<int>(activity.Priority) << "|" << static_cast<int>(activity.Status) << std::endl;

	file.close();
}

void ActivityManager::LoadActivitiesFromFile()
{
	std::ifstream file(SAVE_FILE_PATH);

	if (!file)
		return;

	std::string line;

	if (!std::getline(file, line))
		return;

	if (!IsSaveFileVersionValid(line))
		return;

	while (std::getline(file, line))
	{
		Activity activity;

		if (TryParseActivityLine(line, activity))
			m_activities.push_back(activity);
	}
}

bool ActivityManager::IsSaveFileVersionValid(const std::string& versionLine)
{
	size_t delimiter{ versionLine.find('=') };

	if (delimiter == std::string::npos)
	{
		PrintWarning("Missing version in save file.");
		return false;
	}

	try
	{
		int version = std::stoi(versionLine.substr(delimiter + 1));

		if (version != SAVE_FILE_VERSION)
		{
			PrintWarning("Incompatible version in save file.");
			return false;
		}

		return true;
	}
	catch (const std::exception&)
	{
		PrintWarning("Invalid version format in save file.");
		return false;
	}
}

bool ActivityManager::TryParseActivityLine(const std::string& line, Activity& outActivity)
{
	size_t firstDelimiter{ line.find('|') };
	size_t secondDelimiter{ line.find('|', firstDelimiter + 1) };

	if (firstDelimiter == std::string::npos || secondDelimiter == std::string::npos)
	{
		PrintWarning("Invalid activity format in save file. Skipping line.");
		return false;
	}

	outActivity.Name = line.substr(0, firstDelimiter);

	try
	{
		int priorityValue = std::stoi(line.substr(firstDelimiter + 1, secondDelimiter - firstDelimiter - 1));
		int statusValue = std::stoi(line.substr(secondDelimiter + 1));

		if (priorityValue < static_cast<int>(PriorityLevel::Lowest) || priorityValue > static_cast<int>(PriorityLevel::Highest) ||
			statusValue < static_cast<int>(ActivityStatus::Todo) || statusValue > static_cast<int>(ActivityStatus::Completed))
		{
			PrintWarning("Invalid priority or status value in save file. Skipping line.");
			return false;
		}

		outActivity.Priority = static_cast<PriorityLevel>(priorityValue);
		outActivity.Status = static_cast<ActivityStatus>(statusValue);
	}
	catch (const std::exception&)
	{
		PrintWarning("Invalid activity data in save file. Skipping line.");
		return false;
	}

	return true;
}
