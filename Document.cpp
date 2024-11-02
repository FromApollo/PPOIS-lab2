#include "Document.h"
#include <iostream>

Document::Document(int id, const std::string& title, const std::string& content, const std::string& creationDate)
    : id(id), title(title), content(content), creationDate(creationDate) {}

void Document::view() const {
    std::cout << "ID: " << id << "\nTitle: " << title << "\nContent: " << content << "\nCreation Date: " << creationDate
        << std::endl;
}

void Document::edit(const std::string& newContent) {
    content = newContent;
    std::cout << "Document content updated.\n";
}

void Document::remove() {
    std::cout << "Document '" << title << "' removed.\n";
}

std::string Document::getTitle() const {
    return title;
}
