#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Notification.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\NotificationSystem.h"

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


class NotificationSystemTest : public ::testing::Test {
protected:
    NotificationSystem* notificationSystem;

    void SetUp() override {
        notificationSystem = new NotificationSystem();
    }

    void TearDown() override {
        delete notificationSystem;
    }
};

TEST_F(NotificationSystemTest, AddNotificationTest) {
    TestNotification* notification = new TestNotification("Test notification", "2024-11-02 10:00", "Test Sender");
    notificationSystem->addNotification(notification);
}

TEST_F(NotificationSystemTest, SendAllNotificationsTest) {
    testing::internal::CaptureStdout();

    TestNotification* notification1 = new TestNotification("First notification", "2024-11-02 10:00", "Sender1");
    TestNotification* notification2 = new TestNotification("Second notification", "2024-11-02 10:01", "Sender2");

    notificationSystem->addNotification(notification1);
    notificationSystem->addNotification(notification2);

    notificationSystem->sendAll();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,
        "Sending notification: First notification at 2024-11-02 10:00\n"
        "Sending notification: Second notification at 2024-11-02 10:01\n"
    );
}

TEST_F(NotificationSystemTest, ReadAllNotificationsTest) {
    testing::internal::CaptureStdout();

    TestNotification* notification1 = new TestNotification("Test notification 1", "2024-11-02 10:00", "Sender1");
    TestNotification* notification2 = new TestNotification("Test notification 2", "2024-11-02 10:01", "Sender2");

    notificationSystem->addNotification(notification1);
    notificationSystem->addNotification(notification2);

    notificationSystem->readAll();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output,
        "Reading notification: Test notification 1\n"
        "Reading notification: Test notification 2\n"
    );
}
