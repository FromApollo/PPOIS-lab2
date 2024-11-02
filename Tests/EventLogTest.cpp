#include "pch.h"
#include "D:\BSUIR\3 semester\PPOIS\lab2\Project1\Project1\EventLog.h"

class EventLogTest : public ::testing::Test {
protected:
    EventLog* eventLog;

    void SetUp() override {
        eventLog = new EventLog();
    }

    void TearDown() override {
        delete eventLog;
    }
};

TEST_F(EventLogTest, AddEntryTest) {

    testing::internal::CaptureStdout();
    eventLog->addEntry("Test event 1");
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Event logged: Test event 1\n");
}

TEST_F(EventLogTest, ViewLogTest) {
    eventLog->addEntry("Test event 1");
    eventLog->addEntry("Test event 2");


    testing::internal::CaptureStdout();
    eventLog->viewLog();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Event Log:"), std::string::npos);
    EXPECT_NE(output.find("- Test event 1"), std::string::npos);
    EXPECT_NE(output.find("- Test event 2"), std::string::npos);
}

TEST_F(EventLogTest, ViewLogEmptyTest) {

    testing::internal::CaptureStdout();
    eventLog->viewLog();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Event Log:\n");
}


