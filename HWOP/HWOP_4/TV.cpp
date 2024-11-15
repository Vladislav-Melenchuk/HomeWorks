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
