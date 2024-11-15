#include "CoffeeMachine.h"
#include <iostream>

void CoffeeMachine::SetBrand(string brand) { this->brand = brand; }
void CoffeeMachine::SetWater(int water) { this->water = water; }
void CoffeeMachine::SetCoffee(int coffee) { this->coffee = coffee; }
void CoffeeMachine::SetMilk(int milk) { this->milk = milk; }
void CoffeeMachine::SetOn(bool isOn) { this->isOn = isOn; }
void CoffeeMachine::SetCoffeeType(string type) { this->coffeeType = type; }

string CoffeeMachine::GetCoffeeType()
{ 
    cout << " ���������" << this->coffeeType << "�������.";
    return this->coffeeType; 
}
string CoffeeMachine::GetBrand()
{
    cout << "����� ���������� " << this->brand << "\n";
    return this->brand; 
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


//������
void CoffeeMachine::turnOn()
{
    if (this->isOn = true)
    {
        cout << "���������� ��� ��������." << "\n";
    }
    this->isOn = true;
    cout << "\n���������� ����������...\n";
}
void CoffeeMachine::turnOff() 
{
    this->isOn = false;
    cout << "\n��������� �����������...\n";
}
void CoffeeMachine::refuel()
{
    this->water += 1500;
    this->coffee += 500;
    this->milk += 1500;
    cout << "\n���������� ���������: ����, ���� � ������.\n";
}
void CoffeeMachine::setCoffeeType(string type)
{
    this->coffeeType = type;
    cout << "\n��� ���� ���������� �� " << this->coffeeType << ".\n";
}
void CoffeeMachine::brewCoffee()
{
    if (this->coffeeType.empty()) 
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
    cout << "\n======\n";
    cout << "\nwater -->" << this->water;
    cout << "\ncoffee -->" << this->coffee;
    cout << "\nmilk  -->" << this->milk;
    cout << "\n======\n";
}
