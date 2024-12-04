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
    cout << "На телефоне " << this->memory << " гб памяти." << "\n";
    return this->memory;
};
double& Smartphone::GetScreen() { return this->screen; };
double& Smartphone::GetBattery()
{
    cout << "На телефоне " << this->battery << "%." << "\n";
    return this->battery;
};

//Конструкторы 
Smartphone::Smartphone() : brand(), model(), battery(54), memory(0), screen(0)
{
    cout << "\nПо умолчанию.\n";
    
}

Smartphone::Smartphone(string brand, string model, double battery, double memory, double screen) : brand(), model(), battery(battery), memory(memory), screen(screen)
{
    SetBrand(brand.c_str());
    SetModel(model.c_str());
    cout << "\nПараметры телефона.";
}

Smartphone::Smartphone(string brand, string model) : Smartphone() {
    SetBrand(brand.c_str());
    SetModel(model.c_str());
    cout << "\nСоздан телефон с брендом и моделью.";
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
void Smartphone::settings() 
{
    cout << "\nНастройки" << "\n";
    cout << "Бренд - " << this->brand << " , модель - " << this->model << "\n";
    cout << "Батарея: " << this->battery << "\n";
}