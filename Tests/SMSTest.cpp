#include "pch.h"
#include <functional>
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\SMS.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Notification.h"

class SMSTestFixture : public ::testing::Test {
protected:
    SMS sms; 

    SMSTestFixture()
        : sms("Hello, this is a test message.", "2024-11-11 10:00:00", "+1234567890", "Alice") {}

    std::string captureOutput(std::function<void()> func) {
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        func();
        std::string output = buffer.str();
        std::cout.rdbuf(old);
        return output;
    }
};

TEST_F(SMSTestFixture, SendSMS) {
    std::string output = captureOutput([&]() { sms.send(); });
    EXPECT_NE(output.find("Sending SMS to +1234567890: Hello, this is a test message. at 2024-11-11 10:00:00"), std::string::npos);
}

TEST_F(SMSTestFixture, ReadSMS) {
    std::string output = captureOutput([&]() { sms.read(); });
    EXPECT_NE(output.find("SMS notification read: Hello, this is a test message."), std::string::npos);
}

