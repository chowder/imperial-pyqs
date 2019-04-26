#ifndef OCEAN_H
#define OCEAN_H

#include <list>

class Ship;

/* We need a common object to store a list of all the ships created. We'll call
   this singleton object the ocean. Only one instance of it will exist and will
   be retrieved every time a Ship object is created via the `getInstance()`
   method */

class Ocean {
    std::list<Ship*> ships;
    static Ocean* instance;
    Ocean();
public:
    static Ocean* getInstance();
    void addShip(Ship*);
    void broadcast(Ship*);
};

#endif
