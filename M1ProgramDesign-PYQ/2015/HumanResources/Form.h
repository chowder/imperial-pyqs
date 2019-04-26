#ifndef FORM_H
#define FORM_H

#include <string>

class Form {
public:
    const std::string name;
    const int yob;
    Form(std::string, int);
    virtual float getScore() = 0;
};

#endif
