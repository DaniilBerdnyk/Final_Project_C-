#pragma once
#include "PC.h"
#include "hConsole.h"
#include<sstream>

class Expensive_PC : public PC {
protected:
    bool Watercooled;
    bool SLI;

public:
    Expensive_PC() : PC() { Watercooled = false; SLI = false; }
    Expensive_PC(int id, string name, string description, bool Watercooled, bool SLI, int cost) : PC(id,name, description, cost)
    {
        this->Watercooled = Watercooled;
        this->SLI = SLI;
    }

    void setWatercooled(bool Watercooled) { this->Watercooled = Watercooled; }
    bool getWatercooled() const { return Watercooled; }

    void setSLI(bool SLI) { this->SLI = SLI; }
    bool getSLI() const { return SLI; }

    void showInfo() const override;

    string getInfo() const override {
        return PC::getInfo() + ", Watercooled: " + (getWatercooled() ? "Yes" : "No") + ", SLI: " + (getSLI() ? "Yes" : "No");
    }

    string getAllPropertiesAsString()const override;
    void setAllPropertiesFromString(string properties);
};
