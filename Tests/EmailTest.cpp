#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Email.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\Notification.h"

class EmailTest : public ::testing::Test {
protected:
    Email* email;

    void SetUp() override {
        email = new Email("�������� ����", "��� ����� ���� ������.", "2024-11-02 10:00",
            "test@example.com", "�����");
    }

    void TearDown() override {
        delete email;
    }
};

TEST_F(EmailTest, SendEmailTest) {

    testing::internal::CaptureStdout();
    email->send();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Sending Email to test@example.com:"), std::string::npos);
    EXPECT_NE(output.find("Subject: �������� ����"), std::string::npos);
    EXPECT_NE(output.find("Body: ��� ����� ���� ������."), std::string::npos);
    EXPECT_NE(output.find("Timestamp: 2024-11-02 10:00"), std::string::npos);
}

TEST_F(EmailTest, ReadEmailTest) {

    testing::internal::CaptureStdout();
    email->read();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Email notification read:"), std::string::npos);
    EXPECT_NE(output.find("From: test@example.com"), std::string::npos);
    EXPECT_NE(output.find("Subject: �������� ����"), std::string::npos);
    EXPECT_NE(output.find("Body: ��� ����� ���� ������."), std::string::npos);
}

TEST_F(EmailTest, GetEmailContentTest) {
    std::string content = email->getEmailContent();
    EXPECT_EQ(content, "Subject: �������� ����\nBody: ��� ����� ���� ������.");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
