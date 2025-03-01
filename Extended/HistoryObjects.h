#pragma once

#include <string>
#include <ctime>

class HistoryObjects 
{
private:
    std::string Str;
    std::string CurrentTime;


public:
    HistoryObjects() {}
    HistoryObjects(const std::string& str);
    // HistoryObjects();

    void setStr(const std::string& str);
    std::string getStr() const;

    void setCurrentTime(const std::string& currenttime);
    std::string getCurrentTime() const;
};