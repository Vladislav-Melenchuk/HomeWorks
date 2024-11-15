#pragma once
#include <string>

using namespace std;

class CoffeeMachine {
    string brand;
    int water = 0;
    int coffee = 0;
    int milk = 0;
    bool isOn = false;
    string coffeeType;

public:
    void SetBrand(string brand);
    void SetWater(int water);
    void SetCoffee(int coffee);
    void SetMilk(int milk);
    void SetOn(bool on);
    void SetCoffeeType(string CoffeeType);

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