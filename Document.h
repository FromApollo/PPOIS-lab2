#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

class Document {
protected:
    int id;
    std::string title;
    std::string content;
    std::string creationDate;

public:
    Document(int id, const std::string& title, const std::string& content, const std::string& creationDate);

    virtual ~Document() = default;

    std::string getTitle() const;

    virtual void view() const;

    void edit(const std::string& newContent);

};

#endif 