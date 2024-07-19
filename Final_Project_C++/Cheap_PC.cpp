#include "Cheap_PC.h"

void Cheap_PC::showInfo() const
{
	SetBlue(); cout << "PC name: ";
	SetRed(); cout << name << endl;

	SetBlue(); cout << "Description: ";
	SetGreen(); cout << description<<endl;

	SetBlue(); cout << "Integrated GPU: ";
	if (getGPU() == true) { SetGreen(); cout << "YES"<<endl; }
	else { SetRed(); cout << "NO" << endl; }

	SetBlue(); cout << "PC costed: ";
	if (getSALE() == 1) { SetRed(); }
	else { SetGreen(); }    cout << (getCost() * getSALE()) << endl;
}

string Cheap_PC::getAllPropertiesAsString() const {
    return to_string(id) + "," + name + "," + description + "," + to_string(cost) + "," + to_string(getGPU()) + "," + to_string(getSALE());
}

void Cheap_PC::setAllPropertiesFromString(string properties) {
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
    setGPU(stoi(property) != 0);

    getline(ss, property, ',');
    setSALE(stof(property));
}



