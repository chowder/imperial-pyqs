#include "ProgrammingForm.h"

using namespace std;

ProgrammingForm::ProgrammingForm(string name, int yob, float os_mark,
                                 float pg_mark):
                                 Form(name, yob),
                                 operating_system_mark(os_mark),
                                 programming_mark(pg_mark) {}

float ProgrammingForm::getScore() {
    return (operating_system_mark + programming_mark) / 2;
}
