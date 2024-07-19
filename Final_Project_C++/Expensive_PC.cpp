#include "Expensive_PC.h"

void Expensive_PC::showInfo() const
{
    SetBlue(); cout << "PC name: ";
    SetRed(); cout << getName() << endl;

    SetBlue(); cout << "Description: ";
    SetGreen(); cout << getDescription() << endl;

    SetBlue(); cout << "Watercooled: ";
    if (getWatercooled()) { SetGreen(); cout << "Yes" << endl; }
    else { SetRed(); cout << "No" << endl; }

    SetBlue(); cout << "SLI: ";
    if (getSLI()) { SetGreen(); cout << "Yes" << endl; }
    else { SetRed(); cout << "No" << endl; }

    SetBlue(); cout << "PC cost: ";
    SetRed(); cout << getCost() << endl;
}

string Expensive_PC::getAllPropertiesAsString() const {
    return to_string(id) + "," + name + "," + description + "," + to_string(cost) + "," + to_string(getWatercooled()) + "," + to_string(getSLI());
}

void Expensive_PC::setAllPropertiesFromString(string properties) {
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
    setWatercooled(stoi(property) != 0);

    getline(ss, property, ',');
    setSLI(stoi(property) != 0);
}
