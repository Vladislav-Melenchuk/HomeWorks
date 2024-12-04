#pragma once
#include <string>

using namespace std;

class CoffeeMachine {
    char* brand = nullptr;
    int water;
    int coffee;
    int milk;
    bool isOn = false;
    string coffeeType;

public:

    CoffeeMachine();
    CoffeeMachine(int w, int c, int m);
    CoffeeMachine(string brand);
    ~CoffeeMachine();


    void SetBrand(const char* brand);
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