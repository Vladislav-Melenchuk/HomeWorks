#pragma once
#include <string>

using namespace std;

class Smartphone
{
    string brand;
    string model;
    double memory;
    double battery = 20;
    double screen;

public:

    Smartphone();
    Smartphone(string brand, string model, double battery, double memory, double screen);
    Smartphone(string brand, string model);

    void SetBrand(string brand);
    void SetModel(string model);
    void SetBattery(double battery);
    void SetMemory(double memory);
    void SetScreen(double screen);

    string GetBrand();
    string GetModel();
    double& GetMemory();
    double& GetScreen();
    double& GetBattery();

    void Call(int number);
    void makePhoto();
    void batteryCheck();
    void playMusic();
    void chargePhone();
    void settings();
};

