#pragma once
#include <string>

using namespace std;

class Smartphone
{
	string brand;
	string model;
	double memory;
	int battery;
	double screen;

public:
    void SetBrand(string br);
    void SetModel(string mod);
    void SetBattery(int b);
    void SetMemory(double m);
    void SetScreen(double scr);

    string GetBrand();
    string GetModel();
    double& GetMemory();
    double& GetScreen();
    int& GetBattery();

    void Call(int number);
    void makePhoto();
    void batteryCheck();
    void playMusic();
    void chargePhone();
};

