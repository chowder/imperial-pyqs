#include <string>
#include "Text.h"

using namespace std;

Text::Text(string body): body(body) {}

int Text::length() {
    return body.size();
}
