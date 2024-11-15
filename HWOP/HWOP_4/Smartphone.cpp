#include "Smartphone.h"
#include <iostream>
#include <Windows.h>

void Smartphone::SetBrand(string brand) { this->brand = brand; }
void Smartphone::SetModel(string model) { this->model = model; }
void Smartphone::SetBattery(double battery) { this->battery = battery; }
void Smartphone::SetMemory(double memory) { this->memory = memory; }
void Smartphone::SetScreen(double screen) { this->screen = screen; }

string Smartphone::GetBrand()
{
    cout << "\n����� ��������:  " << this->brand << "\n";
    return this->brand;
};

string Smartphone::GetModel()
{
    cout << "������ ��������: " << this->model;
    return this->model;
};
double& Smartphone::GetMemory()
{
    cout << "�� �������� " << this->memory << " �� ������." << "\n";
    return this->memory;
};
double& Smartphone::GetScreen() { return this->screen; };
double& Smartphone::GetBattery()
{
    cout << "�� �������� " << this->battery << "%." << "\n";
    return this->battery;
};

//������
void Smartphone::Call(int number)
{
    if (this->battery > 0)
    {
        this->battery -= 5;
        cout << "\n���� ����� �� " << number << "... \n";
    }
    else throw "������� ��������, ������� �� ��������.";
}

void Smartphone::makePhoto()
{
    if (this->battery > 0)
    {
        this->battery -= 1.5;
        this->memory -= 0.5;
        cout << "����... \n ���� ��������� � �������.\n";
    }
    else throw "������� ��������.";
}
void Smartphone::batteryCheck()
{
    cout << "\n������� ������� �� " << this->battery << "%\n";
}
void Smartphone::playMusic()
{
    if (this->battery > 0)
    {
        if (this->battery <= 5)
        {
            cout << "\n������������ �����. �������� �������.\n";
        }
        else
        {
            this->battery -= 5;
            cout << "\n������ ������...\n";
        }
    }
    else throw "������������ �����.";
   
}
void Smartphone::chargePhone()
{
    cout << "������� ����������..." << "\n";
    Sleep(3000);
    this->battery = 100;
    cout << "\n������� �������.\n";
}