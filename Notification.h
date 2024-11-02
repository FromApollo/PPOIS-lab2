#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <string>

class Notification {
protected:
    std::string text;
    std::string timestamp;


    class Sender {
    private:
        std::string name;

    public:
        Sender(const std::string& name);

        std::string getName() const;
    };

    Sender sender;

public:
    Notification(const std::string& text, const std::string& timestamp, const std::string& senderName);

    virtual void send() = 0;

    virtual void read() = 0;

    std::string getText() const;

    std::string getTimestamp() const;

    std::string getSenderName() const;
};

#endif 
