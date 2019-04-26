#include <iostream>
#include "User.h"

using namespace std;

int main() {
    /* Create our users */
    User* alice = new User("Alice", 3.5, 0.5, 5);
    User* bob = new User("Bob", 10.0, 5.0, 0);
    User* charles = new User("Charles", 7.0, 7.0, 2);

    /* Alice broadcasrs a message abd then moves */
    alice->broadcast("Hello!", 10);
    alice->moveTo(3.0, 3.0);

    /* The number of message credits Alice has is displayed */
    cout << "Alice has " << alice->getCredits() << " credits" << endl;

    /* Charles broadcasts a message */
    charles->broadcast("Come to my party at the Royal Albert Hall", 5);
    bob->addCredits(10);
}
