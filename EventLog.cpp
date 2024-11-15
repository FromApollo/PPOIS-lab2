#include "EventLog.h"

void EventLog::addEntry(const std::string& event) {
    entries.push_back(event);
    std::cout << "Event logged: " << event << "\n";
}

void EventLog::viewLog() const {
    std::cout << "Event Log:\n";
    for (const auto& entry : entries) {
        std::cout << "- " << entry << "\n";
    }
}