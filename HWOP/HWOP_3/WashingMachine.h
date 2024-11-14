#pragma once
#include <string>

using namespace std;

class WashingMachine {
    string brand;
    string model;
    double weight;
    bool soap = false;
    bool isOn = false;

public:
    void SetBrand(string br);
    void SetModel(const string mod);
    void SetWeight(double w);
    void SetSoap(bool sp);
    void SetIsOn(bool sOn);

    string GetBrand();
    string GetModel();
    double& GetWeight();
    bool GetSoap();
    bool GetIsOn();

    void turnOn();
    void turnOff();
    void selectMode(int mode);
    void addSoap();
    void startWash();
};
