#ifndef NOTIFICATIONSYSTEM_H
#define NOTIFICATIONSYSTEM_H

#include "Notification.h"
#include <vector>

class NotificationSystem {
private:
    std::vector<Notification*> notifications;

public:
    void addNotification(Notification* notification);

    void sendAll();

    void readAll();

    ~NotificationSystem();
};

#endif 