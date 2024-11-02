#ifndef EMAIL_H
#define EMAIL_H

#include "Notification.h"
#include <iostream>
#include <string>

class Email : public Notification {
private:
    std::string address;


    class EmailContent {
    private:
        std::string subject;
        std::string body;

    public:
        EmailContent(const std::string& subject, const std::string& body);

        std::string getSubject() const;

        std::string getBody() const;
    };

    EmailContent content;

public:
    Email(const std::string& subject, const std::string& body, const std::string& timestamp, const std::string& address,
        const std::string& senderName);

    void send() override;

    void read() override;

    std::string getEmailContent() const;
};

#endif 
