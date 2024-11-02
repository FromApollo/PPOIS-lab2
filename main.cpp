#include <iostream>
#include <vector>
#include "Administrator.h"
#include "Draft.h"
#include "Editor.h"
#include "Email.h"
#include "EventLog.h"
#include "Notification.h"
#include "NotificationSystem.h"
#include "OfficialDocument.h"
#include "Reader.h"
#include "SecuritySystem.h"
#include "SMS.h"
#include "User.h"
#include "UserGroup.h"
#include "Document.h"
#include "AccessRights.h"

int main() {

    User* user1 = new User(1, "Alice", "alice@example.com", "password123");
    User* user2 = new User(2, "Bob", "bob@example.com", "password456");


    Administrator admin(1, "Charlie", "charlie@example.com", "adminpassword", 1);


    admin.addUser(*user1);
    admin.addUser(*user2);
    admin.deleteUser(*user1);


    UserGroup group("Editors");
    group.addUser(user1);
    group.addUser(user2);
    group.listMembers();


    Document document(1, "Sample Document", "This is the content of the document.", "2024-11-01");
    document.view();


    NotificationSystem notificationSystem;
    Email* email = new Email("Meeting Reminder", "Don't forget about the meeting at 3 PM.", "2024-11-01 12:00",
        "bob@example.com", "Alice");
    SMS* sms = new SMS("Meeting in 1 hour", "2024-11-01 14:00", "+1234567890", "Alice");
    notificationSystem.addNotification(email);
    notificationSystem.addNotification(sms);
    notificationSystem.sendAll();


    notificationSystem.readAll();


    OfficialDocument officialDoc(1, "Official Document Title", "Official content", "2024-11-01", 123, "Report", false);
    officialDoc.view();
    officialDoc.sign();
    officialDoc.view();


    Reader reader(1, "Diana", "diana@example.com", "password789");
    reader.viewDocument(officialDoc);
    reader.addToBookmarks(officialDoc);


    SecuritySystem securitySystem;
    securitySystem.addUser(user1, "password123");
    securitySystem.addUser(user2, "password456");


    securitySystem.checkPassword(user1, "password123");
    securitySystem.checkPassword(user2, "wrongpassword");


    AccessRights accessRights(user1, &document, "admin");
    accessRights.assignAccess("write");
    std::cout << "Access level for user " << user1->getName() << ": " << accessRights.getAccessLevel() << std::endl;


    EventLog eventLog;
    eventLog.addEntry("User Alice logged in.");
    eventLog.addEntry("User Bob logged in.");
    eventLog.viewLog();


    document.edit("This is the new content of the document.");
    document.view();
    document.remove();


    delete user1;
    delete user2;
    delete email;
    delete sms;

    return 0;
}
