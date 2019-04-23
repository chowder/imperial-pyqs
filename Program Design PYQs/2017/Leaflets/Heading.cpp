#include <string>
#include <iostream>
#include "Heading.h"
#include "Leaflet.h"
#include "Sheet.h"

using namespace std;

Heading::Heading(string body): Text(body) {}

void Heading::printOn(Leaflet* leaflet) {
    int index = leaflet->currentIndex++;
    int width = leaflet->sheet->width;
    // adding index
    string content = to_string(index) + ". " + body;
    // adding line breaks
    for (int i = 0; i < content.size(); i += width) {
        content.insert(i, "\n");
    }
    cout << content << endl;
}
