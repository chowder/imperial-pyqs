#include <iostream>
#include "Almond.h"
#include "Wallnut.h"
#include "Bag.h"
#include "Label.h"

using namespace std;

int main() {
    /* Create a bag that can hold 5 nuts */
    Bag bag = Bag(5);

    /* Insert a 8g wallnut and 1.5g Almond into our bag */
    bag.insert(new Wallnut(8));
    bag.insert(new Almond(1.5));

    /* Create a label with the BNI and stick it on the bag */
    Label* label = new Label(bag.getBNI());
    bag.stick(label);
    bag.showLabel();

    /* Add another 8g wallnut and stick a new sticker */
    bag.insert(new Wallnut(8));
    label = new Label(bag.getBNI());
    bag.stick(label);
    bag.showLabel();
}
