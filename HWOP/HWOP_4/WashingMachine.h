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
    void SetBrand(string brand);
    void SetModel(const string model);
    void SetWeight(double weight);
    void SetSoap(bool soap);
    void SetIsOn(bool isOn);

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
