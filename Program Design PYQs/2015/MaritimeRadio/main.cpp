#include "Ship.h"
#include "Ocean.h"

int main() {
    Ship* endeavor = new Ship("Endeavor", "2FBA7", 20, 36.158, -5.357);
    Ship* seaswan = new Ship("Sea Swan", "2CEU8", 10, 36.180, -5.390);

    seaswan->setEmergency(true);
    seaswan->broadcast();
    endeavor->moveTo(36.179, -5.391);
}
