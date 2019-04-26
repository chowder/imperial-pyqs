#ifndef GUARD_H
#define GUARD_H

#include <string>

class Property;

class Guard {
    std::string name;
    Property* property;
    void alert(std::string);
    void setProperty(Property* p);
    friend class Property;
public:
    Guard(std::string);
};

#endif
