#pragma once
#include<iostream>
#include<string>

using namespace std;

class PC {
protected:
	int id;
	string name;
	string description;
	int cost;
public:
	static int counter;

	PC() { id = counter; name = "Undefined"; description = "None"; cost = 0; }
	PC(int id, string name, string description, int cost) {
		this->id = id;
		this->name = name;
		this->description = description;
		this->cost = cost;
	}

	void setName(string name) { this->name = name; }
	void setDescription(string descriprion) { this->description = description; }
	void setCost(int) { this->cost = cost; }

	string getName()const { return name; }
	string getDescription()const { return description; }
	int getCost()const { return cost; }

	int getID() const { return id; }
	virtual void showInfo() const = 0;

	virtual string getInfo() const {
		return "Name: " + name + ", Description: " + description + ", Cost: " + to_string(cost);
	}	

	virtual string getAllPropertiesAsString()const = 0;

	

};
