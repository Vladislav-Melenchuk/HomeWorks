#include "CoffeeMachine.h"
#include <iostream>

void CoffeeMachine::SetBrand(string br) { brand = br; }
void CoffeeMachine::SetWater(int w) { water = w; }
void CoffeeMachine::SetCoffee(int c) { coffee = c; }
void CoffeeMachine::SetMilk(int m) { milk = m; }
void CoffeeMachine::SetOn(bool on) { isOn = on; }
void CoffeeMachine::SetCoffeeType(string type) { coffeeType = type; }

string CoffeeMachine::GetCoffeeType() { return coffeeType; }
string CoffeeMachine::GetBrand() { return brand; }
bool CoffeeMachine::GetIsOn() { return isOn; }
int& CoffeeMachine::GetWater() { return water; }
int& CoffeeMachine::GetCoffee() { return coffee; }
int& CoffeeMachine::GetMilk() { return milk; }

void CoffeeMachine::turnOn()
{
    isOn = true;
    cout << "\nКофеварка включена.\n";
}
void CoffeeMachine::turnOff() {
    isOn = false;
    cout << "\nКофеварка выключена.\n";
}
void CoffeeMachine::refuel() 
{
    water += 1500;
    coffee += 500;
    milk += 1500;
    cout << "\nРезервуары заполнены: вода, кофе и молоко.\n";
}
void CoffeeMachine::setCoffeeType(string type)
{
    coffeeType = type;
    cout << "\nТип кофе установлен на " << coffeeType << ".\n";
}
void CoffeeMachine::brewCoffee() 
{
    if (water <= 0 || coffee <= 0) {
        cout << "\nНедостаточно воды или кофе.\n";
        return;
    }
    if (coffeeType == "латте" || coffeeType == "капучино" || coffeeType == "флэт") {
        if (milk <= 0) {
            cout << "\nНедостаточно молока для приготовления " << coffeeType << ".\n";
            return;
        }
        milk -= 200;
    }
    water -= 200;
    coffee -= 20;
    std::cout << "\nВаш " << coffeeType << " готов!\n";
}
void CoffeeMachine::stats()
{
    cout << "\n======\n";
    cout << "\nwater -->" << water;
    cout << "\ncoffee -->" << coffee;
    cout << "\nmilk  -->" << milk;
    cout << "\n======\n";
}
