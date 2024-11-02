#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Notification.h"


class TestNotification : public Notification {
public:
    TestNotification(const std::string& text, const std::string& timestamp, const std::string& senderName)
        : Notification(text, timestamp, senderName) {}

    void send() override {
        std::cout << "Sending notification: " << text << " at " << timestamp << "\n";
    }

    void read() override {
        std::cout << "Reading notification: " << text << "\n";
    }
};

class NotificationTest : public ::testing::Test {
protected:
    TestNotification* notification;

    void SetUp() override {
        notification = new TestNotification("Test notification", "2024-11-02 10:00", "Test Sender");
    }

    void TearDown() override {
        delete notification;
    }
};

TEST_F(NotificationTest, GetTextTest) {
    EXPECT_EQ(notification->getText(), "Test notification");
}

TEST_F(NotificationTest, GetTimestampTest) {
    EXPECT_EQ(notification->getTimestamp(), "2024-11-02 10:00");
}

TEST_F(NotificationTest, GetSenderNameTest) {
    EXPECT_EQ(notification->getSenderName(), "Test Sender");
}

TEST_F(NotificationTest, SendNotificationTest) {
    testing::internal::CaptureStdout();
    notification->send();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sending notification: Test notification at 2024-11-02 10:00\n");
}

TEST_F(NotificationTest, ReadNotificationTest) {
    testing::internal::CaptureStdout();
    notification->read();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Reading notification: Test notification\n");
}
