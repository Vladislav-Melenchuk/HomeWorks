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
    cout << "\nБренд телефона:  " << this->brand << "\n";
    return this->brand;
};

string Smartphone::GetModel()
{
    cout << "Модель телефона: " << this->model;
    return this->model;
};
double& Smartphone::GetMemory()
{
    cout << "На телефоне " << this->memory << " гб памяти." << "\n";
    return this->memory;
};
double& Smartphone::GetScreen() { return this->screen; };
double& Smartphone::GetBattery()
{
    cout << "На телефоне " << this->battery << "%." << "\n";
    return this->battery;
};

//Методы
void Smartphone::Call(int number)
{
    if (this->battery > 0)
    {
        this->battery -= 5;
        cout << "\nИдет гудок на " << number << "... \n";
    }
    else throw "Телефон разряжен, функция не возможна.";
}

void Smartphone::makePhoto()
{
    if (this->battery > 0)
    {
        this->battery -= 1.5;
        this->memory -= 0.5;
        cout << "Чикс... \n Фото сохранено в галереи.\n";
    }
    else throw "Телефон разряжен.";
}
void Smartphone::batteryCheck()
{
    cout << "\nТелефон заряжен на " << this->battery << "%\n";
}
void Smartphone::playMusic()
{
    if (this->battery > 0)
    {
        if (this->battery <= 5)
        {
            cout << "\nНедостаточно заряд. Зарядите телефон.\n";
        }
        else
        {
            this->battery -= 5;
            cout << "\nИграет музыка...\n";
        }
    }
    else throw "Недостаточно заряд.";
   
}
void Smartphone::chargePhone()
{
    cout << "Телефон заряжается..." << "\n";
    Sleep(3000);
    this->battery = 100;
    cout << "\nТелефон заряжен.\n";
}