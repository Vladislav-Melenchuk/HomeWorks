#include "WashingMachine.h"
#include <iostream>

void WashingMachine::SetBrand(const char* brand) 
{ 
    if (this->brand != nullptr)
    {
        delete[] this->brand;
    }
    this->brand = new char[100];
    strcpy_s(this->brand, 99, brand);
}
void WashingMachine::SetModel(const string model) { this->model = model; }
void WashingMachine::SetWeight(double weight) { this->weight = weight; }
void WashingMachine::SetSoap(bool soap) { this->soap = soap; }
void WashingMachine::SetIsOn(bool isOn) { this->isOn = isOn; }

string WashingMachine::GetBrand() { return string(brand); }
string WashingMachine::GetModel() { return this->model; }
double& WashingMachine::GetWeight() { return this->weight; }
bool WashingMachine::GetSoap() { return this->soap; }
bool WashingMachine::GetIsOn() { return this->isOn; }


//Конструкторы

WashingMachine::WashingMachine() : model("None"), weight(0), isOn(false), soap(0) 
{
    cout << "\nПо умолчанию" << "\n";
}

WashingMachine::WashingMachine(string brand, string model, double weight) : brand(nullptr), model(model), weight(weight), isOn(false), soap(false)
{
    SetBrand(brand.c_str());
    cout << "\nСтиральная машинка создана.\n";
}

WashingMachine::WashingMachine(string brand, string model) : WashingMachine(brand, model, 10.0) 
{
    SetBrand(brand.c_str());
    this->model = model;
    cout << "\nСтиральная машинка с заданным брендом и моделью создана.\n";
}

WashingMachine::WashingMachine(string brand) : WashingMachine()
{
    SetBrand(brand.c_str());
}

WashingMachine::~WashingMachine()
{
    if (brand != nullptr)
    {
        delete[] brand;
        brand = nullptr;
    }
}

//Методы
void WashingMachine::turnOn()
{
    this->isOn = true;
    cout << "\nВключение...";
}
void WashingMachine::turnOff()
{
    this->isOn = false;
    cout << "\nВыключение...";
}
void WashingMachine::selectMode(int mode)
{
    if (!this->isOn) {
        cout << "\nОшибка, машинка выключена, вы не можете выбрать программу.";
        return;
    }
    if (this->soap) {
        cout << "\nПрограмма " << mode << " выбрана.";
    }
    else {
        cout << "\nНету мыла, добавьте мыло в отсек.";
    }
}
void WashingMachine::addSoap()
{
    if (!this->isOn) {
        cout << "\nОшибка, машинка выключена, вы не можете выбрать программу.";
        return;
    }
    if (this->soap) {
        cout << "\nОтсек уже заполнен.";
        return;
    }
    this->soap = true;
    cout << "\nОтсек с мылом заполнен.";
}
void WashingMachine::startWash()
{
    if (!this->isOn) {
        cout << "\nОшибка, машинка выключена, вы не можете выбрать программу.";
        return;
    }
    this->soap = false;
    cout << "\nМашинка моет...";
}
