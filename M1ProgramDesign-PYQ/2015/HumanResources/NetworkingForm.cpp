#include "NetworkingForm.h"

using namespace std;

NetworkingForm::NetworkingForm(string name, int yob, float os_mark,
                               float nw_mark):
                               Form(name, yob), operating_system_mark(os_mark),
                               networking_mark(nw_mark) {}

float NetworkingForm::getScore() {
    return (operating_system_mark + networking_mark) / 2;
}
