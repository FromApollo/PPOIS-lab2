#include "Editor.h"
#include <iostream>

Editor::Editor(int id, const std::string& name, const std::string& email, const std::string& password,
    const std::string& section)
    : User(id, name, email, password), section(section) {}

void Editor::editDocument(Document& document, const std::string& newContent) {
    document.edit(newContent);
    std::cout << "Editor " << name << " edited document " << document.getTitle() << ".\n";
}

void Editor::suggestChanges(Document& document, const std::string& suggestion) {
    std::cout << "Editor " << name << " suggested changes for document " << document.getTitle()
        << ": " << suggestion << ".\n";
}
