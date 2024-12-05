#pragma once
#include <string>
#include <iostream>

using namespace std;

class Smartphone
{
    char* brand = nullptr;
    char* model = nullptr;
    double memory = 0;
    double battery;
    double screen = 0;

public:

    Smartphone();
    Smartphone(string brand, string model, double battery, double memory, double screen);
    Smartphone(string brand, string model);

    Smartphone(Smartphone& original);
    ~Smartphone();

    //--
    bool operator >(Smartphone& another);
    bool operator <(Smartphone& another);
    bool operator ==(Smartphone& another);
    bool operator !=(Smartphone& another);
   
    friend ostream& operator <<(ostream& os, const Smartphone& phone);
    friend istream& operator >>(istream& is, Smartphone& phone);


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

