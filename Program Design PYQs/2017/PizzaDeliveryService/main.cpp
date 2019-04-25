#include <functional>
#include "Drone.h"
#include "Pizza.h"

using namespace std;

int main() {
    static function<float()> getAltitude = []() -> float {
        return 100;
    };
    /*
     A Margherita pizza of weight 512 grams is prepared
    */
    Pizza* pizza = new Pizza(512);
    /*
     The pizza is cooked and then loaded onto a drone at
     location (51.4988, -0.1749, 0)
    */
    pizza->cook();
    Drone* drone = new Drone(51.4988, -0.1749, 0, &getAltitude);
    drone->load(pizza);
    /*
     The drone flies to location (51.5010, -0.1919, 31.5) where it
     releases the pizza
    */
    drone->flyTo(51.5010, -0.1919, 31.5);
    /*
     The cruising altitude for drones is set to 80 meters
    */
    getAltitude = []() -> float {
        return 80;
    };
    /*
     The drone returns to location (51.4988, -0.1749, 0)
    */
    drone->flyTo(51.4988, -0.1749, 0);
}
