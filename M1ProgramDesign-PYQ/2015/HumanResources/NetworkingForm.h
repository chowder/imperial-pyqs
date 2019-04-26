#ifndef NETWORKINGFORM_H
#define NETWORKINGFORM_H

#include <string>
#include "Form.h"

class NetworkingForm: public Form {
    const float operating_system_mark;
    const float networking_mark;
public:
    NetworkingForm(std::string, int, float, float);
    float getScore();
};

#endif
