#ifndef EVENTLOG_H
#define EVENTLOG_H

#include <vector>
#include <string>
#include <iostream>

class EventLog {
private:
    std::vector<std::string> entries;

public:
    void addEntry(const std::string& event);

    void viewLog() const;
};

#endif 