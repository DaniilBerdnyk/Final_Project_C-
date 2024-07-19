#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>

#include"hConsole.h"
using namespace std;

class User
{
private:
	string name;
	int money;
public:
	const string rules = "User";

	User() { name = "Undefined"; money = -1; }
	User(string name, int money) { this->name = name; this->money = money;
	if (name != "Undefined" && money != (-1)) { WriteUserToFile();}}
	User& operator=(const User& other) {
		if (this != &other) {
			this->name = other.name;
			this->money = other.money;
		}
		return *this;
	}


	string getName() const { return name; }
	int getMoney()const { return money; }

	void setMoney(int money) { this->money = money; WriteUserToFile(); SetGreen(); cout << "\nSucsess!" << endl; }

	void showInfo()const {
		SetBlue();
		cout << "User name: ";
		SetRed();
		cout << name << endl;
		SetBlue(); Sleep(300);
		cout << "Balance: ";
		SetRed();
		cout << money << endl;
	}

	void WriteUserToFile() const {
		ofstream outFile("User_" + name + ".txt");
		if (outFile.is_open()) {
			outFile << "User name: " << name << endl;
			outFile << "Balance: " << money << endl;
			outFile.close();
		}
		else {
			SetRed(); cout << "Unable to open file";
		}
	}

};

