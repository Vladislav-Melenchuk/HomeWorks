#include "Smartphone.h"
#include <iostream>

void Smartphone::SetBrand(string br) { brand = br; }
void Smartphone::SetModel(string mod) { model = mod; }
void Smartphone::SetBattery(int b) { battery = b; }
void Smartphone::SetMemory(double m) { memory = m; }
void Smartphone::SetScreen(double scr) { screen = scr; }

string Smartphone::GetBrand()
{ 
	cout << "\n-> " << brand;
	return brand; 
};

string Smartphone::GetModel() { return model; };
double& Smartphone::GetMemory() { return memory; };
double& Smartphone::GetScreen() { return screen; };
int& Smartphone::GetBattery() { return battery; };


void Smartphone::Call(int number) 
{
    cout << "\nИдет гудок на " << number << "... \n";
}
void Smartphone::makePhoto()
{
    battery -= 2;
    memory -= 0.5;
    cout << "Чикс... Фото сохранено в галереи.\n";
}
void Smartphone::batteryCheck() 
{
    cout << "\nТелефон заряжен на " << battery << "%\n";
}
void Smartphone::playMusic() 
{
    if (battery <= 5) 
    {
        cout << "\nНедостаточно заряд. Зарядите телефон.\n";
    }
    else 
    {
        battery -= 5;
        cout << "\nВоспроизведение музыки...\n";
    }
}
void Smartphone::chargePhone() 
{
    battery = 100;
    cout << "\nТелефон заряжен.\n";
}