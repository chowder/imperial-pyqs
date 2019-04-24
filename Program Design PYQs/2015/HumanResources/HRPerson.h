#ifndef HRPERSON_H
#define HRPERSON_H

#include <string>
#include <stack>

class Form;

class HRPerson {
    const std::string name;
    const int dob;
    const int tray_capacity;
    const int min_score = 66;
    std::stack<Form*> tray;
public:
    HRPerson(std::string, int, int);
    void receive(Form*);
    int count();
    void filterForms();
};

#endif
