#pragma once
#include "PC.h"
#include "hConsole.h"
#include<sstream>

class Mid_PC : public PC {
protected:
    bool VR_Ready;
    bool SSD;
    bool DDR5_ready;

public:
    Mid_PC() : PC() { VR_Ready = false; SSD = false; DDR5_ready = false; }
    Mid_PC(int id, string name, string description, bool VR_Ready, bool SSD, bool DDR5_ready, int cost) : PC(id , name, description, cost)
    {
        this->VR_Ready = VR_Ready;
        this->SSD = SSD;
        this->DDR5_ready = DDR5_ready;
    }

    void setVRReady(bool VR_Ready) { this->VR_Ready = VR_Ready; }
    bool getVRReady() const { return VR_Ready; }

    void setSSD(bool SSD) { this->SSD = SSD; }
    bool getSSD() const { return SSD; }

    void setDDR5Ready(bool DDR5_ready) { this->DDR5_ready = DDR5_ready; }
    bool getDDR5Ready() const { return DDR5_ready; }

    void showInfo() const override;

    string getInfo() const override {
        return PC::getInfo() + ", VR Ready: " + (getVRReady() ? "Yes" : "No") + ", SSD: " + (getSSD() ? "Yes" : "No") + ", DDR5 ready: " + (getDDR5Ready() ? "Yes" : "No");
    }

    string getAllPropertiesAsString() const override;
    void setAllPropertiesFromString(string properties);
};

