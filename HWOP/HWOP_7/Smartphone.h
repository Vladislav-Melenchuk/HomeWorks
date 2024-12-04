#pragma once
#include <string>

using namespace std;

class Smartphone
{
    char* brand = nullptr;
    char* model = nullptr;
    double memory;
    double battery = 20;
    double screen;

public:

    Smartphone();
    Smartphone(string brand, string model, double battery, double memory, double screen);
    Smartphone(string brand, string model);

    Smartphone(Smartphone& original);
    ~Smartphone();


    void SetBrand(const char* brand);
    void SetModel(const char* model);
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

