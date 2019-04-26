#ifndef LEAFLET_H
#define LEAFLET_H

#include <list>

class Sheet;
class Heading;
class Paragraph;
class Text;

class Leaflet {
    const int CHAR_LIMIT = 1000;
    const int uid;
    int currentIndex = 1;
    int characters = 0;
    Sheet* sheet;
    std::list<Text*> elements;
    friend class Heading;
    friend class Paragraph;
public:
    Leaflet(int);
    void addElement(Text*);
    void useSheet(Sheet*);
    void print();
    ~Leaflet();
};

#endif
