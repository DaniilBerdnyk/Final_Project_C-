#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>

#include"hConsole.h"
using namespace std;

class Admin 
{
private:
	string name;
	string password;
public:
	const string rules = "Admin";

	Admin() { name = "Undefined"; password = "0000"; }
	Admin(string name, string password) { this->name = name; this->password = password; WriteAdminToFile(); }
	

	string getName() const { return name; }

	void ChangePassword() { 
	string text;
	SetBlue();cout << "Write Old password: ";
	SetRed(); cin >> text; cout << endl;
	if (text == GetPassword())
	{
		SetGreen(); cout << "Success !" << endl; Sleep(500);
		SetBlue(); cout << "Write new password: ";
		SetRed(); cin >> text;	if (text.size() != 4) { SetRed(); cout << "Wrong formular!" << endl; return; } //Exeption 
		SetPassword(text); cout << endl;
		SetGreen(); cout << "Done!" << endl; Sleep(500);
		WriteAdminToFile();
		return;
	}
	else { SetRed(); cout << "Password incorrect!" << endl;Sleep(500); return; }
	}

	void WriteAdminToFile() const{
		ofstream outFile("Admin_" + name + ".txt");
		if (outFile.is_open()) {
			outFile << "User name: " << name << endl;
			outFile << "Password: " << password << endl;
			outFile.close();
		}
		else {
			SetRed(); cout << "Unable to open file";
		}
	}

	void showInfo() {
		SetBlue();
		cout << "Admin name: ";
		SetRed();
		cout << name << endl;
	}
	string GetPassword()const { return password; }
	void SetPassword(string password) { this->password = password; }
};