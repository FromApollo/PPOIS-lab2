#include "Notification.h"


Notification::Sender::Sender(const std::string& name) : name(name) {}


std::string Notification::Sender::getName() const {
    return name;
}


Notification::Notification(const std::string& text, const std::string& timestamp, const std::string& senderName)
    : text(text), timestamp(timestamp), sender(senderName) {}


std::string Notification::getText() const {
    return text;
}


std::string Notification::getTimestamp() const {
    return timestamp;
}


std::string Notification::getSenderName() const {
    return sender.getName();
}
