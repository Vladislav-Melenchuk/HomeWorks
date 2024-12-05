#pragma once
#include <string>



using namespace std;

class CoffeeMachine {

    static int machine_count;

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

    //K-K
    CoffeeMachine(CoffeeMachine& original);

    bool operator >(CoffeeMachine& another);
    bool operator <(CoffeeMachine& another);
    bool operator ==(CoffeeMachine& another);
    bool operator !=(CoffeeMachine& another);

    friend ostream& operator <<(ostream& os, const CoffeeMachine& machine);
    friend istream& operator >>(istream& is, CoffeeMachine& machine);


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
    static int GetCount();



    void turnOn();
    void turnOff();
    void refuel();
    void setCoffeeType(string type);
    void brewCoffee();
    void stats();
};