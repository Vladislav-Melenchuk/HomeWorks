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
    cout << "\n���������...";
}
void WashingMachine::turnOff()
{
    isOn = false;
    cout << "\n����������...";
}
void WashingMachine::selectMode(int mode)
{
    if (!isOn) {
        cout << "\n������, ������� ���������, �� �� ������ ������� ���������.";
        return;
    }
    if (soap) {
        cout << "\n��������� " << mode << " �������.";
    }
    else {
        cout << "\n���� ����, �������� ���� � �����.";
    }
}
void WashingMachine::addSoap() 
{
    if (!isOn) {
        cout << "\n������, ������� ���������, �� �� ������ ������� ���������.";
        return;
    }
    if (soap) {
        cout << "\n����� ��� ��������.";
        return;
    }
    soap = true;
    cout << "\n����� � ����� ��������.";
}
void WashingMachine::startWash()
{
    if (!isOn) {
        cout << "\n������, ������� ���������, �� �� ������ ������� ���������.";
        return;
    }
    soap = false;
    cout << "\n������� ����...";
}
