#include "SMS.h"


SMS::SMS(const std::string& text, const std::string& timestamp, const std::string& phoneNumber,
    const std::string& senderName)
    : Notification(text, timestamp, senderName), phoneNumber(phoneNumber) {}

void SMS::send() {
    std::cout << "Sending SMS to " << phoneNumber << ": " << text << " at " << timestamp << "\n";
}

void SMS::read() {
    std::cout << "SMS notification read: " << text << "\n";
}
