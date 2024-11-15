#ifndef DRAFT_H
#define DRAFT_H

#include "Document.h"
#include <string>

class Draft : public Document {
private:
    int version;
    std::string editor;

public:
    Draft(int id, const std::string& title, const std::string& content, const std::string& creationDate,
        int version, const std::string& editor);

    void createNewVersion();

    void submitForReview();

    void view() const;

    int getVersion() const;
};

#endif 