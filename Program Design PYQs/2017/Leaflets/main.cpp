#include <iostream>
#include "Leaflet.h"
#include "Text.h"
#include "Sheet.h"
#include "Heading.h"
#include "Paragraph.h"

using namespace std;

int main() {
    /* Create a leaflet with ID 1. Create two sheets: a small sheet (with a
       width of 50 and height of 50 characters) and a tiny sheet (with a width
       of 20 and height of 40 characters)*/
    Leaflet leaflet = Leaflet(1);
    Sheet* small_sheet = new Sheet(50, 50);
    Sheet* tiny_sheet = new Sheet(20, 40);

    /* Create and add the following text elements to the leaflet in the given
       order: A heading with the text "Importance of Bees", a paragraph with the
       text "Bees are important because...", another heading with the text
       "Threat to Bees", and a paragraph with the text "Significant
       threats..."*/
    leaflet.addElement(new Heading("Importance of Bees"));
    leaflet.addElement(new Paragraph("Bees are important because..."));
    leaflet.addElement(new Heading("Threats to Bees"));
    leaflet.addElement(new Paragraph("Significant threats..."));

    /* Assign the small sheet to the leaflet and print it. */
    leaflet.useSheet(small_sheet);
    leaflet.print();

    /* Assign the tiny sheet to the leaflet and print it again */
    leaflet.useSheet(tiny_sheet);
    leaflet.print();
}
