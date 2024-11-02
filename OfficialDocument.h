#ifndef OFFICIALDOCUMENT_H
#define OFFICIALDOCUMENT_H

#include "Document.h"
#include <string>

class OfficialDocument : public Document {
private:
    int number;
    std::string type;
    bool isSigned;

public:
    OfficialDocument(int id, const std::string& title, const std::string& content, const std::string& creationDate,
        int number, const std::string& type, bool isSigned = false);

    void sign();

    void revokeSignature();

    void view() const override;
};

#endif 
