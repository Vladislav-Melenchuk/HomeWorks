#include "WashingMachine.h"
#include <iostream>

void WashingMachine::SetBrand(string br) { brand = br; }
void WashingMachine::SetModel(const string mod) { model = mod; }
void WashingMachine::SetWeight(double w) { weight = w; }
void WashingMachine::SetSoap(bool sp) { soap = sp; }
void WashingMachine::SetIsOn(bool sOn) { isOn = sOn; }

string WashingMachine::GetBrand() { return brand; }
string WashingMachine::GetModel() { return model; }
double& WashingMachine::GetWeight() { return weight; }
bool WashingMachine::GetSoap() { return soap; }
bool WashingMachine::GetIsOn() { return isOn; }

void WashingMachine::turnOn() 
{
    isOn = true;
    cout << "\nВключение...";
}
void WashingMachine::turnOff()
{
    isOn = false;
    cout << "\nВыключение...";
}
void WashingMachine::selectMode(int mode)
{
    if (!isOn) {
        cout << "\nОшибка, машинка выключена, вы не можете выбрать программу.";
        return;
    }
    if (soap) {
        cout << "\nПрограмма " << mode << " выбрана.";
    }
    else {
        cout << "\nНету мыла, добавьте мыло в отсек.";
    }
}
void WashingMachine::addSoap() 
{
    if (!isOn) {
        cout << "\nОшибка, машинка выключена, вы не можете выбрать программу.";
        return;
    }
    if (soap) {
        cout << "\nОтсек уже заполнен.";
        return;
    }
    soap = true;
    cout << "\nОтсек с мылом заполнен.";
}
void WashingMachine::startWash()
{
    if (!isOn) {
        cout << "\nОшибка, машинка выключена, вы не можете выбрать программу.";
        return;
    }
    soap = false;
    cout << "\nМашинка моет...";
}
