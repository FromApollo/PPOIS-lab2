#ifndef SMS_H
#define SMS_H

#include "Notification.h"
#include <iostream>

class SMS : public Notification {
private:
    std::string phoneNumber;

public:
    SMS(const std::string& text, const std::string& timestamp, const std::string& phoneNumber,
        const std::string& senderName);

    void send() override;

    void read() override;
};

#endif 
