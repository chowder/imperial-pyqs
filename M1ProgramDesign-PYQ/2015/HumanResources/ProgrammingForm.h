#ifndef PROGRAMMINGFORM_H
#define PROGRAMMINGFORM_H

#include <string>
#include "Form.h"

class ProgrammingForm: public Form {
    const float operating_system_mark;
    const float programming_mark;
public:
    ProgrammingForm(std::string, int, float, float);
    float getScore();
};

#endif
