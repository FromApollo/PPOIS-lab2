#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Notification.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\NotificationSystem.h"


class MockNotification : public Notification {
public:
    MockNotification(const std::string& text, const std::string& timestamp, const std::string& senderName)
        : Notification(text, timestamp, senderName) {}

    void send() override {
        std::cout << "Sending mock notification: " << text << "\n";
    }

    void read() override {
        std::cout << "Reading mock notification: " << text << "\n";
    }
};

class NotificationSystemTest : public ::testing::Test {
protected:
    NotificationSystem system; 

    NotificationSystemTest() {}

    void TearDown() override {}
};

TEST_F(NotificationSystemTest, AddNotification) {

    testing::internal::CaptureStdout();

    MockNotification* notification = new MockNotification("Test Notification", "2024-11-11 12:00", "Test Sender");
    system.addNotification(notification);

    system.sendAll(); 

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Sending mock notification: Test Notification"), std::string::npos);
}

TEST_F(NotificationSystemTest, SendAllNotifications) {

    testing::internal::CaptureStdout();

    MockNotification* notification1 = new MockNotification("First Notification", "2024-11-11 12:00", "Sender1");
    MockNotification* notification2 = new MockNotification("Second Notification", "2024-11-11 12:05", "Sender2");
    system.addNotification(notification1);
    system.addNotification(notification2);

    system.sendAll();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Sending mock notification: First Notification"), std::string::npos);
    EXPECT_NE(output.find("Sending mock notification: Second Notification"), std::string::npos);
}

TEST_F(NotificationSystemTest, ReadAllNotifications) {

    testing::internal::CaptureStdout();

    MockNotification* notification1 = new MockNotification("First Notification", "2024-11-11 12:00", "Sender1");
    MockNotification* notification2 = new MockNotification("Second Notification", "2024-11-11 12:05", "Sender2");
    system.addNotification(notification1);
    system.addNotification(notification2);

    system.readAll();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Reading mock notification: First Notification"), std::string::npos);
    EXPECT_NE(output.find("Reading mock notification: Second Notification"), std::string::npos);
}

TEST_F(NotificationSystemTest, DestructorDeletesNotifications) {

    NotificationSystem system;

    MockNotification* notification1 = new MockNotification("First Notification", "2024-11-11 12:00", "Sender1");
    MockNotification* notification2 = new MockNotification("Second Notification", "2024-11-11 12:05", "Sender2");
    system.addNotification(notification1);
    system.addNotification(notification2);
}

