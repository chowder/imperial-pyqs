#include <iostream>
#include "Driver.h"
#include "Car.h"
#include "Turbocharge.h"
#include "Superman.h"

using namespace std;

int main() {
    float min_mass = 642;
    Driver* lewis = new Driver("Lewis Hamilton", 67);
    Car* nr14 = new Car("NR-14", 582, new TurboCharge(5, 91, 250), &min_mass);
    Car* tfd2 = new Car("TFD-2", 411, new Superman(4, 87, 175), &min_mass);

    int results;
    nr14->setDriver(lewis);
    tfd2->setDriver(lewis);

    results = nr14->benchmark(1000);
    cout << "Time taken for Lewis Hamilton to race the NR-14 over 1000m is "
         << results << endl;

    results = tfd2->benchmark(1500);
    cout << "Time taken for Lewis Hamlton to race the TFD-2 over 1500m is "
         << results << endl;

    min_mass = 550;

    results = nr14->benchmark(1000);
    cout << "Time taken for Lewis Hamilton to race the NR-14 over 1000m is "
         << results << endl;

    results = tfd2->benchmark(1500);
    cout << "Time taken for Lewis Hamlton to race the TFD-2 over 1500m is "
         << results << endl;
}
