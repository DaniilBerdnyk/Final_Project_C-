#pragma once
#include"PC.h"
#include"hConsole.h"
#include<sstream>

class Cheap_PC:public PC {
protected:
	bool IntegratedGPU;
	float SALE; //*0.75 = 15 %
public:
	Cheap_PC() :PC() { IntegratedGPU = true; SALE = 1; }
	Cheap_PC(int id ,string name, string description, bool IntegratedGPU, float SALE , int cost) :PC(id ,name, description , cost)
	{
		this->IntegratedGPU = IntegratedGPU; this->SALE = SALE;
	}

	void setGPU(bool IntegratedGPU) { this->IntegratedGPU = IntegratedGPU; }
	bool getGPU()const { return IntegratedGPU; }

	void setSALE(float SALE) { this->SALE = SALE; }
	float getSALE()const { return SALE; }

	void showInfo()const override;


	string getInfo() const override {
		return PC::getInfo() + ", Integrated GPU: " + (getGPU() ? "Yes" : "No") + ", Sale: " + to_string(SALE);
	}

	string getAllPropertiesAsString()const override;
	void setAllPropertiesFromString(string properties);
};