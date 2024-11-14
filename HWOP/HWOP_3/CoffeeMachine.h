#pragma once
#include <string>

using namespace std;

class CoffeeMachine {
    string brand;
    int water = 0;
    int coffee = 0;
    int milk = 0;
    bool isOn;
    string coffeeType;

public:
    void SetBrand(string br);
    void SetWater(int w);
    void SetCoffee(int c);
    void SetMilk(int m);
    void SetOn(bool on);
    void SetCoffeeType(string type);

    string GetCoffeeType();
    string GetBrand();
    bool GetIsOn();
    int& GetWater();
    int& GetCoffee();
    int& GetMilk();

    void turnOn();
    void turnOff();
    void refuel();
    void setCoffeeType(string type);
    void brewCoffee();
    void stats();
};