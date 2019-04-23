#include <iostream>
#include <string>
#include <list>
#include "Guard.h"
#include "Property.h"
#include "MotionDetector.h"

using namespace std;


int main() {
    /*
     Kensington Palance is a property fitted with three motion detectors
     having location descriptions "Hallway East", "Hallway West", and "Crown
     Jewels Display Case" respectively
    */
    Property* kensington = new Property("Kensington Palace");
    MotionDetector* hallway_east = new MotionDetector("Hallway East");
    kensington->addMotionDetector(hallway_east);
    kensington->addMotionDetector(new MotionDetector("Hallway West"));
    MotionDetector* display_case = new MotionDetector("Crown Jewels Display Case");
    kensington->addMotionDetector(display_case);

    /*
     Imperial College is a property fitted with a single motion detector
     having location description "Rector's Office"
    */
    Property* imperial = new Property("Imperial College");
    imperial->addMotionDetector(new MotionDetector("Rector's Office"));

    /*
     Alice and Bob are security guards who are assigned to protect Kensington
     Palace
    */
    Guard* alice = new Guard("Alice");
    Guard* bob = new Guard("Bob");
    kensington->addGuard(alice);
    kensington->addGuard(bob);

    /*
     "Hallway East" motion detector activates
    */
    hallway_east->activate();

    /*
     Alice is assigned to protect Imperial College
    */
    kensington->transferGuard(alice, imperial);

    /*
     The "Crown Jewels Display Case" motion detector activates
    */
    display_case->activate();
}
