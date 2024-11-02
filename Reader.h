#ifndef READER_H
#define READER_H

#include "User.h"
#include "Document.h"
#include <vector>

class Reader : public User {
public:
    Reader(int id, const std::string& name, const std::string& email, const std::string& password);

    void viewDocument(const Document& document) const;

    void addToBookmarks(const Document& document);

private:
    std::vector<std::string> bookmarks;
};

#endif 
