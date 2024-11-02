#include "Email.h"
#include "Notification.h"


Email::Email(const std::string& subject, const std::string& body, const std::string& timestamp,
    const std::string& address, const std::string& senderName)
    : Notification(body, timestamp, senderName),
    address(address),
    content(subject, body) {}

Email::EmailContent::EmailContent(const std::string& subject, const std::string& body)
    : subject(subject), body(body) {}

std::string Email::EmailContent::getSubject() const {
    return subject;
}

std::string Email::EmailContent::getBody() const {
    return body;
}

void Email::send() {
    std::cout << "Sending Email to " << address << ":\n"
        << "Subject: " << content.getSubject() << "\n"
        << "Body: " << content.getBody() << "\n"
        << "Timestamp: " << timestamp << "\n";
}

void Email::read() {
    std::cout << "Email notification read:\n"
        << "From: " << address << "\n"
        << "Subject: " << content.getSubject() << "\n"
        << "Body: " << content.getBody() << "\n";
}


std::string Email::getEmailContent() const {
    return "Subject: " + content.getSubject() + "\nBody: " + content.getBody();
}
