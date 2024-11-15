#include "WashingMachine.h"
#include <iostream>

void WashingMachine::SetBrand(string brand) { this->brand = brand; }
void WashingMachine::SetModel(const string model) { this->model = model; }
void WashingMachine::SetWeight(double weight) { this->weight = weight; }
void WashingMachine::SetSoap(bool soap) { this->soap = soap; }
void WashingMachine::SetIsOn(bool isOn) { this->isOn = isOn; }

string WashingMachine::GetBrand() { return this->brand; }
string WashingMachine::GetModel() { return this->model; }
double& WashingMachine::GetWeight() { return this->weight; }
bool WashingMachine::GetSoap() { return this->soap; }
bool WashingMachine::GetIsOn() { return this->isOn; }

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
