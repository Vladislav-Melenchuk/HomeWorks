#include "TV.h"
#include <iostream>

void TV::SetBrand(const char* brand) 
{
    if (this->brand != nullptr)
    {
        delete[] this->brand;
    }
    int length = strlen(brand) + 1;
    this->brand = new char[length];
    strcpy_s(this->brand, length, brand);
}
void TV::SetModel(const char* model) {
    if (this->model != nullptr)
    {
        delete[] this->model;
    }
    int length = strlen(model) + 1;
    this->model = new char[length];
    strcpy_s(this->model, length, model);
}
void TV::SetScreenSize(double screenSize) { this->screenSize = screenSize; }
void TV::SetVolume(int volume) { this->volume = volume; }
void TV::SetSound(bool sound) { this->isSound = sound; }

string TV::GetBrand() { return this->brand; }
string TV::GetModel() { return this->model; }
double& TV::GetScreenSize() { return this->screenSize; }
int& TV::GetVolume() { return this->volume; }
bool TV::GetIsSound() { return this->isSound; }


//Конструкторы
TV::TV() : screenSize(0), volume(0), isSound(false)
{
    cout << "По умолчанию.";
}

TV::TV(string brand, string model, double screenSize) : brand(), model(), screenSize(screenSize), volume(50), isSound(true)
{
    SetBrand(brand.c_str());
    SetModel(model.c_str());
    cout << "Телевизор с параметрами.";
}

TV::TV(string brand, string model) : TV()
{
    SetBrand(brand.c_str());
    SetModel(model.c_str());
    cout << "Телевизор с брендом и моделью.";
}

TV::~TV()
{
    if (brand != nullptr)
    {
        delete[] brand;
        brand = nullptr;
    }
    if (model != nullptr)
    {
        delete[] model;
        model = nullptr;
    }
}


//K-K
TV::TV(TV& original)
{
    cout << "\nCopy C=tor";
    SetBrand(original.brand);
    SetModel(original.model);
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
