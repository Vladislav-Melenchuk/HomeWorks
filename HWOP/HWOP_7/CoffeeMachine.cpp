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
    cout << " ��������� " << this->coffeeType << " �������.\n";
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
        cout << "������� ���������." << "\n";
        return this->isOn;
    }
    else
        cout << "������� ��������" << "\n";
        return this->isOn; 
}
int& CoffeeMachine::GetWater()
{
    if (this->water <= 0)
    {
        cout << "��������� ����..." << "\n";
        return this->water;
    }
    else
        cout << "��������� � ����� �������� �� " << this->water << "��\n";
        return this->water;
}
int& CoffeeMachine::GetCoffee()
{
    if (this->coffee <= 0)
    {
        cout << "��������� ����..." << "\n";
        return this->coffee;
    }
    else
        cout << "��������� � ������� �������� �� " << this->coffee << "��\n";
        return this->coffee;
}
int& CoffeeMachine::GetMilk()
{ 
    if (this->milk <= 0) 
    {
        cout << "��������� ����..." << "\n";
        return this->milk;
    }
    else
        cout << "��������� � ������� �������� �� " << this-> milk << "��\n";
        return this->milk; 
}

int CoffeeMachine::GetCount()
{
    return machine_count;
}

//������������
CoffeeMachine::CoffeeMachine() : brand(), water(0), coffee(0), milk(0), isOn(false), coffeeType("None")
{
    cout << "���������� � ����������� �� ���������." << "\n";
    machine_count++;
}

CoffeeMachine::CoffeeMachine( int w, int c, int m) : water(w), coffee(c), milk(m) 
{
    cout << "\n���������� ����������.";
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


//�-�
CoffeeMachine::CoffeeMachine(CoffeeMachine& original)
{
    cout << "\nCopy C=tor";
    SetBrand(original.brand);
    milk = original.milk;
    water = original.water;
    coffee = original.coffee;

    machine_count++;
}





// ������
void CoffeeMachine::turnOn()
{
    if (this->isOn == true)
    {
        cout << "���������� ��� ��������." << "\n";
    }
    this->isOn = true;
    cout << "\n���������� ����������...\n";
}
void CoffeeMachine::turnOff() 
{
    if (this->isOn == false)
    {
        cout << "���������� ���������" << "\n";
    }
    this->isOn = false;
    cout << "\n��������� �����������...\n";
}
void CoffeeMachine::refuel()
{
    if (this->isOn = false)
    {
        cout << "���������� ���������" << "\n";
    }
    this->water += 1500;
    this->coffee += 500;
    this->milk += 1500;
    cout << "\n���������� ���������: ����, ���� � ������.\n";
}
void CoffeeMachine::setCoffeeType(string type)
{
    if (this->isOn = false)
    {
        cout << "���������� ���������" << "\n";
    }
    this->coffeeType = type;
    cout << "\n��� ���� ���������� �� " << this->coffeeType << ".\n";
}
void CoffeeMachine::brewCoffee()
{
    if (this->isOn = false)
    {
        cout << "���������� ���������" << "\n";
    }

    if (this->coffeeType.empty() || this->coffeeType == "None")
    {
        cout << "\n������: ��� ���� �� ������. ����������, �������� ��� ���� ����� ��������������.\n";
        return;
    }

    if (this->water <= 0 || this->coffee <= 0) {
        cout << "\n������������ ���� ��� ����.\n";
        return;
    }
    if (this->coffeeType == "�����" || this->coffeeType == "��������" || this->coffeeType == "����" || this->coffeeType =="��������� � �������") {
        if (this->milk <= 0) {
            cout << "\n������������ ������ ��� ������������� " << this->coffeeType << ".\n";
            return;
        }
        this->milk -= 200;
    }
    this->water -= 200;
    this->coffee -= 20;
    cout << "\n��� " << this->coffeeType << " �����!\n";
}
void CoffeeMachine::stats()
{
    if (this->isOn = false)
    {
        cout << "���������� ���������" << "\n";
    }
    cout << "\n======\n";
    cout << "\nBrand -->" << this->brand;
    cout << "\nwater -->" << this->water;
    cout << "\ncoffee -->" << this->coffee;
    cout << "\nmilk  -->" << this->milk;
    cout << "\n======\n";
}
