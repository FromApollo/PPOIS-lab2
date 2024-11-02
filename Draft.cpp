#include "Draft.h"
#include <iostream>

Draft::Draft(int id, const std::string& title, const std::string& content, const std::string& creationDate,
    int version, const std::string& editor)
    : Document(id, title, content, creationDate), version(version), editor(editor) {}

void Draft::createNewVersion() {
    version++;
    std::cout << "New version created. Current version: " << version << std::endl;
}

void Draft::submitForReview() {
    std::cout << "Draft submitted for review by editor: " << editor << std::endl;
}

void Draft::view() const {
    std::cout << "Draft ID: " << id << "\nTitle: " << title << "\nContent: " << content
        << "\nCreation Date: " << creationDate << "\nVersion: " << version
        << "\nEditor: " << editor << std::endl;
}
