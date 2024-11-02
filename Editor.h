#ifndef EDITOR_H
#define EDITOR_H

#include "User.h"
#include "Document.h"
#include <string>

class Editor : public User {
private:
    std::string section;

public:
    Editor(int id, const std::string& name, const std::string& email, const std::string& password,
        const std::string& section);

    void editDocument(Document& document, const std::string& newContent);

    void suggestChanges(Document& document, const std::string& suggestion);
};

#endif 
