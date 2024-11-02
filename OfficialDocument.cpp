#include "OfficialDocument.h"
#include <iostream>

OfficialDocument::OfficialDocument(int id, const std::string& title, const std::string& content,
    const std::string& creationDate, int number, const std::string& type, bool isSigned)
    : Document(id, title, content, creationDate), number(number), type(type), isSigned(isSigned) {}

void OfficialDocument::sign() {
    isSigned = true;
    std::cout << "Document " << getTitle() << " has been signed.\n";
}

void OfficialDocument::revokeSignature() {
    isSigned = false;
    std::cout << "Signature revoked for document " << getTitle() << ".\n";
}

void OfficialDocument::view() const {
    Document::view();
    std::cout << "Document Number: " << number << "\nType: " << type
        << "\nSigned: " << (isSigned ? "Yes" : "No") << std::endl;
}
