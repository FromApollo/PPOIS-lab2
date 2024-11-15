#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Email.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Notification.h"


class FakeNotification : public Notification {
public:
    FakeNotification(const std::string& text, const std::string& timestamp, const std::string& senderName)
        : Notification(text, timestamp, senderName) {}

    void send() override {
    }

    void read() override {
    }
};

class EmailTest : public ::testing::Test {
protected:

    Email email;

    EmailTest() : email("Subject", "Body", "2024-11-11 10:00:00", "receiver@example.com", "John Doe") {}

    void TearDown() override {
    }
};

TEST_F(EmailTest, SendEmail) {

    testing::internal::CaptureStdout();
    email.send();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Sending Email to receiver@example.com:"), std::string::npos);
    EXPECT_NE(output.find("Subject: Subject"), std::string::npos);
    EXPECT_NE(output.find("Body: Body"), std::string::npos);
}

TEST_F(EmailTest, ReadEmail) {

    testing::internal::CaptureStdout();
    email.read();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Email notification read:"), std::string::npos);
    EXPECT_NE(output.find("From: receiver@example.com"), std::string::npos);
    EXPECT_NE(output.find("Subject: Subject"), std::string::npos);
    EXPECT_NE(output.find("Body: Body"), std::string::npos);
}

TEST_F(EmailTest, GetEmailContent) {

    std::string content = email.getEmailContent();
    EXPECT_EQ(content, "Subject: Subject\nBody: Body");
}
