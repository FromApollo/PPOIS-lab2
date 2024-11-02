#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\SMS.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Notification.h"

#include <gtest/gtest.h>
#include "SMS.h"

class SMSTest : public ::testing::Test {
protected:
    SMS* sms;

    void SetUp() override {
        sms = new SMS("Hello, World!", "2024-11-02 10:00", "+1234567890", "Alice");
    }

    void TearDown() override {
        delete sms;
    }
};

TEST_F(SMSTest, TestSend) {
    testing::internal::CaptureStdout(); 
    sms->send(); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sending SMS to +1234567890: Hello, World! at 2024-11-02 10:00\n");
}

TEST_F(SMSTest, TestRead) {
    testing::internal::CaptureStdout();
    sms->read(); 
    std::string output = testing::internal::GetCapturedStdout(); 
    EXPECT_EQ(output, "SMS notification read: Hello, World!\n"); 
}

TEST_F(SMSTest, TestGetText) {
    EXPECT_EQ(sms->getText(), "Hello, World!");
}

TEST_F(SMSTest, TestGetTimestamp) {
    EXPECT_EQ(sms->getTimestamp(), "2024-11-02 10:00");
}

TEST_F(SMSTest, TestGetSenderName) {
    EXPECT_EQ(sms->getSenderName(), "Alice");
}
