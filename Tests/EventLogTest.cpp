#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\EventLog.h"


class EventLogTest : public ::testing::Test {
protected:
    EventLog log;  

    EventLogTest() {}

    void TearDown() override {}
};

TEST_F(EventLogTest, AddEntry) {

    testing::internal::CaptureStdout();

    log.addEntry("User logged in");

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Event logged: User logged in"), std::string::npos);
}

TEST_F(EventLogTest, ViewLog) {

    testing::internal::CaptureStdout();

    log.addEntry("User logged in");
    log.addEntry("File uploaded");

    log.viewLog();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Event Log:"), std::string::npos);
    EXPECT_NE(output.find("- User logged in"), std::string::npos);
    EXPECT_NE(output.find("- File uploaded"), std::string::npos);
}

TEST_F(EventLogTest, EmptyLog) {

    testing::internal::CaptureStdout();

    log.viewLog();

    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Event Log:"), std::string::npos);
    EXPECT_EQ(output.find("-"), std::string::npos);  
}
