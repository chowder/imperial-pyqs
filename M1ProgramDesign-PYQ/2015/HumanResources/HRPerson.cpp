#include <iostream>
#include "HRPerson.h"
#include "Form.h"

using namespace std;

HRPerson::HRPerson(string name, int dob, int tray_capacity):
                   name(name), dob(dob), tray_capacity(tray_capacity) {}

void HRPerson::receive(Form* form) {
    if (tray.size() < tray_capacity) {
        cout << "Received " << form->name << "'s form" << endl;
        tray.push(form);
    }
    else cout << name << "'s tray is full!" << endl;
}

void HRPerson::filterForms() {
    cout << "Filtering..." << endl;
    stack<Form*> temp;
    // we go through everything in our tray
    while (tray.size() > 0) {
        Form* form = tray.top();
        tray.pop();
        // and only put onto the temp tray the applications that meet min reqs
        if (form->getScore() >= min_score) temp.push(form);
        else {
            delete form;
            cout << "Removing " << form->name << "'s application" << endl;
        }
    }
    cout << "Done filtering" << endl;
    // now we move every application back to our usual tray
    while (temp.size() > 0) {
        tray.push(temp.top());
        temp.pop();
    }
}

int HRPerson::count() {
    return tray.size();
}
