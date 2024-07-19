#include "Mid_PC.h"

void Mid_PC::showInfo() const
{
    SetBlue(); cout << "PC name: ";
    SetRed(); cout << name << endl;

    SetBlue(); cout << "Description: ";
    SetGreen(); cout << description << endl;

    SetBlue(); cout << "VR Ready: ";
    if (getVRReady()) { SetGreen(); cout << "Yes" << endl; }
    else { SetRed(); cout << "No" << endl; }

    SetBlue(); cout << "SSD: ";
    if (getSSD()) { SetGreen(); cout << "Yes" << endl; }
    else { SetRed(); cout << "No" << endl; }

    SetBlue(); cout << "DDR5 ready: ";
    if (getDDR5Ready()) { SetGreen(); cout << "Yes" << endl; }
    else { SetRed(); cout << "No" << endl; }

    SetBlue(); cout << "PC cost: ";
    SetRed(); cout << getCost() << endl;
}


string Mid_PC::getAllPropertiesAsString() const {
    return to_string(id) + "," + name + "," + description + "," + to_string(cost) + "," + to_string(getVRReady()) + "," + to_string(getSSD()) + "," + to_string(getDDR5Ready());
}

void Mid_PC::setAllPropertiesFromString(string properties) {
    stringstream ss(properties);
    string property;

    getline(ss, property, ',');
    id = stoi(property);

    getline(ss, property, ',');
    setName(property);

    getline(ss, property, ','); 
    setDescription(property);

    getline(ss, property, ',');
    setCost(stoi(property));

    getline(ss, property, ',');
    setVRReady(stoi(property) != 0);

    getline(ss, property, ',');
    setSSD(stoi(property) != 0);

    getline(ss, property, ',');
    setDDR5Ready(stoi(property) != 0);
}
