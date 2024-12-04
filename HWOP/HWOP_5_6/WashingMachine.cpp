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


//������������

WashingMachine::WashingMachine() : model("None"), weight(0), isOn(false), soap(0) 
{
    cout << "\n�� ���������" << "\n";
}

WashingMachine::WashingMachine(string brand, string model, double weight) : brand(nullptr), model(model), weight(weight), isOn(false), soap(false)
{
    SetBrand(brand.c_str());
    cout << "\n���������� ������� �������.\n";
}

WashingMachine::WashingMachine(string brand, string model) : WashingMachine(brand, model, 10.0) 
{
    SetBrand(brand.c_str());
    this->model = model;
    cout << "\n���������� ������� � �������� ������� � ������� �������.\n";
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

//������
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
