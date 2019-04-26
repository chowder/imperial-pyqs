#include <string>
#include <iostream>
#include "Paragraph.h"
#include "Leaflet.h"
#include "Sheet.h"

using namespace std;

Paragraph::Paragraph(string body): Text(body) {}

void Paragraph::printOn(Leaflet* leaflet) {
    int width = leaflet->sheet->width;
    // adding two spaces
    string content = "  " + body;
    // adding line breaks
    for (int i = 0; i < content.size(); i += width) {
        content.insert(i, "\n");
    }
    // add additional line break
    content += "\n";
    cout << content << endl;
}
