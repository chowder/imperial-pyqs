#ifndef PROPERTY_H
#define PROPERTY_H

#include <list>
#include <string>

class MotionDetector;
class Guard;

class Property {
    std::string name;
    std::list<MotionDetector*> detectors;
    std::list<Guard*> guards;
    void alertAllGuards(std::string);
    friend class MotionDetector;
public:
    Property(std::string);
    void addMotionDetector(MotionDetector*);
    void addGuard(Guard*);
    void transferGuard(Guard*, Property*);
};

#endif
