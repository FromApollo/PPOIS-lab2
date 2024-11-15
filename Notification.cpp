#include "Notification.h"

Notification::Notification(const std::string& text, const std::string& timestamp, const std::string& senderName)
    : text(text), timestamp(timestamp), senderName(senderName) {}

std::string Notification::getText() const {
    return text;
}

std::string Notification::getTimestamp() const {
    return timestamp;
}

std::string Notification::getSenderName() const {
    return senderName;
}
