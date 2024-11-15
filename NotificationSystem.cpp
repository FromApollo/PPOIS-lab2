#include "NotificationSystem.h"
#include <iostream>

void NotificationSystem::addNotification(Notification* notification) {
    notifications.push_back(notification);
}

void NotificationSystem::sendAll() {
    for (auto notification : notifications) {
        notification->send();
    }
}

void NotificationSystem::readAll() {
    for (auto notification : notifications) {
        notification->read();
    }
}

NotificationSystem::~NotificationSystem() {

    for (auto notification : notifications) {
        delete notification;
    }
    notifications.clear();
}