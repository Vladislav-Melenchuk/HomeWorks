#include "CoffeeMachine.h"
#include <iostream>

int CoffeeMachine::machine_count = 0;


void CoffeeMachine::SetBrand(const char* brand)
{ 
    if (this->brand != nullptr)
    {
        delete[] this->brand;
    }
    int length = strlen(brand) + 1;
    this->brand = new char[length];
    strcpy_s(this->brand, length, brand);
}
void CoffeeMachine::SetWater(int water) { this->water = water; }
void CoffeeMachine::SetCoffee(int coffee) { this->coffee = coffee; }
void CoffeeMachine::SetMilk(int milk) { this->milk = milk; }
void CoffeeMachine::SetOn(bool isOn) { this->isOn = isOn; }
void CoffeeMachine::SetCoffeeType(string type) { this->coffeeType = type; }

string CoffeeMachine::GetCoffeeType()
{ 
    cout << " Программа " << this->coffeeType << " выбрана.\n";
    return this->coffeeType; 
}
string CoffeeMachine::GetBrand()
{
    return string(brand); 
}
bool CoffeeMachine::GetIsOn()
{
    if (this->isOn == 0)
    {
        cout << "Машинка выключена." << "\n";
        return this->isOn;
    }
    else
        cout << "Машинка работает" << "\n";
        return this->isOn; 
}
int& CoffeeMachine::GetWater()
{
    if (this->water <= 0)
    {
        cout << "Резервуар пуст..." << "\n";
        return this->water;
    }
    else
        cout << "Резервуар с водой заполнен на " << this->water << "мл\n";
        return this->water;
}
int& CoffeeMachine::GetCoffee()
{
    if (this->coffee <= 0)
    {
        cout << "Резервуар пуст..." << "\n";
        return this->coffee;
    }
    else
        cout << "Резервуар с зернами заполнен на " << this->coffee << "мг\n";
        return this->coffee;
}
int& CoffeeMachine::GetMilk()
{ 
    if (this->milk <= 0) 
    {
        cout << "Резервуар пуст..." << "\n";
        return this->milk;
    }
    else
        cout << "Резервуар с молоком заполнен на " << this-> milk << "мл\n";
        return this->milk; 
}

int CoffeeMachine::GetCount()
{
    return machine_count;
}

//Конструкторы
CoffeeMachine::CoffeeMachine() : brand(), water(0), coffee(0), milk(0), isOn(false), coffeeType("None")
{
    cout << "Кофемашина с настройками по умолчанию." << "\n";
    machine_count++;
}

CoffeeMachine::CoffeeMachine( int w, int c, int m) : water(w), coffee(c), milk(m) 
{
    cout << "\nКофемашина заправлена.";
}

CoffeeMachine::CoffeeMachine(string brand) : CoffeeMachine()
{
    SetBrand(brand.c_str());
}

CoffeeMachine::~CoffeeMachine() {
    if (brand != nullptr)
    {
        delete[] brand;
        brand = nullptr;
    }

    machine_count--;
}


//К-К
CoffeeMachine::CoffeeMachine(CoffeeMachine& original)
{
    cout << "\nCopy C=tor";
    SetBrand(original.brand);
    milk = original.milk;
    water = original.water;
    coffee = original.coffee;

    machine_count++;
}





// Методы
void CoffeeMachine::turnOn()
{
    if (this->isOn == true)
    {
        cout << "Кофемашина уже работает." << "\n";
    }
    this->isOn = true;
    cout << "\nКофемашика включается...\n";
}
void CoffeeMachine::turnOff() 
{
    if (this->isOn == false)
    {
        cout << "Кофемашина выключена" << "\n";
    }
    this->isOn = false;
    cout << "\nКофеварка выключается...\n";
}
void CoffeeMachine::refuel()
{
    if (this->isOn = false)
    {
        cout << "Кофемашина выключена" << "\n";
    }
    this->water += 1500;
    this->coffee += 500;
    this->milk += 1500;
    cout << "\nРезервуары заполнены: вода, кофе и молоко.\n";
}
void CoffeeMachine::setCoffeeType(string type)
{
    if (this->isOn = false)
    {
        cout << "Кофемашина выключена" << "\n";
    }
    this->coffeeType = type;
    cout << "\nТип кофе установлен на " << this->coffeeType << ".\n";
}
void CoffeeMachine::brewCoffee()
{
    if (this->isOn = false)
    {
        cout << "Кофемашина выключена" << "\n";
    }

    if (this->coffeeType.empty() || this->coffeeType == "None")
    {
        cout << "\nОшибка: тип кофе не выбран. Пожалуйста, выберите тип кофе перед приготовлением.\n";
        return;
    }

    if (this->water <= 0 || this->coffee <= 0) {
        cout << "\nНедостаточно воды или кофе.\n";
        return;
    }
    if (this->coffeeType == "латте" || this->coffeeType == "капучино" || this->coffeeType == "флэт" || this->coffeeType =="американо с молоком") {
        if (this->milk <= 0) {
            cout << "\nНедостаточно молока для приготовления " << this->coffeeType << ".\n";
            return;
        }
        this->milk -= 200;
    }
    this->water -= 200;
    this->coffee -= 20;
    cout << "\nВаш " << this->coffeeType << " готов!\n";
}
void CoffeeMachine::stats()
{
    if (this->isOn = false)
    {
        cout << "Кофемашина выключена" << "\n";
    }
    cout << "\n======\n";
    cout << "\nBrand -->" << this->brand;
    cout << "\nwater -->" << this->water;
    cout << "\ncoffee -->" << this->coffee;
    cout << "\nmilk  -->" << this->milk;
    cout << "\n======\n";
}
