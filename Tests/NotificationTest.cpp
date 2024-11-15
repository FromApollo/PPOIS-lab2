#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Notification.h"

class TestNotification : public Notification {
public:
    TestNotification(const std::string& text, const std::string& timestamp, const std::string& senderName)
        : Notification(text, timestamp, senderName) {}

    void send() override {
        std::cout << "Sending: " << text << " from " << senderName << " at " << timestamp << std::endl;
    }

    void read() override {
        std::cout << "Reading: " << text << " from " << senderName << " at " << timestamp << std::endl;
    }
};

TEST(NotificationTest, GetText) {
    TestNotification notification("Hello, world!", "2024-11-11 10:00", "John Doe");

    EXPECT_EQ(notification.getText(), "Hello, world!");
}

TEST(NotificationTest, GetTimestamp) {
    TestNotification notification("Hello, world!", "2024-11-11 10:00", "John Doe");

    EXPECT_EQ(notification.getTimestamp(), "2024-11-11 10:00");
}

TEST(NotificationTest, GetSenderName) {
    TestNotification notification("Hello, world!", "2024-11-11 10:00", "John Doe");

    EXPECT_EQ(notification.getSenderName(), "John Doe");
}

TEST(NotificationTest, Send) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf()); 

    TestNotification notification("Hello, world!", "2024-11-11 10:00", "John Doe");
    notification.send();

    std::string output = buffer.str();
    EXPECT_NE(output.find("Sending: Hello, world! from John Doe at 2024-11-11 10:00"), std::string::npos);

    std::cout.rdbuf(old); 
}

TEST(NotificationTest, Read) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf()); 

    TestNotification notification("Hello, world!", "2024-11-11 10:00", "John Doe");
    notification.read();

    std::string output = buffer.str();
    EXPECT_NE(output.find("Reading: Hello, world! from John Doe at 2024-11-11 10:00"), std::string::npos);

    std::cout.rdbuf(old); 
}
