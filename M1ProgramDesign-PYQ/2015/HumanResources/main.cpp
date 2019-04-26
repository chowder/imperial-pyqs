#include <iostream>
#include "HRPerson.h"
#include "NetworkingForm.h"
#include "ProgrammingForm.h"

using namespace std;

int main() {
    /* HR person Helen, who was born in 1975, has a tray that can hold up to 50
     applications */
    HRPerson helen = HRPerson("Helen", 1975, 50);

    /* She receives a NAF application from Peter, and a NAF and PAF application
    from Susan */
    helen.receive(new NetworkingForm("Peter", 1986, 65, 75));
    helen.receive(new ProgrammingForm("Susan", 1989, 70, 60));
    helen.receive(new NetworkingForm("Susan", 1989, 70, 80));

    /* Helen is asked to remove AFs that do not meet the minimum score */
    helen.filterForms();

    /* Helem is asked to report the number of AFs that are left */
    cout << "Helen has " << helen.count() << " AFs left" << endl;

}
