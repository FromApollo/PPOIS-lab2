#include "Reader.h"
#include <iostream>

Reader::Reader(int id, const std::string& name, const std::string& email, const std::string& password)
    : User(id, name, email, password) {}

void Reader::viewDocument(const Document& document) const {
    std::cout << "Reader " << name << " is viewing document: " << document.getTitle() << "\n";
}

void Reader::addToBookmarks(const Document& document) {
    bookmarks.push_back(document.getTitle());
    std::cout << "Document " << document.getTitle() << " has been added to bookmarks by reader " << name << ".\n";
}
