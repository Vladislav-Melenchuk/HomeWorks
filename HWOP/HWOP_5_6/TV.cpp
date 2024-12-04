#include "TV.h"
#include <iostream>

void TV::SetBrand(string brand) { this->brand = brand; }
void TV::SetModel(string model) { this->model = model; }
void TV::SetScreenSize(double screenSize) { this->screenSize = screenSize; }
void TV::SetVolume(int volume) { this->volume = volume; }
void TV::SetSound(bool sound) { this->isSound = sound; }

string TV::GetBrand() { return this->brand; }
string TV::GetModel() { return this->model; }
double& TV::GetScreenSize() { return this->screenSize; }
int& TV::GetVolume() { return this->volume; }
bool TV::GetIsSound() { return this->isSound; }


//Конструкторы
TV::TV() : brand("Unknown"), model("Unknown"), screenSize(0), volume(0), isSound(false)
{
    cout << "По умолчанию.";
}

TV::TV(string brand, string model, double screenSize) : brand(brand), model(model), screenSize(screenSize), volume(50), isSound(true)
{
    cout << "Телевизор с параметрами.";
}

TV::TV(string brand, string model) : TV()
{
    this->brand = brand;
    this->model = model;
    cout << "Телевизор с брендом и моделью.";
}


//Методы
void TV::turnOn()
{
    this->isSound = true;
    cout << "\nВключение\n";
}
void TV::turnOff()
{
    cout << "\nВыключение\n";
}
void TV::addVolume()
{
    if (this->volume == 100) {
        cout << "\n Звук на максимум.";
        return;
    }
    this->volume += 5;
    cout << "\n-->" << this->volume;
}
void TV::delVolume()
{
    if (this->volume <= 0) {
        cout << "\n Звук на минимуме.";
        return;
    }
    this->volume -= 5;
    cout << "\n-->" << this->volume;
}
void TV::offSound()
{
    this->isSound = false;
    cout << "\nЗвук выключен.";
}
void TV::onSound()
{
    this->isSound = true;
    cout << "\nЗвук включен.";
}
