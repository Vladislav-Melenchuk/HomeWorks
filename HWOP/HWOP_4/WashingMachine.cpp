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
    cout << "\n���������...";
}
void WashingMachine::turnOff()
{
    this->isOn = false;
    cout << "\n����������...";
}
void WashingMachine::selectMode(int mode)
{
    if (!this->isOn) {
        cout << "\n������, ������� ���������, �� �� ������ ������� ���������.";
        return;
    }
    if (this->soap) {
        cout << "\n��������� " << mode << " �������.";
    }
    else {
        cout << "\n���� ����, �������� ���� � �����.";
    }
}
void WashingMachine::addSoap()
{
    if (!this->isOn) {
        cout << "\n������, ������� ���������, �� �� ������ ������� ���������.";
        return;
    }
    if (this->soap) {
        cout << "\n����� ��� ��������.";
        return;
    }
    this->soap = true;
    cout << "\n����� � ����� ��������.";
}
void WashingMachine::startWash()
{
    if (!this->isOn) {
        cout << "\n������, ������� ���������, �� �� ������ ������� ���������.";
        return;
    }
    this->soap = false;
    cout << "\n������� ����...";
}
