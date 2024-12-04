#include "Smartphone.h"
#include <iostream>
#include <Windows.h>
#include <string>


void Smartphone::SetBrand(const char* brand)
{
     
    if (this->brand != nullptr)
    {
        delete[] this->brand;
    }
    int length = strlen(brand) + 1;
    this->brand = new char[length];
    strcpy_s(this->brand, length, brand);
}
void Smartphone::SetModel(const char* model) 
{
    if (this->model != nullptr)
    {
        delete[] this->model;
    }
    int length = strlen(model) + 1;
    this->model = new char[length];
    strcpy_s(this->model, length, model);
}
void Smartphone::SetBattery(double battery) { this->battery = battery; }
void Smartphone::SetMemory(double memory) { this->memory = memory; }
void Smartphone::SetScreen(double screen) { this->screen = screen; }

string Smartphone::GetBrand()
{
    return string(brand);
};
string Smartphone::GetModel()
{
    return string(model);
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

//������������ 
Smartphone::Smartphone() : brand(), model(), battery(54), memory(0), screen(0)
{
    cout << "\n�� ���������.\n";
    
}

Smartphone::Smartphone(string brand, string model, double battery, double memory, double screen) : brand(), model(), battery(battery), memory(memory), screen(screen)
{
    SetBrand(brand.c_str());
    SetModel(model.c_str());
    cout << "\n��������� ��������.";
}

Smartphone::Smartphone(string brand, string model) : Smartphone() {
    SetBrand(brand.c_str());
    SetModel(model.c_str());
    cout << "\n������ ������� � ������� � �������.";
}

Smartphone::~Smartphone() {
    if (brand != nullptr)
    {
        delete[] brand;
        brand = nullptr;
    }

    if (model != nullptr)
    {
        delete[] model;
        brand = nullptr;
    }
}

//K-K
Smartphone::Smartphone(Smartphone& original)
{
    cout << "\nCopy C=tor";
    SetBrand(original.brand);
    SetModel(original.model);
    battery = original.battery;
}


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
void Smartphone::settings() 
{
    cout << "\n���������" << "\n";
    cout << "����� - " << this->brand << " , ������ - " << this->model << "\n";
    cout << "�������: " << this->battery << "\n";
}