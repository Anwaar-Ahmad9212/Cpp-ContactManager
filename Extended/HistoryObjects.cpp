
#include "HistoryObjects.h"
#include "iostream"
HistoryObjects::HistoryObjects(const std::string& str)
	: Str(str)
{
	char buffer[26];
	std::time_t now = std::time(nullptr);

	if (ctime_s(buffer, sizeof(buffer), &now) == 0) {
		std::string currentTime(buffer);

		setCurrentTime(currentTime);
		//std::cout << "Current time: " << currentTime << std::endl;
	}
	else {
		std::cout << "Failed to get current time\n";
	}
}

//HistoryObjects::HistoryObjects() {}

void HistoryObjects::setStr(const std::string& str)
{
	Str = str;
}

std::string HistoryObjects::getStr() const
{
	return Str;
}

void HistoryObjects::setCurrentTime(const std::string& currenttime)
{
	CurrentTime = currenttime;
}

std::string HistoryObjects::getCurrentTime() const
{
	return CurrentTime;
}
